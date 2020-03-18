import { Canvas } from "./Canvas"
import { Resource } from "../Internal/Resource"
import { Usage } from "./Usage"
import { GL } from "../GL"
import { TextureFormat } from "./TextureFormat"
import { ImageFormat } from "./ImageFormat"
import { DepthStencilFormat } from "./DepthStencilFormat"
import { RenderTargetFormat, RenderTarget } from "./Graphics4/RenderTarget"
import { Bytes } from "../Internal/Bytes"
import { Color } from "./Color"
import { Texture } from "./Graphics4/Texture"
import { Graphics } from "./Graphics4/Graphics"
import { Graphics2 } from "./Graphics4/Graphics2"

export enum ImageCompression {
    NONE,
    DXT5,
    ASTC,
    PVRTC
}

// export interface ICanvas extends Canvas, Resource { }

export class Image implements Canvas {

    format: TextureFormat;
    data: Uint8Array;
    readable: boolean;
    renderTarget: RenderTarget
    texture: Texture

    compression: ImageCompression;

    private graphics4: Graphics
    private graphics2: Graphics2

    constructor(readable: boolean) {
        this.readable = readable;
    }

    static getRenderTargetFormat(format: TextureFormat): number {
        switch (format) {
            case TextureFormat.RGBA32:	// Target32Bit
                return 0;
            case TextureFormat.RGBA64:	// Target64BitFloat
                return 1;
            case TextureFormat.A32:		// Target32BitRedFloat
                return 2;
            case TextureFormat.RGBA128:	// Target128BitFloat
                return 3;
            case TextureFormat.DEPTH16:	// Target16BitDepth
                return 4;
            case TextureFormat.L8:
                return 5;	// Target8BitRed
            case TextureFormat.A16:
                return 6;	// Target16BitRedFloat
            default:
                return 0;
        }
    }

    sizeOf(format: TextureFormat) {
        switch (Image.getTextureFormat(format)) {
            case ImageFormat.RGBA128:
                return 16;
            case ImageFormat.RGBA32:
            case ImageFormat.BGRA32:
                return 4;
            case ImageFormat.RGBA64:
                return 8;
            case ImageFormat.A32:
                return 4;
            case ImageFormat.A16:
                return 2;
            case ImageFormat.GREY8:
                return 1;
            case ImageFormat.RGB24:
                return 3;
        }
        return -1;
    }

    _sizeOf(format: ImageFormat) {
        switch (format) {
            case ImageFormat.RGBA128:
                return 16;
            case ImageFormat.RGBA32:
            case ImageFormat.BGRA32:
                return 4;
            case ImageFormat.RGBA64:
                return 8;
            case ImageFormat.A32:
                return 4;
            case ImageFormat.A16:
                return 2;
            case ImageFormat.GREY8:
                return 1;
            case ImageFormat.RGB24:
                return 3;
        }
        return -1;
    }


    static getDepthBufferBits(depthAndStencil: DepthStencilFormat): number {
        switch (depthAndStencil) {
            case DepthStencilFormat.NoDepthAndStencil: return -1;
            case DepthStencilFormat.DepthOnly: return 24;
            case DepthStencilFormat.DepthAutoStencilAuto: return 24;
            case DepthStencilFormat.Depth24Stencil8: return 24;
            case DepthStencilFormat.Depth32Stencil8: return 32;
            case DepthStencilFormat.Depth16: return 16;
        }
    }

    static getStencilBufferBits(depthAndStencil: DepthStencilFormat): number {
        switch (depthAndStencil) {
            case DepthStencilFormat.NoDepthAndStencil: return -1;
            case DepthStencilFormat.DepthOnly: return -1;
            case DepthStencilFormat.DepthAutoStencilAuto: return 8;
            case DepthStencilFormat.Depth24Stencil8: return 8;
            case DepthStencilFormat.Depth32Stencil8: return 8;
            case DepthStencilFormat.Depth16: return 0;
        }
    }

    static getTextureFormat(format: TextureFormat): number {
        switch (format) {
            case TextureFormat.RGBA32:
                return 0;
            case TextureFormat.RGBA128:
                return 3;
            case TextureFormat.RGBA64:
                return 4;
            case TextureFormat.A32:
                return 5;
            case TextureFormat.A16:
                return 7;
            default:
                return 1; // Grey8
        }
    }

    init(width: number, height: number, format: ImageFormat) {
        this.texture = Texture.init(width, height, format);
    }

    init3D(width: number, height: number, depth: number, format: ImageFormat) {
        this.texture = Texture.init3D(width, height, depth, format);
    }

    initRenderTarget(width: number, height: number, depthBufferBits: number, antiAliasing: boolean, format: RenderTargetFormat, stencilBufferBits: number, contextId: number) {
        this.renderTarget = RenderTarget.init(width, height, depthBufferBits, antiAliasing, format, stencilBufferBits, contextId);
    }

    private initFromBytes(bytes: ArrayBuffer, width: number, height: number, format: ImageFormat) {
        this.data = new Uint8Array(bytes);
        this.width = width;
        this.height = height;
        this.readable = true;
        this.texture = Texture.initFromImage(this);
    }



    private initFromBytes3D(bytes: ArrayBuffer, width: number, height: number, depth: number, format: ImageFormat) {
        this.data = new Uint8Array(bytes);
        this.width = width;
        this.height = height;
        this.readable = true;
        this.depth = depth;
        this.texture = Texture.initFromImage3D(this);
    }

    static fromBytes(bytes: Bytes, width: number, height: number, format: TextureFormat = null, usage: Usage = null) {
        var readable = true;
        var image = new Image(readable);
        image.format = format;
        image.initFromBytes(bytes.getData(), width, height, this.getTextureFormat(format));
        return image;
    }

    static fromBytes3D(bytes: Bytes, width: number, height: number, depth: number, format: TextureFormat = null, usage: Usage = null) {
        var readable = true;
        var image = new Image(readable);
        image.format = format;
        image.initFromBytes3D(bytes.getData(), width, height, depth, this.getTextureFormat(format));
        return image;
    }

    static create(width: number, height: number, format: TextureFormat = null, readable: boolean, renderTarget: boolean, depthStencil: DepthStencilFormat, antiAliasing: boolean, contextId: number): Image {
        const image = new Image(readable);
        image.format = format;

        if (renderTarget) image.initRenderTarget(width, height, this.getDepthBufferBits(depthStencil), antiAliasing, this.getRenderTargetFormat(format), this.getStencilBufferBits(depthStencil), contextId);
        else image.init(width, height, this.getTextureFormat(format));
        return image;
    }

    static create3D(width: number, height: number, depth: number, format: TextureFormat, readable: boolean, contextId: number): Image {
        var image = new Image(readable);
        image.format = format;
        image.init3D(width, height, depth, this.getTextureFormat(format));
        return image;
    }


    static createEmpty(readable: boolean, floatFormat: boolean) {
        var image = new Image(readable);
        image.format = floatFormat ? TextureFormat.RGBA128 : TextureFormat.RGBA32;
        return image;
    }


    get depth() {
        return this.texture ? this.texture.texDepth : 0;
    }

    set depth(depth: number) {
        this.texture ? this.texture.texDepth = depth : this.texture.texDepth = 0;
    }

    get realWidth() {
        return this.texture ? this.texture.texWidth : this.renderTarget.texWidth;
    }

    get realHeight() {
        return this.texture ? this.texture.texHeight : this.renderTarget.texHeight;
    }

    isOpaque(x: number, y: number) {
        return (this.texture.at(x, y) & 0xff) != 0;
    }

    private atInternal(x: number, y: number) {
        return this.texture.at(x, y);
    }

    at(x: number, y: number) {
        return Color.fromValue(this.atInternal(x, y));
    }

    /**
     *  The width of the image in pixels and been power of two.
     */
    get width() {
        return this.width
    }

    set width(width: number) {
        this.width = width
    }

    /**
     * The height of the image in pixels and been power of two.
     */
    get height() {
        return this.width
    }

    set height(width: number) {
        this.width = width
    }

    /**
     * Use this for 2D operations.
     */
    public get g2(): Graphics2 {
        this.graphics2 = new Graphics2(this);
        return this.graphics2;
    }


    /**
     * Use this for 3D operations.
     */
    public get g4(): Graphics {
        this.graphics4 = new Graphics(this);
        return this.graphics4;
    }

    public get maxSize() {
        return 4096;
    }

    bytes: Bytes = null

    lock() {
        const size = this.texture.sizeOf(this.format) * this.texture.texWidth * this.texture.texHeight
        this.bytes = Bytes.alloc(size)
        return this.bytes
    }

    unlock() {
        const b = this.bytes.getData();
        const tex = this.bytes.getData();
        const size = this.texture.sizeOf(this.texture.format)
        const stride = this.texture.stride();
        for (let y = 0; y < this.texture.texHeight; ++y) {
            for (let x = 0; x < this.texture.texWidth; ++x) {
                for (let i = 0; i < size; ++i) {
                    tex[y * stride + x * size + i] = b[(y * this.texture.texWidth + x) * size + i];
                }
            }
        }

        this.texture.unlock()
    }


    unload(): void {
        this.texture = null;
        this.renderTarget = null;
    }


    private pixels: Bytes = null;
    private pixelsAllocated: boolean = false;

    private getPixelsInternal(formatSize: number) {
        if (this.renderTarget == null) return null;

        if (!this.pixelsAllocated) {
            const size = formatSize * this.renderTarget.width * this.renderTarget.height
            this.pixels = Bytes.alloc(size);
            this.pixelsAllocated = true;
        }

        const b = new Uint8Array(this.pixels.getData());
        this.renderTarget.getPixels(b);
        this.pixels = Bytes.ofData(b);
        return this.pixels;
    }

    getPixels() {
        return this.getPixelsInternal(this.sizeOf(this.format));
    }

    generateMipMaps(levels: number) {
        this.texture != null ? this.texture.generateMipMaps(levels) : this.renderTarget.generateMipMaps(levels);
    }

    setMipMaps(mipmaps: Array<Image>) {
        for (let i = 0; i < mipmaps.length; i++) {
            const image = mipmaps[i];
            const level = i + 1;
            this.texture.setMipMap(image.texture, level);
        }
    }

    setDepthStencil(image: Image) {
        this.renderTarget.setDepthStencilFrom(image.renderTarget);
    }

    clear(x: number, y: number, z: number, width: number, height: number, depth: number, color: Color) {
        if (this.texture != null) this.texture.clear(x, y, z, width, height, depth, color);
    }

    set(stage: number) {
        const G = GL.context
        G.activeTexture(G.TEXTURE0 + stage);
        G.bindTexture(G.TEXTURE_2D, this.texture._texture);
        // if (video != null) SystemImpl.gl.texImage2D(GL.TEXTURE_2D, 0, GL.RGBA, GL.RGBA, GL.UNSIGNED_BYTE, video);
    }

    setDepth(stage: number) {
        const G = GL.context
        G.activeTexture(G.TEXTURE0 + stage);
        if(this.renderTarget != null) G.bindTexture(G.TEXTURE_2D, this.renderTarget._depthTexture);
    }



}