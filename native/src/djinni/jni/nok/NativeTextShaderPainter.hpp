// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from nok.djinni

#pragma once

#include "djinni_support.hpp"
#include "text_shader_painter.hpp"

namespace djinni_generated {

class NativeTextShaderPainter final : ::djinni::JniInterface<::nok::TextShaderPainter, NativeTextShaderPainter> {
public:
    using CppType = std::shared_ptr<::nok::TextShaderPainter>;
    using CppOptType = std::shared_ptr<::nok::TextShaderPainter>;
    using JniType = jobject;

    using Boxed = NativeTextShaderPainter;

    ~NativeTextShaderPainter();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<NativeTextShaderPainter>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<NativeTextShaderPainter>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    NativeTextShaderPainter();
    friend ::djinni::JniClass<NativeTextShaderPainter>;
    friend ::djinni::JniInterface<::nok::TextShaderPainter, NativeTextShaderPainter>;

};

}  // namespace djinni_generated
