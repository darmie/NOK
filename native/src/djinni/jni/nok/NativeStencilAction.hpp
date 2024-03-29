// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from nok.djinni

#pragma once

#include "djinni_support.hpp"
#include "stencil_action.hpp"

namespace djinni_generated {

class NativeStencilAction final : ::djinni::JniEnum {
public:
    using CppType = ::nok::StencilAction;
    using JniType = jobject;

    using Boxed = NativeStencilAction;

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return static_cast<CppType>(::djinni::JniClass<NativeStencilAction>::get().ordinal(jniEnv, j)); }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, CppType c) { return ::djinni::JniClass<NativeStencilAction>::get().create(jniEnv, static_cast<jint>(c)); }

private:
    NativeStencilAction() : JniEnum("co/zenturi/nok/StencilAction") {}
    friend ::djinni::JniClass<NativeStencilAction>;
};

}  // namespace djinni_generated
