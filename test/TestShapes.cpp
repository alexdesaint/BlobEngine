#include <iostream>
#include <vector>
#include <Blob/Reader/FileReader.hpp>
#include <iomanip>

#include <glm/glm.hpp>

using namespace std;

template<typename T, int SIZE>
std::vector<array<T, SIZE>> readSerie(const vector<uint8_t> &buffer, const int count, int &offset) {
    union {
        T f;
        uint8_t b[sizeof(T)];
    } u;

    std::vector<array<T, SIZE>> data(count);

    int posIndex = 0;
    int localPosIndex = 0;
    for (int i = offset; i < (count * SIZE * sizeof(T) + offset); i += sizeof(T)) {
        for(int j = 0; j < sizeof(T); j++)
            u.b[j] = buffer[j + i];
        data[posIndex][localPosIndex] = u.f;
        localPosIndex++;
        if (localPosIndex == SIZE) {
            localPosIndex = 0;
            posIndex++;
        }
    }

    offset += count * SIZE * sizeof(T);

    return data;
}

std::ostream & operator<<(std::ostream &os, array<float, 2> p) {
    //os << "{" << std::setprecision(1) << std::fixed << p[0] << "f, " << p[1] << "f}";
    os << "{" << std::setprecision(2) << p[0] << ", " << p[1] << "}";
    return os;
}
std::ostream & operator<<(std::ostream &os, array<float, 3> p) {
    //os << "{" << std::setprecision(1) << std::fixed << p[0] << "f, " << p[1] << "f, " << p[2] << "f}";
    os << "{" << std::setprecision(2) << p[0] << ", " << p[1] << ", " << p[2] << "}";
    return os;
}
std::ostream & operator<<(std::ostream &os, array<float, 4> p) {
    //os << "{" << std::setprecision(1) << std::fixed << p[0] << "f, " << p[1] << "f, " << p[2] << "f, " << p[3] << "f}";
    //os << "{" << std::setprecision(1) << std::fixed << p[0] << "f, " << p[1] << "f, " << p[2] << "f}";
    os << "{" << std::setprecision(2) << p[0] << ", " << p[1] << ", " << p[2] << "}";
    return os;
}

void decode(const vector<uint8_t> &buffer, const int posNormalLen, const int indicesLen) {
    union {
        float f;
        uint8_t b[4];
    } u;

    int offset = 0;
    std::vector<array<float, 3>> pos = readSerie<float, 3>(buffer, posNormalLen, offset);
    std::vector<array<float, 3>> normal = readSerie<float, 3>(buffer, posNormalLen, offset);
    std::vector<array<float, 4>> tangent = readSerie<float, 4>(buffer, posNormalLen, offset);
    std::vector<array<float, 2>> textcoor = readSerie<float, 2>(buffer, posNormalLen, offset);
    std::vector<array<uint16_t, 1>> indices = readSerie<uint16_t, 1>(buffer, indicesLen, offset);

    for (int i = 0; i < posNormalLen; i++) {
        cout << "{" << pos[i] << ", " << normal[i] << ", " << tangent[i] << ", " << textcoor[i] << "}," << endl;
    }
    for (int i = 0; i < indicesLen; i++) {
        cout << indices[i][0] << ", ";
    }
    cout << endl;
}

void decodeNoT(const vector<uint8_t> &buffer, const int posNormalLen, const int indicesLen) {
    union {
        float f;
        uint8_t b[4];
    } u;

    int offset = 0;
    std::vector<array<float, 3>> pos = readSerie<float, 3>(buffer, posNormalLen, offset);
    std::vector<array<float, 3>> normal = readSerie<float, 3>(buffer, posNormalLen, offset);
    std::vector<array<float, 4>> tangent(posNormalLen);
    std::vector<array<float, 2>> textcoor = readSerie<float, 2>(buffer, posNormalLen, offset);
    std::vector<array<uint16_t, 1>> indices = readSerie<uint16_t, 1>(buffer, indicesLen, offset);

    for (int i = 0; i < posNormalLen; i++) {
        glm::vec3 tan, norm;
        norm.x = normal[i][0];
        norm.y = normal[i][1];
        norm.z = normal[i][2];

        glm::vec3 c1 = glm::cross(norm, glm::vec3(0.0, 0.0, 1.0));
        glm::vec3 c2 = glm::cross(norm, glm::vec3(0.0, 1.0, 0.0));

        if( glm::length(c1) > glm::length(c2) )
            tan = c1;
        else
            tan = c2;

        tan = glm::normalize(tan);

        tangent[i][0] = tan.x;
        tangent[i][1] = tan.y;
        tangent[i][2] = tan.z;

        cout << "{" << pos[i] << ", " << normal[i] << ", " << tangent[i] << ", " << textcoor[i] << "}," << endl;
    }
    for (int i = 0; i < indicesLen; i++) {
        cout << indices[i][0] << ", ";
    }
    cout << endl;
}

int main(){
    printf("Cube :\n");
    decode(Blob::Reader::FileReader::loadBinaryFile("data/models/cube.bin"), 24, 36);

    printf("Plane :\n");
    decode(Blob::Reader::FileReader::loadBinaryFile("data/models/plane.bin"), 4, 6);

    printf("OctagonalPrism :\n");
    decodeNoT(Blob::Reader::FileReader::loadBinaryFile("data/models/OctagonalPrism.bin"), 48, 84);

    return 0;
}
