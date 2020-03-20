// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from nok.djinni

#include "NativeShader.hpp"  // my header
#include "Marshal.hpp"
#include "NativeShaderType.hpp"

namespace djinni_generated {

NativeShader::NativeShader() : ::djinni::JniInterface<::nok::Shader, NativeShader>("co/zenturi/nok/Shader$CppProxy") {}

NativeShader::~NativeShader() = default;


CJNIEXPORT void JNICALL Java_co_zenturi_nok_Shader_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<::djinni::CppProxyHandle<::nok::Shader>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jobject JNICALL Java_co_zenturi_nok_Shader_00024CppProxy_create(JNIEnv* jniEnv, jobject /*this*/, jbyteArray j_data, jint j_length, jobject j_type)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::nok::Shader::create(::djinni::Binary::toCpp(jniEnv, j_data),
                                       ::djinni::I32::toCpp(jniEnv, j_length),
                                       ::djinni_generated::NativeShaderType::toCpp(jniEnv, j_type));
        return ::djinni::release(::djinni_generated::NativeShader::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_co_zenturi_nok_Shader_00024CppProxy_createWithSource(JNIEnv* jniEnv, jobject /*this*/, jstring j_source, jobject j_type)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::nok::Shader::createWithSource(::djinni::String::toCpp(jniEnv, j_source),
                                                 ::djinni_generated::NativeShaderType::toCpp(jniEnv, j_type));
        return ::djinni::release(::djinni_generated::NativeShader::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

}  // namespace djinni_generated
