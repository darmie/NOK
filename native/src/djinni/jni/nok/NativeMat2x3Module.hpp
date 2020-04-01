// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from math.djinni

#pragma once

#include "djinni_support.hpp"
#include "mat2x3_module.hpp"

namespace djinni_generated {

class NativeMat2x3Module final : ::djinni::JniInterface<::nok::Mat2x3Module, NativeMat2x3Module> {
public:
    using CppType = std::shared_ptr<::nok::Mat2x3Module>;
    using CppOptType = std::shared_ptr<::nok::Mat2x3Module>;
    using JniType = jobject;

    using Boxed = NativeMat2x3Module;

    ~NativeMat2x3Module();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<NativeMat2x3Module>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<NativeMat2x3Module>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    NativeMat2x3Module();
    friend ::djinni::JniClass<NativeMat2x3Module>;
    friend ::djinni::JniInterface<::nok::Mat2x3Module, NativeMat2x3Module>;

};

}  // namespace djinni_generated
