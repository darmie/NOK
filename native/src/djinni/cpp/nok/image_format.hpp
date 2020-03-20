// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from nok.djinni

#pragma once

#include <functional>

namespace nok {

enum class ImageFormat : int {
    RGBA32,
    GREY8,
    RGB24,
    RGBA128,
    RGBA64,
    A32,
    BGRA32,
    A16,
};

}  // namespace nok

namespace std {

template <>
struct hash<::nok::ImageFormat> {
    size_t operator()(::nok::ImageFormat type) const {
        return std::hash<int>()(static_cast<int>(type));
    }
};

}  // namespace std
