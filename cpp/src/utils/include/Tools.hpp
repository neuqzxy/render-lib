//
// Created by xinyu zhou on 2022/10/29.
//

#ifndef WASM_EMSCRIPTEN_TEMPLATE_TOOLS_HPP
#define WASM_EMSCRIPTEN_TEMPLATE_TOOLS_HPP

#include <numeric>
#include <type_traits>
#include <functional>
#include "Matrix.hpp"

/* 随机数生成器 */
extern float Random(float left, float right);
extern Vec2f Random(const Vec2f &left, const Vec2f &right);
extern Vec3f Random(const Vec3f &left, const Vec3f &right);

/* 字符串处理 */
extern std::wstring StrToWStr(const std::string &str);
extern std::string WStrToStr(const std::wstring &wstr);

template<typename T1, typename T2>
struct IsSameType {
    explicit operator bool() {
        return false;
    }
};
template <typename T>
struct IsSameType<T, T> {
    explicit operator bool() {
        return true;
    }
};

template <typename T>
struct IsVec2 {
    explicit operator bool() {
        return false;
    }
};
template <>
struct IsVec2<Vec2f> {
    explicit operator bool() {
        return true;
    }
};

template <typename T>
struct IsVec3 {
    explicit operator bool() {
        return false;
    }
};
template <>
struct IsVec3<Vec3f> {
    explicit operator bool() {
        return true;
    }
};

template <typename T>
struct IsVec4 {
    explicit operator bool() {
        return false;
    }
};
template <>
struct IsVec4<Vec4f> {
    explicit operator bool() {
        return true;
    }
};

template <typename T>
struct IsFloat {
    explicit operator bool() {
        return false;
    }
};
template <>
struct IsFloat<float> {
    explicit operator bool() {
        return true;
    }
};

template <typename T>
struct IsDouble {
    explicit operator bool() {
        return false;
    }
};
template <>
struct IsDouble<double> {
    explicit operator bool() {
        return true;
    }
};

template <typename T>
struct IsFloatOrDouble {
    explicit operator bool() {
        return false;
    }
};
template <>
struct IsFloatOrDouble<float> {
    explicit operator bool() {
        return true;
    }
};
template <>
struct IsFloatOrDouble<double> {
    explicit operator bool() {
        return true;
    }
};

template <typename T>
struct IsInt {
    explicit operator bool() {
        return false;
    }
};
template <>
struct IsInt<int> {
    explicit operator bool() {
        return true;
    }
};

// 牛顿-拉夫逊算法
template<typename T>
struct NewtonRapson {
    typedef std::function<T(T)> Func; // 函数
    typedef std::function<T(T)> FuncDaoshu; // 函数的导函数
    static inline T Solve(T x, Func func, FuncDaoshu funcDaoshu) {
        T x1, x2 = x;
        do {
            x1 = x2;
            T value = func(x1);
            T k = funcDaoshu(x1);
            x2 = x1 - (value / k);
        } while(std::abs(x2 - x1) >= 10E-6);

        return x2;
    }
};

template <typename T>
T linearBezier(const T &p1, const T &p2, const float &t) {
    return (1.f - t) * p1 + t * p2;
}

template <typename T>
T quadraticBezier(const T &p1, const T &p2, const T &p3, const float &t) {
    return (1.f - t) * linearBezier(p1, p2, t) + t * linearBezier(p2, p3, t);
}

template <typename T>
T cubicBezier(const T &p1, const T &p2, const T &p3, const T &p4, const float &t) {
    return (1.f - t) * quadraticBezier(p1, p2, p3, t) + t * quadraticBezier(p2, p3, p4, t);
}

template <typename T>
T bezier(std::vector<T> pList, const float &t) {
    if (pList.size() == 1) return pList[0];

    std::vector<T> _pList{};
    for (int i = 0; i < pList.size()-1; i++) {
        _pList.push_back(linearBezier(pList[i], pList[i+1], t));
    }
    return bezier(_pList, t);
}

#endif //WASM_EMSCRIPTEN_TEMPLATE_TOOLS_HPP
