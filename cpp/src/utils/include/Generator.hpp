//
// Created by xinyu zhou on 2022/10/29.
//

#ifndef WASM_EMSCRIPTEN_TEMPLATE_GENERATOR_HPP
#define WASM_EMSCRIPTEN_TEMPLATE_GENERATOR_HPP

#include <string>

class Generator final {
public:
    Generator(): mId{0} {}

    unsigned int GetId() { return mId++; }
    std::string GetStringId() { return std::to_string(mId++); }

private:
    unsigned int mId;
};

#endif //WASM_EMSCRIPTEN_TEMPLATE_GENERATOR_HPP
