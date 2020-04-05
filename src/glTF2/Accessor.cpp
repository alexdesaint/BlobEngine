#include <Blob/glTF2/Accessor.hpp>
#include <Blob/glTF2/BasicFunctions.hpp>
#include <glad/glad.h>

using namespace std;

namespace Blob::glTF2 {

static const size_t NUM_TYPE = 7;

struct TypeInfo {
    const char *name;
    Accessor::Type type;
};

const TypeInfo typeInfos[NUM_TYPE] = {{"SCALAR", Accessor::SCALAR}, {"VEC2", Accessor::VEC2}, {"VEC3", Accessor::VEC3}, {"VEC4", Accessor::VEC4},
                                      {"MAT2", Accessor::MAT2},     {"MAT3", Accessor::MAT3}, {"MAT4", Accessor::MAT4}};

static Accessor::Type strToType(const char *str) {
    for (auto typeInfo : typeInfos) {
        if (strcmp(typeInfo.name, str) == 0) {
            return typeInfo.type;
        }
    }
    // TODO throw exeption when getType fail
    return Accessor::SCALAR;
}

Accessor::Accessor(const nlohmann::json &j) {
    NotRequired(j, "bufferView", bufferView);
    NotRequired(j, "byteOffset", byteOffset);
    Required(j, "componentType", componentType);
    NotRequired(j, "normalized", normalized);
    Required(j, "count", count);

    string typeStr;
    Required(j, "type", typeStr);
    type = strToType(typeStr.c_str());

    NotRequired(j, "min", min);
    NotRequired(j, "max", max);
    NotRequired(j, "name", name);
}

template<typename T>
std::ostream &printArray(std::ostream &s, uint8_t *b, int size, int nbOfElements) {
    for (int k = 0; k < size / sizeof(T); k++) {
        s << ((T *) b)[k] << " ";
        if (nbOfElements > 1 && (k + 1) % nbOfElements == 0)
            s << "* ";
    }
    return s << endl;
}

std::ostream &operator<<(std::ostream &s, const Accessor &d) {

    s << "  Accessor {" << endl;

    s << "    bufferView : " << d.bufferView << endl;

    s << "    byteOffset : " << d.byteOffset << endl;

    switch (d.componentType) {
    case GL_FLOAT:
        s << "    componentType : float" << endl;
        break;
    case GL_UNSIGNED_SHORT:
        s << "    componentType : unsigned short" << endl;
        break;
    default:
        s << "    componentType " << d.componentType << " not implemented" << endl;
        break;
    }

    s << "    normalized : " << d.normalized << endl;

    switch (d.type) {
    case Accessor::Type::MAT2:
        s << "    type : MAT2 or VEC4" << endl;
        break;
    case Accessor::Type::MAT3:
        s << "    type : MAT3" << endl;
        break;
    case Accessor::Type::MAT4:
        s << "    type : MAT4" << endl;
        break;
    case Accessor::Type::SCALAR:
        s << "    type : SCALAR" << endl;
        break;
    case Accessor::Type::VEC2:
        s << "    type : VEC2" << endl;
        break;
    case Accessor::Type::VEC3:
        s << "    type : VEC3" << endl;
        break;
    default:
        s << "    Type " << d.type << " not implemented" << endl;
        break;
    }

    s << "    count : " << d.count << endl;

    if (!d.max.empty()) {
        s << "    max : ";
        for (auto &m : d.max)
            s << m << " ";
        s << endl;
    }

    if (!d.min.empty()) {
        s << "    min : ";
        for (auto &m : d.min)
            s << m << " ";
        s << endl;
    }

    s << "  }" << endl;
    return s;
}

uint32_t getGlTypeSize(GLenum dataType) {
    GLuint typeSize;

    switch (dataType) {
    case GL_BYTE:
        typeSize = sizeof(GLbyte);
        break;
    case GL_UNSIGNED_BYTE:
        typeSize = sizeof(GLubyte);
        break;
    case GL_SHORT:
        typeSize = sizeof(GLshort);
        break;
    case GL_UNSIGNED_SHORT:
        typeSize = sizeof(GLushort);
        break;
    case GL_INT:
        typeSize = sizeof(GLint);
        break;
    case GL_UNSIGNED_INT:
        typeSize = sizeof(GLuint);
        break;
    case GL_FLOAT:
        typeSize = sizeof(GLfloat);
        break;
    default:
        throw Exception("incorrect Type of data");
    }

    return typeSize;
}

uint32_t Accessor::getSize() const {
    return getGlTypeSize(componentType) * type * count;
}
} // namespace Blob::glTF2
