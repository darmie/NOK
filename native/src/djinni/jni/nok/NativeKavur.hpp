// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from nok.djinni

#pragma once

#include "djinni_support.hpp"
#include "kavur.hpp"

namespace djinni_generated {

class NativeKavur final : ::djinni::JniInterface<::nok::Kavur, NativeKavur> {
public:
    using CppType = std::shared_ptr<::nok::Kavur>;
    using CppOptType = std::shared_ptr<::nok::Kavur>;
    using JniType = jobject;

    using Boxed = NativeKavur;

    ~NativeKavur();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<NativeKavur>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<NativeKavur>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    NativeKavur();
    friend ::djinni::JniClass<NativeKavur>;
    friend ::djinni::JniInterface<::nok::Kavur, NativeKavur>;

};

}  // namespace djinni_generated