// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from math.djinni

#include "NativeMat3.hpp"  // my header
#include "Marshal.hpp"
#include "NativeVec3i.hpp"

namespace djinni_generated {

NativeMat3::NativeMat3() : ::djinni::JniInterface<::nok::Mat3, NativeMat3>("co/zenturi/nok/Mat3$CppProxy") {}

NativeMat3::~NativeMat3() = default;


CJNIEXPORT void JNICALL Java_co_zenturi_nok_Mat3_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<::djinni::CppProxyHandle<::nok::Mat3>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jfloat JNICALL Java_co_zenturi_nok_Mat3_00024CppProxy_native_1get(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jfloat j_row, jfloat j_col)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::nok::Mat3>(nativeRef);
        auto r = ref->get(::djinni::F32::toCpp(jniEnv, j_row),
                          ::djinni::F32::toCpp(jniEnv, j_col));
        return ::djinni::release(::djinni::F32::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT void JNICALL Java_co_zenturi_nok_Mat3_00024CppProxy_native_1set(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jfloat j_row, jfloat j_col, jfloat j_v)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::nok::Mat3>(nativeRef);
        ref->set(::djinni::F32::toCpp(jniEnv, j_row),
                 ::djinni::F32::toCpp(jniEnv, j_col),
                 ::djinni::F32::toCpp(jniEnv, j_v));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jobject JNICALL Java_co_zenturi_nok_Mat3_00024CppProxy_orthogonalProjection(JNIEnv* jniEnv, jobject /*this*/, jfloat j_left, jfloat j_right, jfloat j_bottom, jfloat j_top, jfloat j_zn, jfloat j_zf)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::nok::Mat3::orthogonalProjection(::djinni::F32::toCpp(jniEnv, j_left),
                                                   ::djinni::F32::toCpp(jniEnv, j_right),
                                                   ::djinni::F32::toCpp(jniEnv, j_bottom),
                                                   ::djinni::F32::toCpp(jniEnv, j_top),
                                                   ::djinni::F32::toCpp(jniEnv, j_zn),
                                                   ::djinni::F32::toCpp(jniEnv, j_zf));
        return ::djinni::release(::djinni_generated::NativeMat3::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_co_zenturi_nok_Mat3_00024CppProxy_perspective(JNIEnv* jniEnv, jobject /*this*/, jfloat j_left, jfloat j_right, jfloat j_top, jfloat j_bottom, jfloat j_near, jfloat j_far)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::nok::Mat3::perspective(::djinni::F32::toCpp(jniEnv, j_left),
                                          ::djinni::F32::toCpp(jniEnv, j_right),
                                          ::djinni::F32::toCpp(jniEnv, j_top),
                                          ::djinni::F32::toCpp(jniEnv, j_bottom),
                                          ::djinni::F32::toCpp(jniEnv, j_near),
                                          ::djinni::F32::toCpp(jniEnv, j_far));
        return ::djinni::release(::djinni_generated::NativeMat3::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_co_zenturi_nok_Mat3_00024CppProxy_perspectiveFOV(JNIEnv* jniEnv, jobject /*this*/, jfloat j_fov, jfloat j_aspect, jfloat j_near, jfloat j_far)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::nok::Mat3::perspectiveFOV(::djinni::F32::toCpp(jniEnv, j_fov),
                                             ::djinni::F32::toCpp(jniEnv, j_aspect),
                                             ::djinni::F32::toCpp(jniEnv, j_near),
                                             ::djinni::F32::toCpp(jniEnv, j_far));
        return ::djinni::release(::djinni_generated::NativeMat3::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_co_zenturi_nok_Mat3_00024CppProxy_lookAt(JNIEnv* jniEnv, jobject /*this*/, jobject j_eye, jobject j_at, jobject j_up)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::nok::Mat3::lookAt(::djinni_generated::NativeVec3i::toCpp(jniEnv, j_eye),
                                     ::djinni_generated::NativeVec3i::toCpp(jniEnv, j_at),
                                     ::djinni_generated::NativeVec3i::toCpp(jniEnv, j_up));
        return ::djinni::release(::djinni_generated::NativeMat3::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_co_zenturi_nok_Mat3_00024CppProxy_lookAlong(JNIEnv* jniEnv, jobject /*this*/, jobject j_axis, jobject j_eye, jobject j_up)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::nok::Mat3::lookAlong(::djinni_generated::NativeVec3i::toCpp(jniEnv, j_axis),
                                        ::djinni_generated::NativeVec3i::toCpp(jniEnv, j_eye),
                                        ::djinni_generated::NativeVec3i::toCpp(jniEnv, j_up));
        return ::djinni::release(::djinni_generated::NativeMat3::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_co_zenturi_nok_Mat3_00024CppProxy_translation(JNIEnv* jniEnv, jobject /*this*/, jfloat j_x, jfloat j_y)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::nok::Mat3::translation(::djinni::F32::toCpp(jniEnv, j_x),
                                          ::djinni::F32::toCpp(jniEnv, j_y));
        return ::djinni::release(::djinni_generated::NativeMat3::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_co_zenturi_nok_Mat3_00024CppProxy_movement(JNIEnv* jniEnv, jobject /*this*/, jfloat j_x, jfloat j_y, jfloat j_z)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::nok::Mat3::movement(::djinni::F32::toCpp(jniEnv, j_x),
                                       ::djinni::F32::toCpp(jniEnv, j_y),
                                       ::djinni::F32::toCpp(jniEnv, j_z));
        return ::djinni::release(::djinni_generated::NativeMat3::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_co_zenturi_nok_Mat3_00024CppProxy_identity(JNIEnv* jniEnv, jobject /*this*/)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::nok::Mat3::identity();
        return ::djinni::release(::djinni_generated::NativeMat3::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_co_zenturi_nok_Mat3_00024CppProxy_scale(JNIEnv* jniEnv, jobject /*this*/, jfloat j_scale)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::nok::Mat3::scale(::djinni::F32::toCpp(jniEnv, j_scale));
        return ::djinni::release(::djinni_generated::NativeMat3::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_co_zenturi_nok_Mat3_00024CppProxy_rotationX(JNIEnv* jniEnv, jobject /*this*/, jfloat j_alpha)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::nok::Mat3::rotationX(::djinni::F32::toCpp(jniEnv, j_alpha));
        return ::djinni::release(::djinni_generated::NativeMat3::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_co_zenturi_nok_Mat3_00024CppProxy_rotationY(JNIEnv* jniEnv, jobject /*this*/, jfloat j_alpha)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::nok::Mat3::rotationY(::djinni::F32::toCpp(jniEnv, j_alpha));
        return ::djinni::release(::djinni_generated::NativeMat3::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_co_zenturi_nok_Mat3_00024CppProxy_rotationZ(JNIEnv* jniEnv, jobject /*this*/, jfloat j_alpha)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::nok::Mat3::rotationZ(::djinni::F32::toCpp(jniEnv, j_alpha));
        return ::djinni::release(::djinni_generated::NativeMat3::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_co_zenturi_nok_Mat3_00024CppProxy_rotation(JNIEnv* jniEnv, jobject /*this*/, jfloat j_yaw, jfloat j_pitch, jfloat j_roll)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::nok::Mat3::rotation(::djinni::F32::toCpp(jniEnv, j_yaw),
                                       ::djinni::F32::toCpp(jniEnv, j_pitch),
                                       ::djinni::F32::toCpp(jniEnv, j_roll));
        return ::djinni::release(::djinni_generated::NativeMat3::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_co_zenturi_nok_Mat3_00024CppProxy_create(JNIEnv* jniEnv, jobject /*this*/)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::nok::Mat3::create();
        return ::djinni::release(::djinni_generated::NativeMat3::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_co_zenturi_nok_Mat3_00024CppProxy_from(JNIEnv* jniEnv, jobject /*this*/, jobject j_mat)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::nok::Mat3::from(::djinni_generated::NativeMat3::toCpp(jniEnv, j_mat));
        return ::djinni::release(::djinni_generated::NativeMat3::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_co_zenturi_nok_Mat3_00024CppProxy_native_1add(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jobject j_mat)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::nok::Mat3>(nativeRef);
        auto r = ref->add(::djinni_generated::NativeMat3::toCpp(jniEnv, j_mat));
        return ::djinni::release(::djinni_generated::NativeMat3::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_co_zenturi_nok_Mat3_00024CppProxy_native_1sub(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jobject j_mat)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::nok::Mat3>(nativeRef);
        auto r = ref->sub(::djinni_generated::NativeMat3::toCpp(jniEnv, j_mat));
        return ::djinni::release(::djinni_generated::NativeMat3::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_co_zenturi_nok_Mat3_00024CppProxy_native_1multiply(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jfloat j_i)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::nok::Mat3>(nativeRef);
        auto r = ref->multiply(::djinni::F32::toCpp(jniEnv, j_i));
        return ::djinni::release(::djinni_generated::NativeMat3::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_co_zenturi_nok_Mat3_00024CppProxy_native_1clone(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::nok::Mat3>(nativeRef);
        auto r = ref->clone();
        return ::djinni::release(::djinni_generated::NativeMat3::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_co_zenturi_nok_Mat3_00024CppProxy_native_1transpose(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::nok::Mat3>(nativeRef);
        auto r = ref->transpose();
        return ::djinni::release(::djinni_generated::NativeMat3::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_co_zenturi_nok_Mat3_00024CppProxy_native_1transpose3x3(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::nok::Mat3>(nativeRef);
        auto r = ref->transpose3x3();
        return ::djinni::release(::djinni_generated::NativeMat3::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jfloat JNICALL Java_co_zenturi_nok_Mat3_00024CppProxy_native_1trace(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::nok::Mat3>(nativeRef);
        auto r = ref->trace();
        return ::djinni::release(::djinni::F32::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jfloat JNICALL Java_co_zenturi_nok_Mat3_00024CppProxy_native_1determinant(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::nok::Mat3>(nativeRef);
        auto r = ref->determinant();
        return ::djinni::release(::djinni::F32::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_co_zenturi_nok_Mat3_00024CppProxy_linearInterpolate(JNIEnv* jniEnv, jobject /*this*/, jobject j_a, jobject j_b, jfloat j_prop)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::nok::Mat3::linearInterpolate(::djinni_generated::NativeMat3::toCpp(jniEnv, j_a),
                                                ::djinni_generated::NativeMat3::toCpp(jniEnv, j_b),
                                                ::djinni::F32::toCpp(jniEnv, j_prop));
        return ::djinni::release(::djinni_generated::NativeMat3::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

}  // namespace djinni_generated
