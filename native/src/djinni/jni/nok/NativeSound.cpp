// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from audio.djinni

#include "NativeSound.hpp"  // my header
#include "Marshal.hpp"

namespace djinni_generated {

NativeSound::NativeSound() : ::djinni::JniInterface<::nok::Sound, NativeSound>("co/zenturi/nok/Sound$CppProxy") {}

NativeSound::~NativeSound() = default;


CJNIEXPORT void JNICALL Java_co_zenturi_nok_Sound_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<::djinni::CppProxyHandle<::nok::Sound>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jbyteArray JNICALL Java_co_zenturi_nok_Sound_00024CppProxy_native_1getCompressedData(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::nok::Sound>(nativeRef);
        auto r = ref->get_compressedData();
        return ::djinni::release(::djinni::Binary::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_co_zenturi_nok_Sound_00024CppProxy_native_1getUncompressedData(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::nok::Sound>(nativeRef);
        auto r = ref->get_uncompressedData();
        return ::djinni::release(::djinni::List<::djinni::F32>::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jfloat JNICALL Java_co_zenturi_nok_Sound_00024CppProxy_native_1getLength(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::nok::Sound>(nativeRef);
        auto r = ref->get_length();
        return ::djinni::release(::djinni::F32::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jint JNICALL Java_co_zenturi_nok_Sound_00024CppProxy_native_1getChannels(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::nok::Sound>(nativeRef);
        auto r = ref->get_channels();
        return ::djinni::release(::djinni::I32::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jint JNICALL Java_co_zenturi_nok_Sound_00024CppProxy_native_1getSampleRate(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::nok::Sound>(nativeRef);
        auto r = ref->get_sampleRate();
        return ::djinni::release(::djinni::I32::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT void JNICALL Java_co_zenturi_nok_Sound_00024CppProxy_native_1setCompressedData(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jbyteArray j_b)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::nok::Sound>(nativeRef);
        ref->set_compressedData(::djinni::Binary::toCpp(jniEnv, j_b));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_co_zenturi_nok_Sound_00024CppProxy_native_1setUncompressedData(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jobject j_d)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::nok::Sound>(nativeRef);
        ref->set_uncompressedData(::djinni::List<::djinni::F32>::toCpp(jniEnv, j_d));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_co_zenturi_nok_Sound_00024CppProxy_native_1setLength(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jfloat j_length)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::nok::Sound>(nativeRef);
        ref->set_length(::djinni::F32::toCpp(jniEnv, j_length));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_co_zenturi_nok_Sound_00024CppProxy_native_1setChannels(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jint j_channels)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::nok::Sound>(nativeRef);
        ref->set_channels(::djinni::I32::toCpp(jniEnv, j_channels));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_co_zenturi_nok_Sound_00024CppProxy_native_1setSampleRate(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jint j_rate)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::nok::Sound>(nativeRef);
        ref->set_sampleRate(::djinni::I32::toCpp(jniEnv, j_rate));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_co_zenturi_nok_Sound_00024CppProxy_native_1unload(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::nok::Sound>(nativeRef);
        ref->unload();
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jobject JNICALL Java_co_zenturi_nok_Sound_create(JNIEnv* jniEnv, jobject /*this*/)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::nok::Sound::create();
        return ::djinni::release(::djinni_generated::NativeSound::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

}  // namespace djinni_generated