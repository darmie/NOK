// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from nok.djinni

#include "NativeVertexBuffer.hpp"  // my header
#include "Marshal.hpp"
#include "NativeUsage.hpp"
#include "NativeVertexStructure.hpp"

namespace djinni_generated {

NativeVertexBuffer::NativeVertexBuffer() : ::djinni::JniInterface<::nok::VertexBuffer, NativeVertexBuffer>("co/zenturi/nok/VertexBuffer$CppProxy") {}

NativeVertexBuffer::~NativeVertexBuffer() = default;


CJNIEXPORT void JNICALL Java_co_zenturi_nok_VertexBuffer_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<::djinni::CppProxyHandle<::nok::VertexBuffer>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jobject JNICALL Java_co_zenturi_nok_VertexBuffer_00024CppProxy_create(JNIEnv* jniEnv, jobject /*this*/, jint j_count, jobject j_structure, jobject j_usage, jint j_instanceDataStepRate)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::nok::VertexBuffer::create(::djinni::I32::toCpp(jniEnv, j_count),
                                             ::djinni_generated::NativeVertexStructure::toCpp(jniEnv, j_structure),
                                             ::djinni_generated::NativeUsage::toCpp(jniEnv, j_usage),
                                             ::djinni::I32::toCpp(jniEnv, j_instanceDataStepRate));
        return ::djinni::release(::djinni_generated::NativeVertexBuffer::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_co_zenturi_nok_VertexBuffer_00024CppProxy_native_1lock(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::nok::VertexBuffer>(nativeRef);
        auto r = ref->lock();
        return ::djinni::release(::djinni::List<::djinni::F32>::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT void JNICALL Java_co_zenturi_nok_VertexBuffer_00024CppProxy_native_1unlock(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::nok::VertexBuffer>(nativeRef);
        ref->unlock();
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jint JNICALL Java_co_zenturi_nok_VertexBuffer_00024CppProxy_native_1count(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::nok::VertexBuffer>(nativeRef);
        auto r = ref->count();
        return ::djinni::release(::djinni::I32::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jint JNICALL Java_co_zenturi_nok_VertexBuffer_00024CppProxy_native_1stride(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::nok::VertexBuffer>(nativeRef);
        auto r = ref->stride();
        return ::djinni::release(::djinni::I32::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

}  // namespace djinni_generated
