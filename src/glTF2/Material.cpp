#include <Blob/glTF2/Material.hpp>
#include <Blob/Exception.hpp>

using namespace std;

namespace Blob::glTF2 {

    Material::textureInfo::textureInfo(const nlohmann::json &j, std::list<Texture> &textures) {
        if (j.find("index") == j.end())
            throw Exception("glTF : Required field \"index\" not found");

        j.at("index").get_to(index);
        indexIt = next(textures.begin(), index);

        if (j.find("texCoord") != j.end())
            j.at("texCoord").get_to(texCoord);

        set = true;
    }

    Material::normalTextureInfo::normalTextureInfo(const nlohmann::json &j, std::list<Texture> &textures) :
            textureInfo(j, textures) {
        if (j.find("scale") != j.end())
            j.at("scale").get_to(texCoord);
    }

    Material::occlusionTextureInfo::occlusionTextureInfo(const nlohmann::json &j, std::list<Texture> &textures) :
            textureInfo(j, textures) {
        if (j.find("strength") != j.end())
            j.at("strength").get_to(texCoord);
    }

    Material::PbrMetallicRoughness::PbrMetallicRoughness(const nlohmann::json &j, std::list<Texture> &textures) {
        if (j.find("baseColorFactor") != j.end())
            j.at("baseColorFactor").get_to(baseColorFactor);

        if (j.find("baseColorTexture") != j.end())
            baseColorTexture = textureInfo(j["baseColorTexture"], textures);

        if (j.find("metallicFactor") != j.end())
            j.at("metallicFactor").get_to(metallicFactor);

        if (j.find("roughnessFactor") != j.end())
            j.at("roughnessFactor").get_to(roughnessFactor);

        if (j.find("metallicRoughnessTexture") != j.end())
            metallicRoughnessTexture = textureInfo(j["metallicRoughnessTexture"], textures);

        set = true;
    }

    Material::Material(const nlohmann::json &j, std::list<Texture> &textures) {
        if (j.find("name") != j.end())
            j.at("name").get_to(name);

        if (j.find("pbrMetallicRoughness") != j.end())
            pbrMetallicRoughness = PbrMetallicRoughness(j["pbrMetallicRoughness"], textures);

        if (j.find("normalTexture") != j.end())
            normalTexture = normalTextureInfo(j["normalTexture"], textures);

        if (j.find("occlusionTexture") != j.end())
            occlusionTexture = occlusionTextureInfo(j["occlusionTexture"], textures);

        if (j.find("emissiveTexture") != j.end())
            emissiveTexture = textureInfo(j["emissiveTexture"], textures);

        if (j.find("emissiveFactor") != j.end())
            j.at("emissiveFactor").get_to(emissiveFactor);

        if (j.find("alphaMode") != j.end())
            j.at("alphaMode").get_to(alphaMode);

        if (j.find("alphaCutoff") != j.end())
            j.at("alphaCutoff").get_to(alphaCutoff);

        if (j.find("doubleSided") != j.end())
            j.at("doubleSided").get_to(doubleSided);
    }

    std::ostream &operator<<(std::ostream &s, const Material &a) {
        s << "  Material {" << endl;

        s << "  }" << endl;
        return s;
    }
}
