#include <Blob/glTF2/Mesh.hpp>
#include <Blob/Exception.hpp>
#include <Blob/GL/Shapes.hpp>

using namespace std;

namespace Blob::glTF2 {

    Mesh::Primitive::Primitive(const nlohmann::json &j, std::deque<Blob::glTF2::Accessor> &a,
                               std::list<Material> &materials) {
        if (j.find("attributes") == j.end())
            throw Exception("glTF : Required field \"attributes\" not found");

        j.at("attributes").get_to(attributes);

        if (attributes.find("POSITION") == attributes.end())
            throw Exception(R"(glTF : Required field "POSITION" in "attributes" not found)");

        switch (attributes.size()) {
            case 1:
                setShaderProgram(*GL::Shaders::Shader_3D_POSITION);
                break;
            case 2:
                if (attributes.find("NORMAL") != attributes.end())
                    setShaderProgram(*GL::Shaders::Shader_3D_POSITION_NORMAL);
                else
                    throw Exception(R"(glTF : fail to find the right shader)");
                break;
            case 3:
                if (attributes.find("NORMAL") != attributes.end() && attributes.find("TEXCOORD_0") != attributes.end())
                    setShaderProgram(*GL::Shaders::Shader_3D_POSITION_NORMAL_TEXCOORD_0);
                else
                    throw Exception(R"(glTF : fail to find the right shader)");
                break;
            default:
                throw Exception(R"(glTF : fail to find the right shader)");
        }

        // TODO: optimise this part, the data need to be in one Interleaved vertex. if the offset < stride
        int32_t pos = 0;
        for (const auto &k : attributes) {
            setBuffer(*a[k.second].bufferViewIt, a[k.second].bufferViewIt->byteStride, a[k.second].byteOffset, pos);

            setArrayVAO(a[k.second].type, k.first.c_str(), a[k.second].componentType, 0, a[k.second].normalized, pos);

            pos++;
        }

        if (j.find("indices") != j.end()) {
            j.at("indices").get_to(indices);

            setBufferIndices(*a[indices].bufferViewIt);

            setIndices((unsigned short *) a[indices].byteOffset, a[indices].count, a[indices].componentType);
        }

        if (j.find("material") != j.end()) {
            j.at("material").get_to(material);

            auto materialIt = std::next(materials.begin(), material);

            if (materialIt->pbrMetallicRoughness.set && materialIt->pbrMetallicRoughness.baseColorTexture.set)
                setTexture(*materialIt->pbrMetallicRoughness.baseColorTexture.indexIt);
        }

        if (j.find("mode") != j.end())
            j.at("mode").get_to(mode);

        // setMode()
    }

    Mesh::Mesh(const nlohmann::json &j, std::deque<Blob::glTF2::Accessor> &a, std::list<Material> &materials) {
        if (j.find("primitives") == j.end())
            throw Exception("glTF : Required field \"primitives\" not found");

        for (const nlohmann::json &js : j["primitives"])
            primitives.emplace_back(js, a, materials);

        if (j.find("weights") != j.end()) {
            weights.reserve(j["weights"].size());
            for (const nlohmann::json &js : j["weights"])
                weights.push_back(js.get<int>());
        }

        if (j.find("name") != j.end())
            j.at("name").get_to(name);
    }

    std::ostream &operator<<(std::ostream &s, const Mesh::Primitive &a) {
        s << "    Primitive {" << endl;
        s << "      attributes {" << endl;
        for (const auto &k : a.attributes)
            s << "        " << k.first << " : " << k.second << endl;

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
}
