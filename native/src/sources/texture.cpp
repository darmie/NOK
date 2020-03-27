#pragma once

#include "headers/texture.hpp"


namespace nok {

    void TextureImpl::_set(const std::shared_ptr<TextureUnit> & unit) {
        this->_texture->_set(*reinterpret_cast<Kore::Graphics4::TextureUnit*>(reinterpret_cast<TextureUnitImpl*>(unit.get())));
    }

    void TextureImpl::_setImage(const std::shared_ptr<TextureUnit> & unit){
        this->_texture->_setImage(*reinterpret_cast<Kore::Graphics4::TextureUnit*>(reinterpret_cast<TextureUnitImpl*>(unit.get())));
    }
    
    std::vector<uint8_t> TextureImpl::lock() {
        uint8_t* lock = this->_texture->lock();
        int size = sizeof(lock)/sizeof(uint8_t);
        std::vector<uint8_t> store(&lock[0], &lock[size - 1]);
        return store;
    }

    void TextureImpl::unlock(){
        this->_texture->unlock();
    }

    void TextureImpl::clear(int32_t x, int32_t y, int32_t z, int32_t width, int32_t height, int32_t depth, int32_t color){
        this->_texture->clear(x, y, z, width, height, depth, (uint32_t)color);
    }

    void TextureImpl::upload(const std::vector<uint8_t> & data, int32_t stride){
        #if defined(KORE_IOS) || defined(KORE_MACOS)
            this->_texture->upload((uint8_t*)&data[0], stride);
        #endif
    }

    void TextureImpl::generateMipmaps(int32_t levels){
        this->_texture->generateMipmaps(levels);
    }

    void TextureImpl::setMipMap(const std::shared_ptr<Texture> & mipmap, int32_t level) {
        Kore::Graphics4::Texture * mm = (reinterpret_cast<TextureImpl*>(mipmap.get()))->_texture;
        this->_texture->setMipmap(mm, level);
    }

    void TextureImpl::stride(){
        this->_texture->stride();
    }

    int32_t TextureImpl::get_texHeight(){
        return this->_texture->texHeight;
    }

    int32_t TextureImpl::get_texWidth(){
        return this->_texture->texWidth;
    }

    void TextureImpl::set_texWidth(int32_t width){
        this->_texture->texWidth = width;
    }

    void TextureImpl::set_texHeight(int32_t height){
        this->_texture->texHeight = height;
    }

    int32_t TextureImpl::get_texDepth(){
        return this->_texture->texDepth;
    }

    void TextureImpl::set_texDepth(int32_t depth){
        this->_texture->texDepth = depth;
    }

    int32_t TextureImpl::at(int32_t x, int32_t y){
        return this->_texture->at(x, y);
    }

    std::vector<uint8_t> TextureImpl::getPixels(){
        uint8_t* px = this->_texture->getPixels();
        int size = sizeof(px)/sizeof(uint8_t);
        std::vector<uint8_t> store(&px[0], &px[size - 1]);
        return store;
    }

    ImageFormat TextureImpl::get_format(){
        return getImageFormat(this->_texture->format);
    }

    bool TextureImpl::readable(){
        return this->_texture->readable;
    }

    ImageCompression TextureImpl::get_compression(){
        return getImageCompression(this->_texture->compression);
    }

    std::vector<uint8_t> TextureImpl::get_data(){
        const unsigned char* data = (unsigned char*)this->_texture->data;
        std::vector<uint8_t> store(data, data + this->_texture->dataSize);
        return store;
    }

    int32_t TextureImpl::get_dataSize(){
        return this->_texture->dataSize;
    }

    int32_t TextureImpl::get_height(){
       return this->_texture->height; 
    }

    int32_t TextureImpl::get_width(){
       return this->_texture->width; 
    }

    void TextureImpl::set_height(int32_t height){
       this->_texture->height = height; 
    }

    void TextureImpl::set_width(int32_t width){
       this->_texture->width = width; 
    }

    int32_t TextureImpl::get_depth(){
       return this->_texture->depth; 
    }

    void TextureImpl::set_depth(int32_t depth){
        this->_texture->depth = depth;
    }

}
