//
// Created by xinyu zhou on 2022/10/29.
//

#ifndef WASM_EMSCRIPTEN_TEMPLATE_OUTPUT_HPP
#define WASM_EMSCRIPTEN_TEMPLATE_OUTPUT_HPP

#include <cstdio>
#include "Constants.hpp"

#define ERROR_PRINT(_STR) (printf(RED _STR "\n" NONE))
#define SUCCESS_PRINT(_STR) (printf(LIGHT_GREEN _STR "\n" NONE))
#define WARN_PRINT(_STR) (printf(YELLOW _STR "\n" NONE))
#define INFO_PRINT(_STR) (printf(LIGHT_GRAY _STR "\n" NONE))

#endif //WASM_EMSCRIPTEN_TEMPLATE_OUTPUT_HPP
