//
// Created by xinyu zhou on 2022/10/29.
//

#ifndef WASM_EMSCRIPTEN_TEMPLATE_MATRIX_HPP
#define WASM_EMSCRIPTEN_TEMPLATE_MATRIX_HPP

#include <type_traits>
#include <memory>
#include <array>
#include <cmath>
#include "Number.hpp"

template<typename T>
concept NumberType = std::is_arithmetic<T>::value;

template<NumberType T>
union Vec2 {
    std::array<T, 2> data;
    struct {
        T x;
        T y;
    };
    Vec2(): x{0}, y{0} {}
    explicit Vec2(T d): x{d}, y{d} {}
    Vec2(T _x, T _y): x{_x}, y{_y} {}

    Vec2<T> operator+(const T &num) const { return Vec2<T>{x+num, y+num}; }
    Vec2<T> operator+(const Vec2<T> &v) const { return Vec2<T>{x+v.x, y+v.y}; }
    friend Vec2<T> operator+(const T &num, const Vec2<T> &v) { return Vec2<T>{v.x+num, v.y+num}; }
    Vec2<T>& operator+=(const T &num) { x+=num; y+=num; return *this; }
    Vec2<T>& operator+=(const Vec2<T> &v) { x+=v.x; y+=v.y; return *this; }

    Vec2<T> operator-(const T &num) const { return Vec2<T>{x-num, y-num}; }
    Vec2<T> operator-(const Vec2<T> &v) const { return Vec2<T>{x-v.x, y-v.y}; }
    friend Vec2<T> operator-(const T &num, const Vec2<T> &v) { return Vec2<T>{num-v.x, num-v.y}; }
    Vec2<T>& operator-=(const T &num) { x-=num; y-=num; return *this; }
    Vec2<T>& operator-=(const Vec2<T> &v) { x-=v.x; y-=v.y; return *this; }

    Vec2<T> operator*(const T &num) const { return Vec2<T>{x*num, y*num}; }
    Vec2<T> operator*(const Vec2<T> &v) const { return Vec2<T>{x*v.x, y*v.y}; }
    friend Vec2<T> operator*(const T &num, const Vec2<T> &v) { return Vec2<T>{num*v.x, num*v.y}; }
    Vec2<T>& operator*=(const T &num) { x*=num; y*=num; return *this; }
    Vec2<T>& operator*=(const Vec2<T> &v) { x*=v.x; y*=v.y; return *this; }

    Vec2<T> operator/(const T &num) const { return Vec2<T>{x/num, y/num}; }
    Vec2<T> operator/(const Vec2<T> &v) const { return Vec2<T>{x/v.x, y/v.y}; }
    friend Vec2<T> operator/(const T &num, const Vec2<T> &v) { return Vec2<T>{num/v.x, num/v.y}; }
    Vec2<T>& operator/=(const T &num) { x/=num; y/=num; return *this; }
    Vec2<T>& operator/=(const Vec2<T> &v) { x/=v.x; y/=v.y; return *this; }

    T& operator[](size_t index) { return data[index]; }
    [[nodiscard]] const T& operator[](size_t index) const {
        return data[index];
    }

    T DotProduct(const Vec2& v) {
        T d{0};
        for (int i = 0; i < 2; i++) {
            d += data[i] * v[i];
        }
        return d;
    }

    int size{2};
};

template<NumberType T>
union Vec3 {
    std::array<T, 3> data;
    struct {
        T x;
        T y;
        T z;
    };
    struct {
        T r;
        T g;
        T b;
    };
    Vec3(): x{0}, y{0}, z{0} {}
    explicit Vec3(T d): x{d}, y{d}, z{d} {}
    Vec3(T _x, T _y, T _z): x{_x}, y{_y}, z{_z} {}

    Vec3<T> operator+(const T &num) const { return Vec3<T>{x+num, y+num, z+num}; }
    Vec3<T> operator+(const Vec3<T> &v) const { return Vec3<T>{x+v.x, y+v.y, z+v.z}; }
    friend Vec3<T> operator+(const T &num, const Vec3<T> &v) { return Vec3<T>{v.x+num, v.y+num, v.z+num}; }
    Vec3<T>& operator+=(const T &num) { x+=num; y+=num; z+=num; return *this; }
    Vec3<T>& operator+=(const Vec3<T> &v) { x+=v.x; y+=v.y; z+=v.z; return *this; }

    Vec3<T> operator-(const T &num) const { return Vec3<T>{x-num, y-num, z-num}; }
    Vec3<T> operator-(const Vec3<T> &v) const { return Vec3<T>{x-v.x, y-v.y, z-v.z}; }
    friend Vec3<T> operator-(const T &num, const Vec3<T> &v) { return Vec3<T>{num-v.x, num-v.y, num-v.z}; }
    Vec3<T>& operator-=(const T &num) { x-=num; y-=num; z-=num; return *this; }
    Vec3<T>& operator-=(const Vec3<T> &v) { x-=v.x; y-=v.y; z-=v.z; return *this; }

    Vec3<T> operator*(const T &num) const { return Vec3<T>{x*num, y*num, z*num}; }
    Vec3<T> operator*(const Vec3<T> &v) const { return Vec3<T>{x*v.x, y*v.y, z*v.z}; }
    friend Vec3<T> operator*(const T &num, const Vec3<T> &v) { return Vec3<T>{num*v.x, num*v.y, num*v.z}; }
    Vec3<T>& operator*=(const T &num) { x*=num; y*=num; z*=num; return *this; }
    Vec3<T>& operator*=(const Vec3<T> &v) { x*=v.x; y*=v.y; z*=v.z; return *this; }

    Vec3<T> operator/(const T &num) const { return Vec3<T>{x/num, y/num, z/num}; }
    Vec3<T> operator/(const Vec3<T> &v) const { return Vec3<T>{x/v.x, y/v.y, z/v.z}; }
    friend Vec3<T> operator/(const T &num, const Vec3<T> &v) { return Vec3<T>{num/v.x, num/v.y, num/v.z}; }
    Vec3<T>& operator/=(const T &num) { x/=num; y/=num; z/=num; return *this; }
    Vec3<T>& operator/=(const Vec3<T> &v) { x/=v.x; y/=v.y; z/=v.z; return *this; }

    T& operator[](size_t index) { return data[index]; }
    [[nodiscard]] const T& operator[](size_t index) const {
        return data[index];
    }

    T DotProduct(const Vec3& v) {
        T d{0};
        for (int i = 0; i < 3; i++) {
            d += data[i] * v[i];
        }
        return d;
    }

    int size{3};
};

template<NumberType T>
union Vec4 {
    std::array<T, 4> data;
    struct {
        T x;
        T y;
        T z;
        T w;
    };
    struct {
        T r;
        T g;
        T b;
        T a;
    };
    Vec4(): x{0}, y{0}, z{0}, w{0} {}
    explicit Vec4(T d): x{d}, y{d}, z{d}, w{d} {}
    Vec4(T _x, T _y, T _z, T _w): x{_x}, y{_y}, z{_z}, w{_w} {}

    Vec4<T> operator+(const T &num) const { return Vec4<T>{x+num, y+num, z+num, w+num}; }
    Vec4<T> operator+(const Vec4<T> &v) const { return Vec4<T>{x+v.x, y+v.y, z+v.z, w+v.w}; }
    friend Vec4<T> operator+(const T &num, const Vec4<T> &v) { return Vec4<T>{v.x+num, v.y+num, v.z+num, v.w+num}; }
    Vec4<T>& operator+=(const T &num) { x+=num; y+=num; z+=num; w+=num; return *this; }
    Vec4<T>& operator+=(const Vec4<T> &v) { x+=v.x; y+=v.y; z+=v.z; w+=v.w; return *this; }

    Vec4<T> operator-(const T &num) const { return Vec4<T>{x-num, y-num, z-num, w-num}; }
    Vec4<T> operator-(const Vec4<T> &v) const { return Vec4<T>{x-v.x, y-v.y, z-v.z, w-v.w}; }
    friend Vec4<T> operator-(const T &num, const Vec4<T> &v) { return Vec4<T>{num-v.x, num-v.y, num-v.z, num-v.w}; }
    Vec4<T>& operator-=(const T &num) { x-=num; y-=num; z-=num; w-=num; return *this; }
    Vec4<T>& operator-=(const Vec4<T> &v) { x-=v.x; y-=v.y; z-=v.z; w-=v.w; return *this; }

    Vec4<T> operator*(const T &num) const { return Vec4<T>{x*num, y*num, z*num, w*num}; }
    Vec4<T> operator*(const Vec4<T> &v) const { return Vec4<T>{x*v.x, y*v.y, z*v.z, w*v.w}; }
    friend Vec4<T> operator*(const T &num, const Vec4<T> &v) { return Vec4<T>{num*v.x, num*v.y, num*v.z, num*v.w}; }
    Vec4<T>& operator*=(const T &num) { x*=num; y*=num; z*=num; w*=num; return *this; }
    Vec4<T>& operator*=(const Vec4<T> &v) { x*=v.x; y*=v.y; z*=v.z; w*=v.w; return *this; }

    Vec4<T> operator/(const T &num) const { return Vec4<T>{x/num, y/num, z/num, w/num}; }
    Vec4<T> operator/(const Vec4<T> &v) const { return Vec4<T>{x/v.x, y/v.y, z/v.z, w/v.w}; }
    friend Vec4<T> operator/(const T &num, const Vec4<T> &v) { return Vec4<T>{num/v.x, num/v.y, num/v.z, num/v.w}; }
    Vec4<T>& operator/=(const T &num) { x/=num; y/=num; z/=num; w/=num; return *this; }
    Vec4<T>& operator/=(const Vec4<T> &v) { x/=v.x; y/=v.y; z/=v.z; w/=v.w; return *this; }

    T& operator[](size_t index) { return data[index]; }
    [[nodiscard]] const T& operator[](size_t index) const {
        return data[index];
    }

    T DotProduct(const Vec4& v) {
        T d{0};
        for (int i = 0; i < 4; i++) {
            d += data[i] * v[i];
        }
        return d;
    }

    int size{4};
};

typedef Vec2<float> Vec2f;
typedef Vec2<int> Vec2i;

typedef Vec3<float> Vec3f;
typedef Vec3<int> Vec3i;

typedef Vec4<float> Vec4f;
typedef Vec4<int> Vec4i;

template<NumberType T>
union Matrix4 {
    std::array<std::array<T, 4>, 4> data;
    struct {
        T a; // m11
        T b; // m12
        T m13;
        T m14;
        T c; // m21
        T d; // m22
        T m23;
        T m24;
        T m31; // m31
        T m32; // m32
        T m33;
        T m34;
        T e;
        T f;
        T m43;
        T m44;
    };
    Matrix4(): data{0} {};
    explicit Matrix4(const T &num) {
        data[0][0] = data[1][1] = data[2][2] = data[3][3] = num;
    };
    Matrix4(T a, T b, T c, T d, T e, T f) {
        data[0][0] = a; data[0][1] = b; data[0][2] = 0; data[0][3] = 0;
        data[1][0] = c; data[1][1] = d; data[1][2] = 0; data[1][3] = 0;
        data[2][0] = 0; data[2][1] = 0; data[2][2] = 1; data[2][3] = 0;
        data[3][0] = e; data[3][1] = f; data[3][2] = 0; data[3][3] = 1;
    };
};

/**
 * 用于2D变换的矩阵
 */
class Matrix2D {
public:
    Matrix2D(): mMatrix{1.f} {};
    Matrix2D(float a, float b, float c, float d, float e, float f): mMatrix{a, b, c, d, e, f} {};

    /* translate */
    static const Matrix2D& Translate(Matrix2D &out, const Matrix2D &matrix, float x, float y) {
        out.mMatrix.e = matrix.mMatrix.e + matrix.mMatrix.a * x + matrix.mMatrix.c * y;
        out.mMatrix.f = matrix.mMatrix.f + matrix.mMatrix.b * x + matrix.mMatrix.d * y;
        return out;
    }
    static const Matrix2D& Translate(Matrix2D &out, const Matrix2D &matrix, const Vec2f &pos) {
        return Matrix2D::Translate(out, matrix, pos.x, pos.y);
    }
    const Matrix2D& Translate(float x, float y) {
        return Matrix2D::Translate(*this, *this, x, y);
    }
    const Matrix2D& Translate(const Vec2f &pos) {
        return Matrix2D::Translate(*this, *this, pos);
    }

    /* rotate */
    static const Matrix2D& Rotate(Matrix2D &out, const Matrix2D &matrix, float angle) {
        float cosAngle = std::cos(angle);
        float sinAngle = std::sin(angle);
        float m11 = matrix.mMatrix.a * cosAngle + matrix.mMatrix.c * sinAngle;
        float m12 = matrix.mMatrix.b * cosAngle + matrix.mMatrix.d * sinAngle;
        float m21 = matrix.mMatrix.a * -sinAngle + matrix.mMatrix.c * cosAngle;
        float m22 = matrix.mMatrix.b * -sinAngle + matrix.mMatrix.d * cosAngle;
        out.mMatrix.a = m11;
        out.mMatrix.b = m12;
        out.mMatrix.c = m21;
        out.mMatrix.d = m22;
        return out;
    }
    const Matrix2D& Rotate(float angle) {
        return Matrix2D::Rotate(*this, *this, angle);
    }

    /* scale */
    static const Matrix2D& Scale(Matrix2D &out, const Matrix2D &matrix, float sx, float sy) {
        out.mMatrix.a = matrix.mMatrix.a * sx;
        out.mMatrix.b = matrix.mMatrix.b * sx;
        out.mMatrix.c = matrix.mMatrix.c * sy;
        out.mMatrix.d = matrix.mMatrix.d * sy;
        return out;
    }
    static const Matrix2D& Scale(Matrix2D &out, const Matrix2D &matrix, const Vec2f &scale) {
        return Matrix2D::Scale(out, matrix, scale.x, scale.y);
    }
    const Matrix2D& Scale(float sx, float sy) {
        return Matrix2D::Scale(*this, *this, sx, sy);
    }
    const Matrix2D& Scale(const Vec2f &scale) {
        return Matrix2D::Scale(*this, *this, scale.x, scale.y);
    }

    /* transform */
    /**
     * transform的语法糖，提高性能
     * @param out
     * @param matrix
     * @param t
     * @param s
     * @param r
     * @param rc
     * @return
     */
    static const Matrix2D& Transform2D(Matrix2D &out, const Matrix2D &matrix, const Vec2f &t, const Vec2f &s, float r, const Vec2f &rc) {
//        Matrix2D::Translate(out, matrix, t);
//        Matrix2D::Translate(out, matrix, rc);
//        Matrix2D::Rotate(out, matrix, r);
//        Matrix2D::Translate(out, matrix, Vec2f{-rc.x, -rc.y});
//        Matrix2D::Scale(out, matrix, s);

        static float a1{}, b1{}, c1{}, d1{}, cosTheta{}, sinTheta{}, offsetX{}, offsetY{};
        static float a{}, b{}, c{}, d{};
        cosTheta = std::cos(r); sinTheta = std::sin(r);
        offsetX = rc.x - t.x; offsetY = rc.y - t.y;
        a = matrix.mMatrix.a; b = matrix.mMatrix.b; c = matrix.mMatrix.c; d = matrix.mMatrix.d;
        a1 = a * cosTheta + c * sinTheta;
        b1 = b * cosTheta + d * sinTheta;
        c1 = c * cosTheta - a * sinTheta;
        d1 = d * cosTheta - b * sinTheta;

        out.mMatrix.a = s.x * a1;
        out.mMatrix.b = s.x * b1;
        out.mMatrix.c = s.y * c1;
        out.mMatrix.d = s.y * d1;

        out.mMatrix.e = matrix.mMatrix.e + a * rc.x + c * rc.y - a1 * offsetX - c1 * offsetY;
        out.mMatrix.f = matrix.mMatrix.f + b * rc.x + d * rc.y - b1 * offsetX - d1 * offsetY;

        return out;
    }

    const Matrix2D& Transform2D(const Vec2f &t, const Vec2f &s, float r, const Vec2f &rc) {
        return Matrix2D::Transform2D(*this, *this, t, s, r, rc);
    }

    [[nodiscard]] Matrix2D Clone() const {
        return Matrix2D{mMatrix.a, mMatrix.b, mMatrix.c, mMatrix.d, mMatrix.e, mMatrix.f};
    }

    static bool Equal(const Matrix2D &m1, const Matrix2D &m2) {
        return IsNumberEqual(m1.mMatrix.a, m2.mMatrix.a)
               && IsNumberEqual(m1.mMatrix.b, m2.mMatrix.b)
               && IsNumberEqual(m1.mMatrix.c, m2.mMatrix.c)
               && IsNumberEqual(m1.mMatrix.d, m2.mMatrix.d)
               && IsNumberEqual(m1.mMatrix.e, m2.mMatrix.e)
               && IsNumberEqual(m1.mMatrix.f, m2.mMatrix.f);
    }
    [[nodiscard]] bool EqualTo(const Matrix2D &m2) const {
        return Matrix2D::Equal(*this, m2);
    }

private:
    Matrix4<float> mMatrix;
};

typedef Matrix4<float> Matrix4f;
typedef Matrix4<int> Matrix4i;


#endif //WASM_EMSCRIPTEN_TEMPLATE_MATRIX_HPP
