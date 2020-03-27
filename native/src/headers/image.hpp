#pragma once

#include "nok/texture.hpp"
#include "nok/image.hpp"
#include "Kore/Graphics1/Image.h"
#include "headers/utils.hpp"

namespace nok
{
class ImageImpl : public nok::Image, public Kore::Graphics1::Image
{
public:
    ImageImpl(int width, int height, ImageFormat format, bool readable) : nok::Image(), Kore::Graphics1::Image(width, height, nok::getInternalImageFormat(format), readable){};
    ImageImpl(int width, int height, int depth, ImageFormat format, bool readable) : nok::Image(), Kore::Graphics1::Image(width, height, depth, nok::getInternalImageFormat(format), readable){};
    ImageImpl(std::vector<uint8_t> data, int width, int height, ImageFormat format, bool readable) : nok::Image(), Kore::Graphics1::Image((void *)&data[0], width, height, nok::getInternalImageFormat(format), readable){};
    ImageImpl(std::vector<uint8_t> data, int width, int height, int depth, ImageFormat format, bool readable) : nok::Image(), Kore::Graphics1::Image((void *)&data[0], width, height, depth, nok::getInternalImageFormat(format), readable){};
    ~ImageImpl(){};

    int32_t sizeOf(ImageFormat format)
    {
        return Kore::Graphics1::Image::sizeOf(getInternalImageFormat(format));
    }

    static std::shared_ptr<nok::Image> create(int32_t width, int32_t height, ImageFormat format, bool readable)
    {
        return std::make_shared<ImageImpl>(width, height, format, readable);
    }

    static std::shared_ptr<nok::Image> create3D(int32_t width, int32_t height, int32_t depth, ImageFormat format, bool readable)
    {
        return std::make_shared<ImageImpl>(width, height, depth, format, readable);
    }

    static std::shared_ptr<nok::Image> fromData(const std::vector<uint8_t> &data, int32_t width, int32_t height, ImageFormat format, bool readable)
    {
        return std::make_shared<ImageImpl>(data, width, height, format, readable);
    }

    static std::shared_ptr<nok::Image> fromData3D(const std::vector<uint8_t> &data, int32_t width, int32_t height, int32_t depth, ImageFormat format, bool readable)
    {
        return std::make_shared<ImageImpl>(data, width, height, depth, format, readable);
    }

    virtual int32_t at(int32_t x, int32_t y) = 0;

    virtual std::vector<uint8_t> getPixels() = 0;

    virtual ImageFormat get_format() = 0;

    virtual bool readable() = 0;

    virtual ImageCompression get_compression() = 0;

    virtual std::vector<uint8_t> get_data() = 0;

    virtual int32_t get_dataSize() = 0;

    virtual int32_t get_height() = 0;

    virtual int32_t get_width() = 0;

    virtual void set_width(int32_t width) = 0;

    virtual void set_height(int32_t height) = 0;

    virtual int32_t get_depth() = 0;

    virtual void set_depth(int32_t depth) = 0;
};
} // namespace nok