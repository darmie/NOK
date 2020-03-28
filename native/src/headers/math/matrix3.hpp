#pragma once

#include "nok/mat3.hpp"
#include "Kore/Math/Matrix.h"

namespace nok
{
template<class T>
class Matrix3Impl : public nok::Mat3, public Kore::Matrix<3U, 3U, T>
{
public:
    Matrix3Impl() : nok::Mat3(), Kore::Matrix<3U, 3U, T>(){};
    Matrix3Impl(Matrix3Impl *mat) : nok::Mat3(), Kore::Matrix<3U, 3U, T>(*static_cast<Matrix3Impl *>(mat)){};
    ~Matrix3Impl(){};
    float get(float row, float col) {
        return static_cast<Kore::Matrix<3U, 3U, T> *>(this)->get(row, col);
    }

    void set(float row, float col, float v) {
        static_cast<Kore::Matrix<3U, 3U, T> *>(this)->Set(row, col, v);
    }

    static std::shared_ptr<Mat3> orthogonalProjection(float left, float right, float bottom, float top, float zn, float zf)
    {
        return std::make_shared<Matrix3Impl<T>>(Kore::Matrix<3U, 3U, T>::orthogonalProjection(left, right, bottom, top, zn, zf));
    }

    static std::shared_ptr<Mat3> perspective(float left, float right, float top, float bottom, float near, float far)
    {
        return std::make_shared<Matrix3Impl<T>>(Kore::Matrix<3U, 3U, T>::Perspective(left, right, top, bottom, near, far));
    }

    static std::shared_ptr<Mat3> perspectiveFOV(float fov, float aspect, float near, float far)
    {
        return std::make_shared<Matrix3Impl<T>>(Kore::Matrix<3U, 3U, T>::Perspective(fov, aspect, near, far));
    }

    static std::shared_ptr<Mat3> lookAt(const std::shared_ptr<Vec3i> &eye, const std::shared_ptr<Vec3i> &at, const std::shared_ptr<Vec3i> &up)
    {
    }

    static std::shared_ptr<Mat3> lookAlong(const std::shared_ptr<Vec3i> &axis, const std::shared_ptr<Vec3i> &eye, const std::shared_ptr<Vec3i> &up)
    {
    }

    static std::shared_ptr<Mat3> translation(float x, float y)
    {
        return std::make_shared<Matrix3Impl<T>>(Kore::Matrix<3U, 3U, T>::Translation(x, y));
    }

    static std::shared_ptr<Mat3> movement(float x, float y, float z)
    {
        return std::make_shared<Matrix3Impl<T>>(Kore::Matrix<3U, 3U, T>::Movement(x, y, z));
    }

    static std::shared_ptr<Mat3> identity()
    {
        return std::make_shared<Matrix3Impl<T>>(Kore::Matrix<3U, 3U, T>::Identity());
    }

    static std::shared_ptr<Mat3> scale(float scale)
    {
        return std::make_shared<Matrix3Impl<T>>(Kore::Matrix<3U, 3U, T>::Scale(scale));
    }

    static std::shared_ptr<Mat3> rotationX(float alpha)
    {
        return std::make_shared<Matrix3Impl<T>>(Kore::Matrix<3U, 3U, T>::RotationX(alpha));
    }

    static std::shared_ptr<Mat3> rotationY(float alpha)
    {
        return std::make_shared<Matrix3Impl<T>>(Kore::Matrix<3U, 3U, T>::RotationY(alpha));
    }

    static std::shared_ptr<Mat3> rotationZ(float alpha)
    {
        return std::make_shared<Matrix3Impl<T>>(Kore::Matrix<3U, 3U, T>::RotationZ(alpha));
    }

    static std::shared_ptr<Mat3> rotation(float yaw, float pitch, float roll)
    {
        return std::make_shared<Matrix3Impl<T>>(Kore::Matrix<3U, 3U, T>::Rotation(yaw, pitch, roll));
    }

    static std::shared_ptr<Mat3> create()
    {
        return std::make_shared<Matrix3Impl<T>>();
    }

    static std::shared_ptr<Mat3> from(const std::shared_ptr<Mat3> &mat)
    {
        return std::make_shared<Matrix3Impl<T>>(new Kore::Matrix<3U, 3U, T>(*static_cast<Matrix3Impl *>(mat.get())));
    }

    std::shared_ptr<Mat3> add(const std::shared_ptr<Mat3> &mat)
    {
        Kore::Matrix<3U, 3U, T> sum = static_cast<Kore::Matrix<3U, 3U, T>>(*static_cast<Matrix3Impl *>(this)) + (static_cast<Kore::Matrix<3U, 3U, T>>(*static_cast<Matrix3Impl *>(mat.get())));
        return std::make_shared<Matrix3Impl<T>>(sum);
    }

    std::shared_ptr<Mat3> sub(const std::shared_ptr<Mat3> &mat)
    {
        Kore::Matrix<3U, 3U, T> sub = static_cast<Kore::Matrix<3U, 3U, T>>(*static_cast<Matrix3Impl *>(this)) - (static_cast<Kore::Matrix<3U, 3U, T>>(*static_cast<Matrix3Impl *>(mat.get())));
        return std::make_shared<Matrix3Impl<T>>(sub);
    }

    std::shared_ptr<Mat3> multiply(float i)
    {
        Kore::Matrix<3U, 3U, T> mu = static_cast<Kore::Matrix<3U, 3U, T>>(*static_cast<Matrix3Impl *>(this)) * i;
        return std::make_shared<Matrix3Impl<T>>(mu);
    }

    std::shared_ptr<Mat3> clone()
    {
        return std::make_shared<Matrix3Impl<T>>(static_cast<Kore::Matrix<3U, 3U, T> *>(this)->Clone());
    }

    std::shared_ptr<Mat3> transpose()
    {
        return std::make_shared<Matrix3Impl<T>>(static_cast<Kore::Matrix<3U, 3U, T> *>(this)->Transpose());
    }

    std::shared_ptr<Mat3> transpose3x3()
    {
        return std::make_shared<Matrix3Impl<T>>(static_cast<Kore::Matrix<3U, 3U, T> *>(this)->Transpose3x3());
    }

    float trace()
    {
        return static_cast<Kore::Matrix<3U, 3U, T> *>(this)->Trace();
    }

    float determinant()
    {
        return static_cast<Kore::Matrix<3U, 3U, T> *>(this)->Determinant();
    }

    static std::shared_ptr<Mat3> linearInterpolate(const std::shared_ptr<Mat3> &a, const std::shared_ptr<Mat3> &b, float prop)
    {
        return std::make_shared<Matrix3Impl<T>>(Kore::Matrix<3U, 3U, T>::linearInterpolate(*static_cast<Matrix3Impl *>(a.get()), *static_cast<Matrix3Impl *>(b.get()), prop));
    }
};
typedef Matrix3Impl<float> mat3;
typedef Matrix3Impl<double> mat3d;
} // namespace nok