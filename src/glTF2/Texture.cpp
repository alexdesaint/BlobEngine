#include <Blob/glTF2/BasicFunctions.hpp>
#include <Blob/glTF2/Texture.hpp>

using namespace std;

namespace Blob::glTF2 {
    Texture::Texture(const nlohmann::json &j, vector<Image> &images, vector<Sampler> &samplers) {

        NotRequired(j, "sampler", sampler);/// TODO: Create a Blob::Sampler class

        if(NotRequired(j, "source", source)) {
            setImage(images[source].uri);
        }

        NotRequired(j, "name", name);
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
