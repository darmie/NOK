#pragma once

#include "nok/mat3.hpp"
#include "Kore/Math/Matrix.h"

namespace nok
{
template<class T>
class Matrix3x2 : public nok::Mat3, public Kore::Matrix<3U, 2U, T>
{
public:
    Matrix3x2() : nok::Mat3(), Kore::Matrix<3U, 2U, T>(){};
    Matrix3x2(Matrix3x2 *mat) : nok::Mat3(), Kore::Matrix<3U, 2U, T>(*static_cast<Matrix3x2 *>(mat)){};
    ~Matrix3x2(){};
    float get(float row, float col) {
        return static_cast<Kore::Matrix<3U, 2U, T> *>(this)->get(row, col);
    }

    void set(float row, float col, float v) {
        static_cast<Kore::Matrix<3U, 2U, T> *>(this)->Set(row, col, v);
    }

    static std::shared_ptr<Mat3> orthogonalProjection(float left, float right, float bottom, float top, float zn, float zf)
    {
        return std::make_shared<Matrix3x2<T>>(Kore::Matrix<3U, 2U, T>::orthogonalProjection(left, right, bottom, top, zn, zf));
    }

    static std::shared_ptr<Mat3> perspective(float left, float right, float top, float bottom, float near, float far)
    {
        return std::make_shared<Matrix3x2<T>>(Kore::Matrix<3U, 2U, T>::Perspective(left, right, top, bottom, near, far));
    }

    static std::shared_ptr<Mat3> perspectiveFOV(float fov, float aspect, float near, float far)
    {
        return std::make_shared<Matrix3x2<T>>(Kore::Matrix<3U, 2U, T>::Perspective(fov, aspect, near, far));
    }

    static std::shared_ptr<Mat3> lookAt(const std::shared_ptr<Vec3> &eye, const std::shared_ptr<Vec3> &at, const std::shared_ptr<Vec3> &up)
    {
    }

    static std::shared_ptr<Mat3> lookAlong(const std::shared_ptr<Vec3> &axis, const std::shared_ptr<Vec3> &eye, const std::shared_ptr<Vec3> &up)
    {
    }

    static std::shared_ptr<Mat3> translation(float x, float y)
    {
        return std::make_shared<Matrix3x2<T>>(Kore::Matrix<3U, 2U, T>::Translation(x, y));
    }

    static std::shared_ptr<Mat3> movement(float x, float y, float z)
    {
        return std::make_shared<Matrix3x2<T>>(Kore::Matrix<3U, 2U, T>::Movement(x, y, z));
    }

    static std::shared_ptr<Mat3> identity()
    {
        return std::make_shared<Matrix3x2<T>>(Kore::Matrix<3U, 2U, T>::Identity());
    }

    static std::shared_ptr<Mat3> scale(float scale)
    {
        return std::make_shared<Matrix3x2<T>>(Kore::Matrix<3U, 2U, T>::Scale(scale));
    }

    static std::shared_ptr<Mat3> rotationX(float alpha)
    {
        return std::make_shared<Matrix3x2<T>>(Kore::Matrix<3U, 2U, T>::RotationX(alpha));
    }

    static std::shared_ptr<Mat3> rotationY(float alpha)
    {
        return std::make_shared<Matrix3x2<T>>(Kore::Matrix<3U, 2U, T>::RotationY(alpha));
    }

    static std::shared_ptr<Mat3> rotationZ(float alpha)
    {
        return std::make_shared<Matrix3x2<T>>(Kore::Matrix<3U, 2U, T>::RotationZ(alpha));
    }

    static std::shared_ptr<Mat3> rotation(float yaw, float pitch, float roll)
    {
        return std::make_shared<Matrix3x2<T>>(Kore::Matrix<3U, 2U, T>::Rotation(yaw, pitch, roll));
    }

    static std::shared_ptr<Mat3> create()
    {
        return std::make_shared<Matrix3x2<T>>();
    }

    static std::shared_ptr<Mat3> from(const std::shared_ptr<Mat3> &mat)
    {
        return std::make_shared<Matrix3x2<T>>(new Kore::Matrix<3U, 2U, T>(*static_cast<Matrix3x2 *>(mat.get())));
    }

    std::shared_ptr<Mat3> add(const std::shared_ptr<Mat3> &mat)
    {
        Kore::Matrix<3U, 2U, T> sum = static_cast<Kore::Matrix<3U, 2U, T>>(*static_cast<Matrix3x2 *>(this)) + (static_cast<Kore::Matrix<3U, 2U, T>>(*static_cast<Matrix3x2 *>(mat.get())));
        return std::make_shared<Matrix3x2<T>>(sum);
    }

    std::shared_ptr<Mat3> sub(const std::shared_ptr<Mat3> &mat)
    {
        Kore::Matrix<3U, 2U, T> sub = static_cast<Kore::Matrix<3U, 2U, T>>(*static_cast<Matrix3x2 *>(this)) - (static_cast<Kore::Matrix<3U, 2U, T>>(*static_cast<Matrix3x2 *>(mat.get())));
        return std::make_shared<Matrix3x2<T>>(sub);
    }

    std::shared_ptr<Mat3> multiply(float i)
    {
        Kore::Matrix<3U, 2U, T> mu = static_cast<Kore::Matrix<3U, 2U, T>>(*static_cast<Matrix3x2 *>(this)) * i;
        return std::make_shared<Matrix3x2<T>>(mu);
    }

    std::shared_ptr<Mat3> clone()
    {
        return std::make_shared<Matrix3x2<T>>(static_cast<Kore::Matrix<3U, 2U, T> *>(this)->Clone());
    }

    std::shared_ptr<Mat3> transpose()
    {
        return std::make_shared<Matrix3x2<T>>(static_cast<Kore::Matrix<3U, 2U, T> *>(this)->Transpose());
    }

    std::shared_ptr<Mat3> transpose3x3()
    {
        return std::make_shared<Matrix3x2<T>>(static_cast<Kore::Matrix<3U, 2U, T> *>(this)->Transpose3x3());
    }

    float trace()
    {
        return static_cast<Kore::Matrix<3U, 2U, T> *>(this)->Trace();
    }

    float determinant()
    {
        return static_cast<Kore::Matrix<3U, 2U, T> *>(this)->Determinant();
    }

    static std::shared_ptr<Mat3> linearInterpolate(const std::shared_ptr<Mat3> &a, const std::shared_ptr<Mat3> &b, float prop)
    {
        return std::make_shared<Matrix3x2<T>>(Kore::Matrix<3U, 2U, T>::linearInterpolate(*static_cast<Matrix3x2 *>(a.get()), *static_cast<Matrix3x2 *>(b.get()), prop));
    }
};
typedef Matrix3x2<float> mat3x2;
typedef Matrix3x2<double> mat3x2d;
} // namespace nok