// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from nok.djinni

#pragma once

#include "cull_mode.hpp"
#include "djinni_support.hpp"

namespace djinni_generated {

class NativeCullMode final : ::djinni::JniEnum {
public:
    using CppType = ::nok::CullMode;
    using JniType = jobject;

    using Boxed = NativeCullMode;

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return static_cast<CppType>(::djinni::JniClass<NativeCullMode>::get().ordinal(jniEnv, j)); }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, CppType c) { return ::djinni::JniClass<NativeCullMode>::get().create(jniEnv, static_cast<jint>(c)); }

private:
    NativeCullMode() : JniEnum("co/zenturi/nok/CullMode") {}
    friend ::djinni::JniClass<NativeCullMode>;
};

}  // namespace djinni_generated
