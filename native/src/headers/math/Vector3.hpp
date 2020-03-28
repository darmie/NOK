#pragma once

#include "nok/vec3.hpp"
#include "Kore/Math/Vector.h"

namespace nok
{
template <class T>
class Vector3 : public nok::Vec3, public Kore::Vector<T, 3U>
{
public:
    Vector3() : nok::Vec3(), Kore::Vector<T, 3U>(){};
    Vector3(T x, T y, T z), nok::Vec3(), Kore::Vector<T, 3U>(x, y){};
    ~Vector3(){};

    double get_x() {
        return static_cast<Kore::Vector<T, 3U> *>(this)->x();
    }

    double get_y() {
        return static_cast<Kore::Vector<T, 3U> *>(this)->y();
    }

    double get_z() {
        return static_cast<Kore::Vector<T, 3U> *>(this)->z();
    }

    void add(const std::shared_ptr<Vec3> &v) {
        static_cast<Kore::Vector<T, 3U> *>(this)->add(*static_cast<Kore::Vector<T, 3U> *>(v.get()));
    }

    void addScaledVector(const std::shared_ptr<Vec3> &v) {
        static_cast<Kore::Vector<T, 3U> *>(this)->addScaledVector(*static_cast<Kore::Vector<T, 3U> *>(v.get()));
    }

    void sub(const std::shared_ptr<Vec3> &v) {
        static_cast<Kore::Vector<T, 3U> *>(this)->sub(*static_cast<Kore::Vector<T, 3U> *>(v.get()));
    }

    void multiply(double i) {
        static_cast<Kore::Vector<T, 3U> *>(this) * i;
    }

    void divide(double i) {
        static_cast<Kore::Vector<T, 3U> *>(this) / i;
    }

    double squareLength() {
        return static_cast<Kore::Vector<T, 3U> *>(this)->squareLength();
    }

    double getLength() {
        return static_cast<Kore::Vector<T, 3U> *>(this)->getLength();
    }

    void setLength(double length) {
        static_cast<Kore::Vector<T, 3U> *>(this)->setLength(length);
    }

    std::shared_ptr<Vec3> normalize() {
        return std::make_shared<Kore::Vector<T, 3U>>(static_cast<Vector3<T> *>(static_cast<Kore::Vector<T, 3U> *>(this)->normalize()));
    }

    bool isZero() {
        return static_cast<Kore::Vector<T, 3U> *>(this)->isZero();
    }

    std::shared_ptr<Vec3> get_xyz() {
        return std::make_shared<Kore::Vector<T, 3U>>(static_cast<Vector3<T> *>(static_cast<Kore::Vector<T, 3U> *>(this)->xyz()));
    }

    void set(double x, double y, double z) {
        static_cast<Kore::Vector<T, 3U> *>(this)->set(x, y, z);
    }

    double dot(const std::shared_ptr<Vec3> &v) {
        return static_cast<Kore::Vector<T, 3U> *>(this)->dot(*static_cast<Kore::Vector<T, 3U>*>(v.get()));
    }

    std::shared_ptr<Vec3> cross(const std::shared_ptr<Vec3> &v) {
        return std::make_shared<Kore::Vector<T, 3U>>(static_cast<Kore::Vector<T, 3U> *>(this)->cross(*static_cast<Kore::Vector<T, 3U>*>(v.get())));
    }

    double distance(const std::shared_ptr<Vec3> &v) {
        return static_cast<Kore::Vector<T, 3U> *>(this)->distance(*static_cast<Kore::Vector<T, 3U>*>(v.get()));
    }

    void invert() {
        return static_cast<Kore::Vector<T, 3U> *>(this)->invert();
    }

    static std::shared_ptr<Vec3> create(double x, double y, double z) {
        return std::make_shared<Kore::Vector<T, 3U>>(x, y, z);
    }
};
typedef Vector3<float> vec3;
typedef Vector3<double> vec3d;
typedef Vector3<int> vec3i;
} // namespace nok
