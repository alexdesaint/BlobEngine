#include <Blob/Maths.inl>
#ifdef _WIN32
#include <intrin.h>
#else
#include <x86intrin.h>
#endif
#define GLM_FORCE_INLINE
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iomanip>
#include <iostream>
#include <nmmintrin.h>
#include <vector>
#include <xmmintrin.h>

using namespace Blob::Maths;

class Mat4SSE {
private:
    // __m256 a1 = {1, 0, 0, 0, 0, 1, 0, 0};
    // __m256 a2 = {0, 0, 1, 0, 0, 0, 0, 1};

    float a11 = 1, a12 = 0, a13 = 0, a14 = 0;
    float a21 = 0, a22 = 1, a23 = 0, a24 = 0;
    float a31 = 0, a32 = 0, a33 = 1, a34 = 0;
    float a41 = 0, a42 = 0, a43 = 0, a44 = 1;

public:
    Mat4SSE() = default;

    Mat4SSE(const Vec4<float> &a1, const Vec4<float> &a2, const Vec4<float> &a3, const Vec4<float> &a4)
        : a11(a1.x)
        , a12(a1.y)
        , a13(a1.z)
        , a14(a1.w)
        , a21(a2.x)
        , a22(a2.y)
        , a23(a2.z)
        , a24(a2.w)
        , a31(a3.x)
        , a32(a3.y)
        , a33(a3.z)
        , a34(a3.w)
        , a41(a4.x)
        , a42(a4.y)
        , a43(a4.z)
        , a44(a4.w) {}

    Mat4SSE(const __m128 &a1, const __m128 &a2, const __m128 &a3, const __m128 &a4) {
        _mm_storeu_ps(&a11, a1);
        _mm_storeu_ps(&a21, a2);
        _mm_storeu_ps(&a31, a3);
        _mm_storeu_ps(&a41, a4);
    }

    Mat4SSE(float a11, float a12, float a13, float a14, float a21, float a22, float a23, float a24, float a31, float a32, float a33, float a34,
            float a41, float a42, float a43, float a44) noexcept
        : a11(a11)
        , a12(a12)
        , a13(a13)
        , a14(a14)
        , a21(a21)
        , a22(a22)
        , a23(a23)
        , a24(a24)
        , a31(a31)
        , a32(a32)
        , a33(a33)
        , a34(a34)
        , a41(a41)
        , a42(a42)
        , a43(a43)
        , a44(a44) {}

    Mat4SSE operator+(const Mat4SSE &v) const {
        Mat4SSE ret;
        __m256 A1 = _mm256_loadu_ps(&a11);
        __m256 A2 = _mm256_loadu_ps(&a31);
        __m256 B1 = _mm256_loadu_ps(&v.a11);
        __m256 B2 = _mm256_loadu_ps(&v.a31);

        A1 = _mm256_add_ps(A1, B1);
        A2 = _mm256_add_ps(A2, B2);

        _mm256_storeu_ps(&ret.a11, A1);
        _mm256_storeu_ps(&ret.a31, A2);

        return ret;
    }

    Mat4SSE operator-(const Mat4SSE &v) const {
        Mat4SSE ret;
        __m256 A1 = _mm256_loadu_ps(&a11);
        __m256 A2 = _mm256_loadu_ps(&a31);
        __m256 B1 = _mm256_loadu_ps(&v.a11);
        __m256 B2 = _mm256_loadu_ps(&v.a31);

        A1 = _mm256_sub_ps(A1, B1);
        A2 = _mm256_sub_ps(A2, B2);

        _mm256_storeu_ps(&ret.a11, A1);
        _mm256_storeu_ps(&ret.a31, A2);

        return ret;
    }

    Mat4SSE operator*(const Mat4SSE &v) const {
        _mm256_zeroupper();

        Mat4SSE ret;
        __m256 a1 = _mm256_loadu_ps(&a11);
        __m256 a2 = _mm256_loadu_ps(&a31);

        __m128 b1 = _mm_loadu_ps(&a11);
        __m128 b2 = _mm_loadu_ps(&a21);
        __m128 b3 = _mm_loadu_ps(&a31);
        __m128 b4 = _mm_loadu_ps(&a41);

        __m256 out01x;
        out01x = _mm256_mul_ps(_mm256_shuffle_ps(a1, a1, 0x00), _mm256_broadcast_ps(&b1));
        out01x = _mm256_add_ps(out01x, _mm256_mul_ps(_mm256_shuffle_ps(a1, a1, 0x55), _mm256_broadcast_ps(&b2)));
        out01x = _mm256_add_ps(out01x, _mm256_mul_ps(_mm256_shuffle_ps(a1, a1, 0xaa), _mm256_broadcast_ps(&b3)));
        out01x = _mm256_add_ps(out01x, _mm256_mul_ps(_mm256_shuffle_ps(a1, a1, 0xff), _mm256_broadcast_ps(&b4)));

        __m256 out23x;
        out23x = _mm256_mul_ps(_mm256_shuffle_ps(a2, a2, 0x00), _mm256_broadcast_ps(&b1));
        out23x = _mm256_add_ps(out23x, _mm256_mul_ps(_mm256_shuffle_ps(a2, a2, 0x55), _mm256_broadcast_ps(&b2)));
        out23x = _mm256_add_ps(out23x, _mm256_mul_ps(_mm256_shuffle_ps(a2, a2, 0xaa), _mm256_broadcast_ps(&b3)));
        out23x = _mm256_add_ps(out23x, _mm256_mul_ps(_mm256_shuffle_ps(a2, a2, 0xff), _mm256_broadcast_ps(&b4)));

        _mm256_storeu_ps(&ret.a11, out01x);
        _mm256_storeu_ps(&ret.a31, out23x);

        return ret;
    }

    Mat4SSE operator*(float val) const {
        Mat4SSE ret;
        __m256 A1 = _mm256_loadu_ps(&a11) * val;
        __m256 A2 = _mm256_loadu_ps(&a31) * val;

        _mm256_storeu_ps(&ret.a11, A1);
        _mm256_storeu_ps(&ret.a31, A2);

        return ret;
    }

    [[nodiscard]] Mat4SSE inverse() const {
        float Coef00 = (a33 * a44 - a43 * a34);
        float Coef02 = (a23 * a44 - a43 * a24);
        float Coef03 = (a23 * a34 - a33 * a24);

        float Coef04 = (a32 * a44 - a42 * a34);
        float Coef06 = (a22 * a44 - a42 * a24);
        float Coef07 = (a22 * a34 - a32 * a24);

        float Coef08 = (a32 * a43 - a42 * a33);
        float Coef10 = (a22 * a43 - a42 * a23);
        float Coef11 = (a22 * a33 - a32 * a23);

        float Coef12 = (a31 * a44 - a41 * a34);
        float Coef14 = (a21 * a44 - a41 * a24);
        float Coef15 = (a21 * a34 - a31 * a24);

        float Coef16 = (a31 * a43 - a41 * a33);
        float Coef18 = (a21 * a43 - a41 * a23);
        float Coef19 = (a21 * a33 - a31 * a23);

        float Coef20 = (a31 * a42 - a41 * a32);
        float Coef22 = (a21 * a42 - a41 * a22);
        float Coef23 = (a21 * a32 - a31 * a22);

        __m128 Fac0 = {Coef00, Coef00, Coef02, Coef03};
        __m128 Fac1 = {Coef04, Coef04, Coef06, Coef07};
        __m128 Fac2 = {Coef08, Coef08, Coef10, Coef11};
        __m128 Fac3 = {Coef12, Coef12, Coef14, Coef15};
        __m128 Fac4 = {Coef16, Coef16, Coef18, Coef19};
        __m128 Fac5 = {Coef20, Coef20, Coef22, Coef23};

        __m128 vec0 = {a21, a11, a11, a11};
        __m128 vec1 = {a22, a12, a12, a12};
        __m128 vec2 = {a23, a13, a13, a13};
        __m128 vec3 = {a24, a14, a14, a14};

        __m128 Inv0(vec1 * Fac0 - vec2 * Fac1 + vec3 * Fac2);
        __m128 Inv1(vec0 * Fac0 - vec2 * Fac3 + vec3 * Fac4);
        __m128 Inv2(vec0 * Fac1 - vec1 * Fac3 + vec3 * Fac5);
        __m128 Inv3(vec0 * Fac2 - vec1 * Fac4 + vec2 * Fac5);

        __m128 SignA = {+1, -1, +1, -1};
        __m128 SignB = {-1, +1, -1, +1};
        Mat4SSE Inverse(Inv0 * SignA, Inv1 * SignB, Inv2 * SignA, Inv3 * SignB);

        __m128 Row0{Inverse.a11, Inverse.a21, Inverse.a31, Inverse.a41};

        float Dot1 = (_mm_dp_ps((__m128{a11, a21, a31, a41}), Row0, 0xFF))[0];

        float OneOverDeterminant = 1.f / Dot1;

        return Inverse * OneOverDeterminant;
    }

    operator Mat4() {
        return {
            a11, a12, a13, a14, a21, a22, a23, a24, a31, a32, a33, a34, a41, a42, a43, a44,
        };
    }

    friend std::ostream &operator<<(std::ostream &os, const Mat4SSE &m) {
        os << m.a11 << ", " << m.a12 << ", " << m.a13 << ", " << m.a14 << std::endl;
        os << m.a21 << ", " << m.a22 << ", " << m.a23 << ", " << m.a24 << std::endl;
        os << m.a31 << ", " << m.a32 << ", " << m.a33 << ", " << m.a34 << std::endl;
        os << m.a41 << ", " << m.a42 << ", " << m.a43 << ", " << m.a44 << std::endl;
        return os;
    }
    /*
        Mat4SSE(float a11, float a12, float a13, float a14, float a21, float a22, float a23, float a24, float a31, float a32, float a33, float a34,
                float a41, float a42, float a43, float a44) noexcept
            : a1{a11, a12, a13, a14, a21, a22, a23, a24}, a2{a31, a32, a33, a34, a41, a42, a43, a44} {}

        // Mat4SSE(const __m128 &a1, const __m128 &a2, const __m128 &a3, const __m128 &a4) : a1(a1), a2(a2), a3(a3), a4(a4) {}

        Mat4SSE(const __m256 &a1, const __m256 &a2) : a1(a1), a2(a2) {}


        Mat4SSE operator-(const Mat4SSE &v) const { return {_mm256_sub_ps(a1, v.a1), _mm256_sub_ps(a2, v.a2)}; }


        explicit operator Mat4() {
            return {a1[0], a1[1], a1[2], a1[3], a1[4], a1[5], a1[6], a1[7], a2[0], a2[1], a2[2], a2[3], a2[4], a2[5], a2[6], a2[7]};
        }

        friend std::ostream &operator<<(std::ostream &os, const Mat4SSE &dt) {
            os << dt.a1[0] << ", " << dt.a1[1] << ", " << dt.a1[2] << ", " << dt.a1[3] << std::endl;
            os << dt.a1[4] << ", " << dt.a1[5] << ", " << dt.a1[6] << ", " << dt.a1[7] << std::endl;
            os << dt.a2[0] << ", " << dt.a2[1] << ", " << dt.a2[2] << ", " << dt.a2[3] << std::endl;
            os << dt.a2[4] << ", " << dt.a2[5] << ", " << dt.a2[6] << ", " << dt.a2[7] << std::endl;

            os << dt.a1[0] << ", " << dt.a1[1] << ", " << dt.a1[2] << ", " << dt.a1[3] << std::endl;
            os << dt.a2[0] << ", " << dt.a2[1] << ", " << dt.a2[2] << ", " << dt.a2[3] << std::endl;
            os << dt.a3[0] << ", " << dt.a3[1] << ", " << dt.a3[2] << ", " << dt.a3[3] << std::endl;
            os << dt.a4[0] << ", " << dt.a4[1] << ", " << dt.a4[2] << ", " << dt.a4[3] << std::endl;

            return os;
        }
        */
};

class Vec4SSE {
private:
    float x = 0, y = 0, z = 0, w = 0;

public:
    Vec4SSE() = default;

    Vec4SSE(float x, float y, float z, float w = 1.f)
        : x(x)
        , y(y)
        , z(z)
        , w(w) {}

    explicit Vec4SSE(float xyzw)
        : x(xyzw)
        , y(xyzw)
        , z(xyzw)
        , w(xyzw) {}

    Vec4SSE operator+(const Vec4SSE &v) const {
        __m128 a = _mm_loadu_ps(&x);
        __m128 b = _mm_loadu_ps(&v.x);
        a = _mm_add_ps(a, b);
        Vec4SSE ret;
        _mm_storeu_ps(&ret.x, a);
        return ret;
    }

    Vec4SSE operator-(const Vec4SSE &v) const {
        __m128 a = _mm_loadu_ps(&x);
        __m128 b = _mm_loadu_ps(&v.x);
        a = _mm_sub_ps(a, b);
        Vec4SSE ret;
        _mm_storeu_ps(&ret.x, a);
        return ret;
    }

    float dot(const Vec4SSE &v) const {
        __m128 a = _mm_loadu_ps(&x);
        __m128 b = _mm_loadu_ps(&v.x);
        a = _mm_dp_ps(a, b, 0xFF);
        return a[0];
    }

    [[nodiscard]] Vec4SSE normalize() const {
        __m128 data = _mm_loadu_ps(&x);
        __m128 temp = _mm_dp_ps(data, data, 0xFF);
        temp = _mm_rsqrt_ps(temp);
        data = _mm_mul_ps(data, temp);
        Vec4SSE ret;
        _mm_storeu_ps(&ret.x, data);
        return ret;
    }

    explicit operator Vec4<float>() const { return {x, y, z, w}; }

    // Print operator
    friend std::ostream &operator<<(std::ostream &os, const Vec4SSE &dt) {
        os << dt.x << ", " << dt.y << ", " << dt.z << ", " << dt.w;
        return os;
    }
};

class Vec4SSEE {
private:
    __m128 data;

public:
    Vec4SSEE() = default;

    Vec4SSEE(float x, float y, float z, float w = 1.f)
        : data{x, y, z, w} {}

    explicit Vec4SSEE(float xyzw)
        : data{xyzw, xyzw, xyzw, xyzw} {}

    explicit Vec4SSEE(__m128 data)
        : data(data) {}

    Vec4SSEE operator+(const Vec4SSEE &v) const { return Vec4SSEE(_mm_add_ps(data, v.data)); }

    Vec4SSEE operator-(const Vec4SSEE &v) const { return Vec4SSEE(_mm_sub_ps(data, v.data)); }

    float dot(const Vec4SSEE &v) const { return (_mm_dp_ps(data, data, 0xFF))[0]; }

    [[nodiscard]] Vec4SSEE normalize() const {
        __m128 temp = _mm_dp_ps(data, data, 0xFF);
        temp = _mm_rsqrt_ps(temp);
        return Vec4SSEE(_mm_mul_ps(data, temp));
    }

    explicit operator Vec4<float>() const { return {data[0], data[1], data[2], data[3]}; }

    // Print operator
    friend std::ostream &operator<<(std::ostream &os, const Vec4SSEE &dt) {
        os << dt.data[0] << ", " << dt.data[1] << ", " << dt.data[2] << ", " << dt.data[3];
        return os;
    }
};

class Vec3SSE {
private:
    float x = 0, y = 0, z = 0, _w;

public:
    Vec3SSE() = default;

    explicit Vec3SSE(float xyz)
        : x(xyz)
        , y(xyz)
        , z(xyz) {}

    Vec3SSE(float x, float y, float z = 0)
        : x(x)
        , y(y)
        , z(z) {}

    Vec3SSE(const Vec3SSE &v)
        : x(v.x)
        , y(v.y)
        , z(v.z) {}

    Vec3SSE operator+(const Vec3SSE &v) const {
        __m128 a = _mm_loadu_ps(&x);
        __m128 b = _mm_loadu_ps(&v.x);
        a = _mm_add_ps(a, b);
        Vec3SSE ret;
        _mm_storeu_ps(&ret.x, a);
        return ret;
    }

    Vec3SSE operator-(const Vec3SSE &v) const {
        __m128 a = _mm_loadu_ps(&x);
        __m128 b = _mm_loadu_ps(&v.x);
        a = _mm_sub_ps(a, b);
        Vec3SSE ret;
        _mm_storeu_ps(&ret.x, a);
        return ret;
    }

    float dot(const Vec3SSE &v) const {
        __m128 a = _mm_loadu_ps(&x);
        __m128 b = _mm_loadu_ps(&v.x);
        a = _mm_dp_ps(a, b, 0xFF);
        return a[0];
    }

    [[nodiscard]] Vec3SSE normalize() const {
        __m128 data = _mm_loadu_ps(&x);
        __m128 temp = _mm_dp_ps(data, data, 0x7F);
        temp = _mm_rsqrt_ps(temp);
        data = _mm_mul_ps(data, temp);
        Vec3SSE ret;
        _mm_storeu_ps(&ret.x, data);
        return ret;
    }

    Vec3SSE cross(const Vec3SSE &v) const {
        __m128 data = _mm_loadu_ps(&x);
        __m128 vdata = _mm_loadu_ps(&v.x);
        __m128 result = _mm_sub_ps(_mm_mul_ps(vdata, _mm_shuffle_ps(data, data, _MM_SHUFFLE(3, 0, 2, 1))),
                                   _mm_mul_ps(data, _mm_shuffle_ps(vdata, vdata, _MM_SHUFFLE(3, 0, 2, 1))));
        result = _mm_shuffle_ps(result, result, _MM_SHUFFLE(3, 0, 2, 1));

        Vec3SSE ret;
        _mm_storeu_ps(&ret.x, result);
        return ret;
    }

    explicit operator Vec3<float>() const { return {x, y, z}; }

    // Print operator
    friend std::ostream &operator<<(std::ostream &os, const Vec3SSE &dt) {
        os << dt.z << ", " << dt.y << ", " << dt.z;
        return os;
    }
};

class Vec3SSEE {
private:
    __m128 data = {0, 0, 0, 1};

public:
    Vec3SSEE() = default;

    Vec3SSEE(float x, float y, float z)
        : data{x, y, z, 1.f} {}

    explicit Vec3SSEE(float xyz)
        : data{xyz, xyz, xyz, 1.f} {}

    explicit Vec3SSEE(__m128 data)
        : data(data) {}

    Vec3SSEE operator+(const Vec3SSEE &v) const { return Vec3SSEE(_mm_add_ps(data, v.data)); }

    Vec3SSEE operator-(const Vec3SSEE &v) const { return Vec3SSEE(_mm_sub_ps(data, v.data)); }

    float dot(const Vec3SSEE &v) const { return (_mm_dp_ps(data, data, 0x7F))[0]; }

    [[nodiscard]] Vec3SSEE normalize() const {
        __m128 temp = _mm_dp_ps(data, data, 0x7F);
        temp = _mm_rsqrt_ps(temp);
        return Vec3SSEE(_mm_mul_ps(data, temp));
    }

    Vec3SSEE cross(const Vec3SSEE &v) const {
        __m128 result = _mm_sub_ps(_mm_mul_ps(v.data, _mm_shuffle_ps(data, data, _MM_SHUFFLE(3, 0, 2, 1))),
                                   _mm_mul_ps(data, _mm_shuffle_ps(v.data, v.data, _MM_SHUFFLE(3, 0, 2, 1))));
        return Vec3SSEE(_mm_shuffle_ps(result, result, _MM_SHUFFLE(3, 0, 2, 1)));
    }

    explicit operator Vec3<float>() { return {data[0], data[1], data[2]}; }

    // Print operator
    friend std::ostream &operator<<(std::ostream &os, const Vec3SSEE &dt) {
        os << dt.data[0] << ", " << dt.data[1] << ", " << dt.data[2] << ", " << dt.data[3];
        return os;
    }
};

std::ostream &operator<<(std::ostream &os, const glm::vec3 &dt) {
    os << dt.x << ", " << dt.y << ", " << dt.z;
    return os;
}

std::ostream &operator<<(std::ostream &os, const glm::vec2 &dt) {
    os << dt.x << ", " << dt.y;
    return os;
}

std::ostream &operator<<(std::ostream &os, const glm::vec4 &dt) {
    os << dt.x << ", " << dt.y << ", " << dt.z << ", " << dt.w;
    return os;
}

std::ostream &operator<<(std::ostream &os, const glm::mat4 &gm) {
    os << gm[0][0] << ", " << gm[1][0] << ", " << gm[2][0] << ", " << gm[3][0] << std::endl;
    os << gm[0][1] << ", " << gm[1][1] << ", " << gm[2][1] << ", " << gm[3][1] << std::endl;
    os << gm[0][2] << ", " << gm[1][2] << ", " << gm[2][2] << ", " << gm[3][2] << std::endl;
    os << gm[0][3] << ", " << gm[1][3] << ", " << gm[2][3] << ", " << gm[3][3] << std::endl;
    return os;
}

bool eq(float v, float u) {
    return u == v || (v < u + 0.001f && v > u - 0.001f);
}

bool eq(const Vec2<float> &v, const glm::vec2 &u) {
    if (eq(v.x, u.x) && eq(v.y, u.y))
        return true;
    std::cout << std::setprecision(15) << "Blob::{" << v << "} \n glm::{" << u << "}" << std::endl;
    return false;
}

bool eq(const Vec3<float> &v, const glm::vec3 &u) {
    if (eq(v.x, u.x) && eq(v.y, u.y) && eq(v.z, u.z))
        return true;
    std::cout << std::setprecision(15) << "Blob::{" << v << "} \n glm::{" << u << "}" << std::endl;
    return false;
}

bool eq(const Vec4<float> &v, const glm::vec4 &u) {
    if (eq(v.x, u.x) && eq(v.y, u.y) && eq(v.z, u.z) && eq(v.w, u.w))
        return true;
    std::cout << std::setprecision(10) << "Blob::{" << v << "} \n glm::{" << u << "}" << std::endl;
    return false;
}

bool eq(const Mat3 &v, const glm::mat3 &u) {
    if (eq(v.a11, u[0][0]) && eq(v.a12, u[0][1]) && eq(v.a13, u[0][2]) && eq(v.a21, u[1][0]) && eq(v.a22, u[1][1]) && eq(v.a23, u[1][2]) &&
        eq(v.a31, u[2][0]) && eq(v.a32, u[2][1]) && eq(v.a33, u[2][2]))
        return true;
    std::cout << std::setprecision(15) << "Blob:" << std::endl << v << "!=" << std::endl << "glm:" << std::endl << u << std::endl;
    return false;
}

bool eq(const Mat4 &v, const glm::mat4 &u) {
    if (eq(v.a11, u[0][0]) && eq(v.a12, u[0][1]) && eq(v.a13, u[0][2]) && eq(v.a14, u[0][3]) && eq(v.a21, u[1][0]) && eq(v.a22, u[1][1]) &&
        eq(v.a23, u[1][2]) && eq(v.a24, u[1][3]) && eq(v.a31, u[2][0]) && eq(v.a32, u[2][1]) && eq(v.a33, u[2][2]) && eq(v.a34, u[2][3]) &&
        eq(v.a41, u[3][0]) && eq(v.a42, u[3][1]) && eq(v.a43, u[3][2]) && eq(v.a44, u[3][3]))
        return true;
    std::cout << std::setprecision(15) << "Blob:" << std::endl << v << "!=" << std::endl << "glm:" << std::endl << u << std::endl;
    return false;
}

#define TEST                                                                                                                                         \
    template<typename T, const unsigned int N>                                                                                                       \
    std::vector<T> TEST_NAME(const T &init, FN) {                                                                                                    \
        std::vector<T> data(N / sizeof(T));                                                                                                          \
                                                                                                                                                     \
        for (T & t : data)                                                                                                                           \
            t = init;                                                                                                                                \
                                                                                                                                                     \
        auto t1 = __rdtsc();                                                                                                                         \
        for (T & t : data)                                                                                                                           \
            ASSIGN;                                                                                                                                  \
        auto t2 = __rdtsc();                                                                                                                         \
                                                                                                                                                     \
        std::cout << std::setw(10) << std::setprecision(4) << (t2 - t1) / ((float) data.size()) << " |";                                             \
                                                                                                                                                     \
        return data;                                                                                                                                 \
        for (T & t : data)                                                                                                                           \
            std::cout << t << std::endl;                                                                                                             \
    }

#define TEST_NAME test2op

#define FN T(fn)(const T &, const T &)
#define ASSIGN t = fn(t, t)
TEST
#undef FN
#undef ASSIGN

#define FN T (T::*fn)(const T &) const
#define ASSIGN t = ((t).*(fn))(t)
    TEST
#undef FN
#undef ASSIGN

#define FN float (T::*fn)(const T &) const
#define ASSIGN t = T(((t).*(fn))(t))
        TEST
#undef FN
#undef ASSIGN

#define FN float(fn)(const T &, const T &)
#define ASSIGN t = T(fn(t, t))
            TEST
#undef FN
#undef ASSIGN

#undef TEST_NAME
#define TEST_NAME test1op

#define FN T(fn)(const T &)
#define ASSIGN t = fn(t)
                TEST
#undef FN
#undef ASSIGN

#define FN T (T::*fn)() const
#define ASSIGN t = ((t).*(fn))()
                    TEST
#undef FN
#undef ASSIGN

#define FN float (T::*fn)() const
#define ASSIGN t = T(((t).*(fn))())
                        TEST
#undef FN
#undef ASSIGN

#define FN float(fn)(const T &)
#define ASSIGN t = T(fn(t))
                            TEST
#undef FN
#undef ASSIGN

#undef TEST_NAME

#define TEST_VEC2                                                                                                                                    \
    {                                                                                                                                                \
        std::cout << "|";                                                                                                                            \
        std::cout << std::setw(13) << NAME " |";                                                                                                     \
        auto dglm = TESTFUNC<glm::vec2, N>(INIT, &glm::FUNC);                                                                                        \
        auto d2 = TESTFUNC<Vec2<float>, N>(INIT, &Vec2<float>::FUNC);                                                                                \
        std::cout << "           |";                                                                                                                 \
        std::cout << "           |";                                                                                                                 \
        std::cout << std::endl;                                                                                                                      \
        for (unsigned int i = 0; i < dglm.size(); i++) {                                                                                             \
            if (!eq(d2[i], dglm[i])) {                                                                                                               \
                std::cout << "ERROR ON Vec2<float>" << std::endl;                                                                                    \
                break;                                                                                                                               \
            }                                                                                                                                        \
        }                                                                                                                                            \
    }

#define TEST_VEC3                                                                                                                                    \
    {                                                                                                                                                \
        std::cout << "|";                                                                                                                            \
        std::cout << std::setw(13) << NAME " |";                                                                                                     \
        auto dglm = TESTFUNC<glm::vec3, N>(INIT, &glm::FUNC);                                                                                        \
        auto d2 = TESTFUNC<Vec3<float>, N>(INIT, &Vec3<float>::FUNC);                                                                                \
        auto d1 = TESTFUNC<Vec3SSE, N>(INIT, &Vec3SSE::FUNC);                                                                                        \
        auto d3 = TESTFUNC<Vec3SSEE, N>(INIT, &Vec3SSEE::FUNC);                                                                                      \
        std::cout << std::endl;                                                                                                                      \
        for (unsigned int i = 0; i < d1.size(); i++) {                                                                                               \
            if (!eq((Vec3<float>) d1[i], dglm[i])) {                                                                                                 \
                std::cout << "ERROR ON VEC3SSE " << i << std::endl;                                                                                  \
                break;                                                                                                                               \
            } else if (!eq(d2[i], dglm[i])) {                                                                                                        \
                std::cout << "ERROR ON Vec3<float>" << std::endl;                                                                                    \
                break;                                                                                                                               \
            }                                                                                                                                        \
        }                                                                                                                                            \
    }

#define TEST_VEC4                                                                                                                                    \
    {                                                                                                                                                \
        std::cout << "|";                                                                                                                            \
        std::cout << std::setw(13) << NAME " |";                                                                                                     \
        auto dglm = TESTFUNC<glm::vec4, N>(INIT, &glm::FUNC);                                                                                        \
        auto d2 = TESTFUNC<Vec4<float>, N>(INIT, &Vec4<float>::FUNC);                                                                                \
        auto d1 = TESTFUNC<Vec4SSE, N>(INIT, &Vec4SSE::FUNC);                                                                                        \
        auto d3 = TESTFUNC<Vec4SSEE, N>(INIT, &Vec4SSEE::FUNC);                                                                                      \
        std::cout << std::endl;                                                                                                                      \
        for (unsigned int i = 0; i < dglm.size(); i++) {                                                                                             \
            if (!eq((Vec4<float>) d1[i], dglm[i])) {                                                                                                 \
                std::cout << "ERROR ON VEC4SSE " << i << std::endl;                                                                                  \
                break;                                                                                                                               \
            } else if (!eq(d2[i], dglm[i])) {                                                                                                        \
                std::cout << "ERROR ON Vec4<float>" << std::endl;                                                                                    \
                break;                                                                                                                               \
            }                                                                                                                                        \
        }                                                                                                                                            \
    }

#define TEST_MAT3                                                                                                                                    \
    {                                                                                                                                                \
        std::cout << "|";                                                                                                                            \
        std::cout << std::setw(13) << NAME " |";                                                                                                     \
        auto dglm = TESTFUNC<glm::mat3, N>(INIT, &glm::FUNC);                                                                                        \
        auto d2 = TESTFUNC<Mat3, N>(INIT, &Mat3::FUNC);                                                                                              \
        std::cout << "           |";                                                                                                                 \
        std::cout << "           |";                                                                                                                 \
        std::cout << std::endl;                                                                                                                      \
        for (unsigned int i = 0; i < dglm.size(); i++) {                                                                                             \
            if (!eq(d2[i], dglm[i])) {                                                                                                               \
                std::cout << "ERROR ON Mat3" << std::endl;                                                                                           \
                break;                                                                                                                               \
            }                                                                                                                                        \
        }                                                                                                                                            \
    }

#define TEST_MAT4                                                                                                                                    \
    {                                                                                                                                                \
        std::cout << "|";                                                                                                                            \
        std::cout << std::setw(13) << NAME " |";                                                                                                     \
        auto dglm = TESTFUNC<glm::mat4, N>(INIT, &glm::FUNC);                                                                                        \
        auto d2 = TESTFUNC<Mat4, N>(INIT, &Mat4::FUNC);                                                                                              \
        auto d1 = TESTFUNC<Mat4SSE, N>(INIT, &Mat4SSE::FUNC);                                                                                        \
        std::cout << "           |";                                                                                                                 \
        std::cout << std::endl;                                                                                                                      \
        for (unsigned int i = 0; i < dglm.size(); i++) {                                                                                             \
            if (!eq(d2[i], dglm[i])) {                                                                                                               \
                std::cout << "ERROR ON Mat4" << std::endl;                                                                                           \
                break;                                                                                                                               \
            } else if (!eq((Mat4) d1[i], dglm[i])) {                                                                                                 \
                std::cout << "ERROR ON MAT4SSE " << i << std::endl;                                                                                  \
                break;                                                                                                                               \
            }                                                                                                                                        \
        }                                                                                                                                            \
    }

    int
    main() {
    static const unsigned int N = 2304 * 500;

    std::cout << "|------------|-----------|-----------|-----------|-----------|" << std::endl;
    std::cout << "|  function  |    glm    |    Blob   |  Blob SSE | Blob SSEE |" << std::endl;
    std::cout << "|------------|-----------|-----------|-----------|-----------|" << std::endl;
    std::cout << "|";
    std::cout << std::setw(13) << "Vec2 |";
    std::cout << std::setw(10) << sizeof(glm::vec2) << " |";
    std::cout << std::setw(10) << sizeof(Vec2<float>) << " |";
    std::cout << "           |           |" << std::endl;
    std::cout << "|------------|-----------|-----------|-----------|-----------|" << std::endl;

#define INIT                                                                                                                                         \
    { 1, 2 }
#define TESTFUNC test2op

#define FUNC operator+
#define NAME "+"
    TEST_VEC2
#undef FUNC
#undef NAME

#define FUNC operator-
#define NAME "-"
    TEST_VEC2
#undef NAME
#undef FUNC

#define FUNC dot
#define NAME "dot"
    TEST_VEC2
#undef NAME
#undef FUNC

#undef TESTFUNC
#define TESTFUNC test1op

#define FUNC normalize
#define NAME "normalize"
    TEST_VEC2
#undef NAME
#undef FUNC

#define FUNC length
#define NAME "length"
    TEST_VEC2
#undef FUNC
#undef NAME

#undef TESTFUNC
#undef INIT

    std::cout << "|------------|-----------|-----------|-----------|-----------|" << std::endl;
    std::cout << "|";
    std::cout << std::setw(13) << "Vec3 |";
    std::cout << std::setw(10) << sizeof(glm::vec3) << " |";
    std::cout << std::setw(10) << sizeof(Vec3<float>) << " |";
    std::cout << std::setw(10) << sizeof(Vec3SSE) << " |";
    std::cout << std::setw(10) << sizeof(Vec3SSEE) << " |" << std::endl;
    std::cout << "|------------|-----------|-----------|-----------|-----------|" << std::endl;

#define FUNC operator+
#define INIT                                                                                                                                         \
    { 1, 2, 3 }
#define NAME "+"
#define TESTFUNC test2op
    TEST_VEC3
#undef TESTFUNC
#undef FUNC
#undef INIT
#undef NAME

#define FUNC operator-
#define INIT                                                                                                                                         \
    { 1, 2, 3 }
#define NAME "-"
#define TESTFUNC test2op
    TEST_VEC3
#undef TESTFUNC
#undef FUNC
#undef INIT
#undef NAME

#define FUNC cross
#define INIT                                                                                                                                         \
    { 1, 2, 3 }
#define NAME "cross"
#define TESTFUNC test2op
    TEST_VEC3
#undef TESTFUNC
#undef FUNC
#undef INIT
#undef NAME

#define FUNC dot
#define INIT                                                                                                                                         \
    { 1, 2, 3 }
#define NAME "dot"
#define TESTFUNC test2op
    TEST_VEC3
#undef TESTFUNC
#undef FUNC
#undef INIT
#undef NAME

#define FUNC normalize
#define INIT                                                                                                                                         \
    { 1, 2, 3 }
#define NAME "normalize"
#define TESTFUNC test1op
    TEST_VEC3
#undef TESTFUNC
#undef FUNC
#undef INIT
#undef NAME

    std::cout << "|------------|-----------|-----------|-----------|-----------|" << std::endl;
    std::cout << "|";
    std::cout << std::setw(13) << "Vec4 |";
    std::cout << std::setw(10) << sizeof(glm::vec4) << " |";
    std::cout << std::setw(10) << sizeof(Vec4<float>) << " |";
    std::cout << std::setw(10) << sizeof(Vec4SSE) << " |";
    std::cout << std::setw(10) << sizeof(Vec4SSEE) << " |" << std::endl;
    std::cout << "|------------|-----------|-----------|-----------|-----------|" << std::endl;

#define INIT                                                                                                                                         \
    { 1, 2, 3, 4 }

#define FUNC operator+
#define NAME "+"
#define TESTFUNC test2op
    TEST_VEC4
#undef TESTFUNC
#undef FUNC
#undef INIT
#undef NAME

#define FUNC operator-
#define INIT                                                                                                                                         \
    { 1, 2, 3, 4 }
#define NAME "-"
#define TESTFUNC test2op
    TEST_VEC4
#undef TESTFUNC
#undef FUNC
#undef INIT
#undef NAME

#define FUNC dot
#define INIT                                                                                                                                         \
    { 1, 2, 3, 4 }
#define NAME "dot"
#define TESTFUNC test2op
    TEST_VEC4
#undef TESTFUNC
#undef FUNC
#undef INIT
#undef NAME

#define FUNC normalize
#define INIT                                                                                                                                         \
    { 1, 2, 3, 4 }
#define NAME "normalize"
#define TESTFUNC test1op
    TEST_VEC4
#undef TESTFUNC
#undef FUNC
#undef INIT
#undef NAME

    std::cout << "|------------|-----------|-----------|-----------|-----------|" << std::endl;
    std::cout << "|";
    std::cout << std::setw(13) << "Mat3 |";
    std::cout << std::setw(10) << sizeof(glm::mat3) << " |";
    std::cout << std::setw(10) << sizeof(Mat3) << " |";
    std::cout << "           |           |" << std::endl;
    // std::cout << std::setw(10) << sizeof(Mat3SSE) << " |";
    // std::cout << std::setw(10) << sizeof(Mat3SSEE) << " |" << std::endl;
    std::cout << "|------------|-----------|-----------|-----------|-----------|" << std::endl;

#define INIT                                                                                                                                         \
    { 1, 2, 3, 4, 5, 6, 7, 8, 9 }
#define TESTFUNC test2op

#define FUNC operator+
#define NAME "+"
    TEST_MAT3
#undef FUNC
#undef NAME

#define FUNC operator-
#define NAME "-"
    TEST_MAT3
#undef FUNC
#undef NAME

#define FUNC operator*
#define NAME "*"
    TEST_MAT3
#undef FUNC
#undef NAME

#undef TESTFUNC
#undef INIT

    std::cout << "|------------|-----------|-----------|-----------|-----------|" << std::endl;
    std::cout << "|";
    std::cout << std::setw(13) << "Mat4 |";
    std::cout << std::setw(10) << sizeof(glm::mat4) << " |";
    std::cout << std::setw(10) << sizeof(Mat4) << " |";
    std::cout << std::setw(10) << sizeof(Mat4SSE) << " |";
    std::cout << "           |" << std::endl;
    // std::cout << std::setw(10) << " |" << std::endl;
    std::cout << "|------------|-----------|-----------|-----------|-----------|" << std::endl;

#define INIT                                                                                                                                         \
    { 1, 2, 3, 4, 2, 1, 2, 3, 3, 2, 1, 2, 4, 3, 2, 1 }
#define TESTFUNC test2op

#define FUNC operator+
#define NAME "+"
    TEST_MAT4
#undef FUNC
#undef NAME

#define FUNC operator-
#define NAME "-"
    TEST_MAT4
#undef FUNC
#undef NAME

#define FUNC operator*
#define NAME "*"
    TEST_MAT4
#undef FUNC
#undef NAME

#undef TESTFUNC
#define TESTFUNC test1op

#define FUNC inverse
#define NAME "inverse"
    TEST_MAT4
#undef FUNC
#undef NAME

#undef TESTFUNC
#undef INIT

    std::cout << "|------------|-----------|-----------|-----------|-----------|" << std::endl;
    std::cout << "|";
    std::cout << std::setw(13) << "Model |";
    std::cout << std::setw(10) << sizeof(glm::mat4) << " |";
    std::cout << std::setw(10) << sizeof(ModelTransform) << " |";
    std::cout << "           |";
    std::cout << "           |" << std::endl;
    std::cout << "|------------|-----------|-----------|-----------|-----------|" << std::endl;
    {
        ModelTransform mt;
        glm::mat4 glmMt(1);
        eq(mt, glmMt);

        glmMt = glm::translate(glmMt, glm::vec3(4, 9, 2));
        glmMt = glm::rotate(glmMt, 8.f, glm::vec3(4, 9, 2));
        glmMt = glm::scale(glmMt, glm::vec3(4, 9, 2));
        mt.move({4, 9, 2});
        mt.rotate(8.f, {4, 9, 2});
        mt.rescale({4, 9, 2});
        eq(mt, glmMt);
    }
    {
        ModelTransform m;
        m.setPosition({15, 78, 1});
        eq(m, glm::translate(glm::mat4(1), {15, 78, 1}));
    }
    {
        ModelTransform m;
        m.setRotation(35.f, {15, 78, 1});
        eq(m, glm::rotate(glm::mat4(1), 35.f, {15, 78, 1}));
    }
    {
        ModelTransform m;
        m.setScale({15, 78, 1});
        eq(m, glm::scale(glm::mat4(1), {15, 78, 1}));
    }

    std::cout << "|------------|-----------|-----------|-----------|-----------|" << std::endl;
    std::cout << "|";
    std::cout << std::setw(13) << "View |";
    std::cout << std::setw(10) << sizeof(glm::mat4) << " |";
    std::cout << std::setw(10) << sizeof(ViewTransform) << " |";
    std::cout << "           |";
    std::cout << "           |" << std::endl;
    std::cout << "|------------|-----------|-----------|-----------|-----------|" << std::endl;

    {
        ViewTransform vt({15, 78, 1}, {4, 9, 2}, {0, 0, 1});
        glm::mat4 glmMt = glm::lookAt(glm::vec3(15, 78, 1), {4, 9, 2}, {0, 0, 1});
        eq(vt, glmMt);
    }

    std::cout << "|------------|-----------|-----------|-----------|-----------|" << std::endl;
    std::cout << "|";
    std::cout << std::setw(13) << "Projection |";
    std::cout << std::setw(10) << sizeof(glm::mat4) << " |";
    std::cout << std::setw(10) << sizeof(ProjectionTransform) << " |";
    std::cout << "           |";
    std::cout << "           |" << std::endl;
    std::cout << "|------------|-----------|-----------|-----------|-----------|" << std::endl;

    {
        ProjectionTransform pt(45.f, {400, 600}, 40.f, 100.F);
        glm::mat4 glmMt = glm::perspective(45.f, 400.f / 600.f, 40.f, 100.F);
        eq(pt, glmMt);
    }

    std::cout << "|------------|-----------|-----------|-----------|-----------|" << std::endl;

    return 0;
}