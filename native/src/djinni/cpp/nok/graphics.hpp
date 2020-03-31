// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from nok.djinni

#pragma once

#include <cstdint>
#include <memory>
#include <vector>

namespace nok {

class ConstantLocation;
class IndexBuffer;
class Mat3;
class Mat4;
class PipelineState;
class RenderTarget;
class Texture;
class TextureArray;
class TextureUnit;
class VertexBuffer;
enum class MipmapFilter;
enum class TexDir;
enum class TextureAddressing;
enum class TextureArgument;
enum class TextureFilter;
enum class TextureOperation;

class Graphics {
public:
    virtual ~Graphics() {}

    static int32_t const CLEARCOLORFLAG;

    static int32_t const CLEARDEPTHFLAG;

    static int32_t const CLEARSTENCILFLAG;

    static void setBool(const std::shared_ptr<ConstantLocation> & location, bool value);

    static void setInt(const std::shared_ptr<ConstantLocation> & location, int32_t value);

    static void setInt2(const std::shared_ptr<ConstantLocation> & location, int32_t value1, int32_t value2);

    static void setInt3(const std::shared_ptr<ConstantLocation> & location, int32_t value1, int32_t value2, int32_t value3);

    static void setInt4(const std::shared_ptr<ConstantLocation> & location, int32_t value1, int32_t value2, int32_t value3, int32_t value4);

    static void setInts(const std::shared_ptr<ConstantLocation> & location, const std::vector<int32_t> & values, int32_t count);

    static void setFloat2(const std::shared_ptr<ConstantLocation> & location, float value1, float value2);

    static void setFloat3(const std::shared_ptr<ConstantLocation> & location, float value1, float value2, float value3);

    static void setFloat4(const std::shared_ptr<ConstantLocation> & location, int32_t value1, float value2, float value3, float value4);

    static void setFloats(const std::shared_ptr<ConstantLocation> & location, const std::vector<float> & values, float count);

    static void setMatrix3(const std::shared_ptr<ConstantLocation> & location, const std::shared_ptr<Mat3> & mat);

    static void setMatrix4(const std::shared_ptr<ConstantLocation> & location, const std::shared_ptr<Mat4> & mat);

    static void setVertexBuffer(const std::shared_ptr<VertexBuffer> & buf);

    static void setVertexBuffers(const std::vector<std::shared_ptr<VertexBuffer>> & bufs, int32_t count);

    static void setIndexBuffer(const std::shared_ptr<IndexBuffer> & buf);

    static void setTexture(const std::shared_ptr<TextureUnit> & unit, const std::shared_ptr<Texture> & texture);

    static void setTextureArray(const std::shared_ptr<TextureUnit> & unit, const std::shared_ptr<TextureArray> & texture_array);

    static void setPipeline(const std::shared_ptr<PipelineState> & pipeline);

    static void setStencilReferenceValue(int32_t value);

    static void drawIndexedVertices(int32_t start, int32_t count);

    static void drawIndexedVerticesInstanced(int32_t instanceCount, int32_t start, int32_t count);

    static int32_t antialiasingSamples();

    static void setAntialiasingSamples(int32_t samples);

    static bool renderTargetsInvertedY();

    static void setRenderTargets(const std::vector<std::shared_ptr<RenderTarget>> & targets, int32_t count);

    static void setRenderTarget(const std::shared_ptr<RenderTarget> & target);

    static void setRenderTargetFace(const std::shared_ptr<RenderTarget> & texture, int32_t face);

    static void restoreRenderTarget();

    static void begin(int32_t win);

    static void end(int32_t win);

    static bool swapBuffers();

    static void viewport(int32_t x, int32_t y, int32_t width, int32_t height);

    static void scissor(int32_t x, int32_t y, int32_t width, int32_t height);

    static void disableScissor();

    static void setTextureAddressing(const std::shared_ptr<TextureUnit> & unit, TexDir dir, TextureAddressing addressing);

    static void setTextureMagnificationFilter(const std::shared_ptr<TextureUnit> & unit, TextureFilter filer);

    static void setTextureMinificationFilter(const std::shared_ptr<TextureUnit> & unit, TextureFilter filer);

    static void setTextureMipmapFilter(const std::shared_ptr<TextureUnit> & unit, MipmapFilter filer);

    static void setTexture3DAddressing(const std::shared_ptr<TextureUnit> & unit, TexDir dir, TextureAddressing addressing);

    static void setTexture3DMagnificationFilter(const std::shared_ptr<TextureUnit> & unit, TextureFilter filer);

    static void setTexture3DMinificationFilter(const std::shared_ptr<TextureUnit> & unit, TextureFilter filer);

    static void setTexture3DMipmapFilter(const std::shared_ptr<TextureUnit> & unit, MipmapFilter filer);

    static void setTextureCompareMode(const std::shared_ptr<TextureUnit> & unit, bool enabled);

    static void setCubeMapCompareMode(const std::shared_ptr<TextureUnit> & unit, bool enabled);

    static void setTextureOperation(TextureOperation operation, TextureArgument arg1, TextureArgument arg2);

    static bool nonPow2TexturesSupported();

    static bool get_fullscreen();

    static void init(int32_t windowId, int32_t depthBufferBits, int32_t stencilBufferBits, bool vsync);

    static void destroy(int32_t windowId);

    static void flush();

    static bool initOcclusionQuery(const std::vector<double> & occlusionQuery);

    static void deleteOcclusionQuery(double occlusionQuery);

    static void renderOcclusionQuery(double occlusionQuery, int32_t triangles);

    static bool isQueryResultsAvailable(double occlusionQuery);

    static void getQueryResults(double occlusionQuery, const std::vector<double> & pixelCount);

    static void clear(int32_t flags, double color, float depth, int32_t stencil);
};

}  // namespace nok
