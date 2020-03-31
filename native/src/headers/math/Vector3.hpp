#pragma once

#include "nok/vec3.hpp"
#include "Kore/Math/Vector.h"
#include "nok/vec3_module.hpp"
#include "source/jobqueue_impl.hpp"

class JavascriptMap;

namespace nok
{
template <class T>
class Vector3 : public nok::Vec3, public nok::Vec3Module, public Kore::Vector<T, 3U>
{
private:
    std::shared_ptr<ReactBridge> mBridge;
    std::shared_ptr<JobQueueImpl> mQueue;
    std::shared_ptr<JobDispatcher> mDispatcher;

public:
    Vector3() : nok::Vec3(), Kore::Vector<T, 3U>(){};
    Vector3(T x, T y, T z), nok::Vec3(), Kore::Vector<T, 3U>(x, y, z){};
    Vector3(const std::shared_ptr<::ReactBridge> &bridge) : nok::Vec3(), nok::Vec3Module(), Kore::Vector<T, 3U>()
    {
        this->mBridge = bridge;

        mQueue = JobQueueImpl::create();
        mDispatcher = mBridge->createJobDispatcher(mQueue);
        mDispatcher->start();
    };
    ~Vector3(){};

    double get_x()
    {
        return static_cast<Kore::Vector<T, 3U> *>(this)->x();
    }

    void get_x(const std::shared_ptr<::JavascriptPromise> &promise)
    {
        promse->resolveDouble(this->get_x());
    }

    double get_y()
    {
        return static_cast<Kore::Vector<T, 3U> *>(this)->y();
    }

    void get_y(const std::shared_ptr<::JavascriptPromise> &promise)
    {
        promse->resolveDouble(this->get_y());
    }

    double get_z()
    {
        return static_cast<Kore::Vector<T, 3U> *>(this)->z();
    }

    void get_z(const std::shared_ptr<::JavascriptPromise> &promise)
    {
        promse->resolveDouble(this->get_z());
    }

    void add(const std::shared_ptr<Vec3> &v)
    {
        static_cast<Kore::Vector<T, 3U> *>(this)->add(*static_cast<Kore::Vector<T, 3U> *>(v.get()));
    }

    void add(const std::shared_ptr<::JavascriptMap> &v)
    {
        const Vector3 *vec = new Vector3(v->getDouble("x"), v->getDouble("y"), v->getDouble("z"));

        this->add(std::make_shared<Vector3>(vec));
    }

    void addScaledVector(const std::shared_ptr<Vec3> &v)
    {
        static_cast<Kore::Vector<T, 3U> *>(this)->addScaledVector(*static_cast<Kore::Vector<T, 3U> *>(v.get()));
    }

    void addScaledVector(const std::shared_ptr<::JavascriptMap> &v)
    {
        const Vector3 *vec = new Vector3(v->getDouble("x"), v->getDouble("y"), v->getDouble("z"));
        this->addScaledVector(std::make_shared<Vector3>(vec));
    }

    void sub(const std::shared_ptr<Vec3> &v)
    {
        static_cast<Kore::Vector<T, 3U> *>(this)->sub(*static_cast<Kore::Vector<T, 3U> *>(v.get()));
    }

    void sub(const std::shared_ptr<::JavascriptMap> &v)
    {
        const Vector3 *vec = new Vector3(v->getDouble("x"), v->getDouble("y"), v->getDouble("z"));
        this->sub(std::make_shared<Vector3>(vec));
    }

    void multiply(double i)
    {
        static_cast<Kore::Vector<T, 3U> *>(this) * i;
    }

    void divide(double i)
    {
        static_cast<Kore::Vector<T, 3U> *>(this) / i;
    }

    double squareLength()
    {
        return static_cast<Kore::Vector<T, 3U> *>(this)->squareLength();
    }

    void squareLength(const std::shared_ptr<::JavascriptPromise> &promise)
    {
        promse->resolveDouble(this->squareLength());
    }

    double getLength()
    {
        return static_cast<Kore::Vector<T, 3U> *>(this)->getLength();
    }

    void getLength(const std::shared_ptr<::JavascriptPromise> &promise)
    {
        promse->resolveDouble(this->getLength());
    }

    void setLength(double length)
    {
        static_cast<Kore::Vector<T, 3U> *>(this)->setLength(length);
    }

    std::shared_ptr<Vec3> normalize()
    {
        return std::make_shared<Kore::Vector<T, 3U>>(static_cast<Vector3<T> *>(static_cast<Kore::Vector<T, 3U> *>(this)->normalize()));
    }

    void normalize(const std::shared_ptr<::JavascriptPromise> &promise)
    {
        auto map = mBridge->createMap();
        map->putDouble("x", this->get_x());
        map->putDouble("y", this->get_y());
        map->putDouble("z", this->get_z());
        promise->resolveMap(map);
    }

    bool isZero()
    {
        return static_cast<Kore::Vector<T, 3U> *>(this)->isZero();
    }

    void isZero(const std::shared_ptr<::JavascriptPromise> &promise)
    {
        promise->resolveBoolean(isZero());
    }

    std::shared_ptr<Vec3> get_xyz()
    {
        return std::make_shared<Kore::Vector<T, 3U>>(static_cast<Vector3<T> *>(static_cast<Kore::Vector<T, 3U> *>(this)->xyz()));
    }

    void get_xyz(const std::shared_ptr<::JavascriptPromise> &promise)
    {
        auto map = mBridge->createMap();
        map->putDouble("x", get_xy()->get_x());
        map->putDouble("y", get_xy()->get_y());
        map->putDouble("z", get_xy()->get_z());
        promise->resolveMap(map);
    }

    void set(double x, double y, double z)
    {
        static_cast<Kore::Vector<T, 3U> *>(this)->set(x, y, z);
    }

    double dot(const std::shared_ptr<Vec3> &v)
    {
        return static_cast<Kore::Vector<T, 3U> *>(this)->dot(*static_cast<Kore::Vector<T, 3U> *>(v.get()));
    }

    void dot(const std::shared_ptr<::JavascriptMap> &v, const std::shared_ptr<::JavascriptPromise> &promise)
    {
        const Vector3 *vec = new Vector3(v->getDouble("x"), v->getDouble("y"), v->getDouble("z"));
        const double dot = this->dot(std::make_shared<Vector3>(vec));
        promise->resolveDouble(dot);
    }

    std::shared_ptr<Vec3> cross(const std::shared_ptr<Vec3> &v)
    {
        return std::make_shared<Kore::Vector<T, 3U>>(static_cast<Kore::Vector<T, 3U> *>(this)->cross(*static_cast<Kore::Vector<T, 3U> *>(v.get())));
    }

    void cross(const std::shared_ptr<::JavascriptMap> &v, const std::shared_ptr<::JavascriptPromise> &promise)
    {
        const Vector3 *vec = new Vector3(v->getDouble("x"), v->getDouble("y"), v->getDouble("z"));
        Vector3 *_cross = static_cast<Vectore3 *>(cross(std::make_shared<Vector3>(vec)).get());
        auto map = mBridge->createMap();
        map->putDouble("x", _cross->get_x());
        map->putDouble("y", _cross->get_y());
        map->putDouble("z", _cross->get_z());
        promise->resolveMap(map);
    }

    double distance(const std::shared_ptr<Vec3> &v)
    {
        return static_cast<Kore::Vector<T, 3U> *>(this)->distance(*static_cast<Kore::Vector<T, 3U> *>(v.get()));
    }

    void distance(const std::shared_ptr<::JavascriptMap> &v, const std::shared_ptr<::JavascriptPromise> &promise)
    {
        const Vector3 *vec = new Vector3(v->getDouble("x"), v->getDouble("y"), v->getDouble("z"));
        const double dist = distance(std::make_shared<Vector3>(vec));
        promise->resolveDouble(dist);
    }

    void invert()
    {
        return static_cast<Kore::Vector<T, 3U> *>(this)->invert();
    }

    static std::shared_ptr<Vec3> create(double x, double y, double z)
    {
        return std::make_shared<Kore::Vector<T, 3U>>(x, y, z);
    }
};
typedef Vector3<float> vec3;
typedef Vector3<double> vec3d;
typedef Vector3<int> vec3i;
} // namespace nok
