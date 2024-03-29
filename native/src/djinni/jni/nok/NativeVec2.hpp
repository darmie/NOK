// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from math.djinni

#pragma once

#include "djinni_support.hpp"
#include "vec2.hpp"

namespace djinni_generated {

class NativeVec2 final : ::djinni::JniInterface<::nok::Vec2, NativeVec2> {
public:
    using CppType = std::shared_ptr<::nok::Vec2>;
    using CppOptType = std::shared_ptr<::nok::Vec2>;
    using JniType = jobject;

    using Boxed = NativeVec2;

    ~NativeVec2();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<NativeVec2>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<NativeVec2>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    NativeVec2();
    friend ::djinni::JniClass<NativeVec2>;
    friend ::djinni::JniInterface<::nok::Vec2, NativeVec2>;

};

}  // namespace djinni_generated
