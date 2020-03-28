#pragma once

#include "nok/mat2.hpp"
#include "Kore/Math/Matrix.h"

namespace nok
{
template <class T>
class Matrix2x3 : public nok::Mat2, public Kore::Matrix<2U, 3U, T>
{
public:
    Matrix2x3() : nok::Mat2(), Kore::Matrix<2U, 3U, T>(){};
    Matrix2x3(Matrix2x3 *mat) : nok::Mat2(), Kore::Matrix<2U, 3U, T>(*static_cast<Matrix2x3 *>(mat)){};
    ~Matrix2x3(){};

    float get(float row, float col)
    {
        return static_cast<Kore::Matrix<2U, 3U, T> *>(this)->get(row, col);
    }

    void set(float row, float col, float v)
    {
        static_cast<Kore::Matrix<2U, 3U, T> *>(this)->Set(row, col, v);
    }

    static std::shared_ptr<Mat2> orthogonalProjection(float left, float right, float bottom, float top, float zn, float zf)
    {
        return std::make_shared<Matrix2x3<T>>(Kore::Matrix<2U, 3U, T>::orthogonalProjection(left, right, bottom, top, zn, zf));
    }

    static std::shared_ptr<Mat2> perspective(float left, float right, float top, float bottom, float near, float far)
    {
        return std::make_shared<Matrix2x3<T>>(Kore::Matrix<2U, 3U, T>::Perspective(left, right, top, bottom, near, far));
    }

    static std::shared_ptr<Mat2> perspectiveFOV(float fov, float aspect, float near, float far)
    {
        return std::make_shared<Matrix2x3<T>>(Kore::Matrix<2U, 3U, T>::Perspective(fov, aspect, near, far));
    }

    static std::shared_ptr<Mat2> lookAt(const std::shared_ptr<Vec3> &eye, const std::shared_ptr<Vec3> &at, const std::shared_ptr<Vec3> &up)
    {
    }

    static std::shared_ptr<Mat2> lookAlong(const std::shared_ptr<Vec3> &axis, const std::shared_ptr<Vec3> &eye, const std::shared_ptr<Vec3> &up)
    {
    }

    static std::shared_ptr<Mat2> translation(float x, float y)
    {
        return std::make_shared<Matrix2x3<T>>(Kore::Matrix<2U, 3U, T>::Translation(x, y));
    }

    static std::shared_ptr<Mat2> movement(float x, float y, float z)
    {
        return std::make_shared<Matrix2x3<T>>(Kore::Matrix<2U, 3U, T>::Movement(x, y, z));
    }

    static std::shared_ptr<Mat2> identity()
    {
        return std::make_shared<Matrix2x3<T>>(Kore::Matrix<2U, 3U, T>::Identity());
    }

    static std::shared_ptr<Mat2> scale(float scale)
    {
        return std::make_shared<Matrix2x3<T>>(Kore::Matrix<2U, 3U, T>::Scale(scale));
    }

    static std::shared_ptr<Mat2> rotationX(float alpha)
    {
        return std::make_shared<Matrix2x3<T>>(Kore::Matrix<2U, 3U, T>::RotationX(alpha));
    }

    static std::shared_ptr<Mat2> rotationY(float alpha)
    {
        return std::make_shared<Matrix2x3<T>>(Kore::Matrix<2U, 3U, T>::RotationY(alpha));
    }

    static std::shared_ptr<Mat2> rotationZ(float alpha)
    {
        return std::make_shared<Matrix2x3<T>>(Kore::Matrix<2U, 3U, T>::RotationZ(alpha));
    }

    static std::shared_ptr<Mat2> rotation(float yaw, float pitch, float roll)
    {
        return std::make_shared<Matrix2x3<T>>(Kore::Matrix<2U, 3U, T>::Rotation(yaw, pitch, roll));
    }

    static std::shared_ptr<Mat2> create()
    {
        return std::make_shared<Matrix2x3<T>>();
    }

    static std::shared_ptr<Mat2> from(const std::shared_ptr<Mat2> &mat)
    {
        return std::make_shared<Matrix2x3<T>>(new Kore::Matrix<2U, 3U, T>(*static_cast<Matrix2x3 *>(mat.get())));
    }

    std::shared_ptr<Mat2> add(const std::shared_ptr<Mat2> &mat)
    {
        Kore::Matrix<2U, 3U, T> sum = static_cast<Kore::Matrix<2U, 3U, T>>(*static_cast<Matrix2x3 *>(this)) + (static_cast<Kore::Matrix<2U, 3U, T>>(*static_cast<Matrix2x3 *>(mat.get())));
        return std::make_shared<Matrix2x3<T>>(sum);
    }

    std::shared_ptr<Mat2> sub(const std::shared_ptr<Mat2> &mat)
    {
        Kore::Matrix<2U, 3U, T> sub = static_cast<Kore::Matrix<2U, 3U, T>>(*static_cast<Matrix2x3 *>(this)) - (static_cast<Kore::Matrix<2U, 3U, T>>(*static_cast<Matrix2x3 *>(mat.get())));
        return std::make_shared<Matrix2x3<T>>(sub);
    }

    std::shared_ptr<Mat2> multiply(float i)
    {
        Kore::Matrix<2U, 3U, T> mu = static_cast<Kore::Matrix<2U, 3U, T>>(*static_cast<Matrix2x3 *>(this)) * i;
        return std::make_shared<Matrix2x3<T>>(mu);
    }

    std::shared_ptr<Mat2> clone()
    {
        return std::make_shared<Matrix2x3<T>>(static_cast<Kore::Matrix<2U, 3U, T> *>(this)->Clone());
    }

    std::shared_ptr<Mat2> transpose()
    {
        return std::make_shared<Matrix2x3<T>>(static_cast<Kore::Matrix<2U, 3U, T> *>(this)->Transpose());
    }

    std::shared_ptr<Mat2> transpose3x3()
    {
        return std::make_shared<Matrix2x3<T>>(static_cast<Kore::Matrix<2U, 3U, T> *>(this)->Transpose3x3());
    }

    float trace()
    {
        return static_cast<Kore::Matrix<2U, 3U, T> *>(this)->Trace();
    }

    float determinant()
    {
        return static_cast<Kore::Matrix<2U, 3U, T> *>(this)->Determinant();
    }

    static std::shared_ptr<Mat2> linearInterpolate(const std::shared_ptr<Mat2> &a, const std::shared_ptr<Mat2> &b, float prop)
    {
        return std::make_shared<Matrix2x3<T>>(Kore::Matrix<2U, 3U, T>::linearInterpolate(*static_cast<Matrix2x3 *>(a.get()), *static_cast<Matrix2x3 *>(b.get()), prop));
    }
};


typedef Matrix2x3<float> mat2x3;
typedef Matrix2x3<double> mat2x3d;
} // namespace nok