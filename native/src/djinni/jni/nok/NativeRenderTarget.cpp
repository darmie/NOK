// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from nok.djinni

#include "NativeRenderTarget.hpp"  // my header
#include "Marshal.hpp"
#include "NativeRenderTargetFormat.hpp"
#include "NativeTextureUnit.hpp"

namespace djinni_generated {

NativeRenderTarget::NativeRenderTarget() : ::djinni::JniInterface<::nok::RenderTarget, NativeRenderTarget>("co/zenturi/nok/RenderTarget$CppProxy") {}

NativeRenderTarget::~NativeRenderTarget() = default;


CJNIEXPORT void JNICALL Java_co_zenturi_nok_RenderTarget_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<::djinni::CppProxyHandle<::nok::RenderTarget>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jobject JNICALL Java_co_zenturi_nok_RenderTarget_00024CppProxy_create(JNIEnv* jniEnv, jobject /*this*/, jint j_width, jint j_height, jint j_depthBufferBits, jboolean j_antialiasing, jobject j_format, jint j_stencilBufferBits, jint j_contextId)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::nok::RenderTarget::create(::djinni::I32::toCpp(jniEnv, j_width),
                                             ::djinni::I32::toCpp(jniEnv, j_height),
                                             ::djinni::I32::toCpp(jniEnv, j_depthBufferBits),
                                             ::djinni::Bool::toCpp(jniEnv, j_antialiasing),
                                             ::djinni_generated::NativeRenderTargetFormat::toCpp(jniEnv, j_format),
                                             ::djinni::I32::toCpp(jniEnv, j_stencilBufferBits),
                                             ::djinni::I32::toCpp(jniEnv, j_contextId));
        return ::djinni::release(::djinni_generated::NativeRenderTarget::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_co_zenturi_nok_RenderTarget_00024CppProxy_createCube(JNIEnv* jniEnv, jobject /*this*/, jint j_cubeMapSize, jint j_depthBufferBits, jboolean j_antialiasing, jobject j_format, jint j_stencilBufferBits, jint j_contextId)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::nok::RenderTarget::createCube(::djinni::I32::toCpp(jniEnv, j_cubeMapSize),
                                                 ::djinni::I32::toCpp(jniEnv, j_depthBufferBits),
                                                 ::djinni::Bool::toCpp(jniEnv, j_antialiasing),
                                                 ::djinni_generated::NativeRenderTargetFormat::toCpp(jniEnv, j_format),
                                                 ::djinni::I32::toCpp(jniEnv, j_stencilBufferBits),
                                                 ::djinni::I32::toCpp(jniEnv, j_contextId));
        return ::djinni::release(::djinni_generated::NativeRenderTarget::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jint JNICALL Java_co_zenturi_nok_RenderTarget_00024CppProxy_native_1getWidth(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::nok::RenderTarget>(nativeRef);
        auto r = ref->get_width();
        return ::djinni::release(::djinni::I32::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jint JNICALL Java_co_zenturi_nok_RenderTarget_00024CppProxy_native_1getHeight(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::nok::RenderTarget>(nativeRef);
        auto r = ref->get_height();
        return ::djinni::release(::djinni::I32::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jint JNICALL Java_co_zenturi_nok_RenderTarget_00024CppProxy_native_1getTexWidth(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::nok::RenderTarget>(nativeRef);
        auto r = ref->get_texWidth();
        return ::djinni::release(::djinni::I32::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jint JNICALL Java_co_zenturi_nok_RenderTarget_00024CppProxy_native_1getTexHeight(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::nok::RenderTarget>(nativeRef);
        auto r = ref->get_texHeight();
        return ::djinni::release(::djinni::I32::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jint JNICALL Java_co_zenturi_nok_RenderTarget_00024CppProxy_native_1getContextId(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::nok::RenderTarget>(nativeRef);
        auto r = ref->get_contextId();
        return ::djinni::release(::djinni::I32::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT void JNICALL Java_co_zenturi_nok_RenderTarget_00024CppProxy_native_1setWidth(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jint j_width)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::nok::RenderTarget>(nativeRef);
        ref->set_width(::djinni::I32::toCpp(jniEnv, j_width));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_co_zenturi_nok_RenderTarget_00024CppProxy_native_1setHeight(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jint j_height)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::nok::RenderTarget>(nativeRef);
        ref->set_height(::djinni::I32::toCpp(jniEnv, j_height));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_co_zenturi_nok_RenderTarget_00024CppProxy_native_1setTexWidth(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jint j_width)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::nok::RenderTarget>(nativeRef);
        ref->set_texWidth(::djinni::I32::toCpp(jniEnv, j_width));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_co_zenturi_nok_RenderTarget_00024CppProxy_native_1setTexHeight(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jint j_height)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::nok::RenderTarget>(nativeRef);
        ref->set_texHeight(::djinni::I32::toCpp(jniEnv, j_height));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_co_zenturi_nok_RenderTarget_00024CppProxy_native_1setContextId(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jint j_id)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::nok::RenderTarget>(nativeRef);
        ref->set_contextId(::djinni::I32::toCpp(jniEnv, j_id));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jboolean JNICALL Java_co_zenturi_nok_RenderTarget_00024CppProxy_native_1isCubeMap(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::nok::RenderTarget>(nativeRef);
        auto r = ref->isCubeMap();
        return ::djinni::release(::djinni::Bool::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jboolean JNICALL Java_co_zenturi_nok_RenderTarget_00024CppProxy_native_1isDepthAttachment(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::nok::RenderTarget>(nativeRef);
        auto r = ref->isDepthAttachment();
        return ::djinni::release(::djinni::Bool::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT void JNICALL Java_co_zenturi_nok_RenderTarget_00024CppProxy_native_1useColorAsTexture(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jobject j_unit)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::nok::RenderTarget>(nativeRef);
        ref->useColorAsTexture(::djinni_generated::NativeTextureUnit::toCpp(jniEnv, j_unit));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_co_zenturi_nok_RenderTarget_00024CppProxy_native_1useDepthAsTexture(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jobject j_unit)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::nok::RenderTarget>(nativeRef);
        ref->useDepthAsTexture(::djinni_generated::NativeTextureUnit::toCpp(jniEnv, j_unit));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_co_zenturi_nok_RenderTarget_00024CppProxy_native_1setDepthStencilFrom(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jobject j_source)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::nok::RenderTarget>(nativeRef);
        ref->setDepthStencilFrom(::djinni_generated::NativeRenderTarget::toCpp(jniEnv, j_source));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_co_zenturi_nok_RenderTarget_00024CppProxy_native_1getPixels(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jbyteArray j_data)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::nok::RenderTarget>(nativeRef);
        ref->getPixels(::djinni::Binary::toCpp(jniEnv, j_data));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_co_zenturi_nok_RenderTarget_00024CppProxy_native_1generateMipmaps(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jint j_levels)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::nok::RenderTarget>(nativeRef);
        ref->generateMipmaps(::djinni::I32::toCpp(jniEnv, j_levels));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

}  // namespace djinni_generated