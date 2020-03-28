#pragma once

#include "nok/vec3.hpp"
#include "Kore/Math/Vector.h"

namespace nok
{
template <class T>
class Vector4 : public nok::Vec4, public Kore::Vector<T, 4U>
{
public:
    Vector4() : nok::Vec4(), Kore::Vector<T, 4U>(){};
    Vector4(T x, T y), nok::Vec4(), Kore::Vector<T, 4U>(x, y){};
    ~Vector4(){};

    double get_x() {
        return static_cast<Kore::Vector<T, 4U> *>(this)->x();
    }

    double get_y() {
        return static_cast<Kore::Vector<T, 4U> *>(this)->y();
    }

    double get_z() {
        return static_cast<Kore::Vector<T, 4U> *>(this)->z();
    }

    double get_w() {
        return static_cast<Kore::Vector<T, 4U> *>(this)->w();
    }

    void add(const std::shared_ptr<Vec4> &v) {
        static_cast<Kore::Vector<T, 4U> *>(this)->add(*static_cast<Kore::Vector<T, 4U> *>(v.get()));
    }

    void addScaledVector(const std::shared_ptr<Vec4> &v) {
        static_cast<Kore::Vector<T, 4U> *>(this)->addScaledVector(*static_cast<Kore::Vector<T, 4U> *>(v.get()));
    }

    void sub(const std::shared_ptr<Vec4> &v) {
        static_cast<Kore::Vector<T, 4U> *>(this)->sub(*static_cast<Kore::Vector<T, 4U> *>(v.get()));
    }

    void multiply(double i) {
        static_cast<Kore::Vector<T, 4U> *>(this) * i;
    }

    void divide(double i) {
        static_cast<Kore::Vector<T, 4U> *>(this) / i;
    }

    double squareLength() {
        return static_cast<Kore::Vector<T, 4U> *>(this)->squareLength();
    }

    double getLength() {
        return static_cast<Kore::Vector<T, 4U> *>(this)->getLength();
    }

    void setLength(double length) {
        static_cast<Kore::Vector<T, 4U> *>(this)->setLength(length);
    }

    std::shared_ptr<Vec4> normalize() {
        return std::make_shared<Kore::Vector<T, 4U>>(static_cast<Vector4<T> *>(static_cast<Kore::Vector<T, 4U> *>(this)->normalize()));
    }

    bool isZero() {
        return static_cast<Kore::Vector<T, 4U> *>(this)->isZero();
    }

    std::shared_ptr<Vec4> get_xyz() {
        return std::make_shared<Kore::Vector<T, 4U>>(static_cast<Vector4<T> *>(static_cast<Kore::Vector<T, 4U> *>(this)->xyz()));
    }

    void set(double x, double y, double z, double w) {
        static_cast<Kore::Vector<T, 4U> *>(this)->set(x, y, z, w);
    }

    double dot(const std::shared_ptr<Vec4> &v) {
        return static_cast<Kore::Vector<T, 4U> *>(this)->dot(*static_cast<Kore::Vector<T, 4U>*>(v.get()));
    }

    std::shared_ptr<Vec4> cross(const std::shared_ptr<Vec4> &v) {
        return std::make_shared<Kore::Vector<T, 4U>>(static_cast<Kore::Vector<T, 4U> *>(this)->cross(*static_cast<Kore::Vector<T, 4U>*>(v.get())));
    }

    double distance(const std::shared_ptr<Vec4> &v) {
        return static_cast<Kore::Vector<T, 4U> *>(this)->distance(*static_cast<Kore::Vector<T, 4U>*>(v.get()));
    }

    void invert() {
        return static_cast<Kore::Vector<T, 4U> *>(this)->invert();
    }

    static std::shared_ptr<Vec4> create(double x, double y, double z, double w) {
        return std::make_shared<Kore::Vector<T, 4U>>(x, y, z, w);
    }
};
typedef Vector4<float> vec4;
typedef Vector4<double> vec4d;
typedef Vector4<int> vec4i;
} // namespace nok
