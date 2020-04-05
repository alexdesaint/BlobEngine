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
}

Mesh::Mesh(const nlohmann::json &j) {
    Required(j, "primitives", primitives);
    NotRequired(j, "weights", weights);
    NotRequired(j, "name", name);

    if(primitives.size() != 1)
        throw Exception("Mesh with multiple primitives not supported yet");

    for (auto &p : primitives) {
        // Choose the Attribute
        // VAO
        // material

        uint8_t attributeDescriptor = 0;

        if (p.attributes.POSITION != -1)
            attributeDescriptor |= 0x01;

        if (p.attributes.NORMAL != -1)
            attributeDescriptor |= 0x02;

        if (p.attributes.TANGENT != -1)
            attributeDescriptor |= 0x04;

        if (p.attributes.TEXCOORD_0 != -1)
            attributeDescriptor |= 0x08;

        if (p.attributes.TEXCOORD_1 != -1)
            attributeDescriptor |= 0x10;

        if (p.attributes.COLOR_0 != -1)
            attributeDescriptor |= 0x20;

        if (p.attributes.JOINTS_0 != -1)
            attributeDescriptor |= 0x40;

        if (p.attributes.WEIGHTS_0 != -1)
            attributeDescriptor |= 0x80;

        printf("attributeDescriptor : %x\n", attributeDescriptor);
    }
}

std::ostream &operator<<(std::ostream &s, const Mesh::Primitive &a) {
    s << "    Primitive {" << endl;
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
