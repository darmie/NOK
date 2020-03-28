// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from nok.djinni

#include "NativeTextureArray.hpp"  // my header
#include "Marshal.hpp"
#include "NativeImage.hpp"

namespace djinni_generated {

NativeTextureArray::NativeTextureArray() : ::djinni::JniInterface<::nok::TextureArray, NativeTextureArray>("co/zenturi/nok/TextureArray$CppProxy") {}

NativeTextureArray::~NativeTextureArray() = default;


CJNIEXPORT void JNICALL Java_co_zenturi_nok_TextureArray_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<::djinni::CppProxyHandle<::nok::TextureArray>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jobject JNICALL Java_co_zenturi_nok_TextureArray_00024CppProxy_create(JNIEnv* jniEnv, jobject /*this*/, jobject j_image, jint j_count)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::nok::TextureArray::create(::djinni::List<::djinni_generated::NativeImage>::toCpp(jniEnv, j_image),
                                             ::djinni::I32::toCpp(jniEnv, j_count));
        return ::djinni::release(::djinni_generated::NativeTextureArray::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

}  // namespace djinni_generated