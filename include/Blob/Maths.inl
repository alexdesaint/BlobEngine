#pragma once

#include <array>
#include <cmath>
#include <numbers>
#include <ostream>

#include <cstring>
#include <functional>

#define PI 3.141592653589793238462643383279502884L

namespace Blob {

template<typename T = float>
class Vec2 {
public:
    T x = 0, y = 0;

    // Constructors
    constexpr inline Vec2() noexcept = default;

    constexpr inline Vec2(T x, T y) noexcept : x(x), y(y) {}

    constexpr inline explicit Vec2(T xy) noexcept : x(xy), y(xy) {}

    constexpr inline Vec2(const Vec2 &v) noexcept : x(v.x), y(v.y) {}

    constexpr inline Vec2(const Vec2 &point1, const Vec2 &point2) noexcept {
        x = point2.x - point1.x;
        y = point2.y - point1.y;
    }

    // operator with nothing

    constexpr inline Vec2 operator-() const { return {-x, -y}; }

    // operator with Vec2
    constexpr inline bool operator==(const Vec2 &v) const {
        return x == v.x && y == v.y;
    }

    constexpr inline bool operator!=(const Vec2 &v) const {
        return x != v.x || y != v.y;
    }

    constexpr inline Vec2 operator-(const Vec2 &v) const {
        return {x - v.x, y - v.y};
    }

    constexpr inline Vec2 operator+(const Vec2 &v) const {
        return {x + v.x, y + v.y};
    }

    constexpr inline Vec2 operator*(const Vec2 &v) const {
        return {x * v.x, y * v.y};
    }

    constexpr inline Vec2 operator/(const Vec2 &v) const {
        return {x / v.x, y / v.y};
    }

    constexpr inline void operator+=(const Vec2 &v) {
        x += v.x;
        y += v.y;
    }

    constexpr inline void operator-=(const Vec2 &v) {
        x -= v.x;
        y -= v.y;
    }

    constexpr inline Vec2 &operator=(const Vec2 &v) {
        x = v.x;
        y = v.y;
        return *this;
    }

    // operator with T
    constexpr inline Vec2 operator+(T a) const { return {a + x, a + y}; }

    constexpr inline Vec2 operator-(T a) const { return {x - a, y - a}; }

    constexpr inline Vec2 operator*(T a) const { return {a * x, a * y}; }

    constexpr inline Vec2 operator/(T a) const { return {x / a, y / a}; }

    constexpr inline void operator+=(T a) {
        x += a;
        y += a;
    }

    constexpr inline void operator-=(T a) {
        x -= a;
        y -= a;
    }

    constexpr inline void operator*=(T a) {
        x *= a;
        y *= a;
    }

    constexpr inline void operator/=(T a) {
        x /= a;
        y /= a;
    }

    constexpr inline Vec2 &operator=(const T a) {
        x = a;
        y = a;
        return *this;
    }

    void set(T &&v) {
        x = v;
        y = v;
    }

    void set(Vec2<T> &&v) {
        x = v.x;
        y = v.y;
    }

    // Functions
    constexpr inline T length2() const { return x * x + y * y; }

    constexpr inline T length() const { return std::sqrt(x * x + y * y); };

    constexpr inline T scalar(const Vec2 &B) const { return x * B.x + y * B.y; }
    constexpr inline T dot(const Vec2 &B) const { return x * B.x + y * B.y; }

    constexpr inline T cross(const Vec2 &B) const { return x * B.y - y * B.x; }

    constexpr inline Vec2 normalize() const {
        return operator/(std::sqrt(x * x + y * y));
    }

    inline Vec2 setLength(T newLength) {
        return *this = *this / std::sqrt(x * x + y * y) * newLength;
    }

    constexpr inline Vec2 rotate() const { return {y, -x}; }

    constexpr inline Vec2 negate() const { return {-x, -y}; }

    constexpr inline Vec2 abs() const { return {std::abs(x), std::abs(y)}; }

    constexpr inline double getOrientation() const { return std::atan2(y, x); }

    constexpr inline double getOrientationDeg() const {
        return std::atan2(y, x) * 180 / PI;
    }

    constexpr inline bool isNull() const { return ((x == 0) && (y == 0)); }

    inline Vec2 round() const noexcept {
        return {std::round(x), std::round(y)};
    }

    template<typename U>
    inline Vec2<U> cast() const {
        return {(U) x, (U) y};
    }

    // Print operator
    friend std::ostream &operator<<(std::ostream &os, const Vec2 &dt) {
        os << dt.x << ", " << dt.y;
        return os;
    }
};

template<typename T = float>
class Vec3 {
public:
    T x = 0, y = 0, z = 0;

    // Constructors
    constexpr inline Vec3() noexcept : x(0), y(0), z(0) {}

    constexpr inline explicit Vec3(T xyz) noexcept : x(xyz), y(xyz), z(xyz) {}

    constexpr inline Vec3(T x, T y, T z) noexcept : x(x), y(y), z(z) {}

    constexpr inline explicit Vec3(T xyz[3]) noexcept :
        x(xyz[0]), y(xyz[1]), z(xyz[2]) {}

    constexpr inline Vec3(const Vec2<T> &v, T u = 0) noexcept :
        x(v.x), y(v.y), z(u) {}

    constexpr inline Vec3(const Vec3 &v) noexcept : x(v.x), y(v.y), z(v.z) {}

    constexpr inline Vec3(const Vec3 &point1, const Vec3 &point2) noexcept {
        x = point2.x - point1.x;
        y = point2.y - point1.y;
        z = point2.z - point1.z;
    }

    // operator with nothing

    constexpr inline Vec3 operator-() const { return {-x, -y, -z}; }

    // operator with Vec3
    inline constexpr bool operator==(const Vec3 &v) const noexcept {
        return x == v.x && y == v.y && z == v.z;
    }

    inline constexpr bool operator!=(const Vec3 &v) const noexcept {
        return x != v.x || y != v.y || z != v.z;
    }

    inline constexpr Vec3 operator-(const Vec3 &v) const noexcept {
        return {x - v.x, y - v.y, z - v.z};
    }

    inline constexpr Vec3 operator+(const Vec3 &v) const noexcept {
        return {x + v.x, y + v.y, z + v.z};
    }

    inline constexpr Vec3 operator*(const Vec3 &v) const noexcept {
        return {x * v.x, y * v.y, z * v.z};
    }

    inline constexpr Vec3 operator/(const Vec3 &v) const noexcept {
        return {x / v.x, y / v.y, z / v.z};
    }

    inline constexpr void operator+=(const Vec3 &v) noexcept {
        x += v.x;
        y += v.y;
        z += v.z;
    }

    inline constexpr void operator-=(const Vec3 &v) noexcept {
        x -= v.x;
        y -= v.y;
        z -= v.z;
    }

    inline constexpr void operator*=(const Vec3 &v) noexcept {
        x *= v.x;
        y *= v.y;
        z *= v.z;
    }

    inline constexpr void operator/=(const Vec3 &v) noexcept {
        x /= v.x;
        y /= v.y;
        z /= v.z;
    }

    inline constexpr Vec3 &operator=(const Vec3 &v) noexcept {
        x = v.x;
        y = v.y;
        z = v.z;
        return *this;
    }

    inline constexpr Vec3 &operator=(const Vec2<T> &v) noexcept {
        x = v.x;
        y = v.y;
        return *this;
    }

    // operator with T
    inline constexpr Vec3 operator+(const T &a) const noexcept {
        return {a + x, a + y, a + z};
    }

    inline constexpr Vec3 operator-(const T &a) const noexcept {
        return {x - a, y - a, a - z};
    }

    inline constexpr Vec3 operator*(const T &a) const noexcept {
        return {a * x, a * y, a * z};
    }

    inline constexpr Vec3 operator/(const T &a) const noexcept {
        return {x / a, y / a, z / a};
    }

    inline constexpr void operator+=(const T &a) noexcept {
        x += a;
        y += a;
        z += a;
    }

    inline constexpr void operator-=(const T &a) noexcept {
        x -= a;
        y -= a;
        z -= a;
    }

    inline constexpr void operator*=(const T &a) noexcept {
        x *= a;
        y *= a;
        z *= a;
    }

    inline constexpr void operator/=(const T &a) noexcept {
        x /= a;
        y /= a;
        z /= a;
    }

    inline constexpr Vec3 &operator=(const T &a) noexcept {
        x = a;
        y = a;
        z = a;
        return *this;
    }

    inline constexpr operator Vec2<T>() const noexcept { return {x, y}; }

    // Functions
    inline T length2() const noexcept { return x * x + y * y + z * z; }

    inline double length() const noexcept {
        return std::sqrt(x * x + y * y + z * z);
    };

    inline T scalar(const Vec3 &B) const noexcept {
        return x * B.x + y * B.y + z * B.z;
    }

    inline T dot(const Vec3 &B) const noexcept {
        return x * B.x + y * B.y + z * B.z;
    }

    inline Vec3 cross(const Vec3 &B) const noexcept {
        return {y * B.z - B.y * z, z * B.x - B.z * x, x * B.y - B.x * y};
    }

    inline Vec3 normalize() const noexcept {
        float t = 1.f / (std::sqrt(x * x + y * y + z * z));
        return {x * t, y * t, z * t};
    }

    inline Vec3 getNormal() const noexcept {
        return operator/(std::sqrt(x * x + y * y + z * z));
    }

    inline Vec3<T> setLength(double newLength) noexcept {
        return operator=(operator/=(std::sqrt(x * x + y * y + z * z)) *
                         newLength);
    }

    inline bool isNull() const noexcept {
        return (x == 0) && (y == 0) && (z == 0);
    }

    inline Vec3 round() const noexcept {
        return {std::round(x), std::round(y), std::round(z)};
    }

    template<typename U>
    inline Vec3<U> cast() const noexcept {
        return {(U) x, (U) y, (U) z};
    }

    // Print operator
    friend std::ostream &operator<<(std::ostream &os, const Vec3 &dt) {
        os << dt.x << ", " << dt.y << ", " << dt.z;
        return os;
    }
};

template<typename T = float>
class Vec4 {
public:
    T x = 0, y = 0, z = 0, w = 0;

    // Constructors
    Vec4() = default;

    explicit Vec4(T xyzw) : x(xyzw), y(xyzw), z(xyzw), w(xyzw) {}

    explicit Vec4(T xyzw[4]) : x(xyzw[0]), y(xyzw[1]), z(xyzw[2]), w(xyzw[3]) {}

    explicit Vec4(const Vec3<T> &xyz, T w = 1) :
        x(xyz.x), y(xyz.y), z(xyz.z), w(w) {}

    Vec4(const Vec2<T> &xy, T z, T w = 1) : x(xy.x), y(xy.y), z(z), w(w) {}

    Vec4(T x, T y, T z, T w = 1) : x(x), y(y), z(z), w(w) {}

    Vec4(const Vec4 &v) : x(v.x), y(v.y), z(v.z), w(v.w) {}

    Vec4(const Vec4 &point1, const Vec4 &point2) {
        x = point2.x - point1.x;
        y = point2.y - point1.y;
        z = point2.z - point1.z;
        w = point2.w - point1.w;
    }

    // operator with nothing

    constexpr inline Vec4 operator-() const { return {-x, -y, -z, -w}; }

    // operator with Vec4
    bool operator==(const Vec4 &v) const {
        return x == v.x && y == v.y && z == v.z && w == v.w;
    }

    bool operator!=(const Vec4 &v) const {
        return x != v.x || y != v.y || z != v.z || w != v.w;
    }

    Vec4 operator-(const Vec4 &v) const {
        return {x - v.x, y - v.y, z - v.z, w - v.w};
    }

    Vec4 operator+(const Vec4 &v) const {
        return {x + v.x, y + v.y, z + v.z, w + v.w};
    }

    Vec4 operator*(const Vec4 &a) const {
        return {a.x * x, a.y * y, a.z * z, a.w * w};
    }

    void operator+=(const Vec4 &v) {
        x += v.x;
        y += v.y;
        z += v.z;
        w += v.w;
    }

    void operator-=(const Vec4 &v) {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        w -= v.w;
    }

    Vec4 &operator=(const Vec4 &v) {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
        return *this;
    }

    // operator with T
    Vec4 operator+(const T &a) const { return {a + x, a + y, a + z, a + w}; }

    Vec4 operator-(const T &a) const { return {x - a, y - a, a - z, a - w}; }

    Vec4 operator*(const T &a) const { return {a * x, a * y, a * z}; }

    Vec4 operator/(const T &a) const { return {x / a, y / a, z / a, w / a}; }

    void operator+=(const T &a) {
        x += a;
        y += a;
        z += a;
        w += a;
    }

    void operator-=(const T &a) {
        x -= a;
        y -= a;
        z -= a;
        w -= a;
    }

    void operator*=(const T &a) {
        x *= a;
        y *= a;
        z *= a;
        w *= a;
    }

    void operator/=(const T &a) {
        x /= a;
        y /= a;
        z /= a;
        w /= a;
    }

    Vec4 &operator=(const T &a) {
        x = a;
        y = a;
        z = a;
        w = a;
        return *this;
    }

    operator Vec3<T>() const { return {x, y, z}; }

    // Functions
    T length2() const { return x * x + y * y + z * z + w * w; }

    double length() const { return std::sqrt(x * x + y * y + z * z + w * w); };

    T scalar(const Vec4 &B) const {
        return x * B.x + y * B.y + z * B.z + w * B.w;
    }

    T dot(const Vec4 &B) const { return x * B.x + y * B.y + z * B.z + w * B.w; }

    /*
               Vec4<T> getNormal() const { return operator/(std::sqrt(x * x + y
       * y + z * z)); }

               Vec4<T> setLength(double newLength) { return
       operator=(operator/=(std::sqrt(x * x + y * y + z * z)) * newLength); }

               */

    Vec4 normalize() const {
        float t = 1.f / (std::sqrt(x * x + y * y + z * z + w * w));
        return {x * t, y * t, z * t, w * t};
    }

    bool isNull() const { return (x == 0) && (y == 0) && (z == 0) && (w == 1); }

    template<typename U>
    Vec4<U> cast() const {
        return {(U) x, (U) y, (U) z, (U) z};
    }

    // Print operator
    friend std::ostream &operator<<(std::ostream &os, const Vec4 &dt) {
        os << dt.x << ", " << dt.y << ", " << dt.z << ", " << dt.w;
        return os;
    }
};

template<typename T>
class Mat2 {
public:
    T a11 = 1, a12 = 0;
    T a21 = 0, a22 = 1;

    Mat2() noexcept = default;

    Mat2(T a11, T a12, T a21, T a22) noexcept :
        a11(a11), a12(a12), a21(a21), a22(a22) {}

    explicit Mat2(const std::array<T, 9> &mat) noexcept :
        a11(mat[0]), a12(mat[1]), a21(mat[2]), a22(mat[3]) {}

    void load(const std::array<T, 4> &mat) {
        a11 = mat[0];
        a12 = mat[1];
        a21 = mat[2];
        a22 = mat[3];
    }

    // operator with nothing

    constexpr inline Mat2 operator-() const { return {-a11, -a22, -a21, -a22}; }

    Mat2 operator+(const Mat2 &v) const {
        return {a11 + v.a11, a12 + v.a12, a21 + v.a21, a22 + v.a22};
    }

    Mat2 operator-(const Mat2 &v) const {
        return {a11 - v.a11, a12 - v.a12, a21 - v.a21, a22 - v.a22};
    }

    Mat2 operator*(const Mat2 &v) const {
        return {a11 * v.a11 + a12 * v.a21,
                a11 * v.a12 + a12 * v.a22,
                a21 * v.a11 + a22 * v.a21,
                a21 * v.a12 + a22 * v.a22};
    }

    Vec2<T> operator*(const Vec2<T> &v) const {
        return {a11 * v.x + a12 * v.y, a21 * v.x + a22 * v.y};
    }

    template<typename U>
    Mat2<U> cast() const {
        return {(U) a11, (U) a12, (U) a21, (U) a22};
    }

    friend std::ostream &operator<<(std::ostream &os, const Mat2 &m) {
        os << m.a11 << ", " << m.a12 << std::endl;
        os << m.a21 << ", " << m.a22 << std::endl;
        return os;
    }
};

class Mat3 {
public:
    float a11 = 1, a12 = 0, a13 = 0;
    float a21 = 0, a22 = 1, a23 = 0;
    float a31 = 0, a32 = 0, a33 = 1;

    Mat3() noexcept = default;

    Mat3(float a11,
         float a12,
         float a13,
         float a21,
         float a22,
         float a23,
         float a31,
         float a32,
         float a33) noexcept :
        a11(a11),
        a12(a12),
        a13(a13),
        a21(a21),
        a22(a22),
        a23(a23),
        a31(a31),
        a32(a32),
        a33(a33) {}

    Mat3(Vec3<> v1, Vec3<> v2, Vec3<> v3) noexcept :
        a11(v1.x),
        a12(v1.y),
        a13(v1.z),
        a21(v2.x),
        a22(v2.y),
        a23(v2.z),
        a31(v3.x),
        a32(v3.y),
        a33(v3.z) {}

    explicit Mat3(const std::array<float, 9> &mat) noexcept :
        a11(mat[0]),
        a12(mat[1]),
        a13(mat[2]),
        a21(mat[3]),
        a22(mat[4]),
        a23(mat[5]),
        a31(mat[6]),
        a32(mat[7]),
        a33(mat[8]) {}

    void load(const std::array<float, 9> &mat) {
        a11 = mat[0];
        a12 = mat[1];
        a13 = mat[2];
        a21 = mat[3];
        a22 = mat[4];
        a23 = mat[5];
        a31 = mat[6];
        a32 = mat[7];
        a33 = mat[8];
    }

    constexpr inline Mat3 &operator=(const Mat2<float> &v) {
        a11 = v.a11;
        a21 = v.a21;
        a12 = v.a12;
        a22 = v.a22;
        return *this;
    }

    Mat3 operator+(const Mat3 &v) const {
        return {a11 + v.a11,
                a12 + v.a12,
                a13 + v.a13,
                a21 + v.a21,
                a22 + v.a22,
                a23 + v.a23,
                a31 + v.a31,
                a32 + v.a32,
                a33 + v.a33};
    }

    Mat3 operator-(const Mat3 &v) const {
        return {a11 - v.a11,
                a12 - v.a12,
                a13 - v.a13,
                a21 - v.a21,
                a22 - v.a22,
                a23 - v.a23,
                a31 - v.a31,
                a32 - v.a32,
                a33 - v.a33};
    }

    Mat3 operator*(const Mat3 &v) const {
        return {a11 * v.a11 + a12 * v.a21 + a13 * v.a31,
                a11 * v.a12 + a12 * v.a22 + a13 * v.a32,
                a11 * v.a13 + a12 * v.a23 + a13 * v.a33,
                a21 * v.a11 + a22 * v.a21 + a23 * v.a31,
                a21 * v.a12 + a22 * v.a22 + a23 * v.a32,
                a21 * v.a13 + a22 * v.a23 + a23 * v.a33,
                a31 * v.a11 + a32 * v.a21 + a33 * v.a31,
                a31 * v.a12 + a32 * v.a22 + a33 * v.a32,
                a31 * v.a13 + a32 * v.a23 + a33 * v.a33};
    }

    friend std::ostream &operator<<(std::ostream &os, const Mat3 &m) {
        os << m.a11 << ", " << m.a12 << ", " << m.a13 << std::endl;
        os << m.a21 << ", " << m.a22 << ", " << m.a23 << std::endl;
        os << m.a31 << ", " << m.a32 << ", " << m.a33 << std::endl;
        return os;
    }
};

/**
 * OpenGL is column major (xyz for rotation and p for position):
 * x.x x.y x.z 0
 * y.x y.y y.z 0
 * z.x z.y z.z 0
 * p.x p.y p.z 1
 * but we still want to use the matrix like row major one
 */
class Mat4 {
public:
    float a11 = 1, a21 = 0, a31 = 0, a41 = 0;
    float a12 = 0, a22 = 1, a32 = 0, a42 = 0;
    float a13 = 0, a23 = 0, a33 = 1, a43 = 0;
    float a14 = 0, a24 = 0, a34 = 0, a44 = 1;

    Mat4() noexcept = default;

    explicit Mat4(float val) :
        a11(val),
        a21(val),
        a31(val),
        a41(val),
        a12(val),
        a22(val),
        a32(val),
        a42(val),
        a13(val),
        a23(val),
        a33(val),
        a43(val),
        a14(val),
        a24(val),
        a34(val),
        a44(val) {}

    Mat4(const Vec4<> &a1,
         const Vec4<> &a2,
         const Vec4<> &a3,
         const Vec4<> &a4) :
        // the default convention is row-major for matrix contruction
        a11(a1.x),
        a12(a1.y),
        a13(a1.z),
        a14(a1.w),
        a21(a2.x),
        a22(a2.y),
        a23(a2.z),
        a24(a2.w),
        a31(a3.x),
        a32(a3.y),
        a33(a3.z),
        a34(a3.w),
        a41(a4.x),
        a42(a4.y),
        a43(a4.z),
        a44(a4.w) {}

    Mat4(float a11,
         float a12,
         float a13,
         float a14,
         float a21,
         float a22,
         float a23,
         float a24,
         float a31,
         float a32,
         float a33,
         float a34,
         float a41,
         float a42,
         float a43,
         float a44) noexcept :
        a11(a11),
        a12(a12),
        a13(a13),
        a14(a14),
        a21(a21),
        a22(a22),
        a23(a23),
        a24(a24),
        a31(a31),
        a32(a32),
        a33(a33),
        a34(a34),
        a41(a41),
        a42(a42),
        a43(a43),
        a44(a44) {}

    Mat4(const Mat4 &mat) noexcept = default;

    explicit Mat4(const std::array<float, 16> &mat) noexcept :
        a11(mat[0]),
        a12(mat[1]),
        a13(mat[2]),
        a14(mat[3]),
        a21(mat[4]),
        a22(mat[5]),
        a23(mat[6]),
        a24(mat[7]),
        a31(mat[8]),
        a32(mat[9]),
        a33(mat[10]),
        a34(mat[11]),
        a41(mat[12]),
        a42(mat[13]),
        a43(mat[14]),
        a44(mat[15]) {}

    Mat4 operator+(float val) const {
        Mat4 ret;
        ret.a11 = a11 + val;
        ret.a12 = a12 + val;
        ret.a13 = a13 + val;
        ret.a14 = a14 + val;
        ret.a21 = a21 + val;
        ret.a22 = a22 + val;
        ret.a23 = a23 + val;
        ret.a24 = a24 + val;
        ret.a31 = a31 + val;
        ret.a32 = a32 + val;
        ret.a33 = a33 + val;
        ret.a34 = a34 + val;
        ret.a41 = a41 + val;
        ret.a42 = a42 + val;
        ret.a43 = a43 + val;
        ret.a44 = a44 + val;
        return ret;
    }

    Mat4 operator-(float val) const {
        Mat4 ret;
        ret.a11 = a11 - val;
        ret.a12 = a12 - val;
        ret.a13 = a13 - val;
        ret.a14 = a14 - val;
        ret.a21 = a21 - val;
        ret.a22 = a22 - val;
        ret.a23 = a23 - val;
        ret.a24 = a24 - val;
        ret.a31 = a31 - val;
        ret.a32 = a32 - val;
        ret.a33 = a33 - val;
        ret.a34 = a34 - val;
        ret.a41 = a41 - val;
        ret.a42 = a42 - val;
        ret.a43 = a43 - val;
        ret.a44 = a44 - val;
        return ret;
    }

    Mat4 operator*(float val) const {
        Mat4 ret;
        ret.a11 = a11 * val;
        ret.a12 = a12 * val;
        ret.a13 = a13 * val;
        ret.a14 = a14 * val;
        ret.a21 = a21 * val;
        ret.a22 = a22 * val;
        ret.a23 = a23 * val;
        ret.a24 = a24 * val;
        ret.a31 = a31 * val;
        ret.a32 = a32 * val;
        ret.a33 = a33 * val;
        ret.a34 = a34 * val;
        ret.a41 = a41 * val;
        ret.a42 = a42 * val;
        ret.a43 = a43 * val;
        ret.a44 = a44 * val;
        return ret;
    }

    Mat4 operator/(float val) const {
        Mat4 ret;
        ret.a11 = a11 / val;
        ret.a12 = a12 / val;
        ret.a13 = a13 / val;
        ret.a14 = a14 / val;
        ret.a21 = a21 / val;
        ret.a22 = a22 / val;
        ret.a23 = a23 / val;
        ret.a24 = a24 / val;
        ret.a31 = a31 / val;
        ret.a32 = a32 / val;
        ret.a33 = a33 / val;
        ret.a34 = a34 / val;
        ret.a41 = a41 / val;
        ret.a42 = a42 / val;
        ret.a43 = a43 / val;
        ret.a44 = a44 / val;
        return ret;
    }

    Vec4<> operator*(const Vec3<> &val) const {
        Vec4<> ret;
        ret.x = a11 * val.x + a21 * val.y + a31 * val.z + a41;
        ret.y = a12 * val.x + a22 * val.y + a32 * val.z + a42;
        ret.z = a13 * val.x + a23 * val.y + a33 * val.z + a43;
        ret.w = a14 * val.x + a24 * val.y + a34 * val.z + a44;
        return ret;
    }

    Vec4<> operator*(const Vec4<> &val) const {
        Vec4<> ret;
        ret.x = a11 * val.x + a21 * val.y + a31 * val.z + a41 * val.w;
        ret.y = a12 * val.x + a22 * val.y + a32 * val.z + a42 * val.w;
        ret.z = a13 * val.x + a23 * val.y + a33 * val.z + a43 * val.w;
        ret.w = a14 * val.x + a24 * val.y + a34 * val.z + a44 * val.w;
        return ret;
    }

    Mat4 operator+(const Mat4 &v) const {
        Mat4 ret;
        ret.a11 = a11 + v.a11;
        ret.a12 = a12 + v.a12;
        ret.a13 = a13 + v.a13;
        ret.a14 = a14 + v.a14;
        ret.a21 = a21 + v.a21;
        ret.a22 = a22 + v.a22;
        ret.a23 = a23 + v.a23;
        ret.a24 = a24 + v.a24;
        ret.a31 = a31 + v.a31;
        ret.a32 = a32 + v.a32;
        ret.a33 = a33 + v.a33;
        ret.a34 = a34 + v.a34;
        ret.a41 = a41 + v.a41;
        ret.a42 = a42 + v.a42;
        ret.a43 = a43 + v.a43;
        ret.a44 = a44 + v.a44;
        return ret;
    }

    Mat4 operator-(const Mat4 &v) const {
        Mat4 ret;
        ret.a11 = a11 - v.a11;
        ret.a12 = a12 - v.a12;
        ret.a13 = a13 - v.a13;
        ret.a14 = a14 - v.a14;
        ret.a21 = a21 - v.a21;
        ret.a22 = a22 - v.a22;
        ret.a23 = a23 - v.a23;
        ret.a24 = a24 - v.a24;
        ret.a31 = a31 - v.a31;
        ret.a32 = a32 - v.a32;
        ret.a33 = a33 - v.a33;
        ret.a34 = a34 - v.a34;
        ret.a41 = a41 - v.a41;
        ret.a42 = a42 - v.a42;
        ret.a43 = a43 - v.a43;
        ret.a44 = a44 - v.a44;
        return ret;
    }

    /**
     * Post-multiplying with column-major is the same as pre-multiplying with
     * row-major.
     */
    Mat4 operator*(const Mat4 &v) const {
        Mat4 ret;
        ret.a11 = a11 * v.a11 + a12 * v.a21 + a13 * v.a31 + a14 * v.a41;
        ret.a12 = a11 * v.a12 + a12 * v.a22 + a13 * v.a32 + a14 * v.a42;
        ret.a13 = a11 * v.a13 + a12 * v.a23 + a13 * v.a33 + a14 * v.a43;
        ret.a14 = a11 * v.a14 + a12 * v.a24 + a13 * v.a34 + a14 * v.a44;
        ret.a21 = a21 * v.a11 + a22 * v.a21 + a23 * v.a31 + a24 * v.a41;
        ret.a22 = a21 * v.a12 + a22 * v.a22 + a23 * v.a32 + a24 * v.a42;
        ret.a23 = a21 * v.a13 + a22 * v.a23 + a23 * v.a33 + a24 * v.a43;
        ret.a24 = a21 * v.a14 + a22 * v.a24 + a23 * v.a34 + a24 * v.a44;
        ret.a31 = a31 * v.a11 + a32 * v.a21 + a33 * v.a31 + a34 * v.a41;
        ret.a32 = a31 * v.a12 + a32 * v.a22 + a33 * v.a32 + a34 * v.a42;
        ret.a33 = a31 * v.a13 + a32 * v.a23 + a33 * v.a33 + a34 * v.a43;
        ret.a34 = a31 * v.a14 + a32 * v.a24 + a33 * v.a34 + a34 * v.a44;
        ret.a41 = a41 * v.a11 + a42 * v.a21 + a43 * v.a31 + a44 * v.a41;
        ret.a42 = a41 * v.a12 + a42 * v.a22 + a43 * v.a32 + a44 * v.a42;
        ret.a43 = a41 * v.a13 + a42 * v.a23 + a43 * v.a33 + a44 * v.a43;
        ret.a44 = a41 * v.a14 + a42 * v.a24 + a43 * v.a34 + a44 * v.a44;
        return ret;
    }

    bool operator==(const Mat4 &v) const {
        return a11 == v.a11 && a12 == v.a12 && a13 == v.a13 && a14 == v.a14 &&
               a21 == v.a21 && a22 == v.a22 && a23 == v.a23 && a24 == v.a24 &&
               a31 == v.a31 && a32 == v.a32 && a33 == v.a33 && a34 == v.a34 &&
               a41 == v.a41 && a42 == v.a42 && a43 == v.a43 && a44 == v.a44;
    }

    Mat4 transpose() const {
        return {a11,
                a21,
                a31,
                a41,
                a12,
                a22,
                a32,
                a42,
                a13,
                a23,
                a33,
                a43,
                a14,
                a24,
                a34,
                a44};
    }

    Mat4 inverse() const {
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

        Mat4 Inverse;
        Inverse.a11 = +a22 * Coef00 - a23 * Coef04 + a24 * Coef08;
        Inverse.a12 = -a12 * Coef00 + a13 * Coef04 - a14 * Coef08;
        Inverse.a13 = +a12 * Coef02 - a13 * Coef06 + a14 * Coef10;
        Inverse.a14 = -a12 * Coef03 + a13 * Coef07 - a14 * Coef11;

        float Det = a11 * Inverse.a11 + a21 * Inverse.a12 + a31 * Inverse.a13 +
                    a41 * Inverse.a14;

        Inverse.a11 /= Det;
        Inverse.a12 /= Det;
        Inverse.a13 /= Det;
        Inverse.a14 /= Det;

        Inverse.a21 = (-a21 * Coef00 + a23 * Coef12 - a24 * Coef16) / Det;
        Inverse.a22 = (+a11 * Coef00 - a13 * Coef12 + a14 * Coef16) / Det;
        Inverse.a23 = (-a11 * Coef02 + a13 * Coef14 - a14 * Coef18) / Det;
        Inverse.a24 = (+a11 * Coef03 - a13 * Coef15 + a14 * Coef19) / Det;

        Inverse.a31 = (+a21 * Coef04 - a22 * Coef12 + a24 * Coef20) / Det;
        Inverse.a32 = (-a11 * Coef04 + a12 * Coef12 - a14 * Coef20) / Det;
        Inverse.a33 = (+a11 * Coef06 - a12 * Coef14 + a14 * Coef22) / Det;
        Inverse.a34 = (-a11 * Coef07 + a12 * Coef15 - a14 * Coef23) / Det;

        Inverse.a41 = (-a21 * Coef08 + a22 * Coef16 - a23 * Coef20) / Det;
        Inverse.a42 = (+a11 * Coef08 - a12 * Coef16 + a13 * Coef20) / Det;
        Inverse.a43 = (-a11 * Coef10 + a12 * Coef18 - a13 * Coef22) / Det;
        Inverse.a44 = (+a11 * Coef11 - a12 * Coef19 + a13 * Coef23) / Det;

        return Inverse;
    }

    friend std::ostream &operator<<(std::ostream &os, const Mat4 &m) {
        os << Vec4({m.a11, m.a12, m.a13, m.a14}) << std::endl;
        os << Vec4({m.a21, m.a22, m.a23, m.a24}) << std::endl;
        os << Vec4({m.a31, m.a32, m.a33, m.a34}) << std::endl;
        os << Vec4({m.a41, m.a42, m.a43, m.a44}) << std::endl;
        return os;
    }
};

class ModelTransform2D : public Mat3 {
private:
    Vec2<> scale = {1, 1};
    Mat2<float> rotation;

    void compute() {
        a11 = rotation.a11 * scale.x;
        a12 = rotation.a12 * scale.x;
        a21 = rotation.a21 * scale.y;
        a22 = rotation.a22 * scale.y;
    }

public:
    using Mat3::Mat3;

    explicit ModelTransform2D(const Mat3 &mat3) : Mat3(mat3) {}

    explicit ModelTransform2D(const Vec2<> &position) { setPosition(position); }
    explicit ModelTransform2D(const Vec2<> &position, const Vec2<> &scale) {
        setPosition(position);
        setScale(scale);
    }
    explicit ModelTransform2D(const Vec2<> &position,
                              const Vec2<> &scale,
                              float angle) :
        scale(scale) {
        setPosition(position);
        setRotation(angle);
    }

    void setPosition(const Vec2<> &xy) {
        a31 = xy.x;
        a32 = xy.y;
    }

    void setRotation(const Mat2<float> &rotation) {
        ModelTransform2D::rotation = rotation;
        compute();
    };

    void setRotation(float angle) {
        const float c = std::cos(angle);
        const float s = std::sin(angle);
        rotation.a11 = c;
        rotation.a12 = -s;
        rotation.a21 = s;
        rotation.a22 = c;
        compute();
    };

    void setScale(float xy) {
        scale = xy;
        compute();
    }

    void setScale(const Vec2<> &xy) {
        scale = xy;
        compute();
    }

    void rescale(float xy) {
        scale *= xy;
        compute();
    }

    void rescale(const Vec2<> &xy) {
        scale = xy;
        compute();
    }
};

class ViewTransform2D : public Mat3 {
private:
    Mat2<float> rotation;

    void compute() {
        a11 = rotation.a11;
        a12 = rotation.a12;
        a21 = rotation.a21;
        a22 = rotation.a22;
    }

public:
    using Mat3::Mat3;

    explicit ViewTransform2D() = default;
    explicit ViewTransform2D(const Mat3 &mat3) : Mat3(mat3) {}
    explicit ViewTransform2D(const Vec2<> &position) { setPosition(position); }
    explicit ViewTransform2D(const Vec2<> &position, float angle) {
        setPosition(position);
        setRotation(angle);
    }

    void setPosition(const Vec2<> &xy) {
        a31 = -xy.x;
        a32 = -xy.y;
    }

    void setRotation(const Mat2<float> &rotation) {
        ViewTransform2D::rotation = -rotation;
        compute();
    };

    void setRotation(float angle) {
        const float c = std::cos(-angle);
        const float s = std::sin(-angle);
        rotation.a11 = c;
        rotation.a12 = -s;
        rotation.a21 = s;
        rotation.a22 = c;
        compute();
    };
};

class ProjectionTransform2D : public Mat3 {
private:
    float height = 1, ratio = 1;

public:
    ProjectionTransform2D() = default;
    explicit ProjectionTransform2D(const Vec2<> &size) { setRatio(size); }
    void setRatio(const Vec2<> &size) {
        ratio = size.x / (float) size.y;
        a11 = 2.f / (height * ratio);
        a22 = 2.f / height;
    }

    void setHeight(float height) {
        ProjectionTransform2D::height = height;
        a11 = 2.f / (height * ratio);
        a22 = 2.f / height;
    }
};

class ModelTransform : public Mat4 {
private:
    Vec3<float> scale = {1, 1, 1};
    Mat3 rotation;

    void compute() {
        a11 = rotation.a11 * scale.x;
        a12 = rotation.a12 * scale.x;
        a13 = rotation.a13 * scale.x;
        a21 = rotation.a21 * scale.y;
        a22 = rotation.a22 * scale.y;
        a23 = rotation.a23 * scale.y;
        a31 = rotation.a31 * scale.z;
        a32 = rotation.a32 * scale.z;
        a33 = rotation.a33 * scale.z;
    }

public:
    using Mat4::Mat4;

    explicit ModelTransform(const Mat4 &mat4) : Mat4(mat4) {}

    void setPosition(const Vec3<float> &xyz) {
        a14 = xyz.x;
        a24 = xyz.y;
        a34 = xyz.z;
    }

    void setPosition(const Vec2<> &xy) {
        a14 = xy.x;
        a24 = xy.y;
    }

    void move(const Vec3<float> &xyz) {
        a14 += xyz.x;
        a24 += xyz.y;
        a34 += xyz.z;
    }

    void setRotation(const Mat3 &rotation) {
        ModelTransform::rotation = rotation;
        compute();
    };

    void setRotation(const Mat2<float> &rotation) {
        ModelTransform::rotation = rotation;
        compute();
    };

    void setRotation(float angle, const Vec3<float> &xyz) {
        const float c = std::cos(angle);
        const float s = std::sin(angle);

        auto n = xyz.getNormal();
        float axis[3] = {n.x, n.y, n.z};
        float temp[3] = {axis[0] * (1.f - c),
                         axis[1] * (1.f - c),
                         axis[2] * (1.f - c)};

        rotation.a11 = c + temp[0] * axis[0];
        rotation.a12 = temp[0] * axis[1] + s * axis[2];
        rotation.a13 = temp[0] * axis[2] - s * axis[1];

        rotation.a21 = temp[1] * axis[0] - s * axis[2];
        rotation.a22 = c + temp[1] * axis[1];
        rotation.a23 = temp[1] * axis[2] + s * axis[0];

        rotation.a31 = temp[2] * axis[0] + s * axis[1];
        rotation.a32 = temp[2] * axis[1] - s * axis[0];
        rotation.a33 = c + temp[2] * axis[2];

        compute();
    }

    void rotate(float angle, const Vec3<float> &xyz) {
        const float c = std::cos(angle);
        const float s = std::sin(angle);

        auto n = xyz.getNormal();
        float axis[3] = {n.x, n.y, n.z};
        float temp[3] = {axis[0] * (1.f - c),
                         axis[1] * (1.f - c),
                         axis[2] * (1.f - c)};

        Mat3 Rotate;
        Rotate.a11 = c + temp[0] * axis[0];
        Rotate.a12 = temp[0] * axis[1] + s * axis[2];
        Rotate.a13 = temp[0] * axis[2] - s * axis[1];

        Rotate.a21 = temp[1] * axis[0] - s * axis[2];
        Rotate.a22 = c + temp[1] * axis[1];
        Rotate.a23 = temp[1] * axis[2] + s * axis[0];

        Rotate.a31 = temp[2] * axis[0] + s * axis[1];
        Rotate.a32 = temp[2] * axis[1] - s * axis[0];
        Rotate.a33 = c + temp[2] * axis[2];

        rotation = rotation * Rotate;
        compute();
    }

    void rotate(const Vec4<float> &quaternion) {
        float sqx = quaternion.x * quaternion.x;
        float sqy = quaternion.y * quaternion.y;
        float sqz = quaternion.z * quaternion.z;
        float sqw = quaternion.w * quaternion.w;

        Mat3 Rotate;
        // invs (inverse square length) is only required if quaternion is not
        // already normalised
        float invs = 1 / (sqx + sqy + sqz + sqw);
        Rotate.a11 = (sqx - sqy - sqz + sqw) *
                     invs; // since sqw + sqx + sqy + sqz =1/invs*invs
        Rotate.a22 = (-sqx + sqy - sqz + sqw) * invs;
        Rotate.a33 = (-sqx - sqy + sqz + sqw) * invs;

        float tmp1 = quaternion.x * quaternion.y;
        float tmp2 = quaternion.z * quaternion.w;
        Rotate.a21 = 2.f * (tmp1 + tmp2) * invs;
        Rotate.a12 = 2.f * (tmp1 - tmp2) * invs;

        tmp1 = quaternion.x * quaternion.z;
        tmp2 = quaternion.y * quaternion.w;
        Rotate.a31 = 2.f * (tmp1 - tmp2) * invs;
        Rotate.a13 = 2.f * (tmp1 + tmp2) * invs;
        tmp1 = quaternion.y * quaternion.z;
        tmp2 = quaternion.x * quaternion.w;
        Rotate.a32 = 2.f * (tmp1 + tmp2) * invs;
        Rotate.a23 = 2.f * (tmp1 - tmp2) * invs;

        rotation = rotation * Rotate;
        compute();
    }

    void setRotation(const Vec4<float> &quaternion) {
        float sqx = quaternion.x * quaternion.x;
        float sqy = quaternion.y * quaternion.y;
        float sqz = quaternion.z * quaternion.z;
        float sqw = quaternion.w * quaternion.w;

        // invs (inverse square length) is only required if quaternion is not
        // already normalised
        float invs = 1 / (sqx + sqy + sqz + sqw);

        rotation.a11 = (sqx - sqy - sqz + sqw) *
                       invs; // since sqw + sqx + sqy + sqz =1/invs*invs
        rotation.a22 = (-sqx + sqy - sqz + sqw) * invs;
        rotation.a33 = (-sqx - sqy + sqz + sqw) * invs;

        float tmp1 = quaternion.x * quaternion.y;
        float tmp2 = quaternion.z * quaternion.w;
        rotation.a12 = 2.f * (tmp1 + tmp2) * invs;
        rotation.a21 = 2.f * (tmp1 - tmp2) * invs;

        tmp1 = quaternion.x * quaternion.z;
        tmp2 = quaternion.y * quaternion.w;
        rotation.a13 = 2.f * (tmp1 - tmp2) * invs;
        rotation.a31 = 2.f * (tmp1 + tmp2) * invs;
        tmp1 = quaternion.y * quaternion.z;
        tmp2 = quaternion.x * quaternion.w;
        rotation.a23 = 2.f * (tmp1 + tmp2) * invs;
        rotation.a32 = 2.f * (tmp1 - tmp2) * invs;

        compute();
    }

    void setScale(float xyz) {
        scale = xyz;
        compute();
    }

    void setScale(const Vec2<> &xyz) {
        scale = xyz;
        compute();
    }

    void setScale(const Vec3<float> &xyz) {
        scale = xyz;
        compute();
    }

    void rescale(float xyz) {
        scale *= xyz;
        compute();
    }

    void rescale(const Vec3<float> &xyz) {
        scale *= xyz;
        compute();
    }

    friend std::ostream &operator<<(std::ostream &out,
                                    const ModelTransform &vec) {
        out << "ModelTransform: " << std::endl << (Mat4) vec << std::endl;
        return out;
    }
};

class ViewTransform : public Mat4 {
private:
    void compute() {
        const Vec3<float> forward = (cameraLookAt - cameraPosition).getNormal();
        const Vec3<float> right = forward.cross(cameraUp).getNormal();
        const Vec3<float> up = right.cross(forward).getNormal();

        a11 = right.x;
        a12 = right.y;
        a13 = right.z;
        a21 = up.x;
        a22 = up.y;
        a23 = up.z;
        a31 = -forward.x;
        a32 = -forward.y;
        a33 = -forward.z;
        a14 = -right.dot(cameraPosition);
        a24 = -up.dot(cameraPosition);
        a34 = forward.dot(cameraPosition);
    }

public:
    Vec3<float> cameraPosition; /// Camera position in World Space
    Vec3<float> cameraLookAt;   /// and looks at the origin
    Vec3<float> cameraUp; /// Head is up (set to 0,-1,0 to look upside-down)

    ViewTransform() :
        cameraPosition(1, 0, 1), cameraLookAt(0, 0, 0), cameraUp(0, 0, 1) {
        compute();
    }

    ViewTransform(const Vec3<float> &cameraPosition,
                  const Vec3<float> &cameraLookAt,
                  const Vec3<float> &cameraUp) :
        cameraPosition(cameraPosition),
        cameraLookAt(cameraLookAt),
        cameraUp(cameraUp) {
        compute();
    }

    void setPosition(const Vec3<float> &pos) {
        cameraPosition = pos;
        compute();
    }

    void move(const Vec3<float> &pos) {
        cameraPosition += pos;
        compute();
    }

    void move(const Vec3<float> &pos, float angle) {
        cameraPosition += pos;
        cameraLookAt =
            cameraPosition + Vec3<>(std::cos(angle), 0, std::sin(angle));
        compute();
    }

    void setLookAt(const Vec3<float> &lookAt) {
        cameraLookAt = lookAt;
        compute();
    }

    void setCameraUp(const Vec3<float> &up) {
        cameraUp = up;
        compute();
    }

    friend std::ostream &operator<<(std::ostream &out,
                                    const ViewTransform &vec) {
        out << "cameraPosition: " << vec.cameraPosition << std::endl;
        out << "cameraLookAt: " << vec.cameraLookAt << std::endl;
        out << "cameraUp: " << vec.cameraUp << std::endl;

        out << "ViewTransform: " << std::endl << (Mat4) vec << std::endl;

        return out;
    }
};

/**
 * Source : http://www.songho.ca/opengl/gl_projectionmatrix.html
 */
class ProjectionTransform : public Mat4 {
private:
    float cameraAngle = std::numbers::pi_v<float> / 4.f, ratio = 1.f,
          closeRange, longRange;
    bool ortho = false;

public:
    ProjectionTransform() = default;

    ProjectionTransform(float cameraAngle,
                        const Vec2<unsigned int> &size,
                        float closeRange,
                        float longRange) :
        Mat4(0), cameraAngle(cameraAngle), ratio(size.x / (float) size.y) {
        setRange(closeRange, longRange);
        setAngle(cameraAngle);
    }

    /*ProjectionTransform(float cameraAngle, const Vec2<unsigned int> &size,
    float closeRange, float farRange) : Mat4(0), cameraAngle(cameraAngle),
    ratio(size.x / (float) size.y) { setRange(closeRange, farRange);
        setAngle(cameraAngle);
    }*/

    /*    void setInfinitRange(float _closeRange) {
            closeRange = _closeRange;

            a43 = -closeRange;
            a33 = -1.f;
            a34 = -1.f;
        }*/

    void setRange(float _closeRange, float _longRange) {
        closeRange = _closeRange;
        longRange = _longRange;

        if (ortho) {
            a34 = (longRange + closeRange) / (longRange - closeRange);
            a33 = -2 / (longRange - closeRange);
            a43 = 0;
            a44 = 1;
        } else {
            a33 = -(longRange + closeRange) / (longRange - closeRange);
            a34 = -(2 * longRange * closeRange) / (longRange - closeRange);
            a43 = -1.f;
            a44 = 0;
        }
    }

    void setAngle(float _cameraAngle) {
        ortho = false;
        cameraAngle = _cameraAngle;

        const float tanHalfFovy = std::tan(cameraAngle / 2.f);
        a11 = 1.f / (ratio * tanHalfFovy);
        a22 = 1.f / (tanHalfFovy);
    }

    void setRatio(const Vec2<unsigned int> &size) {
        ratio = size.x / (float) size.y;

        if (ortho) {
            a11 = 1.f / (cameraAngle * ratio); // 2 / width
            a22 = 1.f / cameraAngle;           // 2 / height
        } else {
            const float tanHalfFovy = std::tan(cameraAngle / 2.f);
            a11 = 1.f / (ratio * tanHalfFovy);
            a22 = 1.f / (tanHalfFovy);
        }
    }

    void setOrthoProjection(float height) {
        cameraAngle = height;
        ortho = true;
        a11 = a22 = a33 = a44 = 1.f;
        a12 = a13 = a14 = 0.f;
        a21 = a23 = a24 = 0.f;
        a31 = a32 = a34 = 0.f;
        a41 = a42 = a43 = 0.f;

        a11 = 1.f / (cameraAngle * ratio); // 2 / width
        a22 = 1.f / cameraAngle;           // 2 / height

        a34 = closeRange / (closeRange - longRange);
        a33 = 1 / (closeRange - longRange);
        a43 = 0;
    }

    friend std::ostream &operator<<(std::ostream &out,
                                    const ProjectionTransform &vec) {
        out << "cameraAngle: " << vec.cameraAngle << std::endl;

        out << "ratio: " << vec.ratio << std::endl;

        //        out << "closeRange: " << vec.closeRange << std::endl;

        //        out << "longRange: " << vec.longRange << std::endl;

        out << "ProjectionTransform: " << std::endl << (Mat4) vec << std::endl;

        return out;
    }
};

}; // namespace Blob

template<>
struct std::hash<Blob::Vec2<uint32_t>> {
    inline std::size_t operator()(const Blob::Vec2<uint32_t> &k) const {
        return *reinterpret_cast<const std::size_t *>(&k);
    }
};

template<>
struct std::hash<Blob::Vec2<int32_t>> {
    inline std::size_t operator()(const Blob::Vec2<int32_t> &k) const {
        return *reinterpret_cast<const std::size_t *>(&k);
    }
};

template<>
struct std::hash<Blob::Vec4<int16_t>> {
    inline std::size_t operator()(const Blob::Vec4<int16_t> &k) const {
        return *reinterpret_cast<const std::size_t *>(&k);
    }
};

template<>
struct std::hash<Blob::Vec4<uint16_t>> {
    inline std::size_t operator()(const Blob::Vec4<uint16_t> &k) const {
        return *reinterpret_cast<const std::size_t *>(&k);
    }
};

template<>
struct std::hash<Blob::Vec2<>> {
    inline std::size_t operator()(const Blob::Vec2<> &k) const {
        return *reinterpret_cast<const std::size_t *>(&k);
    }
};