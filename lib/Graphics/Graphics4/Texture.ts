import { ImageFormat } from "../ImageFormat"
import { GameView } from "../../GameView";
import { TextureUnit } from "../TextureUnit";
import { Image, ImageCompression } from "../Image";
import { Bytes } from "../../Internal/Bytes";
import { Color } from "../Color";



const GL_COMPRESSED_RGBA_ASTC_4x4_KHR =  0x93B0
const GL_COMPRESSED_RGBA_ASTC_5x4_KHR =  0x93B1
const GL_COMPRESSED_RGBA_ASTC_5x5_KHR =  0x93B2
const GL_COMPRESSED_RGBA_ASTC_6x5_KHR =  0x93B3
const GL_COMPRESSED_RGBA_ASTC_6x6_KHR =  0x93B4
const GL_COMPRESSED_RGBA_ASTC_8x5_KHR =  0x93B5
const GL_COMPRESSED_RGBA_ASTC_8x6_KHR =  0x93B6
const GL_COMPRESSED_RGBA_ASTC_8x8_KHR =  0x93B7
const GL_COMPRESSED_RGBA_ASTC_10x5_KHR =  0x93B8
const GL_COMPRESSED_RGBA_ASTC_10x6_KHR =  0x93B9
const GL_COMPRESSED_RGBA_ASTC_10x8_KHR =  0x93BA
const GL_COMPRESSED_RGBA_ASTC_10x10_KHR =  0x93BB
const GL_COMPRESSED_RGBA_ASTC_12x10_KHR =  0x93BC
const GL_COMPRESSED_RGBA_ASTC_12x12_KHR =  0x93BD
const GL_COMPRESSED_SRGB8_ALPHA8_ASTC_4x4_KHR =  0x93D0
const GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x4_KHR =  0x93D1
const GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x5_KHR =  0x93D2
const GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x5_KHR =  0x93D3
const GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x6_KHR =  0x93D4
const GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x5_KHR =  0x93D5
const GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x6_KHR =  0x93D6
const GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x8_KHR =  0x93D7
const GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x5_KHR =  0x93D8
const GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x6_KHR =  0x93D9
const GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x8_KHR =  0x93DA
const GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x10_KHR =  0x93DB
const GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x10_KHR =  0x93DC
const GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x12_KHR =  0x93DD


function astcFormat(blockX:number, blockY:number) {
	switch (blockX) {
	case 4:
		switch (blockY) {
		case 4:
			return GL_COMPRESSED_RGBA_ASTC_4x4_KHR;
		}
	case 5:
		switch (blockY) {
		case 4:
			return GL_COMPRESSED_RGBA_ASTC_5x4_KHR;
		case 5:
			return GL_COMPRESSED_RGBA_ASTC_5x5_KHR;
		}
	case 6:
		switch (blockY) {
		case 5:
			return GL_COMPRESSED_RGBA_ASTC_6x5_KHR;
		case 6:
			return GL_COMPRESSED_RGBA_ASTC_6x6_KHR;
		}
	case 8:
		switch (blockY) {
		case 5:
			return GL_COMPRESSED_RGBA_ASTC_8x5_KHR;
		case 6:
			return GL_COMPRESSED_RGBA_ASTC_8x6_KHR;
		case 8:
			return GL_COMPRESSED_RGBA_ASTC_8x8_KHR;
		}
	case 10:
		switch (blockY) {
		case 5:
			return GL_COMPRESSED_RGBA_ASTC_10x5_KHR;
		case 6:
			return GL_COMPRESSED_RGBA_ASTC_10x6_KHR;
		case 8:
			return GL_COMPRESSED_RGBA_ASTC_10x8_KHR;
		case 10:
			return GL_COMPRESSED_RGBA_ASTC_10x10_KHR;
		}
	case 12:
		switch (blockY) {
		case 10:
			return GL_COMPRESSED_RGBA_ASTC_12x10_KHR;
		case 12:
			return GL_COMPRESSED_RGBA_ASTC_12x12_KHR;
		}
	}
	return 0;
}


function convertType(format: ImageFormat) {
    switch (format) {
        case ImageFormat.RGBA128:
        case ImageFormat.RGBA64:
        case ImageFormat.A32:
        case ImageFormat.A16:
            return GameView.context.FLOAT;
        case ImageFormat.RGBA32:
        default:
            return GameView.context.UNSIGNED_BYTE;
    }
}

function convertFormat(format: ImageFormat) {
    switch (format) {
        case ImageFormat.BGRA32:
            return GameView.context.RGBA;
        case ImageFormat.RGBA32:
        case ImageFormat.RGBA64:
        case ImageFormat.RGBA128:
        default:
            return GameView.context.RGBA;
        case ImageFormat.RGB24:
            return GameView.context.RGB;
        case ImageFormat.A32:
        case ImageFormat.A16:
        case ImageFormat.GREY8:
            return GameView.context.RED;
    }
}

function convertInternalFormat(format: ImageFormat) {
    switch (format) {
        case ImageFormat.RGBA128:
            return GameView.context.RGBA32F;
        case ImageFormat.RGBA64:
            return GameView.context.RGBA16F;
        case ImageFormat.RGBA32:
        default:
            return GameView.context.RGBA8;
        case ImageFormat.RGB24:
            return GameView.context.RGB;
        case ImageFormat.A32:
            return GameView.context.R32F;
        case ImageFormat.A16:
            return GameView.context.R16F;
        case ImageFormat.GREY8:
            return GameView.context.R8;
    }
}

export class Texture extends Image {
    texWidth: number;
    texHeight: number;
    texDepth: number;

    _format: ImageFormat;
    pixfmt: number;
    _texture: WebGLTexture;
    

    static GL = GameView.context

    constructor() {
        super(false);
        this._format = null;
        this.pixfmt = 0;
        this.texDepth = 1;
        this.texWidth = 0;
        this.texHeight = 0;
        this._texture = null;
    }




    static init(width: number, height: number, format: ImageFormat) {
        const instance = new Texture();
        instance.texWidth = width;
        instance.texHeight = height;
        instance.texDepth = 1;
        instance._format = format;

        this.GL.pixelStorei(this.GL.UNPACK_ALIGNMENT, 1);
        instance._texture = this.GL.createTexture();
        this.GL.bindTexture(this.GL.TEXTURE_2D, instance._texture);
        this.GL.texParameteri(this.GL.TEXTURE_2D, this.GL.TEXTURE_MIN_FILTER, this.GL.LINEAR);
        this.GL.texParameteri(this.GL.TEXTURE_2D, this.GL.TEXTURE_MIN_FILTER, this.GL.LINEAR);

        if (convertType(format) == this.GL.FLOAT) {
            this.GL.texImage2D(this.GL.TEXTURE_2D, 0, convertInternalFormat(format), instance.texWidth, instance.texHeight, 0, convertFormat(format), this.GL.FLOAT, null);
        } else {
            this.GL.texImage2D(this.GL.TEXTURE_2D, 0, convertInternalFormat(format), instance.texWidth, instance.texHeight, 0, convertFormat(format), this.GL.UNSIGNED_BYTE, null);
        }

        return instance
    }

    private static maxi(a:number, b:number) {
        return a > b ? a : b;
    }

    static initFromImage(image:Image){
        const instance = new Texture();
        instance.texWidth = image.width;
        instance.texHeight = image.height;
        instance.texDepth = 1;
        instance._format = convertFormat(Image.getRenderTargetFormat(image.format));

        switch(image.compression){
            case ImageCompression.NONE:{
                break;
            }
            case ImageCompression.PVRTC:{
                instance.texWidth = this.maxi(instance.texWidth, instance.texHeight);
                instance.texHeight = this.maxi(instance.texWidth, instance.texHeight);
                if (instance.texWidth < 8) instance.texWidth = 8;
                if (instance.texHeight < 8) instance.texHeight = 8;
                break;
            }
            default:{
                instance.texWidth = image.width;
                instance.texHeight = image.height;
            }
        }

        const GL = Texture.GL;
        GL.pixelStorei(GL.UNPACK_ALIGNMENT, 1);
        instance._texture = GL.createTexture();
        GL.bindTexture(GL.TEXTURE_2D, instance._texture);

        const convertedType = convertType(Image.getRenderTargetFormat(image.format));
        const isHdr = convertedType == GL.FLOAT;

        const conversionBuffer = new Uint8Array();

        switch(image.compression){
            case ImageCompression.PVRTC:{

            }
            case ImageCompression.ASTC:{
                const blockX = convertInternalFormat(Image.getRenderTargetFormat(image.format)) >> 8;
                const blockY = convertInternalFormat(Image.getRenderTargetFormat(image.format)) >> 0xff;
                GL.compressedTexImage2D(GL.TEXTURE_2D, astcFormat(blockX, blockY), instance.texWidth, instance.texHeight, 0, image.data.length, image.data);
                break;
            }
            case ImageCompression.DXT5:{

            }
            case ImageCompression.NONE:{
                let texData = image.data;
                GL.texImage2D(GL.TEXTURE_2D, 0, convertInternalFormat(Image.getTextureFormat(image.format)), instance.texWidth, instance.texHeight, 0 ,convertFormat(Image.getTextureFormat(image.format)), convertedType, texData);
                break;
            }
        }

        GL.texParameteri(GL.TEXTURE_2D, GL.TEXTURE_MIN_FILTER, GL.LINEAR);
        GL.texParameteri(GL.TEXTURE_2D, GL.TEXTURE_MAG_FILTER, GL.LINEAR);
        GL.texParameteri(GL.TEXTURE_2D, GL.TEXTURE_WRAP_S, GL.CLAMP_TO_EDGE);
        GL.texParameteri(GL.TEXTURE_2D, GL.TEXTURE_WRAP_T, GL.CLAMP_TO_EDGE);

        return instance;

    }

    static initFromImage3D(image:Image){
        const instance = new Texture();
        instance.texWidth = image.width;
        instance.texHeight = image.height;
        instance.texDepth = image.depth;
        instance._format = convertFormat(Image.getRenderTargetFormat(image.format));

        const GL = Texture.GL;
        GL.pixelStorei(GL.UNPACK_ALIGNMENT, 1);
        instance._texture = GL.createTexture();
        GL.bindTexture(GL.TEXTURE_3D, instance._texture);

        const convertedType = convertType(Image.getRenderTargetFormat(image.format));
        const isHdr = convertedType == GL.FLOAT;

        let texData = image.data;

        GL.texImage3D(GL.TEXTURE_3D, 0, convertInternalFormat(Image.getRenderTargetFormat(image.format)), instance.texWidth, instance.texHeight, image.depth, 0, convertFormat(Image.getTextureFormat(image.format)), convertedType, texData);

        GL.texParameteri(GL.TEXTURE_3D, GL.TEXTURE_WRAP_S, GL.CLAMP_TO_EDGE);
        GL.texParameteri(GL.TEXTURE_3D, GL.TEXTURE_WRAP_T, GL.CLAMP_TO_EDGE);
        GL.texParameteri(GL.TEXTURE_3D, GL.TEXTURE_WRAP_R, GL.CLAMP_TO_EDGE);

        GL.texParameteri(GL.TEXTURE_3D, GL.TEXTURE_MAG_FILTER, GL.LINEAR);
        GL.texParameteri(GL.TEXTURE_3D, GL.TEXTURE_MIN_FILTER, GL.LINEAR);
       

        return instance;
    }

    static init3D(width: number, height: number, depth: number, format: ImageFormat) {
        const instance = new Texture();
        instance.texWidth = width;
        instance.texHeight = height;
        instance.texDepth = depth;
        instance._format = format;

        instance._texture = this.GL.createTexture();
        this.GL.bindTexture(this.GL.TEXTURE_3D, instance._texture);
        this.GL.texParameteri(this.GL.TEXTURE_3D, this.GL.TEXTURE_MIN_FILTER, this.GL.LINEAR);
        this.GL.texParameteri(this.GL.TEXTURE_3D, this.GL.TEXTURE_MIN_FILTER, this.GL.LINEAR);

        this.GL.texImage3D(this.GL.TEXTURE_2D, 0, convertInternalFormat(format), instance.texWidth, instance.texHeight, depth, 0, convertFormat(format), this.GL.UNSIGNED_BYTE, null);

        return instance;
    }

    destroy() {
        Texture.GL.deleteTexture(this.texture);
        Texture.GL.flush();
    }

    // textureSet(unit:TextureUnit){
    //     const GL = Texture.GL;
    //     const target = this.texDepth > 1 ? GL.TEXTURE_3D : GL.TEXTURE_2D;

    //     GL.activeTexture(GL.TEXTURE0 + unit.value);

    //     GL.bindTexture(target, this.texture);
    //     GL.texParameteri(GL.TEXTURE_2D, GL.TEXTURE_WRAP_S, );
    // }

    lockCache:Bytes = null;

    lock() {
        if (this.lockCache == null) {
            this.lockCache = Bytes.alloc(4096 * 4096 * 4);
        }

        return this.lockCache;
    }

    unlock() {
        const GL = Texture.GL;
        const target = this.texDepth > 1 ? GL.TEXTURE_3D : GL.TEXTURE_2D;

        const texData = this.lockCache;
        GL.bindTexture(target, this.texture);

        if (this.texDepth > 1) {
            GL.texSubImage3D(GL.TEXTURE_3D, 0, 0, 0, 0, this.texWidth, this.texHeight, this.texDepth, convertFormat(this._format),
                convertType(this._format), new Uint8Array(texData.getData()));
        }
    }

    clear(x: number, y: number, z: number, width: number, height: number, depth: number, color:Color) {
        const GL = Texture.GL;
        const clearColor = new Array<number>(4)
        clearColor[0] = ((color.value & 0x00ff0000) >> 16) / 255.0;
        clearColor[1] = ((color.value & 0x0000ff00) >> 8) / 255.0;
        clearColor[2] = (color.value & 0x000000ff) / 255.0;
        clearColor[3] = ((color.value & 0xff000000) >> 24) / 255.0;
        const target = depth > 1 ? GL.TEXTURE_3D : GL.TEXTURE_2D;
        GL.bindTexture(target, this._texture);
        // This can only work in GL_VERSION_4_4
        // glClearTexSubImage(texture->impl.texture, 0, x, y, z, width, height, depth, convertFormat(texture->format), convertType(texture->format), clearColor);
    }

    upload(data: Uint8Array, stride: number) {
        const GL = Texture.GL;
        GL.bindTexture(GL.TEXTURE_3D, this.texture);
        GL.pixelStorei(GL.UNPACK_ROW_LENGTH, stride);
        GL.texSubImage2D(GL.TEXTURE_2D, 0, 0, 0, this.texWidth, this.texHeight, convertFormat(this._format), GL.UNSIGNED_BYTE, data);

        GL.pixelStorei(GL.UNPACK_ROW_LENGTH, 0);
    }

    generateMipMaps(levels: number) {
        const GL = Texture.GL;
        const target = this.texDepth > 1 ? GL.TEXTURE_3D : GL.TEXTURE_2D;

        GL.bindTexture(target, this.texture);
        GL.generateMipmap(target);
    }

    setMipMap(mipmap: Image, level: number) {
        const GL = Texture.GL;
        const convertedType = convertType(Image.getTextureFormat(mipmap.format));
        const isHdr = convertedType == GL.FLOAT;
        const target = this.texDepth > 1 ? GL.TEXTURE_3D : GL.TEXTURE_2D;
        GL.bindTexture(target, this.texture);
        GL.texImage2D(target, level, convertInternalFormat(Image.getTextureFormat(mipmap.format)), mipmap.width, mipmap.height, 0, convertFormat(Image.getTextureFormat(mipmap.format)),
            convertedType, mipmap.data);
    }

    stride(){
        return this.texWidth * this._sizeOf(this._format);
    }

}
