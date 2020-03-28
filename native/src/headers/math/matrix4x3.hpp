#pragma once

#include "nok/mat4.hpp"
#include "Kore/Math/Matrix.h"

namespace nok
{

template <class T>
class Matrix4x3 : public nok::Mat4, public Kore::Matrix<4U, 3U, T>
{
public:
    Matrix4x3() : nok::Mat4(), Kore::Matrix<4U, 3U, T>(){};
    Matrix4x3(Matrix4x3<T> *mat) : nok::Mat4(), Kore::Matrix<4U, 3U, T>(*static_cast<Kore::Matrix<4U, 3U, T> *>(mat)){};
    ~Matrix4x3(){};
    float get(float row, float col)
    {
        return static_cast<Kore::Matrix<4U, 3U, T> *>(this)->get(row, col);
    }

    void set(float row, float col, float v)
    {
        static_cast<Kore::Matrix<4U, 3U, T> *>(this)->Set(row, col, v);
    }

    static std::shared_ptr<Mat4> orthogonalProjection(float left, float right, float bottom, float top, float zn, float zf)
    {
        return std::make_shared<Matrix4x3<T>>(Kore::Matrix<4U, 3U, T>::orthogonalProjection(left, right, bottom, top, zn, zf));
    }

    static std::shared_ptr<Mat4> perspective(float left, float right, float top, float bottom, float near, float far)
    {
        return std::make_shared<Matrix4x3<T>>(Kore::Matrix<4U, 3U, T>::Perspective(left, right, top, bottom, near, far));
    }

    static std::shared_ptr<Mat4> perspectiveFOV(float fov, float aspect, float near, float far)
    {
        return std::make_shared<Matrix4x3<T>>(Kore::Matrix<4U, 3U, T>::Perspective(fov, aspect, near, far));
    }

    static std::shared_ptr<Mat4> lookAt(const std::shared_ptr<Vec3> &eye, const std::shared_ptr<Vec3> &at, const std::shared_ptr<Vec3> &up)
    {
    }

    static std::shared_ptr<Mat4> lookAlong(const std::shared_ptr<Vec3> &axis, const std::shared_ptr<Vec3> &eye, const std::shared_ptr<Vec3> &up)
    {
    }

    static std::shared_ptr<Mat4> translation(float x, float y)
    {
        return std::make_shared<Matrix4x3<T>>(Kore::Matrix<4U, 3U, T>::Translation(x, y));
    }

    static std::shared_ptr<Mat4> movement(float x, float y, float z)
    {
        return std::make_shared<Matrix4x3<T>>(Kore::Matrix<4U, 3U, T>::Movement(x, y, z));
    }

    static std::shared_ptr<Mat4> identity()
    {
        return std::make_shared<Matrix4x3<T>>(Kore::Matrix<4U, 3U, T>::Identity());
    }

    static std::shared_ptr<Mat4> scale(float scale)
    {
        return std::make_shared<Matrix4x3<T>>(Kore::Matrix<4U, 3U, T>::Scale(scale));
    }

    static std::shared_ptr<Mat4> rotationX(float alpha)
    {
        return std::make_shared<Matrix4x3<T>>(Kore::Matrix<4U, 3U, T>::RotationX(alpha));
    }

    static std::shared_ptr<Mat4> rotationY(float alpha)
    {
        return std::make_shared<Matrix4x3<T>>(Kore::Matrix<4U, 3U, T>::RotationY(alpha));
    }

    static std::shared_ptr<Mat4> rotationZ(float alpha)
    {
        return std::make_shared<Matrix4x3<T>>(Kore::Matrix<4U, 3U, T>::RotationZ(alpha));
    }

    static std::shared_ptr<Mat4> rotation(float yaw, float pitch, float roll)
    {
        return std::make_shared<Matrix4x3<T>>(Kore::Matrix<4U, 3U, T>::Rotation(yaw, pitch, roll));
    }

    static std::shared_ptr<Mat4> create()
    {
        return std::make_shared<Matrix4x3<T>>();
    }

    static std::shared_ptr<Mat4> from(const std::shared_ptr<Mat4> &mat)
    {
        return std::make_shared<Matrix4x3<T>>(new Kore::Matrix<4U, 3U, T>(*static_cast<Matrix4x3 *>(mat.get())));
    }

    std::shared_ptr<Mat4> add(const std::shared_ptr<Mat4> &mat)
    {
        Kore::Matrix<4U, 3U, T> sum = static_cast<Kore::Matrix<4U, 3U, T>>(*static_cast<Matrix4x3 *>(this)) + (static_cast<Kore::Matrix<4U, 3U, T>>(*static_cast<Matrix4x3 *>(mat.get())));
        return std::make_shared<Matrix4x3<T>>(sum);
    }

    std::shared_ptr<Mat4> sub(const std::shared_ptr<Mat4> &mat)
    {
        Kore::Matrix<4U, 3U, T> sub = static_cast<Kore::Matrix<4U, 3U, T>>(*static_cast<Matrix4x3 *>(this)) - (static_cast<Kore::Matrix<4U, 3U, T>>(*static_cast<Matrix4x3 *>(mat.get())));
        return std::make_shared<Matrix4x3<T>>(sub);
    }

    std::shared_ptr<Mat4> multiply(float i)
    {
        Kore::Matrix<4U, 3U, T> mu = static_cast<Kore::Matrix<4U, 3U, T>>(*static_cast<Matrix4x3 *>(this)) * i;
        return std::make_shared<Matrix4x3<T>>(mu);
    }

    std::shared_ptr<Mat4> clone()
    {
        return std::make_shared<Matrix4x3<T>>(static_cast<Kore::Matrix<4U, 3U, T> *>(this)->Clone());
    }

    std::shared_ptr<Mat4> transpose()
    {
        return std::make_shared<Matrix4x3<T>>(static_cast<Kore::Matrix<4U, 3U, T> *>(this)->Transpose());
    }

    std::shared_ptr<Mat4> transpose3x3()
    {
        return std::make_shared<Matrix4x3<T>>(static_cast<Kore::Matrix<4U, 3U, T> *>(this)->Transpose3x3());
    }

    float trace()
    {
        return static_cast<Kore::Matrix<4U, 3U, T> *>(this)->Trace();
    }

    float determinant()
    {
        return static_cast<Kore::Matrix<4U, 3U, T> *>(this)->Determinant();
    }

    static std::shared_ptr<Mat4> linearInterpolate(const std::shared_ptr<Mat4> &a, const std::shared_ptr<Mat4> &b, float prop)
    {
        return std::make_shared<Matrix4x3<T>>(Kore::Matrix<4U, 3U, T>::linearInterpolate(*static_cast<Matrix4x3 *>(a.get()), *static_cast<Matrix4x3 *>(b.get()), prop));
    }
};
typedef Matrix4x3<float> mat4x3;
typedef Matrix4x3<double> mat4x3d;
} // namespace nok