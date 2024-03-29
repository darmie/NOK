// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from nok.djinni

#pragma once

#include <functional>

namespace nok {

enum class RenderTargetFormat : int {
    TARGET32BIT,
    TARGET64BITFLOAT,
    TARGET32BITREDFLOAT,
    TARGET128BITFLOAT,
    TARGET16BITDEPTH,
    TARGET8BITRED,
    TARGET16BITREDFLOAT,
};

}  // namespace nok

namespace std {

template <>
struct hash<::nok::RenderTargetFormat> {
    size_t operator()(::nok::RenderTargetFormat type) const {
        return std::hash<int>()(static_cast<int>(type));
    }
};

}  // namespace std
