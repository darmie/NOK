// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from nok.djinni

#pragma once

#include "djinni_support.hpp"
#include "vertex_attribute.hpp"

namespace djinni_generated {

class NativeVertexAttribute final : ::djinni::JniEnum {
public:
    using CppType = ::nok::VertexAttribute;
    using JniType = jobject;

    using Boxed = NativeVertexAttribute;

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return static_cast<CppType>(::djinni::JniClass<NativeVertexAttribute>::get().ordinal(jniEnv, j)); }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, CppType c) { return ::djinni::JniClass<NativeVertexAttribute>::get().create(jniEnv, static_cast<jint>(c)); }

private:
    NativeVertexAttribute() : JniEnum("co/zenturi/nok/VertexAttribute") {}
    friend ::djinni::JniClass<NativeVertexAttribute>;
};

}  // namespace djinni_generated
