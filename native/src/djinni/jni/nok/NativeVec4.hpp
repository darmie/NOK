// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from math.djinni

#pragma once

#include "djinni_support.hpp"
#include "vec4.hpp"

namespace djinni_generated {

class NativeVec4 final : ::djinni::JniInterface<::nok::Vec4, NativeVec4> {
public:
    using CppType = std::shared_ptr<::nok::Vec4>;
    using CppOptType = std::shared_ptr<::nok::Vec4>;
    using JniType = jobject;

    using Boxed = NativeVec4;

    ~NativeVec4();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<NativeVec4>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<NativeVec4>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    NativeVec4();
    friend ::djinni::JniClass<NativeVec4>;
    friend ::djinni::JniInterface<::nok::Vec4, NativeVec4>;

};

}  // namespace djinni_generated
