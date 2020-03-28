// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from math.djinni

#pragma once

#include "djinni_support.hpp"
#include "quaternion.hpp"

namespace djinni_generated {

class NativeQuaternion final : ::djinni::JniInterface<::nok::Quaternion, NativeQuaternion> {
public:
    using CppType = std::shared_ptr<::nok::Quaternion>;
    using CppOptType = std::shared_ptr<::nok::Quaternion>;
    using JniType = jobject;

    using Boxed = NativeQuaternion;

    ~NativeQuaternion();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<NativeQuaternion>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<NativeQuaternion>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    NativeQuaternion();
    friend ::djinni::JniClass<NativeQuaternion>;
    friend ::djinni::JniInterface<::nok::Quaternion, NativeQuaternion>;

};

}  // namespace djinni_generated