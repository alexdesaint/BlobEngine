#include <Blob/glTF2/BasicFunctions.hpp>
#include <Blob/glTF2/Material.hpp>
#include <Blob/Materials.hpp>

using namespace std;

namespace Blob::glTF2 {

Material::textureInfo::textureInfo(const nlohmann::json &j) {
    Required(j, "index", index);
    NotRequired(j, "texCoord", texCoord);

    set = true;
}

std::ostream &operator<<(ostream &s, const Material::textureInfo &a) {
    s << "      textureInfo {" << endl;
    s << "        index : " << a.index << endl;
    s << "        texCoord : " << a.texCoord << endl;
    s << "      }" << endl;
    return s;
}

Material::PbrMetallicRoughness::PbrMetallicRoughness(const nlohmann::json &j) {
    float a[4] = {1.f};
    if (NotRequired(j, "baseColorFactor", a)) {
        baseColorFactor.R = a[0];
        baseColorFactor.G = a[1];
        baseColorFactor.B = a[2];
        baseColorFactor.A = a[3];

        baseColorFactorSet = true;
    }
    NotRequired(j, "metallicFactor", metallicFactor);
    NotRequired(j, "roughnessFactor", roughnessFactor);

    if (j.find("baseColorTexture") != j.end())
        baseColorTexture = textureInfo(j["baseColorTexture"]);

    if (j.find("metallicRoughnessTexture") != j.end())
        metallicRoughnessTexture = textureInfo(j["metallicRoughnessTexture"]);

    set = true;
}

std::ostream &operator<<(ostream &s, const Material::PbrMetallicRoughness &a) {
    s << "    PbrMetallicRoughness {" << endl;

    if (a.baseColorTexture.set)
        s << a.baseColorTexture;

    if(a.baseColorFactorSet)
        s << "      baseColorFactor : " << a.baseColorFactor << endl;

    if (a.metallicRoughnessTexture.set)
        s << "      metallicRoughnessTexture : " << a.metallicRoughnessTexture << endl;
    else {
        s << "      metallicFactor : " << a.metallicFactor << endl;
        s << "      roughnessFactor : " << a.roughnessFactor << endl;
    }
    s << "    }" << endl;
    return s;
}

Material::normalTextureInfo::normalTextureInfo(const nlohmann::json &j) : textureInfo(j) {
    NotRequired(j, "scale", scale);
}

Material::occlusionTextureInfo::occlusionTextureInfo(const nlohmann::json &j) : textureInfo(j) {
    NotRequired(j, "strength", strength);
}

Material::Material(const nlohmann::json &j) {
    NotRequired(j, "name", name);

    if (j.find("pbrMetallicRoughness") != j.end())
        pbrMetallicRoughness = PbrMetallicRoughness(j["pbrMetallicRoughness"]);

    if (j.find("normalTexture") != j.end())
        normalTexture = normalTextureInfo(j["normalTexture"]);

    if (j.find("occlusionTexture") != j.end())
        occlusionTexture = occlusionTextureInfo(j["occlusionTexture"]);

    if (j.find("emissiveTexture") != j.end())
        emissiveTexture = textureInfo(j["emissiveTexture"]);

    float a[3] = {1.f};
    if (NotRequired(j, "emissiveFactor", a)) {
        emissiveFactor.R = a[0];
        emissiveFactor.G = a[1];
        emissiveFactor.B = a[2];
    }

    NotRequired(j, "alphaMode", alphaMode);
    NotRequired(j, "alphaCutoff", alphaCutoff);
    NotRequired(j, "doubleSided", doubleSided);
}

void Material::make(uint8_t options, std::vector<Texture> &textures) {
    if(!((options >> 1) & 1)) // if no NORMAL
        material = make_unique<Materials::SingleColor>(pbrMetallicRoughness.baseColorFactor);
    else if((options >> 5) & 1) // if COLOR_0
        material = make_unique<Materials::PBRColorArray>();
    else if(pbrMetallicRoughness.baseColorTexture.set && ((options >> 3) & 1)) // if texture
        material = make_unique<Materials::PBRSingleTexture>(textures[pbrMetallicRoughness.baseColorTexture.index]);
    else
        material = make_unique<Materials::PBRSingleColor>(pbrMetallicRoughness.baseColorFactor);
}

std::ostream &operator<<(std::ostream &s, const Material &a) {
    s << "  Material \"" << a.name << "\" {" << endl;

    if (a.pbrMetallicRoughness.set)
        s << a.pbrMetallicRoughness;
    if (a.normalTexture.set)
        s << "    normalTexture : " << a.normalTexture << endl;
    if (a.occlusionTexture.set)
        s << "    occlusionTexture : " << a.occlusionTexture << endl;
    if (a.emissiveTexture.set)
        s << "    emissiveTexture : " << a.emissiveTexture << endl;

    s << "    emissiveFactor : " << a.emissiveFactor;
    s << "    alphaMode : " << a.alphaMode << endl;
    s << "    alphaCutoff : " << a.alphaCutoff << endl;
    s << "    doubleSided : " << a.doubleSided << endl;

    s << "  }" << endl;
    return s;
}

} // namespace Blob::glTF2
