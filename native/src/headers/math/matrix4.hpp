#pragma once 

#include "nok/mat4.hpp"
#include "Kore/Math/Matrix.h"

namespace nok {
    class Matrix4Impl : public nok::Mat4, public Kore::Matrix<4, 4, float> {
        public:
           Matrix4Impl() : nok::Mat4(), Kore::Matrix<4, 4, float>() {};
           ~Matrix4Impl(){};

    };
    typedef Matrix4Impl mat3;
} // namespace nok