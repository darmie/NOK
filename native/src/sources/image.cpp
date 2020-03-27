

#include "headers/image.hpp"


namespace nok {
    int32_t ImageImpl::at(int32_t x, int32_t y){
        return static_cast<Kore::Graphics1::Image*>(this)->at(x, y);
    }

    std::vector<uint8_t> ImageImpl::getPixels(){
        const unsigned char* px = (const unsigned char*) static_cast<Kore::Graphics1::Image*>(this)->getPixels();
        std::vector<uint8_t> store(px, px + (sizeof(px)/sizeof(uint8_t)));
        return store;
    }

    ImageFormat ImageImpl::get_format() {
        Kore::Graphics1::Image::Format format = static_cast<Kore::Graphics1::Image*>(this)->format;
        return getImageFormat(format);
    }

    bool ImageImpl::readable(){
        return static_cast<Kore::Graphics1::Image*>(this)->readable;
    }

    ImageCompression ImageImpl::get_compression(){
        Kore::Graphics1::ImageCompression comp = static_cast<Kore::Graphics1::Image*>(this)->compression;
        return getImageCompression(comp);
    }

    std::vector<uint8_t> ImageImpl::get_data(){
        const unsigned char* px = (const unsigned char*) static_cast<Kore::Graphics1::Image*>(this)->data;
        std::vector<uint8_t> store(px, px + (sizeof(px)/sizeof(uint8_t)));
        return store;
    }

    int32_t ImageImpl::get_dataSize(){
        return static_cast<Kore::Graphics1::Image*>(this)->dataSize;
    }

    int32_t ImageImpl::get_height(){
        return static_cast<Kore::Graphics1::Image*>(this)->height;
    }

    int32_t ImageImpl::get_width(){
        return static_cast<Kore::Graphics1::Image*>(this)->width;
    }

    void ImageImpl::set_width(int32_t width){
        static_cast<Kore::Graphics1::Image*>(this)->width = width;
    }

    void ImageImpl::set_height(int32_t height){
        static_cast<Kore::Graphics1::Image*>(this)->height = height;
    }

    int32_t ImageImpl::get_depth(){
        return static_cast<Kore::Graphics1::Image*>(this)->depth;
    }

    void ImageImpl::set_depth(int32_t depth){
        static_cast<Kore::Graphics1::Image*>(this)->depth = depth;
    }
}