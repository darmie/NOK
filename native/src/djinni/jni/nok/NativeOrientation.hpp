// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from system.djinni

#pragma once

#include "djinni_support.hpp"
#include "orientation.hpp"

namespace djinni_generated {

class NativeOrientation final : ::djinni::JniEnum {
public:
    using CppType = ::nok::Orientation;
    using JniType = jobject;

    using Boxed = NativeOrientation;

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return static_cast<CppType>(::djinni::JniClass<NativeOrientation>::get().ordinal(jniEnv, j)); }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, CppType c) { return ::djinni::JniClass<NativeOrientation>::get().create(jniEnv, static_cast<jint>(c)); }

private:
    NativeOrientation() : JniEnum("co/zenturi/nok/Orientation") {}
    friend ::djinni::JniClass<NativeOrientation>;
};

}  // namespace djinni_generated
