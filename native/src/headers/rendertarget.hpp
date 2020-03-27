#pragma once

#include "Kore/Graphics4/Graphics.h"
#include "nok/render_target.hpp"
#include "nok/render_target_format.hpp"

namespace nok
{
class RenderTargetImpl : public nok::RenderTarget, public Kore::Graphics4::RenderTarget
{
public:
    RenderTargetImpl(int width, int height, int depthBufferBits, bool antialiasing = false, RenderTargetFormat format = RenderTargetFormat::TARGET32BIT,
                     int stencilBufferBits = -1, int contextId = 0)
        : nok::RenderTarget(),
          Kore::Graphics4::RenderTarget(width, height, depthBufferBits, antialiasing, getInternalRenderTargetFormat(format),
                                        stencilBufferBits, contextId){};
    RenderTargetImpl(int cubeMapSize, int depthBufferBits, bool antialiasing = false, RenderTargetFormat format = RenderTargetFormat::TARGET32BIT,
                     int stencilBufferBits = -1, int contextId = 0)
        : nok::RenderTarget(),
          Kore::Graphics4::RenderTarget(cubeMapSize, depthBufferBits, antialiasing, getInternalRenderTargetFormat(format),
                                        stencilBufferBits, contextId){};
    ~RenderTargetImpl(){};

    static std::shared_ptr<nok::RenderTarget> create(int32_t width, int32_t height, int32_t depthBufferBits, bool antialiasing, RenderTargetFormat format, int32_t stencilBufferBits, int32_t contextId)
    {
        return std::make_shared<RenderTargetImpl>(width, height, depthBufferBits, antialiasing, format, stencilBufferBits, contextId);
    }

    static std::shared_ptr<nok::RenderTarget> createCube(int32_t cubeMapSize, int32_t depthBufferBits, bool antialiasing, RenderTargetFormat format, int32_t stencilBufferBits, int32_t contextId)
    {
        return std::make_shared<RenderTargetImpl>(cubeMapSize, depthBufferBits, antialiasing, format, stencilBufferBits, contextId);
    }

    int32_t get_width();

    int32_t get_height();

    int32_t get_texWidth();

    int32_t get_texHeight();

    int32_t get_contextId();

    void set_width(int32_t width);

    void set_height(int32_t height);

    void set_texWidth(int32_t width);

    void set_texHeight(int32_t height);

    void set_contextId(int32_t id);

    bool isCubeMap();

    bool isDepthAttachment();

    void useColorAsTexture(const std::shared_ptr<TextureUnit> &unit);

    void useDepthAsTexture(const std::shared_ptr<TextureUnit> &unit);

    void setDepthStencilFrom(const std::shared_ptr<nok::RenderTarget> &source);

    void getPixels(const std::vector<uint8_t> &data);

    void generateMipmaps(int32_t levels);
};

static Kore::Graphics4::RenderTargetFormat getInternalRenderTargetFormat(RenderTargetFormat format)
{
    switch (format)
    {
    case RenderTargetFormat::TARGET32BIT:
        return Kore::Graphics4::RenderTargetFormat::Target32Bit;
    case RenderTargetFormat::TARGET128BITFLOAT:
        return Kore::Graphics4::RenderTargetFormat::Target128BitFloat;
    case RenderTargetFormat::TARGET16BITDEPTH:
        return Kore::Graphics4::RenderTargetFormat::Target16BitDepth;
    case RenderTargetFormat::TARGET16BITREDFLOAT:
        return Kore::Graphics4::RenderTargetFormat::Target16BitRedFloat;
    case RenderTargetFormat::TARGET32BITREDFLOAT:
        return Kore::Graphics4::RenderTargetFormat::Target32BitRedFloat;
    case RenderTargetFormat::TARGET64BITFLOAT:
        return Kore::Graphics4::RenderTargetFormat::Target64BitFloat;
    case RenderTargetFormat::TARGET8BITRED:
        return Kore::Graphics4::RenderTargetFormat::Target8BitRed;
    }
}
} // namespace nok