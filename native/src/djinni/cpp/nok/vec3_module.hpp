// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from math.djinni

#pragma once

#include "javascript_map.hpp"
#include "javascript_promise.hpp"
#include "react_bridge.hpp"
#include <memory>

namespace nok {

class Vec3Module {
public:
    virtual ~Vec3Module() {}

    static std::shared_ptr<Vec3Module> create(const std::shared_ptr<::ReactBridge> & bridge);

    virtual void get_x(const std::shared_ptr<::JavascriptPromise> & promise) = 0;

    virtual void get_y(const std::shared_ptr<::JavascriptPromise> & promise) = 0;

    virtual void get_z(const std::shared_ptr<::JavascriptPromise> & promise) = 0;

    virtual void add(const std::shared_ptr<::JavascriptMap> & v) = 0;

    virtual void addScaledVector(const std::shared_ptr<::JavascriptMap> & v) = 0;

    virtual void sub(const std::shared_ptr<::JavascriptMap> & v) = 0;

    virtual void multiply(double i) = 0;

    virtual void divide(double i) = 0;

    virtual void squareLength(const std::shared_ptr<::JavascriptPromise> & promise) = 0;

    virtual void getLength(const std::shared_ptr<::JavascriptPromise> & promise) = 0;

    virtual void setLength(double length) = 0;

    virtual void normalize(const std::shared_ptr<::JavascriptPromise> & promise) = 0;

    virtual void isZero(const std::shared_ptr<::JavascriptPromise> & promise) = 0;

    virtual void get_xyz(const std::shared_ptr<::JavascriptPromise> & promise) = 0;

    virtual void set(double x, double y, double z) = 0;

    virtual void dot(const std::shared_ptr<::JavascriptMap> & v, const std::shared_ptr<::JavascriptPromise> & promise) = 0;

    virtual void cross(const std::shared_ptr<::JavascriptMap> & v, const std::shared_ptr<::JavascriptPromise> & promise) = 0;

    virtual void distance(const std::shared_ptr<::JavascriptMap> & v, const std::shared_ptr<::JavascriptPromise> & promise) = 0;

    virtual void invert() = 0;
};

}  // namespace nok
