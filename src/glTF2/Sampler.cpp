#include <Blob/glTF2/Sampler.hpp>
#include <glad/glad.h>

using namespace std;

namespace Blob::glTF2 {
    Sampler::Sampler(const nlohmann::json &j) {
        if (j.find("magFilter") != j.end())
            j.at("magFilter").get_to(magFilter);

        if (j.find("minFilter") != j.end())
            j.at("minFilter").get_to(minFilter);

        if (j.find("wrapS") != j.end())
            j.at("wrapS").get_to(wrapS);

        if (j.find("wrapT") != j.end())
            j.at("wrapT").get_to(wrapT);

        if (j.find("name") != j.end())
            j.at("name").get_to(name);
    }

    string getName(int num) {
        switch (num) {
            case GL_NEAREST:
                return "NEAREST";
            case GL_LINEAR:
                return "GL_LINEAR";
            case GL_NEAREST_MIPMAP_NEAREST:
                return "GL_NEAREST_MIPMAP_NEAREST";
            case GL_LINEAR_MIPMAP_NEAREST:
                return "GL_LINEAR_MIPMAP_NEAREST";
            case GL_NEAREST_MIPMAP_LINEAR:
                return "GL_NEAREST_MIPMAP_LINEAR";
            case GL_LINEAR_MIPMAP_LINEAR:
                return "GL_LINEAR_MIPMAP_LINEAR";
            case GL_CLAMP_TO_EDGE:
                return "GL_CLAMP_TO_EDGE";
            case GL_MIRRORED_REPEAT:
                return "GL_CLAMP_TO_EDGE";
            case GL_REPEAT:
                return "GL_CLAMP_TO_EDGE";
            default:
                return "UNKNOW";
        }
    }

    std::ostream &operator<<(std::ostream &s, const Sampler &a) {
        s << "  Sampler {" << endl;

        s << "    magFilter : " << getName(a.magFilter) << endl;
        s << "    minFilter : " << getName(a.minFilter) << endl;
        s << "    wrapS : " << getName(a.wrapS) << endl;
        s << "    wrapT : " << getName(a.wrapT) << endl;

        if (!a.name.empty())
            s << "    name : " << a.name << endl;

        s << "  }" << endl;

        return s;
    }
}