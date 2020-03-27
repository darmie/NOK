#pragma once

#include "nok/mat3.hpp"
#include "Kore/Math/Matrix.h"

namespace nok
{
class Matrix3Impl : public nok::Mat3, public Kore::Matrix<3U, 3U, float>
{
public:
    Matrix3Impl() : nok::Mat3(), Kore::Matrix<3U, 3U, float>(){};
    Matrix3Impl(Matrix3Impl* mat) : nok::Mat3(), Kore::Matrix<3U, 3U, float>(*static_cast<Matrix3Impl*>(mat)){};
    ~Matrix3Impl(){};
    float get(float row, float col);

    void set(float row, float col, float v);

    static std::shared_ptr<Mat3> orthogonalProjection(float left, float right, float bottom, float top, float zn, float zf)
    {
        return std::make_shared<Matrix3Impl>(Kore::mat3::orthogonalProjection(left, right, bottom, top, zn, zf));
    }

    static std::shared_ptr<Mat3> perspective(float left, float right, float top, float bottom, float near, float far)
    {
        return std::make_shared<Matrix3Impl>(Kore::mat3::Perspective(left, right, top, bottom, near, far));
    }

    static std::shared_ptr<Mat3> perspectiveFOV(float fov, float aspect, float near, float far)
    {
        return std::make_shared<Matrix3Impl>(Kore::mat3::Perspective(fov, aspect, near, far));
    }

    static std::shared_ptr<Mat3> lookAt(const std::shared_ptr<Vec3i> &eye, const std::shared_ptr<Vec3i> &at, const std::shared_ptr<Vec3i> &up)
    {
    }

    static std::shared_ptr<Mat3> lookAlong(const std::shared_ptr<Vec3i> &axis, const std::shared_ptr<Vec3i> &eye, const std::shared_ptr<Vec3i> &up)
    {
    }

    static std::shared_ptr<Mat3> translation(float x, float y)
    {
        return std::make_shared<Matrix3Impl>(Kore::mat3::Translation(x, y));
    }

    static std::shared_ptr<Mat3> movement(float x, float y, float z)
    {
        return std::make_shared<Matrix3Impl>(Kore::mat3::Movement(x, y, z));
    }

    static std::shared_ptr<Mat3> identity()
    {
        return std::make_shared<Matrix3Impl>(Kore::mat3::Identity());
    }

    static std::shared_ptr<Mat3> scale(float scale)
    {
        return std::make_shared<Matrix3Impl>(Kore::mat3::Scale(scale));
    }

    static std::shared_ptr<Mat3> rotationX(float alpha)
    {
        return std::make_shared<Matrix3Impl>(Kore::mat3::RotationX(alpha));
    }

    static std::shared_ptr<Mat3> rotationY(float alpha) {
        return std::make_shared<Matrix3Impl>(Kore::mat3::RotationY(alpha));
    }

    static std::shared_ptr<Mat3> rotationZ(float alpha)
    {
        return std::make_shared<Matrix3Impl>(Kore::mat3::RotationZ(alpha));
    }

    static std::shared_ptr<Mat3> rotation(float yaw, float pitch, float roll) {
        return std::make_shared<Matrix3Impl>(Kore::mat3::Rotation(yaw, pitch, roll));
    }

    static std::shared_ptr<Mat3> create() 
    {
        return std::make_shared<Matrix3Impl>();
    }

    static std::shared_ptr<Mat3> from(const std::shared_ptr<Mat3> &mat) {
        return std::make_shared<Matrix3Impl>(new Kore::mat3(*static_cast<Matrix3Impl*>(mat.get())));
    }

    std::shared_ptr<Mat3> add(const std::shared_ptr<Mat3> &mat) {
       Kore::mat3 sum =  static_cast<Kore::mat3>(*static_cast<Matrix3Impl*>(this))+(static_cast<Kore::mat3>(*static_cast<Matrix3Impl*>(mat.get())));
       return std::make_shared<Matrix3Impl>(sum);
    }

    std::shared_ptr<Mat3> sub(const std::shared_ptr<Mat3> &mat) {
        Kore::mat3 sub =  static_cast<Kore::mat3>(*static_cast<Matrix3Impl*>(this))-(static_cast<Kore::mat3>(*static_cast<Matrix3Impl*>(mat.get())));
       return std::make_shared<Matrix3Impl>(sub);
    }

    std::shared_ptr<Mat3> multiply(float i) {
        Kore::mat3 mu =  static_cast<Kore::mat3>(*static_cast<Matrix3Impl*>(this))*i;
       return std::make_shared<Matrix3Impl>(mu);
    }

    std::shared_ptr<Mat3> clone() {
        return std::make_shared<Matrix3Impl>(static_cast<Kore::mat3*>(this)->Clone());
    }

    std::shared_ptr<Mat3> transpose() {
        return std::make_shared<Matrix3Impl>(static_cast<Kore::mat3*>(this)->Transpose());
    }

    std::shared_ptr<Mat3> transpose3x3() {
        return std::make_shared<Matrix3Impl>(static_cast<Kore::mat3*>(this)->Transpose3x3());
    }

    float trace() {
        return static_cast<Kore::mat3*>(this)->Trace();
    }

    float determinant() {
        return static_cast<Kore::mat3*>(this)->Determinant();
    }

    static std::shared_ptr<Mat3> linearInterpolate(const std::shared_ptr<Mat3> &a, const std::shared_ptr<Mat3> &b, float prop)
    {
        return std::make_shared<Matrix3Impl>(Kore::mat3::linearInterpolate(*static_cast<Matrix3Impl *>(a.get()), *static_cast<Matrix3Impl *>(b.get()), prop));
    }
};
typedef Matrix3Impl mat3;
} // namespace nok