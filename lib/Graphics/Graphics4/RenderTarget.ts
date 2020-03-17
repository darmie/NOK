import { GameView } from "../../GameView";
import { TextureUnit } from "../TextureUnit";


export class RenderTarget  {
    isCubeMap: boolean;
    isDepthAttachment: boolean;
    texWidth: number;
    texHeight: number;
    _hasDepth: boolean;
    _framebuffer;
    _texture;
    _depthTexture;
    width: number;
    height: number;
    format: RenderTargetFormat
    contextId: number

    GL = GameView.context

    constructor() { }

    static init(width: number, height: number, depthBufferBits: number, antiAliasing: boolean, format: RenderTargetFormat, stencilBufferBits: number, contextId: number) {
        const renderTarget = new RenderTarget();
        renderTarget.width = width;
        renderTarget.height = height;
        renderTarget.isCubeMap = false;
        renderTarget.isDepthAttachment = false;

        renderTarget._hasDepth = false;

        renderTarget.texHeight = height;
        renderTarget.texWidth = width;

        renderTarget._texture = renderTarget.GL.createTexture();
        renderTarget.GL.bindTexture(renderTarget.GL.TEXTURE_2D, renderTarget._texture);

        renderTarget.GL.texParameteri(renderTarget.GL.TEXTURE_2D, renderTarget.GL.TEXTURE_MAG_FILTER, renderTarget.GL.LINEAR);
        renderTarget.GL.texParameteri(renderTarget.GL.TEXTURE_2D, renderTarget.GL.TEXTURE_MIN_FILTER, renderTarget.GL.LINEAR);
        renderTarget.GL.texParameteri(renderTarget.GL.TEXTURE_2D, renderTarget.GL.TEXTURE_WRAP_S, renderTarget.GL.CLAMP_TO_EDGE);
        renderTarget.GL.texParameteri(renderTarget.GL.TEXTURE_2D, renderTarget.GL.TEXTURE_WRAP_T, renderTarget.GL.CLAMP_TO_EDGE);

        switch (format) {
            case RenderTargetFormat.FORMAT_128BIT_FLOAT: {
                renderTarget.GL.texImage2D(renderTarget.GL.TEXTURE_2D, 0, renderTarget.GL.RGBA32F, renderTarget.texWidth, renderTarget.texHeight, 0, renderTarget.GL.RGBA, renderTarget.GL.FLOAT, 0);
                break;
            }
            case RenderTargetFormat.FORMAT_64BIT_FLOAT: {
                renderTarget.GL.texImage2D(renderTarget.GL.TEXTURE_2D, 0, renderTarget.GL.RGBA16F, renderTarget.texWidth, renderTarget.texHeight, 0, renderTarget.GL.RGBA, renderTarget.GL.HALF_FLOAT, 0);
                break;
            }
            case RenderTargetFormat.FORMAT_16BIT_DEPTH: {
                renderTarget.GL.texParameteri(renderTarget.GL.TEXTURE_2D, renderTarget.GL.TEXTURE_MAG_FILTER, renderTarget.GL.NEAREST);
                renderTarget.GL.texParameteri(renderTarget.GL.TEXTURE_2D, renderTarget.GL.TEXTURE_MIN_FILTER, renderTarget.GL.NEAREST);
                break;
            }
            case RenderTargetFormat.FORMAT_16BIT_RED_FLOAT: {
                renderTarget.GL.texImage2D(renderTarget.GL.TEXTURE_2D, 0, renderTarget.GL.R16F, renderTarget.texWidth, renderTarget.texHeight, 0, renderTarget.GL.RED, renderTarget.GL.HALF_FLOAT, 0);
                break;
            }
            case RenderTargetFormat.FORMAT_32BIT_RED_FLOAT: {
                renderTarget.GL.texImage2D(renderTarget.GL.TEXTURE_2D, 0, renderTarget.GL.R32F, renderTarget.texWidth, renderTarget.texHeight, 0, renderTarget.GL.RED, renderTarget.GL.FLOAT, 0);
                break;
            }
            case RenderTargetFormat.FORMAT_8BIT_RED: {
                renderTarget.GL.texImage2D(renderTarget.GL.TEXTURE_2D, 0, renderTarget.GL.R8, renderTarget.texWidth, renderTarget.texHeight, 0, renderTarget.GL.RED, renderTarget.GL.UNSIGNED_BYTE, 0);
                break;
            }
            case RenderTargetFormat.FORMAT_32BIT: {
                renderTarget.GL.texImage2D(renderTarget.GL.TEXTURE_2D, 0, renderTarget.GL.RGBA, renderTarget.texWidth, renderTarget.texHeight, 0, renderTarget.GL.RGBA, renderTarget.GL.UNSIGNED_BYTE, 0);
                break;
            }
        }

        renderTarget._framebuffer = renderTarget.GL.createFramebuffer();
        renderTarget.GL.bindFramebuffer(renderTarget.GL.FRAMEBUFFER, renderTarget._framebuffer);

        renderTarget.setupDepthStencil(renderTarget.GL.TEXTURE_2D, depthBufferBits, stencilBufferBits, renderTarget.texWidth, renderTarget.texHeight);

        if (format == RenderTargetFormat.FORMAT_16BIT_DEPTH) {
            renderTarget.GL.framebufferTexture2D(renderTarget.GL.FRAMEBUFFER, renderTarget.GL.DEPTH_ATTACHMENT, renderTarget.GL.TEXTURE_2D, renderTarget._texture, 0);
            renderTarget.GL.drawBuffers([renderTarget.GL.NONE]);
            renderTarget.GL.readBuffer(renderTarget.GL.NONE);
        } else {
            renderTarget.GL.framebufferTexture2D(renderTarget.GL.FRAMEBUFFER, renderTarget.GL.COLOR_ATTACHMENT0, renderTarget.GL.TEXTURE_2D, renderTarget._texture, 0);
        }

        renderTarget.GL.bindFramebuffer(renderTarget.GL.FRAMEBUFFER, 0);
        renderTarget.GL.bindTexture(renderTarget.GL.TEXTURE_2D, 0);

        return renderTarget;
    }


    setupDepthStencil(texType: number, depthBufferBits: number, stencilBufferBits: number, width: number, height: number) {
        const renderTarget = this;
        renderTarget.width = width;
        renderTarget.height = height;
        if (depthBufferBits > 0 && stencilBufferBits > 0) {
            renderTarget._hasDepth = true;
            let internalFormat = renderTarget.GL.DEPTH24_STENCIL8;
            renderTarget._depthTexture = renderTarget.GL.createTexture();
            renderTarget.GL.bindTexture(texType, renderTarget._depthTexture);
            renderTarget.GL.texImage2D(texType, 0, internalFormat, width, height, 0, renderTarget.GL.DEPTH_COMPONENT, renderTarget.GL.UNSIGNED_INT, 0);
            renderTarget.GL.texParameteri(texType, renderTarget.GL.TEXTURE_MAG_FILTER, renderTarget.GL.NEAREST);
            renderTarget.GL.texParameteri(texType, renderTarget.GL.TEXTURE_MIN_FILTER, renderTarget.GL.NEAREST);
            renderTarget.GL.texParameteri(texType, renderTarget.GL.TEXTURE_WRAP_S, renderTarget.GL.CLAMP_TO_EDGE);
            renderTarget.GL.texParameteri(texType, renderTarget.GL.TEXTURE_WRAP_T, renderTarget.GL.CLAMP_TO_EDGE);

            renderTarget.GL.bindFramebuffer(renderTarget.GL.FRAMEBUFFER, renderTarget._framebuffer);

            renderTarget.GL.framebufferTexture2D(renderTarget.GL.FRAMEBUFFER, renderTarget.GL.DEPTH_ATTACHMENT, texType, renderTarget._depthTexture, 0);
            renderTarget.GL.framebufferTexture2D(renderTarget.GL.FRAMEBUFFER, renderTarget.GL.STENCIL_ATTACHMENT, texType, renderTarget._depthTexture, 0);
        } else if (depthBufferBits > 0) {
            renderTarget._hasDepth = true;

            // Renderbuffer 
            renderTarget._depthTexture = renderTarget.GL.createRenderbuffer();
            renderTarget.GL.bindRenderbuffer(renderTarget.GL.RENDERBUFFER, renderTarget._depthTexture);
            renderTarget.GL.renderbufferStorage(renderTarget.GL.RENDERBUFFER, renderTarget.GL.DEPTH_COMPONENT16, width, height);
            renderTarget.GL.framebufferRenderbuffer(renderTarget.GL.FRAMEBUFFER, renderTarget.GL.DEPTH_ATTACHMENT, renderTarget.GL.RENDERBUFFER, renderTarget._depthTexture);

        } else {
            renderTarget._depthTexture = renderTarget.GL.createTexture();
            renderTarget.GL.bindTexture(texType, renderTarget._depthTexture);
            const format = depthBufferBits == 16 ? renderTarget.GL.DEPTH_COMPONENT16 : renderTarget.GL.DEPTH_COMPONENT;
            renderTarget.GL.texImage2D(texType, 0, format, width, height, 0, renderTarget.GL.DEPTH_COMPONENT, renderTarget.GL.UNSIGNED_INT, 0);
            renderTarget.GL.texParameteri(texType, renderTarget.GL.TEXTURE_MAG_FILTER, renderTarget.GL.NEAREST);
            renderTarget.GL.texParameteri(texType, renderTarget.GL.TEXTURE_MIN_FILTER, renderTarget.GL.NEAREST);
            renderTarget.GL.texParameteri(texType, renderTarget.GL.TEXTURE_WRAP_S, renderTarget.GL.CLAMP_TO_EDGE);
            renderTarget.GL.texParameteri(texType, renderTarget.GL.TEXTURE_WRAP_T, renderTarget.GL.CLAMP_TO_EDGE);

            renderTarget.GL.bindFramebuffer(renderTarget.GL.FRAMEBUFFER, renderTarget._framebuffer);
            renderTarget.GL.framebufferTexture2D(renderTarget.GL.FRAMEBUFFER, renderTarget.GL.DEPTH_ATTACHMENT, texType, renderTarget._depthTexture, 0);

        }
    }

    static initCube(cubeMapSize: number, depthBufferBits: number, antiAliasing: boolean, format: RenderTargetFormat, stencilBufferBits: number, contextId: number) {
        const renderTarget = new RenderTarget();
        renderTarget.width = cubeMapSize;
        renderTarget.height = cubeMapSize;
        renderTarget.isCubeMap = true;
        renderTarget.isDepthAttachment = false;
        renderTarget._hasDepth = false;

        renderTarget.texHeight = renderTarget.height;
        renderTarget.texWidth = renderTarget.width;

        renderTarget.contextId = contextId;
        renderTarget.format = format;

        renderTarget._texture = renderTarget.GL.createTexture();
        renderTarget.GL.bindTexture(renderTarget.GL.TEXTURE_CUBE_MAP, renderTarget._texture);

        renderTarget.GL.texParameteri(renderTarget.GL.TEXTURE_CUBE_MAP, renderTarget.GL.TEXTURE_MAG_FILTER, renderTarget.GL.NEAREST);
        renderTarget.GL.texParameteri(renderTarget.GL.TEXTURE_CUBE_MAP, renderTarget.GL.TEXTURE_MIN_FILTER, renderTarget.GL.NEAREST);
        renderTarget.GL.texParameteri(renderTarget.GL.TEXTURE_CUBE_MAP, renderTarget.GL.TEXTURE_WRAP_S, renderTarget.GL.CLAMP_TO_EDGE);
        renderTarget.GL.texParameteri(renderTarget.GL.TEXTURE_CUBE_MAP, renderTarget.GL.TEXTURE_WRAP_T, renderTarget.GL.CLAMP_TO_EDGE);

        switch (format) {
            case RenderTargetFormat.FORMAT_128BIT_FLOAT: {
                for (let i = 0; i < 6; i++) renderTarget.GL.texImage2D(renderTarget.GL.TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, renderTarget.GL.RGBA32F, renderTarget.texWidth, renderTarget.texHeight, 0, renderTarget.GL.RGBA, renderTarget.GL.FLOAT, 0);
                break;
            }
            case RenderTargetFormat.FORMAT_64BIT_FLOAT: {
                for (let i = 0; i < 6; i++) renderTarget.GL.texImage2D(renderTarget.GL.TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, renderTarget.GL.RGBA16F, renderTarget.texWidth, renderTarget.texHeight, 0, renderTarget.GL.RGBA, renderTarget.GL.HALF_FLOAT, 0);
                break;
            }
            case RenderTargetFormat.FORMAT_16BIT_DEPTH: {
                renderTarget.GL.texParameteri(renderTarget.GL.TEXTURE_CUBE_MAP, renderTarget.GL.TEXTURE_MAG_FILTER, renderTarget.GL.NEAREST);
                renderTarget.GL.texParameteri(renderTarget.GL.TEXTURE_CUBE_MAP, renderTarget.GL.TEXTURE_MIN_FILTER, renderTarget.GL.NEAREST);
                break;
            }
            case RenderTargetFormat.FORMAT_32BIT:
            default: {
                for (let i = 0; i < 6; i++) renderTarget.GL.texImage2D(renderTarget.GL.TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, renderTarget.GL.RGBA, renderTarget.texWidth, renderTarget.texHeight, 0, renderTarget.GL.RGBA, renderTarget.GL.UNSIGNED_BYTE, 0);
            }
        }

        renderTarget._framebuffer = renderTarget.GL.createFramebuffer();
        renderTarget.GL.bindFramebuffer(renderTarget.GL.FRAMEBUFFER, renderTarget._framebuffer);


        renderTarget.setupDepthStencil(renderTarget.GL.TEXTURE_CUBE_MAP, depthBufferBits, stencilBufferBits, renderTarget.texWidth, renderTarget.texHeight);

        if (format == RenderTargetFormat.FORMAT_16BIT_DEPTH) {
            renderTarget.isDepthAttachment = true;
            renderTarget.GL.drawBuffers([renderTarget.GL.NONE]);
            renderTarget.GL.readBuffer(renderTarget.GL.NONE);
        }

        renderTarget.GL.bindFramebuffer(renderTarget.GL.FRAMEBUFFER, 0);
        renderTarget.GL.bindTexture(renderTarget.GL.TEXTURE_CUBE_MAP, 0);

        return renderTarget;
    }

    destroy() {
        this.GL.deleteTexture(this._texture);

        if (this._hasDepth) {
            this.GL.deleteTexture(this._depthTexture);
        }

        this.GL.deleteFramebuffer(this._framebuffer);
    }

    colorAsTexture(unit: TextureUnit) {
        this.GL.activeTexture(this.GL.TEXTURE0 + unit.value);
        this.GL.bindTexture(this.isCubeMap ? this.GL.TEXTURE_CUBE_MAP : this.GL.TEXTURE_2D, this._texture);
    }

    depthAsTexture(depth: TextureUnit) {
        this.GL.activeTexture(this.GL.TEXTURE0 + depth.value);
        this.GL.bindTexture(this.isCubeMap ? this.GL.TEXTURE_CUBE_MAP : this.GL.TEXTURE_2D, this._texture);
    }

    setDepthStencilFrom(source: RenderTarget) {
        this._depthTexture = source._depthTexture;
        this.GL.bindFramebuffer(this.GL.FRAMEBUFFER, this._framebuffer);
        this.GL.framebufferTexture2D(this.GL.FRAMEBUFFER, this.GL.DEPTH_ATTACHMENT, this.isCubeMap ? this.GL.TEXTURE_CUBE_MAP : this.GL.TEXTURE_2D, this._depthTexture, 0);
    }


    getPixels(data: Uint8Array) {
        this.GL.bindFramebuffer(this.GL.FRAMEBUFFER, this._framebuffer);

        switch (this.format) {
            case RenderTargetFormat.FORMAT_128BIT_FLOAT: {
                this.GL.readPixels(0, 0, this.texWidth, this.texHeight, this.GL.RGBA, this.GL.FLOAT, data);
                break;
            }
            case RenderTargetFormat.FORMAT_64BIT_FLOAT: {
                this.GL.readPixels(0, 0, this.texWidth, this.texHeight, this.GL.RGBA, this.GL.HALF_FLOAT, data);
                break;
            }
            case RenderTargetFormat.FORMAT_8BIT_RED: {
                this.GL.readPixels(0, 0, this.texWidth, this.texHeight, this.GL.RED, this.GL.UNSIGNED_BYTE, data);
                break;
            }
            case RenderTargetFormat.FORMAT_16BIT_RED_FLOAT: {
                this.GL.readPixels(0, 0, this.texWidth, this.texHeight, this.GL.RED, this.GL.HALF_FLOAT, data);
                break;
            }
            case RenderTargetFormat.FORMAT_32BIT:
            default: {
                this.GL.readPixels(0, 0, this.texWidth, this.texHeight, this.GL.RGBA, this.GL.UNSIGNED_BYTE, data);
                break;
            }
        }
    }

    generateMipMaps(levels: number) {
        this.GL.bindTexture(this.GL.TEXTURE_2D, this._texture);
        this.GL.generateMipmap(this.GL.TEXTURE_2D);
    }
}

export enum RenderTargetFormat {
    FORMAT_32BIT,
    FORMAT_64BIT_FLOAT,
    FORMAT_32BIT_RED_FLOAT,
    FORMAT_128BIT_FLOAT,
    FORMAT_16BIT_DEPTH,
    FORMAT_8BIT_RED,
    FORMAT_16BIT_RED_FLOAT
}
