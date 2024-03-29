// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from audio.djinni

#pragma once

#include "audio.hpp"
#include "djinni_support.hpp"

namespace djinni_generated {

class NativeAudio final : ::djinni::JniInterface<::nok::Audio, NativeAudio> {
public:
    using CppType = std::shared_ptr<::nok::Audio>;
    using CppOptType = std::shared_ptr<::nok::Audio>;
    using JniType = jobject;

    using Boxed = NativeAudio;

    ~NativeAudio();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<NativeAudio>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<NativeAudio>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    NativeAudio();
    friend ::djinni::JniClass<NativeAudio>;
    friend ::djinni::JniInterface<::nok::Audio, NativeAudio>;

};

}  // namespace djinni_generated
