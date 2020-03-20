// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from math.djinni

#pragma once

#include "djinni_support.hpp"
#include "vec2i.hpp"

namespace djinni_generated {

class NativeVec2i final : ::djinni::JniInterface<::nok::Vec2i, NativeVec2i> {
public:
    using CppType = std::shared_ptr<::nok::Vec2i>;
    using CppOptType = std::shared_ptr<::nok::Vec2i>;
    using JniType = jobject;

    using Boxed = NativeVec2i;

    ~NativeVec2i();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<NativeVec2i>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<NativeVec2i>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    NativeVec2i();
    friend ::djinni::JniClass<NativeVec2i>;
    friend ::djinni::JniInterface<::nok::Vec2i, NativeVec2i>;

};

}  // namespace djinni_generated
