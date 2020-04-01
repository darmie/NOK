#pragma once

#include "nok/mat3.hpp"
#include "nok/mat3x4_module.hpp"
#include "Kore/Math/Matrix.h"
#include "source/jobqueue_impl.hpp"
#include "headers/math/Vector3.hpp"

class JavascriptMap;

namespace nok
{
template<class T>
class Matrix3x4 : public nok::Mat3, public nok::Mat3x4Module, public Kore::Matrix<3U, 4U, T>
{
private:
    std::shared_ptr<ReactBridge> mBridge;
    std::shared_ptr<JobQueueImpl> mQueue;
    std::shared_ptr<JobDispatcher> mDispatcher;
public:
    Matrix3x4() : nok::Mat3(), nok::Mat3x4Module(), Kore::Matrix<3U, 4U, T>(){};
    Matrix3x4(Matrix3x4 *mat) : nok::Mat3(), nok::Mat3x4Module(), Kore::Matrix<3U, 4U, T>(*static_cast<Matrix3x4 *>(mat)){};
    ~Matrix3x4(){};


    Matrix3x4(const std::shared_ptr<::ReactBridge> &bridge) : nok::Mat3(), nok::Mat3x4Module(), Kore::Matrix<3U, 4U, T>()
    {
        this->mBridge = bridge;

        mQueue = JobQueueImpl::create();
        mDispatcher = mBridge->createJobDispatcher(mQueue);
        mDispatcher->start();
    };

    static const float HEIGHT = 4;

    float get(float row, float col) {
        return static_cast<Kore::Matrix<3U, 4U, T> *>(this)->get(row, col);
    }

    void get(double row, double col, const std::shared_ptr<::JavascriptPromise> &promise)
    {
        promise->resolveDouble(get(row, col));
    }


    void set(float row, float col, float v) {
        static_cast<Kore::Matrix<3U, 4U, T> *>(this)->Set(row, col, v);
    }

    static std::shared_ptr<Mat3> orthogonalProjection(float left, float right, float bottom, float top, float zn, float zf)
    {
        return std::make_shared<Matrix3x4<T>>(Kore::Matrix<3U, 4U, T>::orthogonalProjection(left, right, bottom, top, zn, zf));
    }

    void orthogonalProjection(double left, double right, double bottom, double top, double zn, double zf, const std::shared_ptr<::JavascriptPromise> &promise)
    {
        auto nMat = std::make_shared<Matrix3x4<double>>(Matrix3x4::orthogonalProjection(left, right, bottom, top, zn, zf));

        nMat->toJavascriptArray(promise);
    }

    static std::shared_ptr<Mat3> perspective(float left, float right, float top, float bottom, float near, float far)
    {
        return std::make_shared<Matrix3x4<T>>(Kore::Matrix<3U, 4U, T>::Perspective(left, right, top, bottom, near, far));
    }

    void perspective(double left, double right, double top, double bottom, double near, double far, const std::shared_ptr<::JavascriptPromise> &promise)
    {
        auto nMat = std::make_shared<Matrix3x4<double>>(Matrix3x4::perspective(left, right, top, bottom, near, far));

        nMat->toJavascriptArray(promise);
    }

    static std::shared_ptr<Mat3> perspectiveFOV(float fov, float aspect, float near, float far)
    {
        return std::make_shared<Matrix3x4<T>>(Kore::Matrix<3U, 4U, T>::Perspective(fov, aspect, near, far));
    }

    void perspectiveFOV(double fov, double aspect, double near, double far, const std::shared_ptr<::JavascriptPromise> &promise)
    {
        auto nMat = std::make_shared<Matrix3x4<double>>(Matrix3x4::perspectiveFOV(fov, aspect, near, far));

        nMat->toJavascriptArray(promise);
    }

    static std::shared_ptr<Mat3> lookAt(const std::shared_ptr<Vec3> &eye, const std::shared_ptr<Vec3> &at, const std::shared_ptr<Vec3> &up)
    {
        Vector3<double> *nEye = static_cast<Vector3<double> *>(eye.get());
        Vector3<double> *nAt = static_cast<Vector3<double> *>(at.get());
        Vector3<double> *nUp = static_cast<Vector3<double> *>(up.get());

        return std::make_shared(static_cast<Matrix3x4 *> Kore::Matrix<3U, 4U, T>::lookAt(nEye, nAt, nUp));
    }

    void lookAt(const std::shared_ptr<::JavascriptMap> &eye, const std::shared_ptr<::JavascriptMap> &at, const std::shared_ptr<::JavascriptMap> &up, const std::shared_ptr<::JavascriptPromise> &promise)
    {
        auto nEye = std::make_shared<nok::Vector3<double>>(eye->getDouble("x"), eye->getDouble("y"), eye->getDouble("z"));
        auto nAt = std::make_shared<nok::Vector3<double>>(at->getDouble("x"), at->getDouble("y"), at->getDouble("z"));
        auto nUp = std::make_shared<nok::Vector3<double>>(up->getDouble("x"), up->getDouble("y"), up->getDouble("z"));

        auto nMat = std::make_shared<Matrix3x4<double>>(Matrix3x4<double>::lookAt(nEye, nAt, nUp));

        nMat->toJavascriptArray(promise);
    }

    static std::shared_ptr<Mat3> lookAlong(const std::shared_ptr<Vec3> &axis, const std::shared_ptr<Vec3> &eye, const std::shared_ptr<Vec3> &up)
    {
        Vector3<double> *nAxis = static_cast<Vector3<double> *>(axis.get());
        Vector3<double> *nEye = static_cast<Vector3<double> *>(eye.get());
        Vector3<double> *nUp = static_cast<Vector3<double> *>(up.get());

        return std::make_shared(static_cast<Matrix3x4 *>(Kore::Matrix<3U, 4U, T>::lookAlong(nAxis, nEye, nUp)));
    }

    void lookAlong(const std::shared_ptr<::JavascriptMap> &axis, const std::shared_ptr<::JavascriptMap> &eye, const std::shared_ptr<::JavascriptMap> &up, const std::shared_ptr<::JavascriptPromise> &promise)
    {
        auto nEye = std::make_shared<nok::Vector3<double>>(eye->getDouble("x"), eye->getDouble("y"), eye->getDouble("z"));
        auto nAxis = std::make_shared<nok::Vector3<double>>(axis->getDouble("x"), axis->getDouble("y"), axis->getDouble("z"));
        auto nUp = std::make_shared<nok::Vector3<double>>(up->getDouble("x"), up->getDouble("y"), up->getDouble("z"));

        auto nMat = std::make_shared<Matrix3x4<double>>(Matrix3x4::lookAlong(nAxis, nEye, nUp));

        nMat->toJavascriptArray(promise);
    } 

    static std::shared_ptr<Mat3> translation(float x, float y)
    {
        return std::make_shared<Matrix3x4<T>>(Kore::Matrix<3U, 4U, T>::Translation(x, y));
    }

    void translation(double x, double y, const std::shared_ptr<::JavascriptPromise> &promise)
    {
        auto mat = std::make_shared<Matrix3x4<double>>(Matrix3x4<double>::translation(x, y));

        mat->toJavascriptArray(promise);
    }

    static std::shared_ptr<Mat3> movement(float x, float y, float z)
    {
        return std::make_shared<Matrix3x4<T>>(Kore::Matrix<3U, 4U, T>::Movement(x, y, z));
    }

    void movement(double x, double y, double z, const std::shared_ptr<::JavascriptPromise> &promise)
    {
        auto mat = std::make_shared<Matrix3x4<double>>(Matrix3x4<double>::movement(x, y, z));

        mat->toJavascriptArray(promise);
    }

    static std::shared_ptr<Mat3> identity()
    {
        return std::make_shared<Matrix3x4<T>>(Kore::Matrix<3U, 4U, T>::Identity());
    }

    void identity(const std::shared_ptr<::JavascriptPromise> &promise)
    {
        auto mat = std::make_shared<Matrix3x4<double>>(Matrix3x4<double>::identity());

        mat->toJavascriptArray(promise);
    }

    static std::shared_ptr<Mat3> scale(float scale)
    {
        return std::make_shared<Matrix3x4<T>>(Kore::Matrix<3U, 4U, T>::Scale(scale));
    }

    void scale(double scale, const std::shared_ptr<::JavascriptPromise> &promise)
    {
        auto mat = std::make_shared<Matrix3x4<double>>(Matrix3x4<double>::scale(scale));

        mat->toJavascriptArray(promise);
    }

    static std::shared_ptr<Mat3> rotationX(float alpha)
    {
        return std::make_shared<Matrix3x4<T>>(Kore::Matrix<3U, 4U, T>::RotationX(alpha));
    }

    void rotationX(double alpha, const std::shared_ptr<::JavascriptPromise> &promise)
    {
        auto mat = std::make_shared<Matrix3x4<double>>(Matrix3x4<double>::rotationX(alpha));

        mat->toJavascriptArray(promise);
    }

    static std::shared_ptr<Mat3> rotationY(float alpha)
    {
        return std::make_shared<Matrix3x4<T>>(Kore::Matrix<3U, 4U, T>::RotationY(alpha));
    }

    void rotationY(double alpha, const std::shared_ptr<::JavascriptPromise> &promise)
    {
        auto mat = std::make_shared<Matrix3x4<double>>(Matrix3x4<double>::rotationY(alpha));

        mat->toJavascriptArray(promise);
    }

    static std::shared_ptr<Mat3> rotationZ(float alpha)
    {
        return std::make_shared<Matrix3x4<T>>(Kore::Matrix<3U, 4U, T>::RotationZ(alpha));
    }

    void rotationZ(double alpha, const std::shared_ptr<::JavascriptPromise> &promise)
    {
        auto mat = std::make_shared<Matrix3x4<double>>(Matrix3x4<double>::rotationZ(alpha));

        mat->toJavascriptArray(promise);
    }

    static std::shared_ptr<Mat3> rotation(float yaw, float pitch, float roll)
    {
        return std::make_shared<Matrix3x4<T>>(Kore::Matrix<3U, 4U, T>::Rotation(yaw, pitch, roll));
    }

    void rotation(double yaw, double pitch, double roll, const std::shared_ptr<::JavascriptPromise> &promise)
    {
        auto mat = std::make_shared<Matrix3x4<double>>(Matrix3x4<double>::rotation(yaw, pitch, roll));

        mat->toJavascriptArray(promise);
    }

    static std::shared_ptr<Mat3> create()
    {
        return std::make_shared<Matrix3x4<T>>();
    }

    static std::shared_ptr<Mat3> from(const std::shared_ptr<Mat3> &mat)
    {
        return std::make_shared<Matrix3x4<T>>(new Kore::Matrix<3U, 4U, T>(*static_cast<Matrix3x4 *>(mat.get())));
    }

    void from(const std::shared_ptr<::JavascriptArray> &mat, const std::shared_ptr<::JavascriptPromise> &promise)
    {
        auto xmat = Matrix3x4<double>::toNativeArray(mat);
        auto _mat = std::make_shared<Matrix3x4<double>>(Matrix3x4<double>::from(xmat));

        _mat->toJavascriptArray(promise);
    }

    std::shared_ptr<Mat3> add(const std::shared_ptr<Mat3> &mat)
    {
        Kore::Matrix<3U, 4U, T> sum = static_cast<Kore::Matrix<3U, 4U, T>>(*static_cast<Matrix3x4 *>(this)) + (static_cast<Kore::Matrix<3U, 4U, T>>(*static_cast<Matrix3x4 *>(mat.get())));
        return std::make_shared<Matrix3x4<T>>(sum);
    }

    void add(const std::shared_ptr<::JavascriptArray> &mat, const std::shared_ptr<::JavascriptPromise> &promise)
    {
        auto xmat = Matrix3x4<double>::toNativeArray(mat);
        auto _mat = std::make_shared<Matrix3x4<double>>(this->add(xmat));

        _mat->toJavascriptArray(promise);
    }

    std::shared_ptr<Mat3> sub(const std::shared_ptr<Mat3> &mat)
    {
        Kore::Matrix<3U, 4U, T> sub = static_cast<Kore::Matrix<3U, 4U, T>>(*static_cast<Matrix3x4 *>(this)) - (static_cast<Kore::Matrix<3U, 4U, T>>(*static_cast<Matrix3x4 *>(mat.get())));
        return std::make_shared<Matrix3x4<T>>(sub);
    }

    void sub(const std::shared_ptr<::JavascriptArray> &mat, const std::shared_ptr<::JavascriptPromise> &promise)
    {
        auto xmat = Matrix3x4<double>::toNativeArray(mat);
        auto _mat = std::make_shared<Matrix3x4<double>>(this->sub(xmat));

        _mat->toJavascriptArray(promise);
    }

    std::shared_ptr<Mat3> multiply(float i)
    {
        Kore::Matrix<3U, 4U, T> mu = static_cast<Kore::Matrix<3U, 4U, T>>(*static_cast<Matrix3x4 *>(this)) * i;
        return std::make_shared<Matrix3x4<T>>(mu);
    }

    void multiply(double i, const std::shared_ptr<::JavascriptPromise> &promise)
    {
        auto mat = std::make_shared<Matrix3x4<double>>(this->multiply(i));

        mat->toJavascriptArray(promise);
    }

    std::shared_ptr<Mat3> clone()
    {
        return std::make_shared<Matrix3x4<T>>(static_cast<Kore::Matrix<3U, 4U, T> *>(this)->Clone());
    }

    void clone(const std::shared_ptr<::JavascriptPromise> &promise)
    {
        auto mat = std::make_shared<Matrix3x4<double>>(this->clone());

        mat->toJavascriptArray(promise);
    }

    std::shared_ptr<Mat3> transpose()
    {
        return std::make_shared<Matrix3x4<T>>(static_cast<Kore::Matrix<3U, 4U, T> *>(this)->Transpose());
    }

    void transpose(const std::shared_ptr<::JavascriptPromise> &promise)
    {
        auto mat = std::make_shared<Matrix3x4<double>>(this->transpose());

        mat->toJavascriptArray(promise);
    }

    std::shared_ptr<Mat3> transpose3x3()
    {
        return std::make_shared<Matrix3x4<T>>(static_cast<Kore::Matrix<3U, 4U, T> *>(this)->Transpose3x3());
    }

    void transpose3x3(const std::shared_ptr<::JavascriptPromise> &promise)
    {
        auto mat = std::make_shared<Matrix3x4<double>>(this->transpose3x3());

        mat->toJavascriptArray(promise);
    }

    float trace()
    {
        return static_cast<Kore::Matrix<3U, 4U, T> *>(this)->Trace();
    }

    void trace(const std::shared_ptr<::JavascriptPromise> &promise)
    {
        auto trace = this->trace();

        promise->resolveDouble(trace);
    }

    float determinant()
    {
        return static_cast<Kore::Matrix<3U, 4U, T> *>(this)->Determinant();
    }

    void determinant(const std::shared_ptr<::JavascriptPromise> &promise)
    {
        auto det = this->determinant();

        promise->resolveDouble(det);
    }

    static std::shared_ptr<Mat3> linearInterpolate(const std::shared_ptr<Mat3> &a, const std::shared_ptr<Mat3> &b, float prop)
    {
        return std::make_shared<Matrix3x4<T>>(Kore::Matrix<3U, 4U, T>::linearInterpolate(*static_cast<Matrix3x4 *>(a.get()), *static_cast<Matrix3x4 *>(b.get()), prop));
    }

    void linearInterpolate(const std::shared_ptr<::JavascriptArray> &a, const std::shared_ptr<::JavascriptArray> &b, double prop, const std::shared_ptr<::JavascriptPromise> &promise)
    {
        auto _a = Matrix3x4<double>::toNative(a);
        auto _b = Matrix3x4<double>::toNative(b);

        auto mat = std::make_shared<Matrix3x4<double>>(Matrix3x4<double>::linearInterpolate(_a, _b, prop));

        mat->toJavascriptArray(promise);
    }

    inline void toJavascriptArray(const std::shared_ptr<::JavascriptPromise> &promise)
    {
        auto mat = mBridge->createArray();
        auto arr = mBridge->createArray();
        for (unsigned x = 0; x < WIDTH; ++x)
        {
            mat->pushArray(arr);
            for (unsigned y = 0; y < HEIGHT; ++y)
            {
                arr->pushDouble(this->get(x, y));
            }
        }

        promise->resolveArray(mat);
    }

    inline std::shared_ptr<JavascriptArray> toJavascriptArray()
    {
        auto mat = mBridge->createArray();
        auto arr = mBridge->createArray();
        for (unsigned x = 0; x < WIDTH; ++x)
        {
            mat->pushArray(arr);
            for (unsigned y = 0; y < HEIGHT; ++y)
            {
                arr->pushDouble(this->get(x, y));
            }
        }

        return mat;
    }

    inline std::shared_ptr<Matrix3x4> toNative(const std::shared_ptr<::JavascriptArray> &arr)
    {
        Kore::Matrix<3U, 4U, T> *nMat = static_cast<Kore::Matrix<3U, 4U, T>>(this);

        for (unsigned x = 0; x < WIDTH; ++x)
        {
            auto nArr = arr->getArray(x);
            for (unsigned y = 0; y < HEIGHT; ++y)
            {
                nMat[x][y] = nArr->getDouble(y);
            }
        }

        return std::make_shared<Matrix3x4>(static_cast<Matrix3x2 *>(nMat));
    }
};
typedef Matrix3x4<float> mat3x4;
typedef Matrix3x4<double> mat3x4d;
} // namespace nok