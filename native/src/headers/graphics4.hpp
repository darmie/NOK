#pragma once

#include <stdint.h>
#include "Kore/Math/Vector.h"
#include "Kore/Math/Matrix.h"
#include "Kore/Graphics4/TextureArray.h"
#include "Kore/Graphics2/Kravur.h"


struct kinc_framebuffer_options;

namespace graphics4
{
    struct ConstantLocation;
    class VertexBuffer;
    class IndexBuffer;
    struct TextureUnit;
    class Texture;
    class PipelineState;
    class RenderTarget;
    enum class TexDir;
    enum class TextureAddressing;
    enum class TextureFilter;
    enum class MipmapFilter;
    enum class TextureOperation;
    enum class TextureArgument;

    class ColoredShaderPainter {
        public:
            void setProjection(Kore::mat4 projectionMatrix);
    };

    class ImageShaderPainter {
        public:
            void setProjection(Kore::mat4 projectionMatrix);
    };

    class TextShaderPainter {
        public:
            void setFont(Kore::Kravur* font);
            void drawString(const char* text, int start, int length, float opacity, uint32_t color, float x, float y, const Kore::mat3& transformation, int* fontGlyphs);
    };

    void setBool(ConstantLocation location, bool value);

    void setInt(ConstantLocation location, int value);
    void setInt2(ConstantLocation location, int value1, int value2);
    void setInt2(ConstantLocation location, Kore::vec2i value);
    void setInt3(ConstantLocation location, int value1, int value2, int value3);
    void setInt3(ConstantLocation location, Kore::vec3i value);
    void setInt4(ConstantLocation location, int value1, int value2, int value3, int value4);
    void setInt4(ConstantLocation location, Kore::vec4i value);
    void setInts(ConstantLocation location, int *values, int count);

    void setFloat(ConstantLocation location, float value);
    void setFloat2(ConstantLocation location, float value1, float value2);
    void setFloat2(ConstantLocation location, Kore::vec2 value);
    void setFloat3(ConstantLocation location, float value1, float value2, float value3);
    void setFloat3(ConstantLocation location, Kore::vec3 value);
    void setFloat4(ConstantLocation location, float value1, float value2, float value3, float value4);
    void setFloat4(ConstantLocation location, Kore::vec4 value);
    void setFloats(ConstantLocation location, float *values, int count);
    void setMatrix(ConstantLocation location, const Kore::mat3 &value);
    void setMatrix(ConstantLocation location, const Kore::mat4 &value);

    void setVertexBuffer(VertexBuffer &vertexBuffer);
    void setVertexBuffers(VertexBuffer **vertexBuffers, int count);
    void setIndexBuffer(IndexBuffer &indexBuffer);
    void setTexture(TextureUnit unit, Texture *texture);
    void setTextureArray(TextureUnit unit, Kore::Graphics4::TextureArray *array);
    void setImageTexture(TextureUnit unit, Texture *texture);
    void setPipeline(PipelineState *pipeline);
    void setStencilReferenceValue(int value);

    void drawIndexedVertices();
    void drawIndexedVertices(int start, int count);
    void drawIndexedVerticesInstanced(int instanceCount);
    void drawIndexedVerticesInstanced(int instanceCount, int start, int count);

    int antialiasingSamples();
    void setAntialiasingSamples(int samples);

    bool renderTargetsInvertedY();
    void setRenderTargets(RenderTarget **targets, int count);
    void setRenderTarget(RenderTarget *target);
    void setRenderTargetFace(RenderTarget *texture, int face = 0);
    void restoreRenderTarget();

    void begin(int window = 0);
    void end(int window = 0);
    bool swapBuffers();

    void _resize(int window, int width, int height);
    void _changeFramebuffer(int window, kinc_framebuffer_options *frame);

    void viewport(int x, int y, int width, int height);
    void scissor(int x, int y, int width, int height);
    void disableScissor();

    void setTextureAddressing(TextureUnit unit, TexDir dir, TextureAddressing addressing);
    void setTextureMagnificationFilter(TextureUnit texunit, TextureFilter filter);
    void setTextureMinificationFilter(TextureUnit texunit, TextureFilter filter);
    void setTextureMipmapFilter(TextureUnit texunit, MipmapFilter filter);
    void setTexture3DAddressing(TextureUnit unit, TexDir dir, TextureAddressing addressing);
    void setTexture3DMagnificationFilter(TextureUnit texunit, TextureFilter filter);
    void setTexture3DMinificationFilter(TextureUnit texunit, TextureFilter filter);
    void setTexture3DMipmapFilter(TextureUnit texunit, MipmapFilter filter);
    void setTextureCompareMode(TextureUnit texunit, bool enabled);
    void setCubeMapCompareMode(TextureUnit texunit, bool enabled);
    void setTextureOperation(TextureOperation operation, TextureArgument arg1, TextureArgument arg2);

    bool nonPow2TexturesSupported();

    // Occlusion Query
    bool initOcclusionQuery(uint8_t *occlusionQuery);
    void deleteOcclusionQuery(uint8_t occlusionQuery);
    void renderOcclusionQuery(uint8_t occlusionQuery, int triangles);
    bool isQueryResultsAvailable(uint8_t occlusionQuery);
    void getQueryResults(uint8_t occlusionQuery, uint8_t *pixelCount);

    const uint8_t ClearColorFlag = 1;
    const uint8_t ClearDepthFlag = 2;
    const uint8_t ClearStencilFlag = 4;

    void clear(uint8_t flags, uint8_t color = 0, float depth = 1.0f, int stencil = 0);

    void init(int windowId, int depthBufferBits, int stencilBufferBits, bool vsync = true);
    void destroy(int windowId);

    extern bool fullscreen;

    void flush();


    class Graphics2 {
        public:
            Kore::mat3 transformation;
            Kore::Kravur* getFont() const;
			void setFont(Kore::Kravur* font);
    };
} // namespace graphics4