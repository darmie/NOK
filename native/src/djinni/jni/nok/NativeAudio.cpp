// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from audio.djinni

#include "NativeAudio.hpp"  // my header
#include "Marshal.hpp"
#include "NativeAudioBuffer.hpp"
#include "NativeAudioChannel.hpp"
#include "NativeSound.hpp"

namespace djinni_generated {

NativeAudio::NativeAudio() : ::djinni::JniInterface<::nok::Audio, NativeAudio>("co/zenturi/nok/Audio$CppProxy") {}

NativeAudio::~NativeAudio() = default;


CJNIEXPORT void JNICALL Java_co_zenturi_nok_Audio_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<::djinni::CppProxyHandle<::nok::Audio>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jint JNICALL Java_co_zenturi_nok_Audio_00024CppProxy_native_1getSamplesPerSecond(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::nok::Audio>(nativeRef);
        auto r = ref->get_samplesPerSecond();
        return ::djinni::release(::djinni::I32::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_co_zenturi_nok_Audio_stream(JNIEnv* jniEnv, jobject /*this*/, jobject j_sound, jboolean j_loop)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::nok::Audio::stream(::djinni_generated::NativeSound::toCpp(jniEnv, j_sound),
                                      ::djinni::Bool::toCpp(jniEnv, j_loop));
        return ::djinni::release(::djinni_generated::NativeAudioChannel::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT void JNICALL Java_co_zenturi_nok_Audio_init(JNIEnv* jniEnv, jobject /*this*/)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        ::nok::Audio::init();
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jobject JNICALL Java_co_zenturi_nok_Audio_getBuffer(JNIEnv* jniEnv, jobject /*this*/)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::nok::Audio::getBuffer();
        return ::djinni::release(::djinni_generated::NativeAudioBuffer::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT void JNICALL Java_co_zenturi_nok_Audio_setBuffer(JNIEnv* jniEnv, jobject /*this*/, jobject j_buf)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        ::nok::Audio::setBuffer(::djinni_generated::NativeAudioBuffer::toCpp(jniEnv, j_buf));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_co_zenturi_nok_Audio_update(JNIEnv* jniEnv, jobject /*this*/)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        ::nok::Audio::update();
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_co_zenturi_nok_Audio_shutdown(JNIEnv* jniEnv, jobject /*this*/)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        ::nok::Audio::shutdown();
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jfloat JNICALL Java_co_zenturi_nok_Audio_readSample(JNIEnv* jniEnv, jobject /*this*/)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::nok::Audio::readSample();
        return ::djinni::release(::djinni::F32::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

}  // namespace djinni_generated
