#include <Blob/glTF2/SceneManager.hpp>

#include <Blob/Reader/FileReader.hpp>

#include <Blob/Core/Exception.hpp>
#include <iostream>
#include <sstream>

using namespace std;

using json = nlohmann::json;

/*
 * use https://github.com/KhronosGroup/glTF/tree/master/specification/2.0#properties-reference
 *
 * node --> Shape
 * mesh
 *   primitive --> VAO
 *
 *  Current status :
    accessor                    Done
        sparse                  Todo
            indices             Todo
            values              Todo
    animation                   Todo
        animation sampler       Todo
        channel                 Todo
            target              Todo
    asset                       Done
    buffer                      Done
    bufferView                  Done
    camera                      Todo
        orthographic            Todo
        perspective             Todo
    extension                   Todo
    extras                      Todo
    image                       Done
    material                    Done
        normalTextureInfo       Done
        occlusionTextureInfo    Done
        pbrMetallicRoughness    Done
    mesh                        Done
        primitive               Done
    node                        Done
    sampler                     Done
    scene                       Done
    skin                        Todo
    texture                     Done
    textureInfo                 Done

 */

namespace Blob::glTF2 {

SceneManager::SceneManager(const std::string &file) : file(file) {

    std::ifstream i(file);
    json j;
    i >> j;

    std::string path = Reader::FileReader::getFilePath(file);

    j.at("asset").get_to(asset);

    buffers.reserve(j["buffers"].size());
    for (const json &js : j["buffers"])
        buffers.emplace_back(js, path);

    bufferViews.reserve(j["bufferViews"].size());
    for (const json &js : j["bufferViews"])
        bufferViews.emplace_back(js);

    images.reserve(j["images"].size());
    for (const json &js : j["images"])
        images.emplace_back(js, path);

    samplers.reserve(j["samplers"].size());
    for (const json &js : j["samplers"])
        samplers.emplace_back(js);

    textures.reserve(j["textures"].size());
    for (const json &js : j["textures"])
        textures.emplace_back(js, images, samplers);

    materials.reserve(j["materials"].size());
    for (const json &js : j["materials"])
        materials.emplace_back(js);

    // accessors.reserve(j["accessors"].size());
    for (const json &js : j["accessors"])
        accessors.emplace_back(js);

    // meshes.reserve(j["meshes"].size());
    for (const json &js : j["meshes"])
        meshes.emplace_back(js, accessors, buffers, bufferViews, materials, defaultMaterial, textures);

    // nodes.reserve(j["nodes"].size());
    for (const json &js : j["nodes"])
        nodes.emplace_back(js, meshes);

    for (auto &node : nodes)
        node.updateChild(nodes);

    // scenes.reserve(j["scenes"].size());
    for (const json &js : j["scenes"])
        scenes.emplace_back(js, nodes);

    createVBO();
}

std::ostream &operator<<(std::ostream &s, const SceneManager &a) {
    s << "SceneManager {" << endl;

    s << a.asset;

    // buffer part
    for (const auto &b : a.buffers)
        s << b;

    for (const auto &b : a.bufferViews)
        s << b;

    // material part
    for (const auto &b : a.images)
        s << b;

    for (const auto &b : a.samplers)
        s << b;

    for (const auto &b : a.textures)
        s << b;

    for (const auto &b : a.materials)
        s << b;

    // model part
    for (const auto &b : a.accessors)
        s << b;

    for (const auto &b : a.meshes)
        s << b;

    for (const auto &b : a.nodes)
        s << b;

    for (const auto &b : a.scenes)
        s << b;

    s << "}" << endl;
    return s;
}

void SceneManager::copyToBuffer(int attribute, std::unordered_map<int, std::vector<uint8_t>> &bufferData, size_t &cursor, int i) {
    if (attribute != -1) {
        Accessor &a = accessors[attribute];
        BufferView &bv = bufferViews[a.bufferView];
        std::vector<uint8_t> &bd = bufferData[bv.buffer];

        size_t s = (bv.byteStride != 0) ? bv.byteStride : a.typeSize;
        for (unsigned int j = 0; j < a.typeSize; j++, cursor++)
            finalBuffer[cursor] = bd[bv.byteOffset + a.byteOffset + s * i + j];
    }
}

void SceneManager::setPrimitive(int accessor, int position, const Mesh::Primitive &p, size_t &relativeOffset) {
    if (accessor != -1) {
        Accessor &a = accessors[accessor];
        p.attributes.setArray(a.type, position, a.componentType, relativeOffset, a.normalized);
        relativeOffset += a.typeSize;
    }
}

/// This is for optimization. We make sure :
/// - buffer have interleaved vertex
/// - we dont buffer what we dont use (like remove TEXCOORD_0 if no texture)
/// - make sure same object with different transform or material are the same buffer
/// - normalize data that need to be normalised (like NORMAL)
/// - separate indices buffer
void SceneManager::createVBO() {
    // get the size of the buffer

    size_t size = 0;
    for (const auto &m : meshes)
        for (const auto &p : m.primitives)
            size += p.attributes.dataSize;

    finalBuffer.resize(size);

    std::unordered_map<int, std::vector<uint8_t>> bufferData;
    for (unsigned int i = 0; i < buffers.size(); i++)
        bufferData.emplace(i, buffers[i].getData(buffers[i].byteLength, 0));

    size_t cursor = 0;

    // buffer assign values :
    for (const auto &m : meshes) {
        for (const auto &p : m.primitives) {
            p.attributes.setBuffer(buffer, p.attributes.strideSize, cursor);

            int count = accessors[p.attributes.POSITION].count;

            for (int i = 0; i < count; i++) {
                copyToBuffer(p.attributes.POSITION, bufferData, cursor, i);
                copyToBuffer(p.attributes.NORMAL, bufferData, cursor, i);
                copyToBuffer(p.attributes.TANGENT, bufferData, cursor, i);
                copyToBuffer(p.attributes.TEXCOORD_0, bufferData, cursor, i);
                copyToBuffer(p.attributes.TEXCOORD_1, bufferData, cursor, i);
                copyToBuffer(p.attributes.COLOR_0, bufferData, cursor, i);
                copyToBuffer(p.attributes.JOINTS_0, bufferData, cursor, i);
                copyToBuffer(p.attributes.WEIGHTS_0, bufferData, cursor, i);
            }

            size_t relativeOffset = 0;

            setPrimitive(p.attributes.POSITION, Core::Shader::AttributeLocation::POSITION, p, relativeOffset);
            setPrimitive(p.attributes.NORMAL, Core::Shader::AttributeLocation::NORMAL, p, relativeOffset);
            setPrimitive(p.attributes.TANGENT, Core::Shader::AttributeLocation::TANGENT, p, relativeOffset);
            setPrimitive(p.attributes.TEXCOORD_0, Core::Shader::AttributeLocation::TEXCOORD_0, p, relativeOffset);
            setPrimitive(p.attributes.TEXCOORD_1, Core::Shader::AttributeLocation::TEXCOORD_1, p, relativeOffset);
            setPrimitive(p.attributes.COLOR_0, Core::Shader::AttributeLocation::COLOR_0, p, relativeOffset);
            setPrimitive(p.attributes.JOINTS_0, Core::Shader::AttributeLocation::JOINTS_0, p, relativeOffset);
            setPrimitive(p.attributes.WEIGHTS_0, Core::Shader::AttributeLocation::WEIGHTS_0, p, relativeOffset);
        }
    }

    buffer.setData(finalBuffer);
}

std::string SceneManager::getPrimitiveLine(int accessor, int position, unsigned int p, size_t &relativeOffset) const {
    string r;

    if (accessor != -1) {
        const Accessor &a = accessors[accessor];
        r = "            attribute" + std::to_string(p) + ".setArray(" + std::to_string(a.type) + ", " + std::to_string(position) + ", " +
            std::to_string(a.componentType) + ", " + std::to_string(relativeOffset) + ", " + std::to_string(a.normalized) + ");\n";
        relativeOffset += a.typeSize;
    }

    return r;
}

std::string join(const std::deque<std::stringstream> &deque, const std::string &j) {
    std::string ss;
    bool start = true;
    for (auto &s : deque) {
        if (start) {
            start = false;
            ss += s.str();
        } else
            ss += j + s.str();
    }

    return ss;
}

std::string SceneManager::toCHeader() const {
    std::stringstream declarations, constructorCode;
    std::deque<std::stringstream> initCode;

    std::string name = Reader::FileReader::getFileName(file);

    declarations << "    constexpr static const std::array<uint8_t, " << finalBuffer.size() << "> data{";

    for (auto d : finalBuffer)
        declarations << (unsigned int) d << ", ";

    declarations << "};\n";

    declarations << "    Blob::Core::Buffer buffer{data.data(), data.size()};\n";

    declarations << "    struct Materials {" << std::endl;
    declarations << "        Blob::Materials::SingleColor defaultM;" << std::endl;
    declarations << "    } materials;" << std::endl;

    size_t cursor = 0;

    for (unsigned int i = 0; i < meshes.size(); i++) {
        const auto &m = meshes[i];

        declarations << "    struct Mesh" + std::to_string(i) + " : public Core::Mesh {\n";
        std::stringstream code;
        std::deque<std::stringstream> init;

        for (unsigned int j = 0; j < m.primitives.size(); j++) {
            const auto &p = m.primitives[j];
            declarations << "        Blob::GL::VertexArrayObject attribute" << j << ";\n";
            declarations << "        Blob::Core::Primitive primitive" << j << ";" << std::endl;
            init.emplace_back() << "primitive" << j << "(attribute" << j << ", materials.defaultM)";

            if (m.primitives[j].indices != -1) {
                declarations << "        std::array<uint8_t, " << p.indicesArray.size() << "> indicesArray" << j << "{";
                for (auto d : p.indicesArray)
                    declarations << (unsigned int) d << ", ";
                declarations << "};\n";

                const auto &a = accessors[p.indices];
                code << "            primitive" << j << ".setIndices(indicesArray" << j << ".data(), " << a.count << ", " << a.componentType
                     << ");\n";
            }

            code << "            addPrimitive(primitive" + std::to_string(j) + ");\n";

            code << "            attribute" << j << ".setBuffer(buffer, " << p.attributes.strideSize << ", " << cursor << ");" << std::endl;
            cursor += p.attributes.dataSize;

            size_t relativeOffset = 0;
            code << getPrimitiveLine(p.attributes.POSITION, Core::Shader::AttributeLocation::POSITION, j, relativeOffset);
            code << getPrimitiveLine(p.attributes.NORMAL, Core::Shader::AttributeLocation::NORMAL, j, relativeOffset);
            code << getPrimitiveLine(p.attributes.TANGENT, Core::Shader::AttributeLocation::TANGENT, j, relativeOffset);
            code << getPrimitiveLine(p.attributes.TEXCOORD_0, Core::Shader::AttributeLocation::TEXCOORD_0, j, relativeOffset);
            code << getPrimitiveLine(p.attributes.TEXCOORD_1, Core::Shader::AttributeLocation::TEXCOORD_1, j, relativeOffset);
            code << getPrimitiveLine(p.attributes.COLOR_0, Core::Shader::AttributeLocation::COLOR_0, j, relativeOffset);
            code << getPrimitiveLine(p.attributes.JOINTS_0, Core::Shader::AttributeLocation::JOINTS_0, j, relativeOffset);
            code << getPrimitiveLine(p.attributes.WEIGHTS_0, Core::Shader::AttributeLocation::WEIGHTS_0, j, relativeOffset);
        }

        declarations << "        Mesh" << i << "(const Blob::Core::Buffer &buffer, const Materials &materials) : " << join(init, ", ") << " {\n"
                     << code.str() << "        }\n    } mesh" << i << ";\n";

        initCode.emplace_back() << "mesh" << i << "(buffer, materials)";
    }

    for (unsigned int i = 0; i < nodes.size(); i++) {
        const auto &n = nodes[i];
        declarations << "    Blob::Core::Shape shape" << i << "{";
        if (n.mesh != -1)
            declarations << "mesh" << std::to_string(n.mesh) << " ,";
        declarations << "{" << (Maths::Mat4) n << "}};\n";

        for (int c : n.children)
            constructorCode << "        shape" << i << ".addChild(shape" << c << ");" << std::endl;
    }

    for (unsigned int i = 0; i < scenes.size(); i++) {
        declarations << "    Blob::Core::Scene scene" << i << "{{";

        for (int j : scenes[i].nodes)
            declarations << "&shape" << j << ", ";

        declarations << "}};" << std::endl;
    }

    std::string cFile =
        "struct " + name + " {\n" + declarations.str() + "    " + name + "() : " + join(initCode, ", ") + " {\n" + constructorCode.str();
    cFile += "    }\n};";
    return cFile;
}
} // namespace Blob::glTF2
