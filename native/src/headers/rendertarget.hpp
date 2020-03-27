#pragma once 


#include "Kore/Graphics4/Graphics.h"
#include "nok/render_target.hpp"
#include "nok/render_target_format.hpp"


namespace nok {
    class RenderTargetImpl : public nok::RenderTarget, public Kore::Graphics4::RenderTarget {
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
    };

    static Kore::Graphics4::RenderTargetFormat getInternalRenderTargetFormat(RenderTargetFormat format){
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
}