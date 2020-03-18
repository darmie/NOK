import { Canvas } from "./Canvas"
// import * as graphics4 from "./Graphics4";
import { DepthStencilFormat } from "./DepthStencilFormat";
import { TextureFormat } from "./TextureFormat";
import { Bytes } from "../Internal/Bytes";
import { GL } from "../GL"
import { RenderTarget } from "./Graphics4/RenderTarget";
import { Texture } from "./Graphics4/Texture";
import { Graphics } from "./Graphics4/Graphics";
import { Graphics2 } from "./Graphics4/Graphics2";

export class CubeMap implements Canvas {
    format: TextureFormat;
    isRenderTarget: boolean;
    depthStencilFormat: DepthStencilFormat;
    graphics4: Graphics;

    public frameBuffer: WebGLFramebuffer = null;
    public texture: Texture = null;
    public renderTarget: RenderTarget = null;
    public depthTexture: any = null;
    public isDepthAttachment: boolean = false;

    constructor(public myWidth:number, public myHeight:number) {
    }

    static create(size: number, format: TextureFormat = null, readable: boolean, renderTarget: boolean, depthStencil: DepthStencilFormat, contextId: number) {
        var cubeMap = new CubeMap(size, size);
        cubeMap.format = format;
        cubeMap.texture = null;
        cubeMap.isRenderTarget = renderTarget
        if (renderTarget) cubeMap.initRenderTarget(size, this.getDepthBufferBits(depthStencil), this.getRenderTargetFormat(format), this.getStencilBufferBits(depthStencil), contextId);
        return cubeMap;
    }

    static createRenderTarget(size: number, format: TextureFormat, depthStencil: DepthStencilFormat = null, contextId: number = 0): CubeMap {
        return this.create(size, format == null ? TextureFormat.RGBA32 : format, false, true, depthStencil, contextId);
    }

    private initRenderTarget(cubeMapSize: number, depthBufferBits: number, format: number, stencilBufferBits: number, contextId: number) {
        return RenderTarget.initCube(cubeMapSize, depthBufferBits, false, format, stencilBufferBits, contextId);
    }


    private static getRenderTargetFormat(format: TextureFormat): number {
        switch (format) {
            case TextureFormat.RGBA32:	// Target32Bit
                return 0;
            case TextureFormat.RGBA64:	// Target64BitFloat
                return 1;
            case TextureFormat.RGBA128:	// Target128BitFloat
                return 3;
            case TextureFormat.DEPTH16:	// Target16BitDepth
                return 4;
            default:
                return 0;
        }
    }

    private static getDepthBufferBits(depthAndStencil: DepthStencilFormat): number {
        switch (depthAndStencil) {
            case DepthStencilFormat.NoDepthAndStencil: return -1;
            case DepthStencilFormat.DepthOnly: return 24;
            case DepthStencilFormat.DepthAutoStencilAuto: return 24;
            case DepthStencilFormat.Depth24Stencil8: return 24;
            case DepthStencilFormat.Depth32Stencil8: return 32;
            case DepthStencilFormat.Depth16: return 16;
        }
    }

    private static getStencilBufferBits(depthAndStencil: DepthStencilFormat): number {
        switch (depthAndStencil) {
            case DepthStencilFormat.NoDepthAndStencil: return -1;
            case DepthStencilFormat.DepthOnly: return -1;
            case DepthStencilFormat.DepthAutoStencilAuto: return 8;
            case DepthStencilFormat.Depth24Stencil8: return 8;
            case DepthStencilFormat.Depth32Stencil8: return 8;
            case DepthStencilFormat.Depth16: return 0;
        }
    }

    private static getTextureFormat(format: TextureFormat): number {
        switch (format) {
            case TextureFormat.RGBA32:
                return 0;
            case TextureFormat.RGBA128:
                return 3;
            case TextureFormat.RGBA64:
                return 4;
            case TextureFormat.A32:
                return 5;
            default:
                return 1; // Grey 8
        }
    }


    public get width(): number {
        if (this.texture != null) return this.texture.texWidth; else return this.renderTarget.width;
    }

    public get height(): number {
        if (this.texture != null) return this.texture.texHeight; else return this.renderTarget.height;
    }


    public get g2(): Graphics2 {
        return null;
    }


    public get g4(): Graphics {
        if (this.graphics4 == null) {
            this.graphics4 = new Graphics(this);
        }
        return this.graphics4;
    }

    public unload(): void {

    }

    public lock(level: number = 0): Bytes {
        return null;
    }

    public unlock(): void {

    }

    public set(stage: number): void {
        const G = GL.context
		G.activeTexture(G.TEXTURE0 + stage);
		G.bindTexture(G.TEXTURE_CUBE_MAP, this.texture._texture);
	}

	public setDepth(stage: number): void {
        const G = GL.context
		G.activeTexture(G.TEXTURE0 + stage);
		G.bindTexture(G.TEXTURE_CUBE_MAP, this.renderTarget._depthTexture);
	}

}