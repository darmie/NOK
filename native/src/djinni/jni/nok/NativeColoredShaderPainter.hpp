// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from nok.djinni

#pragma once

#include "colored_shader_painter.hpp"
#include "djinni_support.hpp"

namespace djinni_generated {

class NativeColoredShaderPainter final : ::djinni::JniInterface<::nok::ColoredShaderPainter, NativeColoredShaderPainter> {
public:
    using CppType = std::shared_ptr<::nok::ColoredShaderPainter>;
    using CppOptType = std::shared_ptr<::nok::ColoredShaderPainter>;
    using JniType = jobject;

    using Boxed = NativeColoredShaderPainter;

    ~NativeColoredShaderPainter();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<NativeColoredShaderPainter>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<NativeColoredShaderPainter>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    NativeColoredShaderPainter();
    friend ::djinni::JniClass<NativeColoredShaderPainter>;
    friend ::djinni::JniInterface<::nok::ColoredShaderPainter, NativeColoredShaderPainter>;

};

}  // namespace djinni_generated
