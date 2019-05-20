#include <Blob/glTF2/Texture.hpp>

using namespace std;

namespace Blob::glTF2 {
    Texture::Texture(const nlohmann::json &j, list<Image> &images, list<Sampler> &samplers) {

        if (j.find("sampler") != j.end()) {
            j.at("sampler").get_to(sampler);
            samplerIt = next(samplers.begin(), sampler);
        }

        if (j.find("source") != j.end()) {
            j.at("source").get_to(source);
            sourceIt = next(images.begin(), source);
            setImage(sourceIt->uri);
        }

        if (j.find("name") != j.end())
            j.at("name").get_to(name);
    }

    std::ostream &operator<<(std::ostream &s, const Texture &a) {
        s << "  Texture {" << endl;

        if (a.source != -1)
            s << "    source : " << a.source << endl;

        if (a.sampler != -1)
            s << "    sampler : " << a.sampler << endl;

        if (!a.name.empty())
            s << "    name : " << a.name << endl;

        s << "  }" << endl;
        return s;
    }
}
