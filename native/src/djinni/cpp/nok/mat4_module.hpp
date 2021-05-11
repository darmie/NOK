// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from math.djinni

#pragma once

#include "javascript_array.hpp"
#include "javascript_map.hpp"
#include "javascript_promise.hpp"
#include "react_bridge.hpp"
#include <memory>

namespace nok {

class Mat4Module {
public:
    virtual ~Mat4Module() {}

    static double const WIDTH;

    static double const HEIGHT;

    static std::shared_ptr<Mat4Module> create(const std::shared_ptr<::ReactBridge> & bridge);

    virtual void get(double row, double col, const std::shared_ptr<::JavascriptPromise> & promise) = 0;

    virtual void set(double row, double col, double v) = 0;

    virtual void orthogonalProjection(double left, double right, double bottom, double top, double zn, double zf, const std::shared_ptr<::JavascriptPromise> & promise) = 0;

    virtual void perspective(double left, double right, double top, double bottom, double near, double far, const std::shared_ptr<::JavascriptPromise> & promise) = 0;

    virtual void perspectiveFOV(double fov, double aspect, double near, double far, const std::shared_ptr<::JavascriptPromise> & promise) = 0;

    virtual void lookAt(const std::shared_ptr<::JavascriptMap> & eye, const std::shared_ptr<::JavascriptMap> & at, const std::shared_ptr<::JavascriptMap> & up, const std::shared_ptr<::JavascriptPromise> & promise) = 0;

    virtual void lookAlong(const std::shared_ptr<::JavascriptMap> & axis, const std::shared_ptr<::JavascriptMap> & eye, const std::shared_ptr<::JavascriptMap> & up, const std::shared_ptr<::JavascriptPromise> & promise) = 0;

    virtual void translation(double x, double y, const std::shared_ptr<::JavascriptPromise> & promise) = 0;

    virtual void movement(double x, double y, double z, const std::shared_ptr<::JavascriptPromise> & promise) = 0;

    virtual void identity(const std::shared_ptr<::JavascriptPromise> & promise) = 0;

    virtual void scale(double scale, const std::shared_ptr<::JavascriptPromise> & promise) = 0;

    virtual void rotationX(double alpha, const std::shared_ptr<::JavascriptPromise> & promise) = 0;

    virtual void rotationY(double alpha, const std::shared_ptr<::JavascriptPromise> & promise) = 0;

    virtual void rotationZ(double alpha, const std::shared_ptr<::JavascriptPromise> & promise) = 0;

    virtual void rotation(double yaw, double pitch, double roll, const std::shared_ptr<::JavascriptPromise> & promise) = 0;

    virtual void from(const std::shared_ptr<::JavascriptArray> & mat, const std::shared_ptr<::JavascriptPromise> & promise) = 0;

    virtual void add(const std::shared_ptr<::JavascriptArray> & mat, const std::shared_ptr<::JavascriptPromise> & promise) = 0;

    virtual void sub(const std::shared_ptr<::JavascriptArray> & mat, const std::shared_ptr<::JavascriptPromise> & promise) = 0;

    virtual void multiply(double i, const std::shared_ptr<::JavascriptPromise> & promise) = 0;

    virtual void clone(const std::shared_ptr<::JavascriptPromise> & promise) = 0;

    virtual void transpose(const std::shared_ptr<::JavascriptPromise> & promise) = 0;

    virtual void transpose3x3(const std::shared_ptr<::JavascriptPromise> & promise) = 0;

    virtual void trace(const std::shared_ptr<::JavascriptPromise> & promise) = 0;

    virtual void determinant(const std::shared_ptr<::JavascriptPromise> & promise) = 0;

    virtual void linearInterpolate(const std::shared_ptr<::JavascriptArray> & a, const std::shared_ptr<::JavascriptArray> & b, double prop, const std::shared_ptr<::JavascriptPromise> & promise) = 0;
};

}  // namespace nok