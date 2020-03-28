#pragma once

#include "nok/mat2.hpp"
#include "Kore/Math/Matrix.h"

namespace nok
{
template <class T>
class Matrix2 : public nok::Mat2, public Kore::Matrix<2U, 2U, T>
{
public:
    Matrix2() : nok::Mat2(), Kore::Matrix<2U, 2U, T>(){};
    Matrix2(Matrix2 *mat) : nok::Mat2(), Kore::Matrix<2U, 2U, T>(*static_cast<Matrix2 *>(mat)){};
    ~Matrix2(){};

    float get(float row, float col)
    {
        return static_cast<Kore::Matrix<2U, 2U, T> *>(this)->get(row, col);
    }

    void set(float row, float col, float v)
    {
        static_cast<Kore::Matrix<2U, 2U, T> *>(this)->Set(row, col, v);
    }

    static std::shared_ptr<Mat2> orthogonalProjection(float left, float right, float bottom, float top, float zn, float zf)
    {
        return std::make_shared<Matrix2<T>>(Kore::Matrix<2U, 2U, T>::orthogonalProjection(left, right, bottom, top, zn, zf));
    }

    static std::shared_ptr<Mat2> perspective(float left, float right, float top, float bottom, float near, float far)
    {
        return std::make_shared<Matrix2<T>>(Kore::Matrix<2U, 2U, T>::Perspective(left, right, top, bottom, near, far));
    }

    static std::shared_ptr<Mat2> perspectiveFOV(float fov, float aspect, float near, float far)
    {
        return std::make_shared<Matrix2<T>>(Kore::Matrix<2U, 2U, T>::Perspective(fov, aspect, near, far));
    }

    static std::shared_ptr<Mat2> lookAt(const std::shared_ptr<Vec3i> &eye, const std::shared_ptr<Vec3i> &at, const std::shared_ptr<Vec3i> &up)
    {
    }

    static std::shared_ptr<Mat2> lookAlong(const std::shared_ptr<Vec3i> &axis, const std::shared_ptr<Vec3i> &eye, const std::shared_ptr<Vec3i> &up)
    {
    }

    static std::shared_ptr<Mat2> translation(float x, float y)
    {
        return std::make_shared<Matrix2<T>>(Kore::Matrix<2U, 2U, T>::Translation(x, y));
    }

    static std::shared_ptr<Mat2> movement(float x, float y, float z)
    {
        return std::make_shared<Matrix2<T>>(Kore::Matrix<2U, 2U, T>::Movement(x, y, z));
    }

    static std::shared_ptr<Mat2> identity()
    {
        return std::make_shared<Matrix2<T>>(Kore::Matrix<2U, 2U, T>::Identity());
    }

    static std::shared_ptr<Mat2> scale(float scale)
    {
        return std::make_shared<Matrix2<T>>(Kore::Matrix<2U, 2U, T>::Scale(scale));
    }

    static std::shared_ptr<Mat2> rotationX(float alpha)
    {
        return std::make_shared<Matrix2<T>>(Kore::Matrix<2U, 2U, T>::RotationX(alpha));
    }

    static std::shared_ptr<Mat2> rotationY(float alpha)
    {
        return std::make_shared<Matrix2<T>>(Kore::Matrix<2U, 2U, T>::RotationY(alpha));
    }

    static std::shared_ptr<Mat2> rotationZ(float alpha)
    {
        return std::make_shared<Matrix2<T>>(Kore::Matrix<2U, 2U, T>::RotationZ(alpha));
    }

    static std::shared_ptr<Mat2> rotation(float yaw, float pitch, float roll)
    {
        return std::make_shared<Matrix2<T>>(Kore::Matrix<2U, 2U, T>::Rotation(yaw, pitch, roll));
    }

    static std::shared_ptr<Mat2> create()
    {
        return std::make_shared<Matrix2<T>>();
    }

    static std::shared_ptr<Mat2> from(const std::shared_ptr<Mat2> &mat)
    {
        return std::make_shared<Matrix2<T>>(new Kore::Matrix<2U, 2U, T>(*static_cast<Matrix2 *>(mat.get())));
    }

    std::shared_ptr<Mat2> add(const std::shared_ptr<Mat2> &mat)
    {
        Kore::Matrix<2U, 2U, T> sum = static_cast<Kore::Matrix<2U, 2U, T>>(*static_cast<Matrix2 *>(this)) + (static_cast<Kore::Matrix<2U, 2U, T>>(*static_cast<Matrix2 *>(mat.get())));
        return std::make_shared<Matrix2<T>>(sum);
    }

    std::shared_ptr<Mat2> sub(const std::shared_ptr<Mat2> &mat)
    {
        Kore::Matrix<2U, 2U, T> sub = static_cast<Kore::Matrix<2U, 2U, T>>(*static_cast<Matrix2 *>(this)) - (static_cast<Kore::Matrix<2U, 2U, T>>(*static_cast<Matrix2 *>(mat.get())));
        return std::make_shared<Matrix2<T>>(sub);
    }

    std::shared_ptr<Mat2> multiply(float i)
    {
        Kore::Matrix<2U, 2U, T> mu = static_cast<Kore::Matrix<2U, 2U, T>>(*static_cast<Matrix2 *>(this)) * i;
        return std::make_shared<Matrix2<T>>(mu);
    }

    std::shared_ptr<Mat2> clone()
    {
        return std::make_shared<Matrix2<T>>(static_cast<Kore::Matrix<2U, 2U, T> *>(this)->Clone());
    }

    std::shared_ptr<Mat2> transpose()
    {
        return std::make_shared<Matrix2<T>>(static_cast<Kore::Matrix<2U, 2U, T> *>(this)->Transpose());
    }

    std::shared_ptr<Mat2> transpose3x3()
    {
        return std::make_shared<Matrix2<T>>(static_cast<Kore::Matrix<2U, 2U, T> *>(this)->Transpose3x3());
    }

    float trace()
    {
        return static_cast<Kore::Matrix<2U, 2U, T> *>(this)->Trace();
    }

    float determinant()
    {
        return static_cast<Kore::Matrix<2U, 2U, T> *>(this)->Determinant();
    }

    static std::shared_ptr<Mat2> linearInterpolate(const std::shared_ptr<Mat2> &a, const std::shared_ptr<Mat2> &b, float prop)
    {
        return std::make_shared<Matrix2<T>>(Kore::Matrix<2U, 2U, T>::linearInterpolate(*static_cast<Matrix2 *>(a.get()), *static_cast<Matrix2 *>(b.get()), prop));
    }
};

typedef Matrix2<float> mat2;
typedef Matrix2<double> mat2d;
} // namespace nok