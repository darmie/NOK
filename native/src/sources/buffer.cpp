#pragma once

#include "headers/buffer.hpp"

namespace nok
{

    std::string nok::VertexElementImpl::get_name(){
        return static_cast<Kore::Graphics4::VertexElement*>(this)->name;
    }

    void nok::VertexElementImpl::set_name(const std::string &n){
        static_cast<Kore::Graphics4::VertexElement*>(this)->name = n.c_str();
    }

    nok::VertexAttribute nok::VertexElementImpl::get_attribute() {
        return getVertexAttribute(static_cast<Kore::Graphics4::VertexElement*>(this)->attribute);
    }

    void nok::VertexElementImpl::set_attribute(nok::VertexAttribute a){
        static_cast<Kore::Graphics4::VertexElement*>(this)->attribute = getInternalVertexAttribute(a);
    }

    nok::VertexData nok::VertexElementImpl::get_data(){
        return getVertexData(static_cast<Kore::Graphics4::VertexElement*>(this)->data);
    }

    void nok::VertexElementImpl::set_data(nok::VertexData d){
        static_cast<Kore::Graphics4::VertexElement*>(this)->data = getInternalVertexData(d);
    }


    std::vector<std::shared_ptr<nok::VertexElement>> nok::VertexStructureImpl::getElements(){
        Kore::Graphics4::VertexElement* elements = static_cast<Kore::Graphics4::VertexStructure*>(this)->elements;

        std::vector<std::shared_ptr<nok::VertexElement>> store;

        store[0] = std::make_shared<VertexElementImpl>(elements[0]);
        store[1] = std::make_shared<VertexElementImpl>(elements[1]);
        store[2] = std::make_shared<VertexElementImpl>(elements[2]);
        store[3] = std::make_shared<VertexElementImpl>(elements[3]);
        store[4] = std::make_shared<VertexElementImpl>(elements[4]);
        store[5] = std::make_shared<VertexElementImpl>(elements[5]);
        store[6] = std::make_shared<VertexElementImpl>(elements[6]);
        store[7] = std::make_shared<VertexElementImpl>(elements[7]);
        store[8] = std::make_shared<VertexElementImpl>(elements[8]);
        store[9] = std::make_shared<VertexElementImpl>(elements[9]);
        store[10] = std::make_shared<VertexElementImpl>(elements[10]);
        store[11] = std::make_shared<VertexElementImpl>(elements[11]);
        store[12] = std::make_shared<VertexElementImpl>(elements[12]);
        store[13] = std::make_shared<VertexElementImpl>(elements[13]);
        store[14] = std::make_shared<VertexElementImpl>(elements[14]);
        store[15] = std::make_shared<VertexElementImpl>(elements[15]);

        return store;
    }

    int32_t nok::VertexStructureImpl::get_size(){
        return static_cast<Kore::Graphics4::VertexStructure*>(this)->size;
    }

    void nok::VertexStructureImpl::set_size(int32_t s){
        static_cast<Kore::Graphics4::VertexStructure*>(this)->size = s;
    }

    bool nok::VertexStructureImpl::instanced(){
        return static_cast<Kore::Graphics4::VertexStructure*>(this)->instanced;
    }

    void nok::VertexStructureImpl::add(const std::string &name, nok::VertexData data){
        static_cast<Kore::Graphics4::VertexStructure*>(this)->add(name.c_str(), getInternalVertexData(data));
    }

    void nok::VertexStructureImpl::addAttribute(nok::VertexAttribute attribute, nok::VertexData data){
        static_cast<Kore::Graphics4::VertexStructure*>(this)->add(getInternalVertexAttribute(attribute), getInternalVertexData(data));
    }

    std::vector<float> nok::VertexBufferImpl::lock()
    {
        float *lock = static_cast<Kore::Graphics4::VertexBuffer *>(this)->lock();
        return std::vector<float>(lock, lock + (sizeof(lock) / sizeof(lock[0])));
    }

    void nok::VertexBufferImpl::unlock(){
        static_cast<Kore::Graphics4::VertexBuffer *>(this)->unlock();
    }

    int32_t nok::VertexBufferImpl::count(){
        return static_cast<Kore::Graphics4::VertexBuffer *>(this)->count();
    }

    int32_t nok::VertexBufferImpl::stride(){
        return static_cast<Kore::Graphics4::VertexBuffer *>(this)->stride();
    }



    std::vector<int32_t> nok::IndexBufferImpl::lock()
    {
        int *lock = static_cast<Kore::Graphics4::IndexBuffer *>(this)->lock();
        return std::vector<int32_t>(lock, lock + (sizeof(lock) / sizeof(lock[0])));
    }

    void nok::IndexBufferImpl::unlock(){
        static_cast<Kore::Graphics4::IndexBuffer *>(this)->unlock();
    }

    int32_t nok::IndexBufferImpl::count(){
        return static_cast<Kore::Graphics4::IndexBuffer *>(this)->count();
    }
} // namespace nok
