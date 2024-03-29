// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from nok.djinni

#pragma once

#include "djinni_support.hpp"
#include "z_compare_mode.hpp"

namespace djinni_generated {

class NativeZCompareMode final : ::djinni::JniEnum {
public:
    using CppType = ::nok::ZCompareMode;
    using JniType = jobject;

    using Boxed = NativeZCompareMode;

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return static_cast<CppType>(::djinni::JniClass<NativeZCompareMode>::get().ordinal(jniEnv, j)); }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, CppType c) { return ::djinni::JniClass<NativeZCompareMode>::get().create(jniEnv, static_cast<jint>(c)); }

private:
    NativeZCompareMode() : JniEnum("co/zenturi/nok/ZCompareMode") {}
    friend ::djinni::JniClass<NativeZCompareMode>;
};

}  // namespace djinni_generated
