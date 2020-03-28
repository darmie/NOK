#pragma once 

#include <cstdint>
#include "nok/graphics.hpp"
#include "Kore/Graphics4/Graphics.h"
#include "nok/constant_location.hpp"
#include "nok/cull_mode.hpp"
#include "headers/math/matrix3.hpp"
#include "headers/math/matrix4.hpp"
#include "headers/buffer.hpp"
#include "headers/texture.hpp"
#include "headers/image.hpp"
#include "headers/pipelinestate.hpp"
#include "headers/rendertarget.hpp"

namespace nok
{
    class ConstantLocationImpl : public nok::ConstantLocation, public Kore::Graphics4::ConstantLocation {
        public:
            ConstantLocationImpl() : nok::ConstantLocation(), Kore::Graphics4::ConstantLocation(){};
            ~ConstantLocationImpl(){};
    };

    class VertexStructureImpl : public nok::VertexStructure, public Kore::Graphics4::VertexStructure {
        public:
            VertexStructureImpl() : nok::VertexStructure(), Kore::Graphics4::VertexStructure(){};
            ~VertexStructureImpl(){}
    };

    class Graphics {
        public: 
            static void init(int32_t windowId, int32_t depthBufferBits, int32_t stencilBufferBits, bool vsync) {
                Kore::Graphics4::init(windowId, depthBufferBits, stencilBufferBits, vsync);
            }
            static void setBool(const std::shared_ptr<ConstantLocation> & location, bool value){
                Kore::Graphics4::ConstantLocation loc = *static_cast<ConstantLocationImpl*>(location.get());
                Kore::Graphics4::setBool(loc, value);
            }

            static void setInt(const std::shared_ptr<ConstantLocation> & location, int32_t value) {
                Kore::Graphics4::ConstantLocation loc = *static_cast<ConstantLocationImpl*>(location.get());
                Kore::Graphics4::setInt(loc, value);
            }

            static void setInt2(const std::shared_ptr<ConstantLocation> & location, int32_t value1, int32_t value2) {
                Kore::Graphics4::ConstantLocation loc = *static_cast<ConstantLocationImpl*>(location.get());
                Kore::Graphics4::setInt2(loc, value1, value2);
            }

            static void setInt3(const std::shared_ptr<ConstantLocation> & location, int32_t value1, int32_t value2, int32_t value3) {
                Kore::Graphics4::ConstantLocation loc = *static_cast<ConstantLocationImpl*>(location.get());
                Kore::Graphics4::setInt3(loc, value1, value2, value3);
            }

            static void setInt4(const std::shared_ptr<ConstantLocation> & location, int32_t value1, int32_t value2, int32_t value3, int32_t value4){
                Kore::Graphics4::ConstantLocation loc = *static_cast<ConstantLocationImpl*>(location.get());
                Kore::Graphics4::setInt4(loc, value1, value2, value3, value4);
            }

            static void setInts(const std::shared_ptr<ConstantLocation> & location, const std::vector<int32_t> & values, int32_t count) {
                Kore::Graphics4::ConstantLocation loc = *static_cast<ConstantLocationImpl*>(location.get());
                Kore::Graphics4::setInts(loc, (int32_t*)&values[0], count);
            }

            static void setFloat2(const std::shared_ptr<ConstantLocation> & location, float value1, float value2) {
                Kore::Graphics4::ConstantLocation loc = *static_cast<ConstantLocationImpl*>(location.get());
                Kore::Graphics4::setFloat2(loc, value1, value2);
            }

            static void setFloat3(const std::shared_ptr<ConstantLocation> & location, float value1, float value2, float value3) {
                Kore::Graphics4::ConstantLocation loc = *static_cast<ConstantLocationImpl*>(location.get());
                Kore::Graphics4::setFloat3(loc, value1, value2, value3);
            }

            static void setFloat4(const std::shared_ptr<ConstantLocation> & location, int32_t value1, float value2, float value3, float value4){
                Kore::Graphics4::ConstantLocation loc = *static_cast<ConstantLocationImpl*>(location.get());
                Kore::Graphics4::setFloat4(loc, value1, value2, value2, value4);
            }

            static void setFloats(const std::shared_ptr<ConstantLocation> & location, const std::vector<float> & values, float count) {
                Kore::Graphics4::ConstantLocation loc = *static_cast<ConstantLocationImpl*>(location.get());
                Kore::Graphics4::setFloats(loc, (float*)&values[0], count);
            }

            static void setMatrix3(const std::shared_ptr<ConstantLocation> & location, const std::shared_ptr<Mat3> & mat) {
                Kore::Graphics4::ConstantLocation loc = *static_cast<ConstantLocationImpl*>(location.get());
                Kore::mat3 mat3 = *static_cast<Matrix3<float>*>(mat.get());
                Kore::Graphics4::setMatrix(loc, mat3);
            }

            static void setMatrix4(const std::shared_ptr<ConstantLocation> & location, const std::shared_ptr<Mat4> & mat) {
                Kore::Graphics4::ConstantLocation loc = *static_cast<ConstantLocationImpl*>(location.get());
                Kore::mat4 mat4 = *static_cast<Matrix4<float>*>(mat.get());
                Kore::Graphics4::setMatrix(loc, mat4);
            }

            static void setVertexBuffer(const std::shared_ptr<VertexBuffer> & buf) {
                Kore::Graphics4::VertexBuffer buff = *static_cast<VertexBufferImpl*>(buf.get());
                Kore::Graphics4::setVertexBuffer(buff);
            }

            static void setVertexBuffers(const std::vector<std::shared_ptr<VertexBuffer>> & bufs, int32_t count) {
                Kore::Graphics4::VertexBuffer** buffs = (Kore::Graphics4::VertexBuffer**)((VertexBufferImpl**) &bufs[0]);
                Kore::Graphics4::setVertexBuffers(buffs, count);
            }

            static void setIndexBuffer(const std::shared_ptr<IndexBuffer> & buf) {
                Kore::Graphics4::IndexBuffer buff = *static_cast<IndexBufferImpl*>(buf.get());
                Kore::Graphics4::setIndexBuffer(buff);
            }

            static void setTexture(const std::shared_ptr<TextureUnit> & unit, const std::shared_ptr<Texture> & texture) {
                Kore::Graphics4::setTexture(*static_cast<TextureUnitImpl*>(unit.get()), static_cast<TextureImpl*>(texture.get())->_texture);
            }

            static void setTextureArray(const std::shared_ptr<TextureUnit> & unit, const std::shared_ptr<TextureArray> & texture) {
                Kore::Graphics4::setTextureArray(*static_cast<TextureUnitImpl*> (unit.get()), static_cast<TextureArrayImpl*> (texture.get()));
            }

            static void setPipeline(const std::shared_ptr<PipelineState> & pipeline) {
                Kore::Graphics4::setPipeline(static_cast<PipelineStateImpl*>(pipeline.get()));
            }

            static void setStencilReferenceValue(int32_t value) {
                Kore::Graphics4::setStencilReferenceValue(value);
            }

            static void drawIndexedVertices(int32_t start, int32_t count) {
                Kore::Graphics4::drawIndexedVertices(start, count);
            }

            static void drawIndexedVerticesInstanced(int32_t instanceCount, int32_t start, int32_t count) {
                Kore::Graphics4::drawIndexedVerticesInstanced(instanceCount, start, count);
            }

            static int32_t antialiasingSamples() {
                return Kore::Graphics4::antialiasingSamples();
            }

            static void setAntialiasingSamples(int32_t samples) {
                Kore::Graphics4::setAntialiasingSamples(samples);
            }

            static bool renderTargetsInvertedY() {
                return Kore::Graphics4::renderTargetsInvertedY();
            }

            static void setRenderTargets(const std::vector<std::shared_ptr<RenderTarget>> & targets, int32_t count) {
                Kore::Graphics4::RenderTarget** _targets;
                for(int i = 0; i < targets.size; i++){
                    _targets[i] = static_cast<Kore::Graphics4::RenderTarget*>(static_cast<RenderTargetImpl*>(targets[i].get()));
                }
                return Kore::Graphics4::setRenderTargets(_targets, count);
            }

            static void setRenderTarget(const std::shared_ptr<RenderTarget> & target) {
                Kore::Graphics4::RenderTarget* t = static_cast<Kore::Graphics4::RenderTarget*>(static_cast<RenderTargetImpl*>(target.get()));
                return Kore::Graphics4::setRenderTarget(t);
            }

            static void setRenderTargetFace(const std::shared_ptr<RenderTarget> & texture, int32_t face) {
                Kore::Graphics4::RenderTarget* t = static_cast<Kore::Graphics4::RenderTarget*>(static_cast<RenderTargetImpl*>(texture.get()));
                return Kore::Graphics4::setRenderTargetFace(t, face);
            }

            static void restoreRenderTarget() {
                Kore::Graphics4::restoreRenderTarget();
            }

            static void begin(int32_t win) {
                Kore::Graphics4::begin(win);
            }

            static void end(int32_t win) {
                Kore::Graphics4::end(win);
            }

            static bool swapBuffers() {
                Kore::Graphics4::swapBuffers();
            }

            static void viewport(int32_t x, int32_t y, int32_t width, int32_t height) {
                Kore::Graphics4::viewport(x, y, width, height);
            }

            static void scissor(int32_t x, int32_t y, int32_t width, int32_t height){
                Kore::Graphics4::scissor(x, y, width, height);
            }

            static void disableScissor() {
                Kore::Graphics4::disableScissor();
            }

            static void setTextureAddressing(const std::shared_ptr<TextureUnit> & unit, TexDir dir, TextureAddressing addressing) {
                Kore::Graphics4::setTextureAddressing(*static_cast<TextureUnitImpl*>(unit.get()), getInternalTexDir(dir), getInternalTextureAddressing(addressing));
            }

            static void setTextureMagnificationFilter(const std::shared_ptr<TextureUnit> & unit, TextureFilter filer) {
                Kore::Graphics4::setTextureMagnificationFilter(*static_cast<TextureUnitImpl*>(unit.get()), getInternalTextureFilter(filer));
            }

            static void setTextureMinificationFilter(const std::shared_ptr<TextureUnit> & unit, TextureFilter filer) {
                Kore::Graphics4::setTextureMinificationFilter(*static_cast<TextureUnitImpl*>(unit.get()), getInternalTextureFilter(filer));
            }

            static void setTextureMipmapFilter(const std::shared_ptr<TextureUnit> & unit, MipmapFilter filer) {
                Kore::Graphics4::setTextureMipmapFilter(*static_cast<TextureUnitImpl*>(unit.get()), getInternalMipMapFilter(filer));
            }

            static void setTexture3DAddressing(const std::shared_ptr<TextureUnit> & unit, TexDir dir, TextureAddressing addressing) {
                Kore::Graphics4::setTexture3DAddressing(*static_cast<TextureUnitImpl*>(unit.get()), getInternalTexDir(dir), getInternalTextureAddressing(addressing));
            }

            static void setTexture3DMagnificationFilter(const std::shared_ptr<TextureUnit> & unit, TextureFilter filer) {
                Kore::Graphics4::setTexture3DMagnificationFilter(*static_cast<TextureUnitImpl*>(unit.get()), getInternalTextureFilter(filer));
            }

            static void setTexture3DMinificationFilter(const std::shared_ptr<TextureUnit> & unit, TextureFilter filer) {
                Kore::Graphics4::setTexture3DMinificationFilter(*static_cast<TextureUnitImpl*>(unit.get()), getInternalTextureFilter(filer));
            }

            static void setTexture3DMipmapFilter(const std::shared_ptr<TextureUnit> & unit, MipmapFilter filer) {
                Kore::Graphics4::setTexture3DMipmapFilter(*static_cast<TextureUnitImpl*>(unit.get()), getInternalMipMapFilter(filer));
            }

            static void setTextureCompareMode(const std::shared_ptr<TextureUnit> & unit, bool enabled) {
                Kore::Graphics4::setTextureCompareMode(*static_cast<TextureUnitImpl*>(unit.get()), enabled);
            }

            static void setCubeMapCompareMode(const std::shared_ptr<TextureUnit> & unit, bool enabled){
                Kore::Graphics4::setTextureCompareMode(*static_cast<TextureUnitImpl*>(unit.get()), enabled);
            }

            static void setTextureOperation(TextureOperation operation, TextureArgument arg1, TextureArgument arg2) {
                Kore::Graphics4::setTextureOperation(getInternalTextureOperation(operation), getInternalTextureArgument(arg1), getInternalTextureArgument(arg2));
            }

            static bool nonPow2TexturesSupported() {
                return Kore::Graphics4::nonPow2TexturesSupported();
            }

            static bool get_fullscreen() {
                return Kore::Graphics4::fullscreen;
            }

            static void destroy(int32_t windowId) {
                Kore::Graphics4::destroy(windowId);
            }

            static void flush(){
                Kore::Graphics4::flush();
            }

            static bool initOcclusionQuery(const std::vector<double> & occlusionQuery) {
                Kore::Graphics4::initOcclusionQuery((Kore::uint*)&occlusionQuery[0]);
            }

            static void deleteOcclusionQuery(double occlusionQuery) {
                Kore::Graphics4::deleteOcclusionQuery(occlusionQuery);
            }

            static void renderOcclusionQuery(double occlusionQuery, int32_t triangles) {
                Kore::Graphics4::renderOcclusionQuery(occlusionQuery, triangles);
            }

            static bool isQueryResultsAvailable(double occlusionQuery){
                return Kore::Graphics4::isQueryResultsAvailable(occlusionQuery);
            }

            static void getQueryResults(double occlusionQuery, const std::vector<double> & pixelCount) {
                Kore::Graphics4::getQueryResults(occlusionQuery, (Kore::uint*)&pixelCount[0]);
            }

            static void clear(int32_t flags, double color, float depth, int32_t stencil) {
                Kore::Graphics4::clear(flags, color, depth);
            }

    };
    static Kore::Graphics4::CullMode getInternalCullMode(nok::CullMode mode) {
        switch (mode)
        {
        case nok::CullMode::NOCULLING: return Kore::Graphics4::CullMode::NoCulling;
        case nok::CullMode::CLOCKWISE: return Kore::Graphics4::CullMode::Clockwise;
        case nok::CullMode::COUNTERCLOCKWISE: return Kore::Graphics4::CullMode::CounterClockwise;
        }
    }

    static nok::CullMode getCullMode(Kore::Graphics4::CullMode mode) {
        switch (mode)
        {
        case Kore::Graphics4::NoCulling: return nok::CullMode::NOCULLING;
        case Kore::Graphics4::Clockwise: return nok::CullMode::CLOCKWISE;
        case Kore::Graphics4::CounterClockwise: return nok::CullMode::COUNTERCLOCKWISE;
        }
    }
} // namespace nok
