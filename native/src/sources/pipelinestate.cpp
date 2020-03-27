
#include "headers/pipelinestate.hpp"
#include "headers/graphics.hpp"
#include "headers/shader.hpp"

namespace nok
{

std::vector<std::shared_ptr<VertexStructure>> PipelineStateImpl::get_inputLayout()
{
    Kore::Graphics4::VertexStructure **structure = static_cast<Kore::Graphics4::PipelineState *>(this)->inputLayout;
    std::vector<std::shared_ptr<VertexStructure>> store;

    store[0] = std::make_shared<VertexStructureImpl>(structure[0]);
    store[1] = std::make_shared<VertexStructureImpl>(structure[1]);
    store[2] = std::make_shared<VertexStructureImpl>(structure[2]);
    store[3] = std::make_shared<VertexStructureImpl>(structure[3]);
    store[4] = std::make_shared<VertexStructureImpl>(structure[4]);
    store[5] = std::make_shared<VertexStructureImpl>(structure[5]);
    store[6] = std::make_shared<VertexStructureImpl>(structure[6]);
    store[7] = std::make_shared<VertexStructureImpl>(structure[7]);
    store[8] = std::make_shared<VertexStructureImpl>(structure[8]);
    store[9] = std::make_shared<VertexStructureImpl>(structure[9]);
    store[10] = std::make_shared<VertexStructureImpl>(structure[10]);
    store[11] = std::make_shared<VertexStructureImpl>(structure[11]);
    store[12] = std::make_shared<VertexStructureImpl>(structure[12]);
    store[13] = std::make_shared<VertexStructureImpl>(structure[13]);
    store[14] = std::make_shared<VertexStructureImpl>(structure[14]);
    store[15] = std::make_shared<VertexStructureImpl>(structure[15]);

    return store;
}

std::shared_ptr<Shader> PipelineStateImpl::get_vertexShader()
{
    ShaderImpl *shader = static_cast<ShaderImpl *>(static_cast<Kore::Graphics4::PipelineState *>(this)->vertexShader);
    return std::make_shared<ShaderImpl>(shader);
}

void PipelineStateImpl::set_vertexShader(const std::shared_ptr<Shader> &shader)
{
    static_cast<Kore::Graphics4::PipelineState *>(this)->vertexShader = static_cast<ShaderImpl *>(shader.get());
}

std::shared_ptr<Shader> PipelineStateImpl::get_fragmentShader()
{
    ShaderImpl *shader = static_cast<ShaderImpl *>(static_cast<Kore::Graphics4::PipelineState *>(this)->fragmentShader);
    return std::make_shared<ShaderImpl>(shader);
}

void PipelineStateImpl::set_fragmentShader(const std::shared_ptr<Shader> &shader)
{
    static_cast<Kore::Graphics4::PipelineState *>(this)->fragmentShader = static_cast<ShaderImpl *>(shader.get());
}

std::shared_ptr<Shader> PipelineStateImpl::get_geometryShader()
{
    ShaderImpl *shader = static_cast<ShaderImpl *>(static_cast<Kore::Graphics4::PipelineState *>(this)->geometryShader);
    return std::make_shared<ShaderImpl>(shader);
}

void PipelineStateImpl::set_geometryShader(const std::shared_ptr<Shader> &shader)
{
    static_cast<Kore::Graphics4::PipelineState *>(this)->geometryShader = static_cast<ShaderImpl *>(shader.get());
}

std::shared_ptr<Shader> PipelineStateImpl::get_tessellationControlShader()
{
    ShaderImpl *shader = static_cast<ShaderImpl *>(static_cast<Kore::Graphics4::PipelineState *>(this)->tessellationControlShader);
    return std::make_shared<ShaderImpl>(shader);
}

void PipelineStateImpl::set_tessellationControlShader(const std::shared_ptr<Shader> &shader)
{
    static_cast<Kore::Graphics4::PipelineState *>(this)->tessellationControlShader = static_cast<ShaderImpl *>(shader.get());
}

std::shared_ptr<Shader> PipelineStateImpl::get_tessellationEvaluationShader()
{
    ShaderImpl *shader = static_cast<ShaderImpl *>(static_cast<Kore::Graphics4::PipelineState *>(this)->tessellationEvaluationShader);
    return std::make_shared<ShaderImpl>(shader);
}

void PipelineStateImpl::set_tessellationEvaluationShader(const std::shared_ptr<Shader> &shader)
{
    static_cast<Kore::Graphics4::PipelineState *>(this)->tessellationEvaluationShader = static_cast<ShaderImpl *>(shader.get());
}

CullMode PipelineStateImpl::get_cullMode()
{
    Kore::Graphics4::CullMode cullMode = static_cast<Kore::Graphics4::PipelineState *>(this)->cullMode;
    return getCullMode(cullMode);
}

void PipelineStateImpl::set_cullMode(CullMode cullMode)
{
    static_cast<Kore::Graphics4::PipelineState *>(this)->cullMode = getInternalCullMode(cullMode);
}

bool PipelineStateImpl::depthWrite()
{
    return static_cast<Kore::Graphics4::PipelineState *>(this)->depthWrite;
}

void PipelineStateImpl::setDepthWrite(bool b)
{
    static_cast<Kore::Graphics4::PipelineState *>(this)->depthWrite = b;
}

ZCompareMode PipelineStateImpl::depthMode()
{
    return getZCompareMode(static_cast<Kore::Graphics4::PipelineState *>(this)->depthMode);
}

void PipelineStateImpl::set_depthMode(ZCompareMode m)
{
    static_cast<Kore::Graphics4::PipelineState *>(this)->depthMode = getInternalZCompareMode(m);
}

ZCompareMode PipelineStateImpl::stencilMode()
{
    return getZCompareMode(static_cast<Kore::Graphics4::PipelineState *>(this)->stencilMode);
}

void PipelineStateImpl::set_stencilMode(ZCompareMode m)
{
    static_cast<Kore::Graphics4::PipelineState *>(this)->stencilMode = getInternalZCompareMode(m);
}

StencilAction PipelineStateImpl::stencilBothPass()
{
    return getStencilAction(static_cast<Kore::Graphics4::PipelineState *>(this)->stencilBothPass);
}

void PipelineStateImpl::set_stencilBothPass(StencilAction s)
{
    static_cast<Kore::Graphics4::PipelineState *>(this)->stencilBothPass = getInternalStencilAction(s);
}

StencilAction PipelineStateImpl::stencilDepthFail()
{
    return getStencilAction(static_cast<Kore::Graphics4::PipelineState *>(this)->stencilDepthFail);
}

void PipelineStateImpl::set_stencilDepthFail(StencilAction s)
{
    static_cast<Kore::Graphics4::PipelineState *>(this)->stencilDepthFail = getInternalStencilAction(s);
}

StencilAction PipelineStateImpl::stencilFail()
{
    return getStencilAction(static_cast<Kore::Graphics4::PipelineState *>(this)->stencilDepthFail);
}

void PipelineStateImpl::set_stencilFail(StencilAction s)
{
    static_cast<Kore::Graphics4::PipelineState *>(this)->stencilFail = getInternalStencilAction(s);
}

BlendingOperation PipelineStateImpl::blendSource()
{
    return getBlendOperation(static_cast<Kore::Graphics4::PipelineState *>(this)->blendSource);
}

void PipelineStateImpl::set_blendSource(BlendingOperation s)
{
    static_cast<Kore::Graphics4::PipelineState *>(this)->blendSource = getInternalBlendOperation(s);
}

BlendingOperation PipelineStateImpl::blendDestination()
{
    return getBlendOperation(static_cast<Kore::Graphics4::PipelineState *>(this)->blendDestination);
}

void PipelineStateImpl::set_blendDestination(BlendingOperation s)
{
    static_cast<Kore::Graphics4::PipelineState *>(this)->blendDestination = getInternalBlendOperation(s);
}

BlendingOperation PipelineStateImpl::alphaBlendSource()
{
    return getBlendOperation(static_cast<Kore::Graphics4::PipelineState *>(this)->alphaBlendSource);
}

void PipelineStateImpl::set_alphaBlendSource(BlendingOperation s)
{
    static_cast<Kore::Graphics4::PipelineState *>(this)->alphaBlendSource = getInternalBlendOperation(s);
}

BlendingOperation PipelineStateImpl::alphaBlendDestination()
{
    return getBlendOperation(static_cast<Kore::Graphics4::PipelineState *>(this)->alphaBlendDestination);
}

void PipelineStateImpl::set_alphaBlendDestination(BlendingOperation s)
{
    static_cast<Kore::Graphics4::PipelineState *>(this)->alphaBlendDestination = getInternalBlendOperation(s);
}

std::vector<bool> PipelineStateImpl::colorWriteMaskRed()
{
    bool *mask = static_cast<Kore::Graphics4::PipelineState *>(this)->colorWriteMaskRed;
    std::vector<bool> store;
    store[0] = mask[0];
    store[1] = mask[1];
    store[2] = mask[2];
    store[3] = mask[3];
    store[4] = mask[4];
    store[5] = mask[5];
    store[6] = mask[6];
    store[7] = mask[7];

    return store;
}

void PipelineStateImpl::set_colorWriteMaskRed(const std::vector<bool> &v)
{
    bool *store = static_cast<Kore::Graphics4::PipelineState *>(this)->colorWriteMaskRed;

    store[0] = v[0];
    store[1] = v[1];
    store[2] = v[2];
    store[3] = v[3];
    store[4] = v[4];
    store[5] = v[5];
    store[6] = v[6];
    store[7] = v[7];
}

std::vector<bool> PipelineStateImpl::colorWriteMaskGreen()
{
    bool *mask = static_cast<Kore::Graphics4::PipelineState *>(this)->colorWriteMaskGreen;
    std::vector<bool> store;
    store[0] = mask[0];
    store[1] = mask[1];
    store[2] = mask[2];
    store[3] = mask[3];
    store[4] = mask[4];
    store[5] = mask[5];
    store[6] = mask[6];
    store[7] = mask[7];

    return store;
}

void PipelineStateImpl::set_colorWriteMaskGreen(const std::vector<bool> &v)
{
    bool *store = static_cast<Kore::Graphics4::PipelineState *>(this)->colorWriteMaskGreen;

    store[0] = v[0];
    store[1] = v[1];
    store[2] = v[2];
    store[3] = v[3];
    store[4] = v[4];
    store[5] = v[5];
    store[6] = v[6];
    store[7] = v[7];
}

std::vector<bool> PipelineStateImpl::colorWriteMaskBlue()
{
    bool *mask = static_cast<Kore::Graphics4::PipelineState *>(this)->colorWriteMaskBlue;
    std::vector<bool> store;
    store[0] = mask[0];
    store[1] = mask[1];
    store[2] = mask[2];
    store[3] = mask[3];
    store[4] = mask[4];
    store[5] = mask[5];
    store[6] = mask[6];
    store[7] = mask[7];

    return store;
}

std::vector<bool> PipelineStateImpl::set_colorWriteMaskBlue(const std::vector<bool> &v)
{
    bool *store = static_cast<Kore::Graphics4::PipelineState *>(this)->colorWriteMaskGreen;

    store[0] = v[0];
    store[1] = v[1];
    store[2] = v[2];
    store[3] = v[3];
    store[4] = v[4];
    store[5] = v[5];
    store[6] = v[6];
    store[7] = v[7];
}

std::vector<bool> PipelineStateImpl::colorWriteMaskAlpha()
{
    bool *mask = static_cast<Kore::Graphics4::PipelineState *>(this)->colorWriteMaskAlpha;
    std::vector<bool> store;
    store[0] = mask[0];
    store[1] = mask[1];
    store[2] = mask[2];
    store[3] = mask[3];
    store[4] = mask[4];
    store[5] = mask[5];
    store[6] = mask[6];
    store[7] = mask[7];

    return store;
}

void PipelineStateImpl::set_colorWriteMaskAlpha(const std::vector<bool> &v)
{
    bool *store = static_cast<Kore::Graphics4::PipelineState *>(this)->colorWriteMaskGreen;

    store[0] = v[0];
    store[1] = v[1];
    store[2] = v[2];
    store[3] = v[3];
    store[4] = v[4];
    store[5] = v[5];
    store[6] = v[6];
    store[7] = v[7];
}

bool PipelineStateImpl::conservativeRasterization()
{
    return static_cast<Kore::Graphics4::PipelineState *>(this)->conservativeRasterization;
}

void PipelineStateImpl::set_conservativeRasterization(bool b)
{
    static_cast<Kore::Graphics4::PipelineState *>(this)->conservativeRasterization = b;
}

void PipelineStateImpl::compile()
{
    static_cast<Kore::Graphics4::PipelineState *>(this)->compile();
}

} // namespace nok