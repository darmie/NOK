// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from nok.djinni

#pragma once

#include "djinni_support.hpp"
#include "graphics2.hpp"

namespace djinni_generated {

class NativeGraphics2 final : ::djinni::JniInterface<::nok::Graphics2, NativeGraphics2> {
public:
    using CppType = std::shared_ptr<::nok::Graphics2>;
    using CppOptType = std::shared_ptr<::nok::Graphics2>;
    using JniType = jobject;

    using Boxed = NativeGraphics2;

    ~NativeGraphics2();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<NativeGraphics2>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<NativeGraphics2>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    NativeGraphics2();
    friend ::djinni::JniClass<NativeGraphics2>;
    friend ::djinni::JniInterface<::nok::Graphics2, NativeGraphics2>;

};

}  // namespace djinni_generated
