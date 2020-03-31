// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from math.djinni

#pragma once

#include <memory>

namespace nok {

class Vec3;

class Mat2 {
public:
    virtual ~Mat2() {}

    static float const WIDTH;

    static float const HEIGHT;

    virtual float get(float row, float col) = 0;

    virtual void set(float row, float col, float v) = 0;

    static std::shared_ptr<Mat2> orthogonalProjection(float left, float right, float bottom, float top, float zn, float zf);

    static std::shared_ptr<Mat2> perspective(float left, float right, float top, float bottom, float near, float far);

    static std::shared_ptr<Mat2> perspectiveFOV(float fov, float aspect, float near, float far);

    static std::shared_ptr<Mat2> lookAt(const std::shared_ptr<Vec3> & eye, const std::shared_ptr<Vec3> & at, const std::shared_ptr<Vec3> & up);

    static std::shared_ptr<Mat2> lookAlong(const std::shared_ptr<Vec3> & axis, const std::shared_ptr<Vec3> & eye, const std::shared_ptr<Vec3> & up);

    static std::shared_ptr<Mat2> translation(float x, float y);

    static std::shared_ptr<Mat2> movement(float x, float y, float z);

    static std::shared_ptr<Mat2> identity();

    static std::shared_ptr<Mat2> scale(float scale);

    static std::shared_ptr<Mat2> rotationX(float alpha);

    static std::shared_ptr<Mat2> rotationY(float alpha);

    static std::shared_ptr<Mat2> rotationZ(float alpha);

    static std::shared_ptr<Mat2> rotation(float yaw, float pitch, float roll);

    static std::shared_ptr<Mat2> create();

    static std::shared_ptr<Mat2> from(const std::shared_ptr<Mat2> & mat);

    virtual std::shared_ptr<Mat2> add(const std::shared_ptr<Mat2> & mat) = 0;

    virtual std::shared_ptr<Mat2> sub(const std::shared_ptr<Mat2> & mat) = 0;

    virtual std::shared_ptr<Mat2> multiply(float i) = 0;

    virtual std::shared_ptr<Mat2> clone() = 0;

    virtual std::shared_ptr<Mat2> transpose() = 0;

    virtual std::shared_ptr<Mat2> transpose3x3() = 0;

    virtual float trace() = 0;

    virtual float determinant() = 0;

    static std::shared_ptr<Mat2> linearInterpolate(const std::shared_ptr<Mat2> & a, const std::shared_ptr<Mat2> & b, float prop);
};

}  // namespace nok
