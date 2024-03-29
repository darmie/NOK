// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from nok.djinni

#import "NOKAlignedQuad+Private.h"
#import "DJIMarshal+Private.h"
#include <cassert>

namespace djinni_generated {

auto AlignedQuad::toCpp(ObjcType obj) -> CppType
{
    assert(obj);
    return {::djinni::F32::toCpp(obj.x0),
            ::djinni::F32::toCpp(obj.y0),
            ::djinni::F32::toCpp(obj.s0),
            ::djinni::F32::toCpp(obj.t0),
            ::djinni::F32::toCpp(obj.x1),
            ::djinni::F32::toCpp(obj.y1),
            ::djinni::F32::toCpp(obj.s1),
            ::djinni::F32::toCpp(obj.t1),
            ::djinni::F32::toCpp(obj.xadvance)};
}

auto AlignedQuad::fromCpp(const CppType& cpp) -> ObjcType
{
    return [[NOKAlignedQuad alloc] initWithX0:(::djinni::F32::fromCpp(cpp.x0))
                                           y0:(::djinni::F32::fromCpp(cpp.y0))
                                           s0:(::djinni::F32::fromCpp(cpp.s0))
                                           t0:(::djinni::F32::fromCpp(cpp.t0))
                                           x1:(::djinni::F32::fromCpp(cpp.x1))
                                           y1:(::djinni::F32::fromCpp(cpp.y1))
                                           s1:(::djinni::F32::fromCpp(cpp.s1))
                                           t1:(::djinni::F32::fromCpp(cpp.t1))
                                     xadvance:(::djinni::F32::fromCpp(cpp.xadvance))];
}

}  // namespace djinni_generated
