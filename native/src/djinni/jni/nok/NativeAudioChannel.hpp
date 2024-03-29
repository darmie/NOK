// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from audio.djinni

#pragma once

#include "audio_channel.hpp"
#include "djinni_support.hpp"

namespace djinni_generated {

class NativeAudioChannel final : ::djinni::JniInterface<::nok::AudioChannel, NativeAudioChannel> {
public:
    using CppType = std::shared_ptr<::nok::AudioChannel>;
    using CppOptType = std::shared_ptr<::nok::AudioChannel>;
    using JniType = jobject;

    using Boxed = NativeAudioChannel;

    ~NativeAudioChannel();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<NativeAudioChannel>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<NativeAudioChannel>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    NativeAudioChannel();
    friend ::djinni::JniClass<NativeAudioChannel>;
    friend ::djinni::JniInterface<::nok::AudioChannel, NativeAudioChannel>;

};

}  // namespace djinni_generated
