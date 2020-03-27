#pragma once

#include <cstdint>
#include "Kore/Graphics4/Graphics.h"
#include "Kore/Graphics4/TextureArray.h"
#include "Kore/Graphics4/Texture.h"
#include "Kore/Graphics1/Image.h"
#include "nok/image.hpp"
#include "nok/texture.hpp"
#include "nok/texture_unit.hpp"
#include "nok/texture_addressing.hpp"
#include "nok/texture_array.hpp"
#include "nok/texture_filter.hpp"
#include "nok/texture_operation.hpp"
#include "nok/texture_argument.hpp"
#include "nok/image_format.hpp"
#include "nok/image_compression.hpp"
#include "nok/mipmap_filter.hpp"
#include "headers/image.hpp"
#include "headers/utils.hpp"
#include "nok/tex_dir.hpp"

namespace nok
{
class TextureArrayImpl : public nok::TextureArray, public Kore::Graphics4::TextureArray
{
public:
    TextureArrayImpl(nok::ImageImpl **textures, int count) : nok::TextureArray(), Kore::Graphics4::TextureArray((Kore::Graphics1::Image **)&textures[0], count){};
    ~TextureArrayImpl(){};
};
class TextureUnitImpl : public nok::TextureUnit, public Kore::Graphics4::TextureUnit
{
public:
    TextureUnitImpl() : nok::TextureUnit(), Kore::Graphics4::TextureUnit() {}
    ~TextureUnitImpl() {}
};

class TextureImpl : public nok::Texture, public Image
{
public:
    TextureImpl(int32_t width, int32_t height, ImageFormat format, bool readable)
    {
        this->_texture = new Kore::Graphics4::Texture(width, height, getInternalImageFormat(format), readable);
    }
    TextureImpl(int32_t width, int32_t height, int32_t depth, ImageFormat format, bool readable)
    {
        this->_texture = new Kore::Graphics4::Texture(width, height, depth, getInternalImageFormat(format), readable);
    }

    TextureImpl(const std::vector<uint8_t> &data, int32_t width, int32_t height, ImageFormat format, bool readable)
    {
        if (!data.empty())
        {
            void *_data = (void *)&data[0];
            this->_texture = new Kore::Graphics4::Texture(_data, width, height, getInternalImageFormat(format), readable);
        }
        else
        {
            throw "data must not be empty";
        }
    }

    TextureImpl(const std::vector<uint8_t> &data, int32_t width, int32_t height, int32_t depth, ImageFormat format, bool readable)
    {
        if (!data.empty())
        {
            void *_data = (void *)&data[0];
            this->_texture = new Kore::Graphics4::Texture(_data, width, height, depth, getInternalImageFormat(format), readable);
        }
        else
        {
            throw "data must not be empty";
        }
    }

    ~TextureImpl() {}

    Kore::Graphics4::Texture *_texture;

    static std::shared_ptr<Texture> create(int32_t width, int32_t height, ImageFormat format, bool readable)
    {
        return std::make_shared<TextureImpl>(width, height, format, readable);
    }

    static std::shared_ptr<Texture> create3D(int32_t width, int32_t height, int32_t depth, ImageFormat format, bool readable)
    {
        return std::make_shared<TextureImpl>(width, height, depth, format, readable);
    }

    static std::shared_ptr<Texture> fromData(const std::vector<uint8_t> &data, int32_t width, int32_t height, ImageFormat format, bool readable)
    {
        return std::make_shared<TextureImpl>(data, width, height, format, readable);
    }

    static std::shared_ptr<Texture> fromData3D(const std::vector<uint8_t> &data, int32_t width, int32_t height, int32_t depth, ImageFormat format, bool readable)
    {
        return std::make_shared<TextureImpl>(data, width, height, depth, format, readable);
    }

    void _set(const std::shared_ptr<TextureUnit> &unit) = 0;

    void _setImage(const std::shared_ptr<TextureUnit> &unit) = 0;
    std::vector<uint8_t> lock() = 0;
    void unlock() = 0;
    void clear(int32_t x, int32_t y, int32_t z, int32_t width, int32_t height, int32_t depth, int32_t color) = 0;

    void upload(const std::vector<uint8_t> &data, int32_t stride) = 0;
    void generateMipmaps(int32_t levels) = 0;
    void setMipMap(const std::shared_ptr<Texture> &mipmap, int32_t level) = 0;
    void stride() = 0;
    int32_t get_texHeight() = 0;
    int32_t get_texWidth() = 0;
    void set_texWidth(int32_t width) = 0;
    void set_texHeight(int32_t height) = 0;
    int32_t get_texDepth() = 0;
    void set_texDepth(int32_t depth) = 0;
    int32_t at(int32_t x, int32_t y) = 0;
    std::vector<uint8_t> getPixels() = 0;
    ImageFormat get_format() = 0;
    bool readable() = 0;
    ImageCompression get_compression() = 0;
    std::vector<uint8_t> get_data() = 0;

    int32_t get_dataSize() = 0;

    int32_t get_height() = 0;

    int32_t get_width() = 0;

    void set_width(int32_t width) = 0;

    void set_height(int32_t height) = 0;

    int32_t get_depth() = 0;

    void set_depth(int32_t depth) = 0;
};

static Kore::Graphics4::TexDir getInternalTexDir(TexDir dir)
{
    switch (dir)
    {
    case TexDir::U:
        return Kore::Graphics4::TexDir::U;
    case TexDir::V:
        return Kore::Graphics4::TexDir::V;
    case TexDir::W:
        return Kore::Graphics4::TexDir::W;
    }
}

static Kore::Graphics4::TextureAddressing getInternalTextureAddressing(TextureAddressing addressing)
{
    switch (addressing)
    {
    case TextureAddressing::REPEAT:
        return Kore::Graphics4::TextureAddressing::Repeat;

    case TextureAddressing::MIRROR:
        return Kore::Graphics4::TextureAddressing::Mirror;
    case TextureAddressing::CLAMP:
        return Kore::Graphics4::TextureAddressing::Clamp;
    case TextureAddressing::BORDER:
        return Kore::Graphics4::TextureAddressing::Border;
    }
}

static Kore::Graphics4::TextureFilter getInternalTextureFilter(TextureFilter filter)
{
    switch (filter)
    {
    case TextureFilter::ANISOTROPICFILTER:
        return Kore::Graphics4::TextureFilter::AnisotropicFilter;
    case TextureFilter::LINEARFILTER:
        return Kore::Graphics4::TextureFilter::LinearFilter;
    case TextureFilter::POINTFILTER:
        return Kore::Graphics4::TextureFilter::PointFilter;
    }
}

static Kore::Graphics4::MipmapFilter getInternalMipMapFilter(MipmapFilter filter)
{
    switch (filter)
    {
    case MipmapFilter::LINEARMIPFILTER:
        return Kore::Graphics4::MipmapFilter::LinearMipFilter;
    case MipmapFilter::NOMIPFILTER:
        return Kore::Graphics4::MipmapFilter::NoMipFilter;
    case MipmapFilter::POINTMIPFILTER:
        return Kore::Graphics4::MipmapFilter::PointMipFilter;
    default:
        return Kore::Graphics4::MipmapFilter::NoMipFilter;
    }
}

static Kore::Graphics4::TextureOperation getInternalTextureOperation(TextureOperation op)
{
    switch (op)
    {
    case TextureOperation::MODULATEOPERATION:
        return Kore::Graphics4::TextureOperation::ModulateOperation;
    case TextureOperation::SELECTFIRSTOPERATION:
        return Kore::Graphics4::TextureOperation::SelectFirstOperation;
    case TextureOperation::SELECTSECONDOPERATION:
        return Kore::Graphics4::TextureOperation::SelectSecondOperation;
    }
}

static Kore::Graphics4::TextureArgument getInternalTextureArgument(TextureArgument arg){
    switch (arg)
    {
    case TextureArgument::CURRENTCOLORARGUMENT: return Kore::Graphics4::TextureArgument::CurrentColorArgument;
    case TextureArgument::TEXTURECOLORARGUMENT: return Kore::Graphics4::TextureArgument::TextureColorArgument;
    }
}


} // namespace nok