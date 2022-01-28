#include <Blob/Maths.hpp>
#include <Blob/Shapes.hpp>
#include <Blob/Window.hpp>

using namespace std;
using namespace Blob;

/*template<typename T, int SIZE>
std::vector<array<T, SIZE>> readSerie(const vector<uint8_t> &buffer, const int
count, int &offset) { union { T f; uint8_t b[sizeof(T)]; } u;

    std::vector<array<T, SIZE>> data(count);

    int posIndex = 0;
    int localPosIndex = 0;
    for (int i = offset; i < (count * SIZE * sizeof(T) + offset); i +=
sizeof(T)) { for (int j = 0; j < sizeof(T); j++) u.b[j] = buffer[j + i];
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

std::ostream &operator<<(std::ostream &os, array<float, 2> p) {
    // os << "{" << std::setprecision(1) << std::fixed << p[0] << "f, " << p[1]
<< "f}"; os << "{" << std::setprecision(2) << p[0] << ", " << p[1] << "}";
    return os;
}
std::ostream &operator<<(std::ostream &os, array<float, 3> p) {
    // os << "{" << std::setprecision(1) << std::fixed << p[0] << "f, " << p[1]
<< "f, " << p[2] << "f}"; os << "{" << std::setprecision(2) << p[0] << ", " <<
p[1] << ", " << p[2] << "}"; return os;
}
std::ostream &operator<<(std::ostream &os, array<float, 4> p) {
    // os << "{" << std::setprecision(1) << std::fixed << p[0] << "f, " << p[1]
<< "f, " << p[2] << "f, " << p[3] << "f}";
    // os << "{" << std::setprecision(1) << std::fixed << p[0] << "f, " << p[1]
<< "f, " << p[2] << "f}"; os << "{" << std::setprecision(2) << p[0] << ", " <<
p[1] << ", " << p[2] << "}"; return os;
}

void decode(const vector<uint8_t> &buffer, const int posNormalLen, const int
indicesLen) {

    int offset = 0;
    std::vector<array<float, 3>> pos = readSerie<float, 3>(buffer, posNormalLen,
offset); std::vector<array<float, 3>> normal = readSerie<float, 3>(buffer,
posNormalLen, offset); std::vector<array<float, 4>> tangent = readSerie<float,
4>(buffer, posNormalLen, offset); std::vector<array<float, 2>> textcoor =
readSerie<float, 2>(buffer, posNormalLen, offset); std::vector<array<uint16_t,
1>> indices = readSerie<uint16_t, 1>(buffer, indicesLen, offset);

    for (int i = 0; i < posNormalLen; i++) {
        cout << "{" << pos[i] << ", " << normal[i] << ", " << tangent[i] << ", "
<< textcoor[i] << "}," << endl;
    }
    for (int i = 0; i < indicesLen; i++) {
        cout << indices[i][0] << ", ";
    }
    cout << endl;
}

void decodeNoT(const vector<uint8_t> &buffer, const int posNormalLen, const int
indicesLen) { union { float f; uint8_t b[4]; } u;

    int offset = 0;
    std::vector<array<float, 3>> pos = readSerie<float, 3>(buffer, posNormalLen,
offset); std::vector<array<float, 3>> normal = readSerie<float, 3>(buffer,
posNormalLen, offset); std::vector<array<float, 4>> tangent(posNormalLen);
    std::vector<array<float, 2>> textcoor = readSerie<float, 2>(buffer,
posNormalLen, offset); std::vector<array<uint16_t, 1>> indices =
readSerie<uint16_t, 1>(buffer, indicesLen, offset);

    for (int i = 0; i < posNormalLen; i++) {
        Blob::Vec3<float> tan, norm;
        norm.x = normal[i][0];
        norm.y = normal[i][1];
        norm.z = normal[i][2];

        Blob::Vec3 c1 = norm.cross({0.0, 0.0, 1.0});
        Blob::Vec3 c2 = norm.cross({0.0, 1.0, 0.0});

        if (c1.length2() > c2.length2())
            tan = c1;
        else
            tan = c2;

        tan.normalize();

        tangent[i][0] = tan.x;
        tangent[i][1] = tan.y;
        tangent[i][2] = tan.z;

        cout << "{" << pos[i] << ", " << normal[i] << ", " << tangent[i] << ", "
<< textcoor[i] << "}," << endl;
    }
    for (int i = 0; i < indicesLen; i++) {
        cout << indices[i][0] << ", ";
    }
    cout << endl;
}*/

class Test : private KeyboardEvents {
private:
    Vec2<> speed, anglePos;

    void keyboardUpdate(const Key &keyboard) final {
        static const float maxSpeed = 1;

        speed = Vec2<>();

        if (keyboard.id == GLFW::Keys::LEFT)
            speed.x = -maxSpeed;
        if (keyboard.id == GLFW::Keys::RIGHT)
            speed.x = maxSpeed;
        if (keyboard.id == GLFW::Keys::UP)
            speed.y = -maxSpeed;
        if (keyboard.id == GLFW::Keys::DOWN)
            speed.y = maxSpeed;
    }

public:
    Test() {
        try {
            Vec3<> pos{0, 0, 10};
            Materials::PBR::light.position = {10, 10, 10};

            Window window;

            Shapes::Cube cube;
            cube.setPosition({2, 0, 0});
            Shapes::Plane plane;
            Shapes::OctagonalPrism octagonalPrism;
            octagonalPrism.setPosition({-2, 0, 0});

            Scene scene{{&cube, &plane, &octagonalPrism}};

            window.projectionTransform.setRange(0.1, 100);

            float flow = 0;
            while (window.isOpen()) {
                anglePos += speed * flow;
                scene.camera.setPosition(Vec3<>(std::cos(anglePos.x),
                                                std::sin(anglePos.x),
                                                std::cos(anglePos.y)) *
                                         10);
                window.draw(scene);

                flow = window.display();
            }

        } catch (Exception &exception) {
            std::cout << exception.what() << std::endl;
        }
    }
};

int main() {
    Test test;

    return 0;
}
