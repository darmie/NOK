#pragma once

#include "nok/vec4.hpp"
#include "Kore/Math/Vector.h"
#include "nok/vec4_module.hpp"
#include "source/jobqueue_impl.hpp"

class JavascriptMap;

namespace nok
{
template <class T>
class Vector4 : public nok::Vec4, public nok::Vec4Module, public Kore::Vector<T, 4U>
{
private:
    std::shared_ptr<ReactBridge> mBridge;
    std::shared_ptr<JobQueueImpl> mQueue;
    std::shared_ptr<JobDispatcher> mDispatcher;

public:
    Vector4() : nok::Vec4(), Kore::Vector<T, 4U>(){};
    Vector4(T x, T y, T z, T w), nok::Vec4(), Kore::Vector<T, 4U>(x, y){};
    Vector4(const std::shared_ptr<::ReactBridge> &bridge) : nok::Vec4(), nok::Vec4Module(), Kore::Vector<T, 4U>()
    {
        this->mBridge = bridge;

        mQueue = JobQueueImpl::create();
        mDispatcher = mBridge->createJobDispatcher(mQueue);
        mDispatcher->start();
    };
    ~Vector4(){};

    double get_x()
    {
        return static_cast<Kore::Vector<T, 4U> *>(this)->x();
    }

    void get_x(const std::shared_ptr<::JavascriptPromise> &promise)
    {
        promse->resolveDouble(this->get_x());
    }

    double get_y()
    {
        return static_cast<Kore::Vector<T, 4U> *>(this)->y();
    }

    void get_y(const std::shared_ptr<::JavascriptPromise> &promise)
    {
        promse->resolveDouble(this->get_y());
    }

    double get_z()
    {
        return static_cast<Kore::Vector<T, 4U> *>(this)->z();
    }

    void get_z(const std::shared_ptr<::JavascriptPromise> &promise)
    {
        promse->resolveDouble(this->get_z());
    }

    double get_w()
    {
        return static_cast<Kore::Vector<T, 4U> *>(this)->w();
    }

    void get_w(const std::shared_ptr<::JavascriptPromise> &promise)
    {
        promse->resolveDouble(this->get_w());
    }

    void add(const std::shared_ptr<Vec4> &v)
    {
        static_cast<Kore::Vector<T, 4U> *>(this)->add(*static_cast<Kore::Vector<T, 4U> *>(v.get()));
    }

    void add(const std::shared_ptr<::JavascriptMap> &v)
    {
        const Vector4 *vec = new Vector4(v->getDouble("x"), v->getDouble("y"), v->getDouble("z"), v->getDouble("w"));

        this->add(std::make_shared<Vector4>(vec));
    }

    void addScaledVector(const std::shared_ptr<Vec4> &v)
    {
        static_cast<Kore::Vector<T, 4U> *>(this)->addScaledVector(*static_cast<Kore::Vector<T, 4U> *>(v.get()));
    }

    void addScaledVector(const std::shared_ptr<::JavascriptMap> &v)
    {
        const Vector4 *vec = new Vector4(v->getDouble("x"), v->getDouble("y"), v->getDouble("z"), v->getDouble("w"));
        this->addScaledVector(std::make_shared<Vector4>(vec));
    }

    void sub(const std::shared_ptr<Vec4> &v)
    {
        static_cast<Kore::Vector<T, 4U> *>(this)->sub(*static_cast<Kore::Vector<T, 4U> *>(v.get()));
    }

    void sub(const std::shared_ptr<::JavascriptMap> &v)
    {
        const Vector4 *vec = new Vector4(v->getDouble("x"), v->getDouble("y"), v->getDouble("z"), v->getDouble("w"));
        this->sub(std::make_shared<Vector4>(vec));
    }

    void multiply(double i)
    {
        static_cast<Kore::Vector<T, 4U> *>(this) * i;
    }

    void divide(double i)
    {
        static_cast<Kore::Vector<T, 4U> *>(this) / i;
    }

    double squareLength()
    {
        return static_cast<Kore::Vector<T, 4U> *>(this)->squareLength();
    }

    void squareLength(const std::shared_ptr<::JavascriptPromise> &promise)
    {
        promse->resolveDouble(this->squareLength());
    }

    double getLength()
    {
        return static_cast<Kore::Vector<T, 4U> *>(this)->getLength();
    }

    void getLength(const std::shared_ptr<::JavascriptPromise> &promise)
    {
        promse->resolveDouble(this->getLength());
    }

    void setLength(double length)
    {
        static_cast<Kore::Vector<T, 4U> *>(this)->setLength(length);
    }

    std::shared_ptr<Vec4> normalize()
    {
        return std::make_shared<Kore::Vector<T, 4U>>(static_cast<Vector4<T> *>(static_cast<Kore::Vector<T, 4U> *>(this)->normalize()));
    }

    void normalize(const std::shared_ptr<::JavascriptPromise> &promise)
    {
        auto map = mBridge->createMap();
        map->putDouble("x", this->get_x());
        map->putDouble("y", this->get_y());
        map->putDouble("z", this->get_z());
        map->putDouble("w", this->get_w());
        promise->resolveMap(map);
    }

    bool isZero()
    {
        return static_cast<Kore::Vector<T, 4U> *>(this)->isZero();
    }

    void isZero(const std::shared_ptr<::JavascriptPromise> &promise)
    {
        promise->resolveBoolean(isZero());
    }

    void set(double x, double y, double z, double w)
    {
        static_cast<Kore::Vector<T, 4U> *>(this)->set(x, y, z, w);
    }

    double dot(const std::shared_ptr<Vec4> &v)
    {
        return static_cast<Kore::Vector<T, 4U> *>(this)->dot(*static_cast<Kore::Vector<T, 4U> *>(v.get()));
    }

    void dot(const std::shared_ptr<::JavascriptMap> &v, const std::shared_ptr<::JavascriptPromise> &promise)
    {
        const Vector4 *vec = new Vector4(v->getDouble("x"), v->getDouble("y"), v->getDouble("z"),  v->getDouble("w"));
        const double dot = this->dot(std::make_shared<Vector4>(vec));
        promise->resolveDouble(dot);
    }

    std::shared_ptr<Vec4> cross(const std::shared_ptr<Vec4> &v)
    {
        return std::make_shared<Kore::Vector<T, 4U>>(static_cast<Kore::Vector<T, 4U> *>(this)->cross(*static_cast<Kore::Vector<T, 4U> *>(v.get())));
    }

    void cross(const std::shared_ptr<::JavascriptMap> &v, const std::shared_ptr<::JavascriptPromise> &promise)
    {
        const Vector4 *vec = new Vector4(v->getDouble("x"), v->getDouble("y"), v->getDouble("z"), v->getDouble("w"));
        Vector4 *_cross = static_cast<Vector4 *>(cross(std::make_shared<Vector4>(vec)).get());
        auto map = mBridge->createMap();
        map->putDouble("x", _cross->get_x());
        map->putDouble("y", _cross->get_y());
        map->putDouble("z", _cross->get_z());
        map->putDouble("w", _cross->get_w());
        promise->resolveMap(map);
    }

    double distance(const std::shared_ptr<Vec4> &v)
    {
        return static_cast<Kore::Vector<T, 4U> *>(this)->distance(*static_cast<Kore::Vector<T, 4U> *>(v.get()));
    }

    void distance(const std::shared_ptr<::JavascriptMap> &v, const std::shared_ptr<::JavascriptPromise> &promise)
    {
        const Vector4 *vec = new Vector4(v->getDouble("x"), v->getDouble("y"), v->getDouble("z"), v->getDouble("w"));
        const double dist = distance(std::make_shared<Vector4>(vec));
        promise->resolveDouble(dist);
    }

    void invert()
    {
        return static_cast<Kore::Vector<T, 4U> *>(this)->invert();
    }

    static std::shared_ptr<Vec4> create(double x, double y, double z, double w)
    {
        return std::make_shared<Kore::Vector<T, 4U>>(x, y, z, w);
    }
};
typedef Vector4<float> vec4;
typedef Vector4<double> vec4d;
typedef Vector4<int> vec4i;
} // namespace nok
