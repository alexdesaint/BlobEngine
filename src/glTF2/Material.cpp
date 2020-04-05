#include <Blob/glTF2/BasicFunctions.hpp>
#include <Blob/glTF2/Material.hpp>

using namespace std;

namespace Blob::glTF2 {

Material::textureInfo::textureInfo(const nlohmann::json &j, std::vector<Texture> &textures) {

    Required(j, "index", index);
    NotRequired(j, "texCoord", texCoord);
    //indexIt = next(textures.begin(), index);

    set = true;
}

Material::normalTextureInfo::normalTextureInfo(const nlohmann::json &j, std::vector<Texture> &textures) : textureInfo(j, textures) {
    NotRequired(j, "scale", scale);
}

Material::occlusionTextureInfo::occlusionTextureInfo(const nlohmann::json &j, std::vector<Texture> &textures) : textureInfo(j, textures) {
    NotRequired(j, "strength", strength);
}

Material::PbrMetallicRoughness::PbrMetallicRoughness(const nlohmann::json &j, std::vector<Texture> &textures) {
    NotRequired(j, "baseColorFactor", baseColorFactor);
    NotRequired(j, "metallicFactor", metallicFactor);
    NotRequired(j, "roughnessFactor", roughnessFactor);

    if (j.find("baseColorTexture") != j.end())
        baseColorTexture = textureInfo(j["baseColorTexture"], textures);

    if (j.find("metallicRoughnessTexture") != j.end())
        metallicRoughnessTexture = textureInfo(j["metallicRoughnessTexture"], textures);

    set = true;
}

Material::Material(const nlohmann::json &j, std::vector<Texture> &textures) {
    NotRequired(j, "name", name);

    if (j.find("pbrMetallicRoughness") != j.end())
        pbrMetallicRoughness = PbrMetallicRoughness(j["pbrMetallicRoughness"], textures);

    if (j.find("normalTexture") != j.end())
        normalTexture = normalTextureInfo(j["normalTexture"], textures);

    if (j.find("occlusionTexture") != j.end())
        occlusionTexture = occlusionTextureInfo(j["occlusionTexture"], textures);

    if (j.find("emissiveTexture") != j.end())
        emissiveTexture = textureInfo(j["emissiveTexture"], textures);

    NotRequired(j, "emissiveFactor", emissiveFactor);
    NotRequired(j, "alphaMode", alphaMode);
    NotRequired(j, "alphaCutoff", alphaCutoff);
    NotRequired(j, "doubleSided", doubleSided);
}

std::ostream &operator<<(std::ostream &s, const Material &a) {
    s << "  Material {" << endl;

    s << "  }" << endl;
    return s;
}
} // namespace Blob::glTF2
