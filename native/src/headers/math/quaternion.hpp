#pragma once

#include "nok/quaternion.hpp"
#include "Kore/Math/Quaternion.h"
#include "headers/math/Vector3.hpp"
#include "headers/math/matrix4.hpp"

namespace nok
{
class QuaternionImpl : public nok::Quaternion, public Kore::Quaternion
{
public:
    QuaternionImpl() : nok::Quaternion(), Kore::Quaternion(){};
    QuaternionImpl(float x, float y, float z, float w) : nok::Quaternion(), Kore::Quaternion(x, y, z, w){};
    QuaternionImpl(std::shared_ptr<vec3> &axis, float radians) : nok::Quaternion(), Kore::Quaternion(*static_cast<Kore::Vector<float, 3> *>(axis.get()), radians){};
    ~QuaternionImpl(){};

    static std::shared_ptr<nok::Quaternion> create(float x, float y, float z, float w)
    {
        return std::make_shared<QuaternionImpl>(x, y, z, w);
    }

    static std::shared_ptr<nok::Quaternion> fromAxis(const std::shared_ptr<Vec3> &axis, float radian)
    {
        return std::make_shared<QuaternionImpl>(axis, radian);
    }

    std::shared_ptr<nok::Quaternion> slerp(float t, const std::shared_ptr<nok::Quaternion> &q)
    {
        return std::make_shared<QuaternionImpl>(static_cast<Kore::Quaternion *>(this)->slerp(t, *static_cast<Kore::Quaternion *>(static_cast<QuaternionImpl *>(q.get()))));
    }

    std::shared_ptr<nok::Quaternion> rotated(const std::shared_ptr<nok::Quaternion> &b)
    {
        return std::make_shared<QuaternionImpl>(static_cast<Kore::Quaternion *>(this)->rotated(*static_cast<Kore::Quaternion *>(static_cast<QuaternionImpl *>(b.get()))));
    }

    std::shared_ptr<nok::Quaternion> scaled(float scale)
    {
        return std::make_shared<QuaternionImpl>(static_cast<Kore::Quaternion *>(this)->scaled(scale));
    }

    float dot(const std::shared_ptr<nok::Quaternion> &q)
    {
        return static_cast<Kore::Quaternion *>(this)->dot(*static_cast<Kore::Quaternion *>(static_cast<QuaternionImpl *>(q.get())));
    }

    std::shared_ptr<Mat4> matrix()
    {
        return std::make_shared<nok::mat4>(static_cast<Kore::Quaternion *>(this)->matrix());
    }

    std::shared_ptr<nok::Quaternion> add(const std::shared_ptr<nok::Quaternion> &q)
    {
        return std::make_shared<QuaternionImpl>(x + q.get()->get_x(), y + q.get()->get_y(), z + q.get()->get_z(), w + q.get()->get_w());
    }

    std::shared_ptr<nok::Quaternion> sub(const std::shared_ptr<nok::Quaternion> &q)
    {
        return std::make_shared<QuaternionImpl>(x - q.get()->get_x(), y - q.get()->get_y(), z - q.get()->get_z(), w - q.get()->get_w());
    }

    std::shared_ptr<nok::Quaternion> addVec3(const std::shared_ptr<Vec3> &v)
    {
        QuaternionImpl result(x, y, z, w);
        QuaternionImpl q1(0, v->get_x(), v->get_y(), v->get_z());
        static_cast<Kore::Quaternion>(q1) = static_cast<Kore::Quaternion>(q1) * result;
        result.x += q1.x * 0.5f;
        result.y += q1.y * 0.5f;
        result.z += q1.z * 0.5f;
        result.w += q1.w * 0.5f;

        return std::make_shared<QuaternionImpl>(result);
    }

    std::shared_ptr<nok::Quaternion> multiply(const std::shared_ptr<nok::Quaternion> &r)
    {
        QuaternionImpl q;
        QuaternionImpl _r = *static_cast<QuaternionImpl *>(r.get());
        q.x = x * _r.x - y * _r.y - z * _r.z - w * _r.w;
        q.y = x * _r.y + y * _r.x - z * _r.w + w * _r.z;
        q.z = x * _r.z - y * _r.w + z * _r.x - w * _r.y;
        q.w = x * _r.w + y * _r.z - z * _r.y + w * _r.x;

        return std::make_shared<QuaternionImpl>(q);
    }

    void normalize()
    {
        static_cast<Kore::Quaternion *>(this)->normalize();
    }

    void rotate(const std::shared_ptr<nok::Quaternion> &q)
    {
        static_cast<Kore::Quaternion *>(this)->rotate(*static_cast<Kore::Quaternion *>(static_cast<QuaternionImpl *>(q.get())));
    }

    std::shared_ptr<nok::Quaternion> conjugate()
    {
        return std::make_shared<QuaternionImpl>(static_cast<Kore::Quaternion *>(this)->conjugate());
    }

    std::shared_ptr<nok::Quaternion> invert()
    {
        return std::make_shared<QuaternionImpl>(static_cast<Kore::Quaternion *>(this)->invert());
    }

    float get_x()
    {
        return x;
    }

    float get_y()
    {
        return y;
    }

    float get_z()
    {
        return z;
    }

    float get_w()
    {
        return w;
    }

    void set_x(float x)
    {
        this->x = x;
    }

    void set_y(float y)
    {
        this->y = y;
    }

    void set_z(float z)
    {
        this->z = z;
    }
    void set_w(float w)
    {
        this->w = w;
    }
};
} // namespace nok