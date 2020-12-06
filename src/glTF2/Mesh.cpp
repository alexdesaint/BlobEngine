#include <Blob/GL/Shader.hpp>
#include <Blob/glTF2/BasicFunctions.hpp>
#include <Blob/glTF2/Mesh.hpp>
#include <iomanip>

using namespace std;

template<typename T, int SIZE>
std::vector<array<T, SIZE>> readSerie(const vector<uint8_t> &buffer, const int count, const int offset) {
    union {
        T f;
        uint8_t b[sizeof(T)];
    } u;

    std::vector<array<T, SIZE>> data(count);

    int posIndex = 0;
    int localPosIndex = 0;
    for (int i = offset; i < (count * SIZE * sizeof(T) + offset); i += sizeof(T)) {
        for (int j = 0; j < sizeof(T); j++)
            u.b[j] = buffer[j + i];
        data[posIndex][localPosIndex] = u.f;
        localPosIndex++;
        if (localPosIndex == SIZE) {
            localPosIndex = 0;
            posIndex++;
        }
    }

    return data;
}

std::ostream &operator<<(std::ostream &os, array<float, 2> p) {
    // os << "{" << std::setprecision(1) << std::fixed << p[0] << "f, " << p[1] << "f}";
    os << "{" << std::setprecision(2) << p[0] << ", " << p[1] << "}";
    return os;
}
std::ostream &operator<<(std::ostream &os, array<float, 3> p) {
    // os << "{" << std::setprecision(1) << std::fixed << p[0] << "f, " << p[1] << "f, " << p[2] << "f}";
    os << "{" << std::setprecision(2) << p[0] << ", " << p[1] << ", " << p[2] << "}";
    return os;
}
std::ostream &operator<<(std::ostream &os, array<float, 4> p) {
    // os << "{" << std::setprecision(1) << std::fixed << p[0] << "f, " << p[1] << "f, " << p[2] << "f, " << p[3] << "f}";
    // os << "{" << std::setprecision(1) << std::fixed << p[0] << "f, " << p[1] << "f, " << p[2] << "f}";
    os << "{" << std::setprecision(2) << p[0] << ", " << p[1] << ", " << p[2] << "}";
    return os;
}

namespace Blob::glTF2 {

Mesh::Primitive::Attribute::Attribute(const nlohmann::json &j, std::deque<glTF2::Accessor> &accessors, std::vector<glTF2::Buffer> &buffers,
                                      std::vector<glTF2::BufferView> &bufferViews) {

    /// TODO: Safety check
    /// - check if all the data have the same buffer and bufferView
    /// - check if the material have all the attributes needed

    Required(j, "POSITION", POSITION);
    strideSize = accessors[POSITION].typeSize;
    dataSize = accessors[POSITION].dataSize;
    std::size_t count = accessors[POSITION].count;
    types = 1;

    if (NotRequired(j, "NORMAL", NORMAL)) {
        if (count != accessors[NORMAL].count)
            NORMAL = -1; // TODO: print a warning
        strideSize += accessors[NORMAL].typeSize;
        dataSize += accessors[NORMAL].dataSize;

        types |= 1 << 1;
    }
    if (NotRequired(j, "TANGENT", TANGENT)) {
        if (count != accessors[TANGENT].count)
            TANGENT = -1; // TODO: print a warning
        strideSize += accessors[TANGENT].typeSize;
        dataSize += accessors[TANGENT].dataSize;

        types |= 1 << 2;
    }
    if (NotRequired(j, "TEXCOORD_0", TEXCOORD_0)) {
        if (count != accessors[TEXCOORD_0].count)
            TEXCOORD_0 = -1; // TODO: print a warning
        strideSize += accessors[TEXCOORD_0].typeSize;
        dataSize += accessors[TEXCOORD_0].dataSize;

        types |= 1 << 3;
    }
    if (NotRequired(j, "TEXCOORD_1", TEXCOORD_1)) {
        if (count != accessors[TEXCOORD_1].count)
            TEXCOORD_1 = -1; // TODO: print a warning
        strideSize += accessors[TEXCOORD_1].typeSize;
        dataSize += accessors[TEXCOORD_1].dataSize;

        types |= 1 << 4;
    }
    if (NotRequired(j, "COLOR_0", COLOR_0)) {
        if (count != accessors[COLOR_0].count)
            COLOR_0 = -1; // TODO: print a warning
        strideSize += accessors[COLOR_0].typeSize;
        dataSize += accessors[COLOR_0].dataSize;

        types |= 1 << 5;
    }
    if (NotRequired(j, "JOINTS_0", JOINTS_0)) {
        if (count != accessors[JOINTS_0].count)
            JOINTS_0 = -1; // TODO: print a warning
        strideSize += accessors[JOINTS_0].typeSize;
        dataSize += accessors[JOINTS_0].dataSize;

        types |= 1 << 6;
    }
    if (NotRequired(j, "WEIGHTS_0", WEIGHTS_0)) {
        if (count != accessors[WEIGHTS_0].count)
            WEIGHTS_0 = -1; // TODO: print a warning
        strideSize += accessors[WEIGHTS_0].typeSize;
        dataSize += accessors[WEIGHTS_0].dataSize;

        types |= 1 << 7;
    }
}

std::ostream &operator<<(std::ostream &s, const Mesh::Primitive::Attribute &a) {
    s << "      attributes {" << endl;
    if (a.POSITION != -1)
        s << "        POSITION : " << a.POSITION << endl;
    if (a.NORMAL != -1)
        s << "        NORMAL : " << a.NORMAL << endl;
    if (a.TANGENT != -1)
        s << "        TANGENT : " << a.TANGENT << endl;
    if (a.TEXCOORD_0 != -1)
        s << "        TEXCOORD_0 : " << a.TEXCOORD_0 << endl;
    if (a.TEXCOORD_1 != -1)
        s << "        TEXCOORD_1 : " << a.TEXCOORD_1 << endl;
    if (a.COLOR_0 != -1)
        s << "        COLOR_0 : " << a.COLOR_0 << endl;
    if (a.JOINTS_0 != -1)
        s << "        JOINTS_0 : " << a.JOINTS_0 << endl;
    if (a.WEIGHTS_0 != -1)
        s << "        WEIGHTS_0 : " << a.WEIGHTS_0 << endl;
    s << "      }" << endl;
    return s;
}

Mesh::Primitive::Primitive(const nlohmann::json &j, std::deque<glTF2::Accessor> &accessors, std::vector<glTF2::Buffer> &buffers,
                           std::vector<glTF2::BufferView> &bufferViews, std::vector<glTF2::Material> &materials, const Core::Material &defautMaterial, std::vector<Texture> &textures)
    : attributes(j["attributes"], accessors, buffers, bufferViews) {

    NotRequired(j, "mode", mode);

    if (NotRequired(j, "material", material)) {
        if(!materials[material].material)
            materials[material].make(attributes.types, textures);
        primitive = std::make_unique<Core::Primitive>(&attributes, &*materials[material].material, &renderOptions);
    } else
        primitive = std::make_unique<Core::Primitive>(&attributes, &defautMaterial, &renderOptions);

    if (NotRequired(j, "indices", indices)) {
        Accessor &a = accessors[indices];
        BufferView &bv = bufferViews[a.bufferView];
        Buffer &b = buffers[bv.buffer];

        indicesArray = b.getData(a.dataSize, bv.byteOffset + a.byteOffset);

        renderOptions.setIndices(indicesArray.data(), a.count, a.componentType);
    }
}

std::ostream &operator<<(std::ostream &s, const Mesh::Primitive &a) {
    s << "    Primitive {" << endl;

    s << a.attributes;

    if (a.indices != -1)
        s << "      indices : " << a.indices << endl;

    if (a.material != -1)
        s << "      material : " << a.material << endl;

    if (a.mode != -1)
        s << "      mode : " << a.mode << endl;
    s << "    }" << endl;

    return s;
}

Mesh::Mesh(const nlohmann::json &j, std::deque<glTF2::Accessor> &accessors, std::vector<glTF2::Buffer> &buffers,
           std::vector<glTF2::BufferView> &bufferViews, std::vector<glTF2::Material> &materials, const Core::Material &defautMaterial, std::vector<Texture> &textures) {

    //primitives.reserve(j["primitives"].size());
    for (const auto &js : j["primitives"])
        primitives.emplace_back(js, accessors, buffers, bufferViews, materials, defautMaterial, textures);

    for (Primitive &p : primitives)
        addPrimitive(*p.primitive);

    NotRequired(j, "weights", weights);
    NotRequired(j, "name", name);
}

std::ostream &operator<<(std::ostream &s, const Mesh &a) {
    s << "  Mesh {" << endl;

    for (auto &i : a.primitives) {
        s << i;
    }

    if (!a.weights.empty()) {
        s << "    weights :" << endl;
        for (auto &i : a.weights)
            s << "      " << i << endl;
    }

    s << "  }" << endl;
    return s;
}

} // namespace Blob::glTF2
