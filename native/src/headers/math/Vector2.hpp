#pragma once

#include "nok/vec2.hpp"
#include "Kore/Math/Vector.h"

namespace nok
{
template <class T>
class Vector2 : public nok::Vec2, public Kore::Vector<T, 2U>
{
public:
    Vector2() : nok::Vec2(), Kore::Vector<T, 2U>(){};
    Vector2(T x, T y), nok::Vec2(), Kore::Vector<T, 2U>(x, y){};
    ~Vector2(){};

    double get_x() {
        return static_cast<Kore::Vector<T, 2U> *>(this)->x();
    }

    double get_y() {
        return static_cast<Kore::Vector<T, 2U> *>(this)->y();
    }

    void add(const std::shared_ptr<Vec2> &v) {
        static_cast<Kore::Vector<T, 2U> *>(this)->add(*static_cast<Kore::Vector<T, 2U> *>(v.get()));
    }

    void addScaledVector(const std::shared_ptr<Vec2> &v) {
        static_cast<Kore::Vector<T, 2U> *>(this)->addScaledVector(*static_cast<Kore::Vector<T, 2U> *>(v.get()));
    }

    void sub(const std::shared_ptr<Vec2> &v) {
        static_cast<Kore::Vector<T, 2U> *>(this)->sub(*static_cast<Kore::Vector<T, 2U> *>(v.get()));
    }

    void multiply(double i) {
        static_cast<Kore::Vector<T, 2U> *>(this) * i;
    }

    void divide(double i) {
        static_cast<Kore::Vector<T, 2U> *>(this) / i;
    }

    double squareLength() {
        return static_cast<Kore::Vector<T, 2U> *>(this)->squareLength();
    }

    double getLength() {
        return static_cast<Kore::Vector<T, 2U> *>(this)->getLength();
    }

    void setLength(double length) {
        static_cast<Kore::Vector<T, 2U> *>(this)->setLength(length);
    }

    std::shared_ptr<Vec2> normalize() {
        return std::make_shared<Kore::Vector<T, 2U>>(static_cast<Vector2<T> *>(static_cast<Kore::Vector<T, 2U> *>(this)->normalize()));
    }

    bool isZero() {
        return static_cast<Kore::Vector<T, 2U> *>(this)->isZero();
    }

    std::shared_ptr<Vec2> get_xy() {
        return std::make_shared<Kore::Vector<T, 2U>>(static_cast<Vector2<T> *>(static_cast<Kore::Vector<T, 2U> *>(this)->xy()));
    }

    void set(double x, double y) {
        static_cast<Kore::Vector<T, 2U> *>(this)->set(x, y);
    }

    double dot(const std::shared_ptr<Vec2> &v) {
        return static_cast<Kore::Vector<T, 2U> *>(this)->dot(*static_cast<Kore::Vector<T, 2U>*>(v.get()));
    }

    std::shared_ptr<Vec2> cross(const std::shared_ptr<Vec2> &v) {
        return std::make_shared<Kore::Vector<T, 2U>>(static_cast<Kore::Vector<T, 2U> *>(this)->cross(*static_cast<Kore::Vector<T, 2U>*>(v.get())));
    }

    double distance(const std::shared_ptr<Vec2> &v) {
        return static_cast<Kore::Vector<T, 2U> *>(this)->distance(*static_cast<Kore::Vector<T, 2U>*>(v.get()));
    }

    void invert() {
        return static_cast<Kore::Vector<T, 2U> *>(this)->invert();
    }

    static std::shared_ptr<Vec2> create(double x, double y) {
        return std::make_shared<Kore::Vector<T, 2U>>(x, y);
    }
};
typedef Vector2<float> vec2;
typedef Vector2<double> vec2d;
typedef Vector2<int> vec2i;
} // namespace nok
