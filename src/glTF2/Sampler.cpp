#include <Blob/glTF2/BasicFunctions.hpp>
#include <Blob/glTF2/Sampler.hpp>
#include <glad/glad.h>

using namespace std;

namespace Blob::glTF2 {
Sampler::Sampler() : magFilter(GL_NEAREST), minFilter(GL_NEAREST), wrapS(GL_REPEAT), wrapT(GL_REPEAT) {}

Sampler::Sampler(const nlohmann::json &j) : magFilter(GL_NEAREST), minFilter(GL_NEAREST), wrapS(GL_REPEAT), wrapT(GL_REPEAT) {
    NotRequired(j, "name", magFilter);
    NotRequired(j, "name", minFilter);
    NotRequired(j, "name", wrapS);
    NotRequired(j, "name", wrapT);
    NotRequired(j, "name", name);
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
        return "GL_MIRRORED_REPEAT";
    case GL_REPEAT:
        return "GL_REPEAT";
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
} // namespace Blob::glTF2