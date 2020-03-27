#pragma once 


#include "headers/rendertarget.hpp"
#include "headers/texture.hpp"

namespace nok
{
    int32_t nok::RenderTargetImpl::get_width(){
        return static_cast<Kore::Graphics4::RenderTarget*>(this)->width;
    }

    int32_t nok::RenderTargetImpl::get_height(){
        return static_cast<Kore::Graphics4::RenderTarget*>(this)->height;
    }

    int32_t nok::RenderTargetImpl::get_texWidth(){
        return static_cast<Kore::Graphics4::RenderTarget*>(this)->texWidth;
    }

    int32_t nok::RenderTargetImpl::get_texHeight(){
        return static_cast<Kore::Graphics4::RenderTarget*>(this)->texHeight;
    }

    int32_t nok::RenderTargetImpl::get_contextId(){
        return static_cast<Kore::Graphics4::RenderTarget*>(this)->contextId;
    }

    void nok::RenderTargetImpl::set_width(int32_t width){
       static_cast<Kore::Graphics4::RenderTarget*>(this)->width = width;
    }

    void nok::RenderTargetImpl::set_height(int32_t height){
       static_cast<Kore::Graphics4::RenderTarget*>(this)->height = height;
    }

    void nok::RenderTargetImpl::set_texWidth(int32_t width){
       static_cast<Kore::Graphics4::RenderTarget*>(this)->texWidth = width;
    }

    void nok::RenderTargetImpl::set_texHeight(int32_t height){
       static_cast<Kore::Graphics4::RenderTarget*>(this)->texHeight = height;
    }

    void nok::RenderTargetImpl::set_contextId(int32_t id){
       static_cast<Kore::Graphics4::RenderTarget*>(this)->contextId = id;
    }

    bool nok::RenderTargetImpl::isCubeMap(){
        return static_cast<Kore::Graphics4::RenderTarget*>(this)->isCubeMap;
    }

    bool nok::RenderTargetImpl::isDepthAttachment(){
        return static_cast<Kore::Graphics4::RenderTarget*>(this)->isDepthAttachment;
    }

    void nok::RenderTargetImpl::useColorAsTexture(const std::shared_ptr<nok::TextureUnit> &unit){
        return static_cast<Kore::Graphics4::RenderTarget*>(this)->useColorAsTexture(*static_cast<TextureUnitImpl*>(unit.get()));
    }

    void nok::RenderTargetImpl::useDepthAsTexture(const std::shared_ptr<nok::TextureUnit> &unit){
        return static_cast<Kore::Graphics4::RenderTarget*>(this)->useDepthAsTexture(*static_cast<TextureUnitImpl*>(unit.get()));
    }

    void nok::RenderTargetImpl::setDepthStencilFrom(const std::shared_ptr<nok::RenderTarget> &source){
        return static_cast<Kore::Graphics4::RenderTarget*>(this)->setDepthStencilFrom(static_cast<RenderTargetImpl*>(source.get()));
    }

    void nok::RenderTargetImpl::getPixels(const std::vector<uint8_t> &data){
        return static_cast<Kore::Graphics4::RenderTarget*>(this)->getPixels((uint8_t*)&data[0]);
    }

    void nok::RenderTargetImpl::generateMipmaps(int32_t levels){
        return static_cast<Kore::Graphics4::RenderTarget*>(this)->generateMipmaps(levels);
    }
} // namespace nok
