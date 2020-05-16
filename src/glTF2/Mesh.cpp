#include <Blob/glTF2/BasicFunctions.hpp>
#include <Blob/glTF2/Mesh.hpp>

using namespace std;

namespace Blob::glTF2 {

void from_json(const nlohmann::json &j, Mesh::Primitive::Attribute &a) {
    Required(j, "POSITION", a.POSITION);
    NotRequired(j, "NORMAL", a.NORMAL);
    NotRequired(j, "TANGENT", a.TANGENT);
    NotRequired(j, "TEXCOORD_0", a.TEXCOORD_0);
    NotRequired(j, "TEXCOORD_1", a.TEXCOORD_1);
    NotRequired(j, "COLOR_0", a.COLOR_0);
    NotRequired(j, "JOINTS_0", a.JOINTS_0);
    NotRequired(j, "WEIGHTS_0", a.WEIGHTS_0);
}

void from_json(const nlohmann::json &j, Mesh::Primitive &a) {
    Required(j, "attributes", a.attributes);

    NotRequired(j, "indices", a.indices);
    NotRequired(j, "material", a.material);
    NotRequired(j, "mode", a.mode);

    if (a.attributes.POSITION != -1)
        a.attributeDescriptor |= 0x01;

    if (a.attributes.NORMAL != -1)
        a.attributeDescriptor |= 0x02;

    if (a.attributes.TANGENT != -1)
        a.attributeDescriptor |= 0x04;

    if (a.attributes.TEXCOORD_0 != -1)
        a.attributeDescriptor |= 0x08;

    if (a.attributes.TEXCOORD_1 != -1)
        a.attributeDescriptor |= 0x10;

    if (a.attributes.COLOR_0 != -1)
        a.attributeDescriptor |= 0x20;

    if (a.attributes.JOINTS_0 != -1)
        a.attributeDescriptor |= 0x40;

    if (a.attributes.WEIGHTS_0 != -1)
        a.attributeDescriptor |= 0x80;
}

Mesh::Mesh(const nlohmann::json &j, std::vector<glTF2::Accessor> &accessors, std::vector<glTF2::Buffer> &buffers,
           std::vector<glTF2::BufferView> &bufferViews, std::vector<glTF2::Material> &materials) {

    //Required(j, "primitives", primitives);
    primitives.reserve(j["primitives"].size());
    for (const auto &js : j["primitives"])
        primitives.emplace_back(js);

    NotRequired(j, "weights", weights);
    NotRequired(j, "name", name);

    if (primitives.size() != 1)
        throw Exception("Mesh with multiple primitives not supported yet");

    for (auto &p : primitives) {
        // Choose the the material from the attributes
        // VAO
        // - check if all the data have the same buffer and bufferView
        // - use bufferView to setBuffer
        // - use accessor to setArray
        // - set the material
        // - set indices

        //if((p.attributeDescriptor & 3) != 3)
        //    throw Exception("attributeDescriptor != 3");

        if (p.attributes.POSITION != -1) {
            Accessor &a = accessors[p.attributes.POSITION];
            BufferView &bv = bufferViews[a.bufferView];
            Buffer &b = buffers[bv.buffer];

            p.vao.setBuffer(b, bv.byteStride, bv.byteOffset);

            p.vao.setArray(accessors[p.attributes.POSITION].type,          /// num of values per array
                           glTF2::Material::shaderProgram->getAttribLocation("POSITION"), /// Shader position
                           accessors[p.attributes.POSITION].componentType, /// Type
                           accessors[p.attributes.POSITION].byteOffset,    /// Relative offset
                           accessors[p.attributes.POSITION].normalized     /// Normalized
            );
        }

        if (p.attributes.NORMAL != -1)
            p.vao.setArray(accessors[p.attributes.NORMAL].type,          /// num of values per array
                           glTF2::Material::shaderProgram->getAttribLocation("NORMAL"), /// Shader position
                           accessors[p.attributes.NORMAL].componentType, /// Type
                           accessors[p.attributes.NORMAL].byteOffset,    /// Relative offset
                           accessors[p.attributes.NORMAL].normalized     /// Normalized
            );

        if(p.indices != -1) {
            Accessor &a = accessors[p.indices];
            BufferView &bv = bufferViews[a.bufferView];
            Buffer &b = buffers[bv.buffer];

            p.indicesArray = b.getData(bv.byteLength, bv.byteOffset);

            p.setIndices(p.indicesArray.data(), a.count, a.componentType);
        }

        if(p.material != -1) {
            // check if exist ?
            p.setMaterial(materials[p.material]);
        }
    }
}

std::ostream &operator<<(std::ostream &s, const Mesh::Primitive &a) {
    s << "    Primitive {" << endl;

    s << "      attributeDescriptor : " << std::hex << (unsigned int) a.attributeDescriptor << endl;

    s << "      attributes {" << endl;
    if (a.attributes.POSITION != -1)
        s << "        POSITION : " << a.attributes.POSITION << endl;
    if (a.attributes.NORMAL != -1)
        s << "        NORMAL : " << a.attributes.NORMAL << endl;
    if (a.attributes.TANGENT != -1)
        s << "        TANGENT : " << a.attributes.TANGENT << endl;
    if (a.attributes.TEXCOORD_0 != -1)
        s << "        TEXCOORD_0 : " << a.attributes.TEXCOORD_0 << endl;
    if (a.attributes.TEXCOORD_1 != -1)
        s << "        TEXCOORD_1 : " << a.attributes.TEXCOORD_1 << endl;
    if (a.attributes.COLOR_0 != -1)
        s << "        COLOR_0 : " << a.attributes.COLOR_0 << endl;
    if (a.attributes.JOINTS_0 != -1)
        s << "        JOINTS_0 : " << a.attributes.JOINTS_0 << endl;
    if (a.attributes.WEIGHTS_0 != -1)
        s << "        WEIGHTS_0 : " << a.attributes.WEIGHTS_0 << endl;
    s << "      }" << endl;

    if (a.indices != -1)
        s << "      indices : " << a.indices << endl;

    if (a.material != -1)
        s << "      material : " << a.material << endl;

    if (a.mode != -1)
        s << "      mode : " << a.mode << endl;
    s << "    }" << endl;

    return s;
}

Mesh::Primitive::Primitive() : Blob::Mesh(vao) {}

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
