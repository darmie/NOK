// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from nok.djinni

#pragma once

#include "djinni_support.hpp"
#include "index_buffer.hpp"

namespace djinni_generated {

class NativeIndexBuffer final : ::djinni::JniInterface<::nok::IndexBuffer, NativeIndexBuffer> {
public:
    using CppType = std::shared_ptr<::nok::IndexBuffer>;
    using CppOptType = std::shared_ptr<::nok::IndexBuffer>;
    using JniType = jobject;

    using Boxed = NativeIndexBuffer;

    ~NativeIndexBuffer();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<NativeIndexBuffer>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<NativeIndexBuffer>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    NativeIndexBuffer();
    friend ::djinni::JniClass<NativeIndexBuffer>;
    friend ::djinni::JniInterface<::nok::IndexBuffer, NativeIndexBuffer>;

};

}  // namespace djinni_generated
