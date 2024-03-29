// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from nok.djinni

#include "NativeVertexStructure.hpp"  // my header
#include "Marshal.hpp"
#include "NativeVertexAttribute.hpp"
#include "NativeVertexData.hpp"
#include "NativeVertexElement.hpp"

namespace djinni_generated {

NativeVertexStructure::NativeVertexStructure() : ::djinni::JniInterface<::nok::VertexStructure, NativeVertexStructure>("co/zenturi/nok/VertexStructure$CppProxy") {}

NativeVertexStructure::~NativeVertexStructure() = default;


CJNIEXPORT void JNICALL Java_co_zenturi_nok_VertexStructure_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<::djinni::CppProxyHandle<::nok::VertexStructure>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jobject JNICALL Java_co_zenturi_nok_VertexStructure_00024CppProxy_native_1getElements(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::nok::VertexStructure>(nativeRef);
        auto r = ref->getElements();
        return ::djinni::release(::djinni::List<::djinni_generated::NativeVertexElement>::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jint JNICALL Java_co_zenturi_nok_VertexStructure_00024CppProxy_native_1getSize(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::nok::VertexStructure>(nativeRef);
        auto r = ref->get_size();
        return ::djinni::release(::djinni::I32::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT void JNICALL Java_co_zenturi_nok_VertexStructure_00024CppProxy_native_1setSize(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jint j_s)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::nok::VertexStructure>(nativeRef);
        ref->set_size(::djinni::I32::toCpp(jniEnv, j_s));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jboolean JNICALL Java_co_zenturi_nok_VertexStructure_00024CppProxy_native_1instanced(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::nok::VertexStructure>(nativeRef);
        auto r = ref->instanced();
        return ::djinni::release(::djinni::Bool::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_co_zenturi_nok_VertexStructure_create(JNIEnv* jniEnv, jobject /*this*/)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::nok::VertexStructure::create();
        return ::djinni::release(::djinni_generated::NativeVertexStructure::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT void JNICALL Java_co_zenturi_nok_VertexStructure_00024CppProxy_native_1add(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jstring j_name, jobject j_data)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::nok::VertexStructure>(nativeRef);
        ref->add(::djinni::String::toCpp(jniEnv, j_name),
                 ::djinni_generated::NativeVertexData::toCpp(jniEnv, j_data));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_co_zenturi_nok_VertexStructure_00024CppProxy_native_1addAttribute(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jobject j_attribute, jobject j_data)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::nok::VertexStructure>(nativeRef);
        ref->addAttribute(::djinni_generated::NativeVertexAttribute::toCpp(jniEnv, j_attribute),
                          ::djinni_generated::NativeVertexData::toCpp(jniEnv, j_data));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

}  // namespace djinni_generated
