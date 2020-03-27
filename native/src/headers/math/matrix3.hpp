#pragma once 

#include "nok/mat3.hpp"
#include "Kore/Math/Matrix.h"

namespace nok {
    class Matrix3Impl : public nok::Mat3, public Kore::Matrix<3, 3, float> {
        public:
           Matrix3Impl() : nok::Mat3(), Kore::Matrix<3, 3, float>() {};
           ~Matrix3Impl(){};

    };
    typedef Matrix3Impl mat3;
} // namespace nok