// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from nok.djinni

#pragma once

#include "djinni_support.hpp"
#include "font_style.hpp"

namespace djinni_generated {

class NativeFontStyle final {
public:
    using CppType = ::nok::FontStyle;
    using JniType = jobject;

    using Boxed = NativeFontStyle;

    ~NativeFontStyle();

    static CppType toCpp(JNIEnv* jniEnv, JniType j);
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c);

private:
    NativeFontStyle();
    friend ::djinni::JniClass<NativeFontStyle>;

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("co/zenturi/nok/FontStyle") };
    const jmethodID jconstructor { ::djinni::jniGetMethodID(clazz.get(), "<init>", "(ZZZ)V") };
    const jfieldID field_mBold { ::djinni::jniGetFieldID(clazz.get(), "mBold", "Z") };
    const jfieldID field_mItalic { ::djinni::jniGetFieldID(clazz.get(), "mItalic", "Z") };
    const jfieldID field_mUnderlined { ::djinni::jniGetFieldID(clazz.get(), "mUnderlined", "Z") };
};

}  // namespace djinni_generated
