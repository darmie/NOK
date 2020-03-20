// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from nok.djinni

#pragma once

#include <functional>

namespace nok {

enum class ImageCompression : int {
    IMAGECOMPRESSIONNONE,
    IMAGECOMPRESSIONDXT5,
    IMAGECOMPRESSIONASTC,
    IMAGECOMPRESSIONPVRTC,
};

}  // namespace nok

namespace std {

template <>
struct hash<::nok::ImageCompression> {
    size_t operator()(::nok::ImageCompression type) const {
        return std::hash<int>()(static_cast<int>(type));
    }
};

}  // namespace std
