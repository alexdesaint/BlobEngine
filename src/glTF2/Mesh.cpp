#include <Blob/GL/ShaderProgram.hpp>
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

Mesh::Primitive::Attribute::Attribute(const nlohmann::json &j, std::vector<glTF2::Accessor> &accessors, std::vector<glTF2::Buffer> &buffers,
                                      std::vector<glTF2::BufferView> &bufferViews) {

    /// TODO: Safety check
    /// - check if all the data have the same buffer and bufferView
    /// - check if the material have all the attributes needed

    Required(j, "POSITION", POSITION);
    NotRequired(j, "NORMAL", NORMAL);
    NotRequired(j, "TANGENT", TANGENT);
    NotRequired(j, "TEXCOORD_0", TEXCOORD_0);
    NotRequired(j, "TEXCOORD_1", TEXCOORD_1);
    NotRequired(j, "COLOR_0", COLOR_0);
    NotRequired(j, "JOINTS_0", JOINTS_0);
    NotRequired(j, "WEIGHTS_0", WEIGHTS_0);

    BufferView &bv = bufferViews[accessors[POSITION].bufferView];

    /// tests
//    auto data = buffers[bv.buffer].getData(bv.byteLength, bv.byteOffset);
//    auto pos = readSerie<float, 3>(data, (int) 24, (int) accessors[POSITION].byteOffset);
//    auto normal = readSerie<float, 3>(data, (int) 24, (int) accessors[NORMAL].byteOffset);
//    auto textcoor = readSerie<float, 2>(data, (int) 24, (int) accessors[TEXCOORD_0].byteOffset);
//    for (int i = 0; i < 24; i++)
//        cout << "{" << pos[i] << ", " << normal[i] << ", " << textcoor[i] << "}," << endl;

    setBuffer(buffers[bv.buffer], bv.byteStride);

    setArray(accessors[POSITION].type,                       /// num of values per array
             GL::ShaderProgram::AttributeLocation::POSITION, /// Shader position
             accessors[POSITION].componentType,              /// Type
             accessors[POSITION].byteOffset + bufferViews[accessors[POSITION].bufferView].byteOffset,                 /// Relative offset
             accessors[POSITION].normalized                  /// Normalized
    );

    if (NORMAL != -1)
        setArray(accessors[NORMAL].type,                       /// num of values per array
                 GL::ShaderProgram::AttributeLocation::NORMAL, /// Shader position
                 accessors[NORMAL].componentType,              /// Type
                 accessors[NORMAL].byteOffset + bufferViews[accessors[NORMAL].bufferView].byteOffset,                 /// Relative offset
                 accessors[NORMAL].normalized                  /// Normalized
        );

    if (TANGENT != -1)
        setArray(accessors[TANGENT].type,                       /// num of values per array
                 GL::ShaderProgram::AttributeLocation::TANGENT, /// Shader position
                 accessors[TANGENT].componentType,              /// Type
                 accessors[TANGENT].byteOffset + bufferViews[accessors[TANGENT].bufferView].byteOffset,                 /// Relative offset
                 accessors[TANGENT].normalized                  /// Normalized
        );

    if (TEXCOORD_0 != -1)
        setArray(accessors[TEXCOORD_0].type,                       /// num of values per array
                 GL::ShaderProgram::AttributeLocation::TEXCOORD_0, /// Shader position
                 accessors[TEXCOORD_0].componentType,              /// Type
                 accessors[TEXCOORD_0].byteOffset + bufferViews[accessors[TEXCOORD_0].bufferView].byteOffset,                 /// Relative offset
                 accessors[TEXCOORD_0].normalized                  /// Normalized
        );

    if (TEXCOORD_1 != -1)
        setArray(accessors[TEXCOORD_1].type,                       /// num of values per array
                 GL::ShaderProgram::AttributeLocation::TEXCOORD_1, /// Shader position
                 accessors[TEXCOORD_1].componentType,              /// Type
                 accessors[TEXCOORD_1].byteOffset + bufferViews[accessors[POSITION].bufferView].byteOffset,                 /// Relative offset
                 accessors[TEXCOORD_1].normalized                  /// Normalized
        );

    if (COLOR_0 != -1)
        setArray(accessors[COLOR_0].type,                       /// num of values per array
                 GL::ShaderProgram::AttributeLocation::COLOR_0, /// Shader position
                 accessors[COLOR_0].componentType,              /// Type
                 accessors[COLOR_0].byteOffset + bufferViews[accessors[TEXCOORD_1].bufferView].byteOffset,                 /// Relative offset
                 accessors[COLOR_0].normalized                  /// Normalized
        );

    if (JOINTS_0 != -1)
        setArray(accessors[JOINTS_0].type,                       /// num of values per array
                 GL::ShaderProgram::AttributeLocation::JOINTS_0, /// Shader position
                 accessors[JOINTS_0].componentType,              /// Type
                 accessors[JOINTS_0].byteOffset + bufferViews[accessors[JOINTS_0].bufferView].byteOffset,                 /// Relative offset
                 accessors[JOINTS_0].normalized                  /// Normalized
        );

    if (WEIGHTS_0 != -1)
        setArray(accessors[WEIGHTS_0].type,                       /// num of values per array
                 GL::ShaderProgram::AttributeLocation::WEIGHTS_0, /// Shader position
                 accessors[WEIGHTS_0].componentType,              /// Type
                 accessors[WEIGHTS_0].byteOffset + bufferViews[accessors[WEIGHTS_0].bufferView].byteOffset,                 /// Relative offset
                 accessors[WEIGHTS_0].normalized                  /// Normalized
        );
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

Mesh::Primitive::Primitive(const nlohmann::json &j, std::vector<glTF2::Accessor> &accessors, std::vector<glTF2::Buffer> &buffers,
                           std::vector<glTF2::BufferView> &bufferViews, std::vector<glTF2::Material> &materials)
    : attributes(j["attributes"], accessors, buffers, bufferViews), Blob::Mesh(attributes) {

    NotRequired(j, "mode", mode);

    if (NotRequired(j, "indices", indices)) {
        Accessor &a = accessors[indices];
        BufferView &bv = bufferViews[a.bufferView];
        Buffer &b = buffers[bv.buffer];

        indicesArray = b.getData(bv.byteLength, bv.byteOffset);

        setIndices(indicesArray.data(), a.count, a.componentType);
        /// Some random tests

        //        auto data = buffers[bv.buffer].getData(bv.byteLength, bv.byteOffset);
        //        auto indices = readSerie<float, 1>(indicesArray, (int) bv.byteLength, (int) accessors[attributes.POSITION].byteOffset);
        //        auto pos = readSerie<float, 3>(data, (int) bv.byteLength, (int) accessors[attributes.POSITION].byteOffset);
        //        for(auto &p : pos)
        //            cout << "{" << std::setprecision(2) << p[0] << ", " << p[1] << ", " << p[2] << "}" << endl;
    }

    if (NotRequired(j, "material", material) && materials[material].material != nullptr)
        setMaterial(*materials[material].material);
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

Mesh::Mesh(const nlohmann::json &j, std::vector<glTF2::Accessor> &accessors, std::vector<glTF2::Buffer> &buffers,
           std::vector<glTF2::BufferView> &bufferViews, std::vector<glTF2::Material> &materials) {

    primitives.reserve(j["primitives"].size());
    for (const auto &js : j["primitives"])
        primitives.emplace_back(js, accessors, buffers, bufferViews, materials);

    NotRequired(j, "weights", weights);
    NotRequired(j, "name", name);

    if (primitives.size() != 1)
        throw Exception("Mesh with multiple primitives not supported yet");
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
