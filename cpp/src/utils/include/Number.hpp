//
// Created by xinyu zhou on 2022/10/29.
//

#ifndef RENDER_LIB_NUMBER_HPP
#define RENDER_LIB_NUMBER_HPP

#include <numeric>

template<typename T>
typename std::enable_if<!std::numeric_limits<T>::is_integer, bool>::type IsNumberEqual(T x, T y, unsigned int ulp=2) {
    return std::fabs(x-y) < std::numeric_limits<T>::epsilon() * ulp
           || std::fabs(x-y) < std::numeric_limits<T>::min();
}

#endif //RENDER_LIB_NUMBER_HPP
