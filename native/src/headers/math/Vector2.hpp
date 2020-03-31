#pragma once

#include "nok/vec2.hpp"
#include "nok/vec2_module.hpp"
#include "Kore/Math/Vector.h"
#include "source/jobqueue_impl.hpp"

class JavascriptMap;

namespace nok
{
template <class T>
class Vector2 : public nok::Vec2, public nok::Vec2Module ,public Kore::Vector<T, 2U>
{
private:
    std::shared_ptr<ReactBridge> mBridge;
    std::shared_ptr<JobQueueImpl> mQueue;
    std::shared_ptr<JobDispatcher> mDispatcher;
public:
    Vector2() : nok::Vec2(), nok::Vec2Module(), Kore::Vector<T, 2U>(){};
    Vector2(const std::shared_ptr<::ReactBridge> & bridge) : nok::Vec2(), nok::Vec2Module(), Kore::Vector<T, 2U>(){
        this->mBridge = bridge;

        mQueue = JobQueueImpl::create();
        mDispatcher = mBridge->createJobDispatcher(mQueue);
        mDispatcher->start();
    };

    Vector2(T x, T y), nok::Vec2(), nok::Vec2Module(), Kore::Vector<T, 2U>(x, y){};
    ~Vector2(){};

    static std::shared_ptr<Vec2Module> create(const std::shared_ptr<::ReactBridge> & bridge){
        return std::make_shared<Vec2Module>(bridge);
    }

    double get_x() {
        return static_cast<Kore::Vector<T, 2U> *>(this)->x();
    }

    void get_x(const std::shared_ptr<::JavascriptPromise> & promise){
        promse->resolveDouble(this->get_x());
    }

    double get_y() {
        return static_cast<Kore::Vector<T, 2U> *>(this)->y();
    }
    
    void get_y(const std::shared_ptr<::JavascriptPromise> & promise){
        promse->resolveDouble(this->get_y());
    }

    void add(const std::shared_ptr<Vec2> &v) {
        static_cast<Kore::Vector<T, 2U> *>(this)->add(*static_cast<Kore::Vector<T, 2U> *>(v.get()));
    }

    void add(const std::shared_ptr<::JavascriptMap> & v) {
        const Vector2* vec = new Vector2(v->getDouble("x"), v->getDouble("y"));

        this->add(std::make_shared<Vector2>(vec));
    }

    void addScaledVector(const std::shared_ptr<Vec2> &v) {
        static_cast<Kore::Vector<T, 2U> *>(this)->addScaledVector(*static_cast<Kore::Vector<T, 2U> *>(v.get()));
    }

    void addScaledVector(const std::shared_ptr<::JavascriptMap> & v){
        const Vector2* vec = new Vector2(v->getDouble("x"), v->getDouble("y"));
        this->addScaledVector(std::make_shared<Vector2>(vec));
    }

    void sub(const std::shared_ptr<Vec2> &v) {
        static_cast<Kore::Vector<T, 2U> *>(this)->sub(*static_cast<Kore::Vector<T, 2U> *>(v.get()));
    }

    void sub(const std::shared_ptr<::JavascriptMap> & v){
        const Vector2* vec = new Vector2(v->getDouble("x"), v->getDouble("y"));
        this->sub(std::make_shared<Vector2>(vec));
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

    void squareLength(const std::shared_ptr<::JavascriptPromise> & promise){
        promse->resolveDouble(this->squareLength());
    }

    double getLength() {
        return static_cast<Kore::Vector<T, 2U> *>(this)->getLength();
    }
    void getLength(const std::shared_ptr<::JavascriptPromise> & promise){
        promse->resolveDouble(this->getLength());
    }

    void setLength(double length) {
        static_cast<Kore::Vector<T, 2U> *>(this)->setLength(length);
    }

    std::shared_ptr<Vec2> normalize() {
        return std::make_shared<Kore::Vector<T, 2U>>(static_cast<Vector2<T> *>(static_cast<Kore::Vector<T, 2U> *>(this)->normalize()));
    }

    void normalize(const std::shared_ptr<::JavascriptPromise> & promise) {
        auto map = mBridge->createMap();
        map->putDouble("x", this->get_x());
        map->putDouble("y", this->get_y());
        promise->resolveMap(map);
    }

    bool isZero() {
        return static_cast<Kore::Vector<T, 2U> *>(this)->isZero();
    }

    void isZero(const std::shared_ptr<::JavascriptPromise> & promise){
        promise->resolveBoolean(isZero());
    }

    std::shared_ptr<Vec2> get_xy() {
        return std::make_shared<Kore::Vector<T, 2U>>(static_cast<Vector2<T> *>(static_cast<Kore::Vector<T, 2U> *>(this)->xy()));
    }

    void get_xy(const std::shared_ptr<::JavascriptPromise> & promise){
        auto map = mBridge->createMap();
        map->putDouble("x", get_xy()->get_x());
        map->putDouble("y", get_xy()->get_y());
        promise->resolveMap(map);
    }

    void set(double x, double y) {
        static_cast<Kore::Vector<T, 2U> *>(this)->set(x, y);
    }

    double dot(const std::shared_ptr<Vec2> &v) {
        return static_cast<Kore::Vector<T, 2U> *>(this)->dot(*static_cast<Kore::Vector<T, 2U>*>(v.get()));
    }

    void dot(const std::shared_ptr<::JavascriptMap> & v, const std::shared_ptr<::JavascriptPromise> & promise){
        const Vector2* vec = new Vector2(v->getDouble("x"), v->getDouble("y"));
        const double dot = this->dot(std::make_shared<Vector2>(vec));
        promise->resolveDouble(dot);
    }

    std::shared_ptr<Vec2> cross(const std::shared_ptr<Vec2> &v) {
        return std::make_shared<Kore::Vector<T, 2U>>(static_cast<Kore::Vector<T, 2U> *>(this)->cross(*static_cast<Kore::Vector<T, 2U>*>(v.get())));
    }

    void cross(const std::shared_ptr<::JavascriptMap> & v, const std::shared_ptr<::JavascriptPromise> & promise){
        const Vector2* vec = new Vector2(v->getDouble("x"), v->getDouble("y"));
        Vector2* _cross = static_cast<Vectore2*>(cross(std::make_shared<Vector2>(vec)).get());
        auto map = mBridge->createMap();
        map->putDouble("x", _cross->get_x());
        map->putDouble("y", _cross->get_y());
        promise->resolveMap(map);
    }

    double distance(const std::shared_ptr<Vec2> &v) {
        return static_cast<Kore::Vector<T, 2U> *>(this)->distance(*static_cast<Kore::Vector<T, 2U>*>(v.get()));
    }

    void distance(const std::shared_ptr<::JavascriptMap> & v, const std::shared_ptr<::JavascriptPromise> & promise){
        const Vector2* vec = new Vector2(v->getDouble("x"), v->getDouble("y"));
        const double dist = distance(std::make_shared<Vector2>(vec));
        promise->resolveDouble(dist);
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
