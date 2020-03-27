#pragma once 

#include "nok/image_compression.hpp"
#include "nok/image_format.hpp"
#include "Kore/Graphics1/Image.h"

namespace nok {
    Kore::Graphics1::Image::Format getInternalImageFormat(ImageFormat format)
    {
        switch (format)
        {
        case nok::ImageFormat::RGBA32:
            return Kore::Graphics1::Image::Format::RGBA32;
        case nok::ImageFormat::GREY8:
            return Kore::Graphics1::Image::Format::Grey8;
        case nok::ImageFormat::RGB24:
            return Kore::Graphics1::Image::Format::RGB24;
        case nok::ImageFormat::RGBA128:
            return Kore::Graphics1::Image::Format::RGBA128;
        case nok::ImageFormat::RGBA64:
            return Kore::Graphics1::Image::Format::RGB24;
        case nok::ImageFormat::A32:
            return Kore::Graphics1::Image::Format::A32;
        case nok::ImageFormat::BGRA32:
            return Kore::Graphics1::Image::Format::BGRA32;
        case nok::ImageFormat::A16:
            return Kore::Graphics1::Image::Format::A16;
        default:
            throw "invalid image format";
        }
    }

    ImageFormat getImageFormat(Kore::Graphics1::Image::Format format)
    {
        switch (format)
        {
        case Kore::Graphics1::Image::Format::RGBA32:
            return ImageFormat::RGBA32;
        case Kore::Graphics1::Image::Format::Grey8:
            return ImageFormat::GREY8;
        case Kore::Graphics1::Image::Format::RGB24:
            return ImageFormat::RGB24;
        case Kore::Graphics1::Image::Format::RGBA128:
            return ImageFormat::RGBA128;
        case Kore::Graphics1::Image::Format::RGBA64:
            return ImageFormat::RGB24;
        case Kore::Graphics1::Image::Format::A32:
            return ImageFormat::A32;
        case Kore::Graphics1::Image::Format::BGRA32:
            return ImageFormat::BGRA32;
        case Kore::Graphics1::Image::Format::A16:
            return ImageFormat::A16;
        default:
            throw "invalid image format";
        }
    }

    Kore::Graphics1::ImageCompression getInternalImageCompression(ImageCompression compression)
    {
        switch (compression)
        {
        case ImageCompression::IMAGECOMPRESSIONASTC:
            return Kore::Graphics1::ImageCompression::ImageCompressionASTC;
        case ImageCompression::IMAGECOMPRESSIONDXT5:
            return Kore::Graphics1::ImageCompression::ImageCompressionDXT5;
        case ImageCompression::IMAGECOMPRESSIONNONE:
            return Kore::Graphics1::ImageCompression::ImageCompressionNone;
        case ImageCompression::IMAGECOMPRESSIONPVRTC:
            return Kore::Graphics1::ImageCompression::ImageCompressionPVRTC;
        default:
            throw "invalid image compression format";
        }
    }

    ImageCompression getImageCompression(Kore::Graphics1::ImageCompression compression)
    {
        switch (compression)
        {
        case Kore::Graphics1::ImageCompression::ImageCompressionASTC:
            return ImageCompression::IMAGECOMPRESSIONASTC;
        case Kore::Graphics1::ImageCompression::ImageCompressionDXT5:
            return ImageCompression::IMAGECOMPRESSIONDXT5;
        case Kore::Graphics1::ImageCompression::ImageCompressionNone:
            return ImageCompression::IMAGECOMPRESSIONNONE;
        case Kore::Graphics1::ImageCompression::ImageCompressionPVRTC:
            return ImageCompression::IMAGECOMPRESSIONPVRTC;
        default:
            throw "invalid image compression format";
        }
    }
}