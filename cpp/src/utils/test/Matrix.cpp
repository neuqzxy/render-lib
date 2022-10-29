//
// Created by xinyu zhou on 2022/10/29.
//
#include <iostream>
#include "Matrix.hpp"

int main() {
    Vec2f a{1.f};
    Vec2f b{2.f};
    a += b;
    b += a;
    std::cout<<a[0]<<", "<<a[1]<<", "<<b[0]<<", "<<b[1]<<", "<<a.DotProduct(b)<<std::endl;
    return 0;
}