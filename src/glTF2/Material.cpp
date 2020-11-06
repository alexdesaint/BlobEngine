#include <Blob/glTF2/BasicFunctions.hpp>
#include <Blob/glTF2/Material.hpp>

using namespace std;

namespace Blob::glTF2 {

Material::textureInfo::textureInfo(const nlohmann::json &j, std::vector<Texture> &textures) {
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

Material::PbrMetallicRoughness::PbrMetallicRoughness(const nlohmann::json &j, std::vector<Texture> &textures) {
    bool singleColor = false, colorTexture = false, mrTexture = false;

    float a[4] = {1.f};
    if (NotRequired(j, "baseColorFactor", a)) {
        baseColorFactor.R = a[0];
        baseColorFactor.G = a[1];
        baseColorFactor.B = a[2];
        baseColorFactor.A = a[3];

        singleColor = true;
    }
    NotRequired(j, "metallicFactor", metallicFactor);
    NotRequired(j, "roughnessFactor", roughnessFactor);

    if (j.find("baseColorTexture") != j.end()) {
        baseColorTexture = textureInfo(j["baseColorTexture"], textures);
        colorTexture = true;
    }

    if (j.find("metallicRoughnessTexture") != j.end()) {
        metallicRoughnessTexture = textureInfo(j["metallicRoughnessTexture"], textures);
        mrTexture = true;
    }

    if (colorTexture)
        colorType = ColorType::TEXTURE;

    set = true;
}

std::ostream &operator<<(ostream &s, const Material::PbrMetallicRoughness &a) {
    s << "    PbrMetallicRoughness {" << endl;
    if (a.baseColorTexture.set)
        s << a.baseColorTexture;
    else
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

Material::normalTextureInfo::normalTextureInfo(const nlohmann::json &j, std::vector<Texture> &textures) : textureInfo(j, textures) {
    NotRequired(j, "scale", scale);
}

Material::occlusionTextureInfo::occlusionTextureInfo(const nlohmann::json &j, std::vector<Texture> &textures) : textureInfo(j, textures) {
    NotRequired(j, "strength", strength);
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

    float a[3] = {1.f};
    if (NotRequired(j, "emissiveFactor", a)) {
        emissiveFactor.R = a[0];
        emissiveFactor.G = a[1];
        emissiveFactor.B = a[2];
    }

    NotRequired(j, "alphaMode", alphaMode);
    NotRequired(j, "alphaCutoff", alphaCutoff);
    NotRequired(j, "doubleSided", doubleSided);

    if (pbrMetallicRoughness.set) {
        switch (pbrMetallicRoughness.colorType) {

        case PbrMetallicRoughness::SINGLE_COLOR:
            material = new SingleColorMaterial();
            break;
        case PbrMetallicRoughness::TEXTURE:
            cout << textures[pbrMetallicRoughness.baseColorTexture.index].getTextureSize() << endl;
            material = new SingleTextureMaterial(textures[pbrMetallicRoughness.baseColorTexture.index]);
            break;
        case PbrMetallicRoughness::COLOR_ARRAY:
            break;
        }
    }
}

Material::~Material() {
    delete material;
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
