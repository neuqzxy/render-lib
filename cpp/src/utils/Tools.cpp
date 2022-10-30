//
// Created by xinyu zhou on 2022/10/29.
//
#include <random>
#include <codecvt>
#include <locale>
#include "Tools.hpp"

float Random(float left, float right)  {
    if (left > right) {
        std::swap(left, right);
    }
    static bool init = false;
    static std::random_device rd;
    static std::mt19937 mt{rd()};
    static std::uniform_real_distribution<double> dist{left, right};
    return dist(mt);
}

Vec2f Random(const Vec2f &left, const Vec2f &right) {
    return Vec2f{Random(left.x, right.x), Random(left.y, right.y)};
}

Vec3f Random(const Vec3f &left, const Vec3f &right) {
    return Vec3f{Random(left.x, right.x), Random(left.y, right.y), Random(left.z, right.z)};
}

std::wstring StrToWStr(const std::string &str) {
    std::wstring_convert <std::codecvt_utf8 <wchar_t>, wchar_t> convert;
    return convert.from_bytes (str);
}

std::string WStrToStr(const std::wstring &wstr) {
    using convert_typeX = std::codecvt_utf8<wchar_t>;
    std::wstring_convert<convert_typeX, wchar_t> converterX;

    return converterX.to_bytes(wstr);
}
