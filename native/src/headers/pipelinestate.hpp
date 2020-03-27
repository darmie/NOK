#pragma once 

#include "Kore/Graphics4/PipelineState.h"
#include "nok/pipeline_state.hpp"
#include "nok/z_compare_mode.hpp"
#include "nok/stencil_action.hpp"
#include "nok/blending_operation.hpp"

namespace nok {
    class PipelineStateImpl : public nok::PipelineState , public Kore::Graphics4::PipelineState {
        public:
            PipelineStateImpl() : nok::PipelineState(), Kore::Graphics4::PipelineState() {};
            ~PipelineStateImpl(){};
            
            std::vector<std::shared_ptr<VertexStructure>> get_inputLayout() = 0;

            std::shared_ptr<Shader> get_vertexShader() = 0;

            void set_vertexShader(const std::shared_ptr<Shader> & shader) = 0;

            std::shared_ptr<Shader> get_fragmentShader() = 0;

            void set_fragmentShader(const std::shared_ptr<Shader> & shader) = 0;

            std::shared_ptr<Shader> get_geometryShader() = 0;

            void set_geometryShader(const std::shared_ptr<Shader> & shader) = 0;

            std::shared_ptr<Shader> get_tessellationControlShader() = 0;

            void set_tessellationControlShader(const std::shared_ptr<Shader> & shader) = 0;

            std::shared_ptr<Shader> get_tessellationEvaluationShader() = 0;

            void set_tessellationEvaluationShader(const std::shared_ptr<Shader> & shader) = 0;

            CullMode get_cullMode() = 0;

            void set_cullMode(CullMode cullMode) = 0;

            bool depthWrite() = 0;

            void setDepthWrite(bool b) = 0;

            ZCompareMode depthMode() = 0;

            void set_depthMode(ZCompareMode m) = 0;

            ZCompareMode stencilMode() = 0;

            void set_stencilMode(ZCompareMode m) = 0;

            StencilAction stencilBothPass() = 0;

            void set_stencilBothPass(StencilAction s) = 0;

            StencilAction stencilDepthFail() = 0;

            void set_stencilDepthFail(StencilAction s) = 0;

            StencilAction stencilFail() = 0;

            void set_stencilFail(StencilAction s) = 0;

            BlendingOperation blendSource() = 0;

            void set_blendSource(BlendingOperation s) = 0;

            BlendingOperation blendDestination() = 0;

            void set_blendDestination(BlendingOperation s) = 0;

            BlendingOperation alphaBlendSource() = 0;

            void set_alphaBlendSource(BlendingOperation s) = 0;

            BlendingOperation alphaBlendDestination() = 0;

            void set_alphaBlendDestination(BlendingOperation s) = 0;

            std::vector<bool> colorWriteMaskRed() = 0;

            void set_colorWriteMaskRed(const std::vector<bool> & v) = 0;

            std::vector<bool> colorWriteMaskGreen() = 0;

            void set_colorWriteMaskGreen(const std::vector<bool> & v) = 0;

            std::vector<bool> colorWriteMaskBlue() = 0;

            std::vector<bool> set_colorWriteMaskBlue(const std::vector<bool> & v) = 0;

            std::vector<bool> colorWriteMaskAlpha() = 0;

            void set_colorWriteMaskAlpha(const std::vector<bool> & v) = 0;

            bool conservativeRasterization() = 0;

            void set_conservativeRasterization(bool b) = 0;

            void compile() = 0;

            std::shared_ptr<ConstantLocation> getConstantLocation(const std::string & name) = 0;

            std::shared_ptr<TextureUnit> getTextureUnit(const std::string & name) = 0;
    };

    static nok::ZCompareMode getZCompareMode(Kore::Graphics4::ZCompareMode mode){
        switch (mode)
        {
        case Kore::Graphics4::ZCompareMode::ZCompareAlways: return nok::ZCompareMode::ZCOMPAREALWAYS;
        case Kore::Graphics4::ZCompareMode::ZCompareNever: return nok::ZCompareMode::ZCOMPARENEVER;
        case Kore::Graphics4::ZCompareMode::ZCompareEqual: return nok::ZCompareMode::ZCOMPAREEQUAL;
        case Kore::Graphics4::ZCompareMode::ZCompareGreater: return nok::ZCompareMode::ZCOMPAREGREATER;
        case Kore::Graphics4::ZCompareMode::ZCompareGreaterEqual: return nok::ZCompareMode::ZCOMPAREGREATEREQUAL;
        case Kore::Graphics4::ZCompareMode::ZCompareLess: return nok::ZCompareMode::ZCOMPARELESS;
        case Kore::Graphics4::ZCompareMode::ZCompareLessEqual: return nok::ZCompareMode::ZCOMPARELESSEQUAL;
        case Kore::Graphics4::ZCompareMode::ZCompareNotEqual: return ZCompareMode::ZCOMPARENOTEQUAL;
        default:
            break;
        }
    }

    static Kore::Graphics4::ZCompareMode getInternalZCompareMode(ZCompareMode mode){
        switch (mode)
        {
        case ZCompareMode::ZCOMPAREALWAYS: return Kore::Graphics4::ZCompareMode::ZCompareAlways;
        case ZCompareMode::ZCOMPARENEVER: return Kore::Graphics4::ZCompareMode::ZCompareNever;
        case ZCompareMode::ZCOMPAREEQUAL: return Kore::Graphics4::ZCompareMode::ZCompareEqual;
        case ZCompareMode::ZCOMPAREGREATER: return Kore::Graphics4::ZCompareMode::ZCompareGreater;
        case ZCompareMode::ZCOMPAREGREATEREQUAL: return Kore::Graphics4::ZCompareMode::ZCompareGreaterEqual;
        case ZCompareMode::ZCOMPARELESS: return Kore::Graphics4::ZCompareMode::ZCompareLess;
        case ZCompareMode::ZCOMPARELESSEQUAL: return Kore::Graphics4::ZCompareMode::ZCompareLessEqual;
        case ZCompareMode::ZCOMPARENOTEQUAL: return Kore::Graphics4::ZCompareMode::ZCompareNotEqual;
        default:
            break;
        }
    }

    static Kore::Graphics4::StencilAction getInternalStencilAction(StencilAction action){
        switch (action)
        {
        case StencilAction::KEEP: return Kore::Graphics4::StencilAction::Keep;
        case StencilAction::DECREMENT: return Kore::Graphics4::StencilAction::Decrement;
        case StencilAction::DECREMENTWRAP: return Kore::Graphics4::StencilAction::DecrementWrap;
        case StencilAction::INCREMENT: return Kore::Graphics4::StencilAction::Increment;
        case StencilAction::INCREMENTWRAP: return Kore::Graphics4::StencilAction::IncrementWrap;
        case StencilAction::INVERT: return Kore::Graphics4::StencilAction::Invert;
        case StencilAction::REPLACE: return Kore::Graphics4::StencilAction::Replace;
        case StencilAction::ZERO: return Kore::Graphics4::StencilAction::Zero;
        }
    }

    static StencilAction getStencilAction(Kore::Graphics4::StencilAction action){
        switch (action)
        {
        case Kore::Graphics4::StencilAction::Keep: return StencilAction::KEEP;
        case Kore::Graphics4::StencilAction::Decrement: return StencilAction::DECREMENT;
        case Kore::Graphics4::StencilAction::DecrementWrap: return StencilAction::DECREMENTWRAP;
        case Kore::Graphics4::StencilAction::Increment: return StencilAction::INCREMENT;
        case Kore::Graphics4::StencilAction::IncrementWrap: return StencilAction::DECREMENTWRAP;
        case Kore::Graphics4::StencilAction::Invert: return StencilAction::INVERT;
        case Kore::Graphics4::StencilAction::Replace: return StencilAction::REPLACE;
        case Kore::Graphics4::StencilAction::Zero: return StencilAction::ZERO;
        }
    }

    static BlendingOperation getBlendOperation(Kore::Graphics4::BlendingOperation op){
        switch (op)
        {
        case Kore::Graphics4::BlendingOperation::BlendOne: return BlendingOperation::BLENDONE;
        case Kore::Graphics4::BlendingOperation::BlendZero: return BlendingOperation::BLENDZERO;
        case Kore::Graphics4::BlendingOperation::SourceAlpha: return BlendingOperation::SOURCEALPHA;
        case Kore::Graphics4::BlendingOperation::SourceColor: return BlendingOperation::SOURCECOLOR;
        case Kore::Graphics4::BlendingOperation::InverseSourceAlpha: return BlendingOperation::INVERSESOURCEALPHA;
        case Kore::Graphics4::BlendingOperation::InverseSourceColor: return BlendingOperation::INVERSESOURCECOLOR;
        case Kore::Graphics4::BlendingOperation::DestinationAlpha: return BlendingOperation::DESTINATIONALPHA;
        case Kore::Graphics4::BlendingOperation::DestinationColor: return BlendingOperation::DESTINATIONCOLOR;
        case Kore::Graphics4::BlendingOperation::InverseDestinationAlpha: return BlendingOperation::INVERSEDESTINATIONALPHA;
        case Kore::Graphics4::BlendingOperation::InverseDestinationColor: return BlendingOperation::INVERSEDESTINATIONCOLOR;
        }
    }

    static Kore::Graphics4::BlendingOperation getInternalBlendOperation(BlendingOperation op){
        switch (op)
        {
        case BlendingOperation::BLENDONE : return Kore::Graphics4::BlendingOperation::BlendOne;
        case BlendingOperation::BLENDZERO: return Kore::Graphics4::BlendingOperation::BlendZero;
        case BlendingOperation::SOURCEALPHA: return Kore::Graphics4::BlendingOperation::SourceAlpha;
        case BlendingOperation::SOURCECOLOR: return Kore::Graphics4::BlendingOperation::SourceColor;
        case BlendingOperation::INVERSESOURCEALPHA: return Kore::Graphics4::BlendingOperation::InverseSourceAlpha;
        case BlendingOperation::INVERSESOURCECOLOR: return Kore::Graphics4::BlendingOperation::InverseSourceColor;
        case BlendingOperation::DESTINATIONALPHA: return Kore::Graphics4::BlendingOperation::DestinationAlpha;
        case BlendingOperation::DESTINATIONCOLOR: return Kore::Graphics4::BlendingOperation::DestinationColor;
        case BlendingOperation::INVERSEDESTINATIONALPHA: return Kore::Graphics4::BlendingOperation::InverseDestinationAlpha;
        case BlendingOperation::INVERSEDESTINATIONCOLOR: return Kore::Graphics4::BlendingOperation::InverseDestinationColor;
        }
    }
}