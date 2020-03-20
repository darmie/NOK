// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from math.djinni

#pragma once

#include <cstdint>
#include <memory>

namespace nok {

class Vec2i {
public:
    virtual ~Vec2i() {}

    virtual int32_t get_x() = 0;

    virtual int32_t get_y() = 0;

    virtual void set_x(int32_t x) = 0;

    virtual void set_y(int32_t y) = 0;

    virtual void add(const std::shared_ptr<Vec2i> & v) = 0;

    virtual void addScaledVector(const std::shared_ptr<Vec2i> & v) = 0;

    virtual void sub(const std::shared_ptr<Vec2i> & v) = 0;

    virtual void multiply(int32_t i) = 0;

    virtual void divide(int32_t i) = 0;

    virtual int32_t squareLength() = 0;

    virtual int32_t getLength() = 0;

    virtual void setLength(int32_t length) = 0;

    virtual std::shared_ptr<Vec2i> normalize() = 0;

    virtual bool isZero() = 0;

    virtual int32_t get(int32_t i) = 0;

    virtual void set(int32_t i, int32_t v) = 0;

    virtual int32_t dot(const std::shared_ptr<Vec2i> & v) = 0;

    virtual std::shared_ptr<Vec2i> cross(const std::shared_ptr<Vec2i> & v) = 0;

    virtual int32_t distance(const std::shared_ptr<Vec2i> & v) = 0;

    static std::shared_ptr<Vec2i> create(int32_t x, int32_t y);
};

}  // namespace nok
