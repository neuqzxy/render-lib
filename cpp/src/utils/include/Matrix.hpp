//
// Created by xinyu zhou on 2022/10/29.
//

#ifndef WASM_EMSCRIPTEN_TEMPLATE_MATRIX_HPP
#define WASM_EMSCRIPTEN_TEMPLATE_MATRIX_HPP

#include <type_traits>
#include <memory>
#include <array>

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

#endif //WASM_EMSCRIPTEN_TEMPLATE_MATRIX_HPP
