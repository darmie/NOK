import { Image } from "../Image";
import { ConstantLocation } from "../ConstantLocation";
import { Vector2 } from "../../Math/Vector2";
import { Vector3 } from "../../Math/Vector3";
import { Vector4 } from "../../Math/Vector4";
import { Matrix4 } from "../../Math/Matrix4";
import { Matrix3 } from "../../Math/Matrix3";
import { IGraphics } from "./IGraphics"
import { PipelineState } from "../PipelineState"
import { VertexBuffer } from "../VertexBuffer"
import { Canvas } from "../Canvas"
import { Color } from "../Color";
import { IndexBuffer } from "../IndexBuffer";
import { TextureUnit } from "../TextureUnit";
// import { CubeMap } from "../CubeMap";
import { TextureAddressing } from "../TextureAddressing";
import { TextureFilter } from "../TextureFilter";
import { MipMapFilter } from "../MipMapFilter";
import { CompareMode } from "../CompareMode"
import { CullMode } from "../CullMode";
import { StencilAction } from "../StencilAction";
import { StencilValue } from "../StencilValue";
import { BlendingFactor } from "../BlendingFactor";
import { BlendingOperation } from "../BlendingOperation";
import { Usage } from "../Usage";
import { Screen } from "../../Screen";
import { RenderTarget } from "./RenderTarget";
import {GL} from "../../GL"


export class Graphics implements IGraphics {
    currentPipeline: PipelineState = null;
    private depthTest: boolean = false;
    private depthMask: boolean = false;
    private colorMaskRed: boolean = true;
    private colorMaskGreen: boolean = true;
    private colorMaskBlue: boolean = true;
    private colorMaskAlpha: boolean = true;
    private indicesCount: number;
    private renderTarget:RenderTarget = null;
    private renderTargetFrameBuffer: any = null;
    private renderTargetMSAA: any = null;
    private renderTargetTexture: any = null;
    private isCubeMap: boolean = false;
    private isDepthAttachment: boolean = false;
    private instancedExtension: boolean;
    private blendMinMaxExtension: any;
    private useVertexAttributes: number = 0;
    private frameBuffer:WebGLFramebuffer = null

    constructor(public target: Canvas = null) {
        this.init()
    }

    private init(){
        if (this.target == null) return;
        if((this.target as any).constructor.name == "CubeMap"){
            const cubemap:any = this.target
            this.renderTarget = cubemap.renderTarget
        } else {
            const image:any = this.target
            // this.renderTargetMSAA= image.MSAAFrameBuffer;
            this.renderTarget = image.renderTarget
        }  
        this.renderTargetFrameBuffer = this.renderTarget ? this.renderTarget._framebuffer : null;
        this.renderTargetTexture = this.renderTarget ? this.renderTarget._texture : null
        this.frameBuffer = null;
    }



    begin(additionalRenderTargets?: Canvas[]) {
        let G = GL.context
        G.enable(G.BLEND);
        G.blendFunc(G.SRC_ALPHA, G.ONE_MINUS_SRC_ALPHA);
  
        if (this.renderTarget == null) {
            G.bindFramebuffer(G.FRAMEBUFFER, null);
            G.viewport(0, 0, Screen.Width, Screen.Height);
        } else {
            G.bindFramebuffer(G.FRAMEBUFFER, this.renderTargetFrameBuffer);
            G.viewport(0, 0, this.renderTarget.width, this.renderTarget.height);
            if (additionalRenderTargets != null) {
                G.framebufferTexture2D(G.FRAMEBUFFER, GL.drawBuffers.COLOR_ATTACHMENT0_WEBGL, G.TEXTURE_2D, this.renderTargetTexture, 0)
                for (let i = 0; i < additionalRenderTargets.length; i++) {
                    G.framebufferTexture2D(G.FRAMEBUFFER, GL.drawBuffers.COLOR_ATTACHMENT0_WEBGL + i + 1, G.TEXTURE_2D, (additionalRenderTargets[i] as Image).texture, 0);
                }
                const attachments = [GL.drawBuffers.COLOR_ATTACHMENT0_WEBGL];
                for (let i = 0; i < additionalRenderTargets.length; i++) {
                    attachments.push(GL.drawBuffers.COLOR_ATTACHMENT0_WEBGL + i + 1);
                }
                G.drawBuffers(attachments);
            }
        }
    }
    beginFace(face: number): void {
        const G = GL.context
        G.enable(G.BLEND);
        G.blendFunc(G.SRC_ALPHA, G.ONE_MINUS_SRC_ALPHA);
        G.bindFramebuffer(G.FRAMEBUFFER, this.renderTargetFrameBuffer);
        G.framebufferTexture2D(G.FRAMEBUFFER, this.isDepthAttachment ? G.DEPTH_ATTACHMENT : G.COLOR_ATTACHMENT0, G.TEXTURE_CUBE_MAP_POSITIVE_X + face, this.renderTargetTexture, 0);
        G.viewport(0, 0, this.renderTarget.width, this.renderTarget.height);
    }
    beginEye(eye: number) {
        const G = GL.context
        
        G.enable(G.BLEND);
        G.blendFunc(G.SRC_ALPHA, G.ONE_MINUS_SRC_ALPHA);
        G.bindFramebuffer(G.FRAMEBUFFER, null);
        if (eye == 0) {
            G.viewport(0, 0, Screen.Width * 0.5, Screen.Height);
        } else {
            G.viewport(Screen.Width * 0.5, 0, Screen.Width * 0.5, Screen.Height);
        }
    }
    end(): void {
        const G = GL.context
       
        if (this.renderTargetMSAA != null) {
            G.bindFramebuffer(G.READ_FRAMEBUFFER, this.renderTargetFrameBuffer);
            G.bindFramebuffer(G.DRAW_FRAMEBUFFER, this.renderTargetMSAA);
            G.blitFramebuffer(0, 0, this.renderTarget.width, this.renderTarget.height,
                0, 0, this.renderTarget.width, this.renderTarget.height,
                G.COLOR_BUFFER_BIT, G.NEAREST);
        }

        var error = G.getError();
        
        switch (error) {
            case G.NO_ERROR:
                break;
            case G.INVALID_ENUM:
                console.warn("GL error: Invalid enum");
                break;
            case G.INVALID_VALUE:
                console.warn("GL error: Invalid value");
                break;
            case G.INVALID_OPERATION:
                console.warn("GL error: Invalid operation");
                break;
            case G.INVALID_FRAMEBUFFER_OPERATION:
                console.warn("GL error: Invalid framebuffer operation");
                break;
            case G.OUT_OF_MEMORY:
                console.warn("GL error: Out of memory");
                break;
            case G.CONTEXT_LOST_WEBGL:
                console.warn("GL error: Context lost");
                break;
            default:
                console.warn("Unknown GL error");
        }

    }
    vsynced(): boolean {
        return true;
    }
    refreshRate(): number {
        return 60;
    }
    clear(color?: Color, depth?: number, stencil?: number): void {
        const G = GL.context
        var clearMask: number = 0;
        if (color != null) {
            clearMask |= G.COLOR_BUFFER_BIT;
            G.colorMask(true, true, true, true);
            G.clearColor(color.R, color.G, color.B, color.A);
        }
        if (depth != null) {
            clearMask |= G.DEPTH_BUFFER_BIT;
            G.enable(G.DEPTH_TEST);
            G.depthMask(true);
            G.clearDepth(depth);
        }
        if (stencil != null) {
            clearMask |= G.STENCIL_BUFFER_BIT;
            G.enable(G.STENCIL_TEST);
            G.stencilMask(0xff);
            G.clearStencil(stencil);
        }
       
        G.clear(clearMask);
        G.colorMask(this.colorMaskRed, this.colorMaskGreen, this.colorMaskBlue, this.colorMaskAlpha);
        if (this.depthTest) {
            G.enable(G.DEPTH_TEST);
        }
        else {
            G.disable(G.DEPTH_TEST);
        }
        G.depthMask(this.depthMask);
    }
    viewport(x: number, y: number, width: number, height: number) {
        
        const G = GL.context
        if (this.renderTarget == null) {
            G.viewport(x, Screen.Height - y - height, width, height);
        }
        else {
            G.viewport(x, y, width, height);
        }
    }
    scissor(x: number, y: number, width: number, height: number): void {
        const G = GL.context
        G.enable(G.SCISSOR_TEST);
        if (this.renderTarget == null) {
            G.scissor(x, Screen.Height - y - height, width, height);
        }
        else {
            G.scissor(x, y, width, height);
        }
    }
    disableScissor(): void {
        const G = GL.context
        G.disable(G.SCISSOR_TEST);
    }
    setVertexBuffer(vertexBuffer: VertexBuffer): void {
        this.useVertexAttributes = vertexBuffer.set(0);
    }
    setVertexBuffers(vertexBuffers: VertexBuffer[]): void {
        var offset: number = 0;
        for (let vertexBuffer of vertexBuffers) {
            offset += vertexBuffer.set(offset);
        }
        this.useVertexAttributes = offset;
    }
    createIndexBuffer(indexCount: number, usage: Usage) {
        return new IndexBuffer(indexCount, usage);
    }
    setIndexBuffer(indexBuffer: IndexBuffer): void {
        this.indicesCount = indexBuffer.count();
        indexBuffer.set();
    }
    setTexture(stage: TextureUnit, texture: Image): void {
        const G = GL.context
        if (texture == null) {
            G.activeTexture(G.TEXTURE0 + stage.value);
            G.bindTexture(G.TEXTURE_2D, null);
        }
        else {
            texture.set(stage.value);
        }
    }
    setTextureDepth(stage: TextureUnit, texture: Image): void {
        texture.setDepth(stage.value);
    }
    setTextureArray(unit: TextureUnit, texture: Image): void {
        throw new Error("Method not implemented.");
    }
    setImageTexture(unit: TextureUnit, texture: Image): void {
        throw new Error("Method not implemented.");
    }

    setTextureParameters(texunit: TextureUnit, uAddressing: TextureAddressing, vAddressing: TextureAddressing, minificationFilter: TextureFilter, magnificationFilter: TextureFilter, mipmapFilter: MipMapFilter): void {
        const G = GL.context
        G.activeTexture(G.TEXTURE0 + texunit.value);

        switch (uAddressing) {
            case TextureAddressing.Clamp:
                G.texParameteri(G.TEXTURE_2D, G.TEXTURE_WRAP_S, G.CLAMP_TO_EDGE);
                break;
            case TextureAddressing.Repeat:
                G.texParameteri(G.TEXTURE_2D, G.TEXTURE_WRAP_S, G.REPEAT);
                break;
            case TextureAddressing.Mirror:
                G.texParameteri(G.TEXTURE_2D, G.TEXTURE_WRAP_S, G.MIRRORED_REPEAT);
                break;
        }

        switch (vAddressing) {
            case TextureAddressing.Clamp:
                G.texParameteri(G.TEXTURE_2D, G.TEXTURE_WRAP_T, G.CLAMP_TO_EDGE);
                break;
            case TextureAddressing.Repeat:
                G.texParameteri(G.TEXTURE_2D, G.TEXTURE_WRAP_T, G.REPEAT);
                break;
            case TextureAddressing.Mirror:
                G.texParameteri(G.TEXTURE_2D, G.TEXTURE_WRAP_T, G.MIRRORED_REPEAT);
                break;
        }

        switch (minificationFilter) {
            case TextureFilter.PointFilter:
                switch (mipmapFilter) {
                    case MipMapFilter.NoMipFilter:
                        G.texParameteri(G.TEXTURE_2D, G.TEXTURE_MIN_FILTER, G.NEAREST);
                        break;
                    case MipMapFilter.PointMipFilter:
                        G.texParameteri(G.TEXTURE_2D, G.TEXTURE_MIN_FILTER, G.NEAREST_MIPMAP_NEAREST);
                        break;
                    case MipMapFilter.LinearMipFilter:
                        G.texParameteri(G.TEXTURE_2D, G.TEXTURE_MIN_FILTER, G.NEAREST_MIPMAP_LINEAR);
                        break;
                }
            case TextureFilter.LinearFilter:
            case TextureFilter.AnisotropicFilter:
                switch (mipmapFilter) {
                    case MipMapFilter.NoMipFilter:
                        G.texParameteri(G.TEXTURE_2D, G.TEXTURE_MIN_FILTER, G.LINEAR);
                        break;
                    case MipMapFilter.PointMipFilter:
                        G.texParameteri(G.TEXTURE_2D, G.TEXTURE_MIN_FILTER, G.LINEAR_MIPMAP_NEAREST);
                        break;
                    case MipMapFilter.LinearMipFilter:
                        G.texParameteri(G.TEXTURE_2D, G.TEXTURE_MIN_FILTER, G.LINEAR_MIPMAP_LINEAR);
                        break;
                }
                if (minificationFilter == TextureFilter.AnisotropicFilter) {
                    G.texParameteri(G.TEXTURE_2D, GL.anisotropic.TEXTURE_MAX_ANISOTROPY_EXT, 4);
                }
        }

        switch (magnificationFilter) {
            case TextureFilter.PointFilter:
                G.texParameteri(G.TEXTURE_2D, G.TEXTURE_MAG_FILTER, G.NEAREST);
                break;
            case TextureFilter.LinearFilter:
            case TextureFilter.AnisotropicFilter:
                G.texParameteri(G.TEXTURE_2D, G.TEXTURE_MAG_FILTER, G.LINEAR);
                break;
        }
    }
    setTexture3DParameters(texunit: TextureUnit, uAddressing: TextureAddressing, vAddressing: TextureAddressing, wAddressing: TextureAddressing, minificationFilter: TextureFilter, magnificationFilter: TextureFilter, mipmapFilter: MipMapFilter): void {
        throw new Error("Method not implemented.");
    }
    setTextureCompareMode(texunit: TextureUnit, enabled: boolean): void {
        const G = GL.context
        if (enabled) {
            G.texParameteri(G.TEXTURE_2D, G.TEXTURE_COMPARE_MODE, G.COMPARE_REF_TO_TEXTURE);
            G.texParameteri(G.TEXTURE_2D, G.TEXTURE_COMPARE_FUNC, G.LEQUAL);
        }
        else {
            G.texParameteri(G.TEXTURE_2D, G.TEXTURE_COMPARE_MODE, G.NONE);
        }
    }
    setCubeMapCompareMode(texunit: TextureUnit, enabled: boolean): void {
        const G = GL.context
        if (enabled) {
            G.texParameteri(G.TEXTURE_CUBE_MAP, G.TEXTURE_COMPARE_MODE, G.COMPARE_REF_TO_TEXTURE);
            G.texParameteri(G.TEXTURE_CUBE_MAP, G.TEXTURE_COMPARE_FUNC, G.LEQUAL);
        }
        else {
            G.texParameteri(G.TEXTURE_CUBE_MAP, G.TEXTURE_COMPARE_MODE, G.NONE);
        }
    }
    setCubeMap(stage: TextureUnit, cubeMap: any): void {
        const G = GL.context
        if (cubeMap == null) {
            G.activeTexture(G.TEXTURE0 + stage.value);
            G.bindTexture(G.TEXTURE_CUBE_MAP, null);
        }
        else {
            cubeMap.set(stage.value);
        }
    }
    setCubeMapDepth(stage: TextureUnit, cubeMap: Canvas): void {
        (cubeMap as any).setDepth(stage.value);
    }
    setStencilReferenceValue(value: number): void {
        const G = GL.context
        G.stencilFunc(this.convertCompareMode(this.currentPipeline.stencilMode), value, this.currentPipeline.stencilReadMask);
    }
    instancedRenderingAvailable(): boolean {
        return this.instancedExtension;
    }

    setDepthMode(write: boolean, mode: CompareMode): void {
        const G = GL.context
        switch (mode) {
            case CompareMode.Always:
                write ? G.enable(G.DEPTH_TEST) : G.disable(G.DEPTH_TEST);
                this.depthTest = write;
                G.depthFunc(G.ALWAYS);
                break;
            case CompareMode.Never:
                G.enable(G.DEPTH_TEST);
                this.depthTest = true;
                G.depthFunc(G.NEVER);
                break;
            case CompareMode.Equal:
                G.enable(G.DEPTH_TEST);
                this.depthTest = true;
                G.depthFunc(G.EQUAL);
                break;
            case CompareMode.NotEqual:
                G.enable(G.DEPTH_TEST);
                this.depthTest = true;
                G.depthFunc(G.NOTEQUAL);
                break;
            case CompareMode.Less:
                G.enable(G.DEPTH_TEST);
                this.depthTest = true;
                G.depthFunc(G.LESS);
                break;
            case CompareMode.LessEqual:
                G.enable(G.DEPTH_TEST);
                this.depthTest = true;
                G.depthFunc(G.LEQUAL);
                break;
            case CompareMode.Greater:
                G.enable(G.DEPTH_TEST);
                this.depthTest = true;
                G.depthFunc(G.GREATER);
                break;
            case CompareMode.GreaterEqual:
                G.enable(G.DEPTH_TEST);
                this.depthTest = true;
                G.depthFunc(G.GEQUAL);
                break;
        }
        G.depthMask(write);
        this.depthMask = write;
    }

    setCullMode(mode: CullMode): void {
        const G = GL.context
        switch (mode) {
            case CullMode.None:
                G.disable(G.CULL_FACE);
                break;
            case CullMode.Clockwise:
                G.enable(G.CULL_FACE);
                G.cullFace(G.BACK);
                break;
            case CullMode.CounterClockwise:
                G.enable(G.CULL_FACE);
                G.cullFace(G.FRONT);
                break;
        }
    }

    getBlendFunc(factor: BlendingFactor): number {
        const G = GL.context
        switch (factor) {
            case BlendingFactor.BlendZero:
            case BlendingFactor.Undefined:
                return G.ZERO;
            case BlendingFactor.BlendOne:
                return G.ONE;
            case BlendingFactor.SourceAlpha:
                return G.SRC_ALPHA;
            case BlendingFactor.DestinationAlpha:
                return G.DST_ALPHA;
            case BlendingFactor.InverseSourceAlpha:
                return G.ONE_MINUS_SRC_ALPHA;
            case BlendingFactor.InverseDestinationAlpha:
                return G.ONE_MINUS_DST_ALPHA;
            case BlendingFactor.SourceColor:
                return G.SRC_COLOR;
            case BlendingFactor.DestinationColor:
                return G.DST_COLOR;
            case BlendingFactor.InverseSourceColor:
                return G.ONE_MINUS_SRC_COLOR;
            case BlendingFactor.InverseDestinationColor:
                return G.ONE_MINUS_DST_COLOR;
        }
    }

    getBlendOp(op: BlendingOperation): number {
        const G = GL.context
        switch (op) {
            case BlendingOperation.Add:
                return G.FUNC_ADD;
            case BlendingOperation.Subtract:
                return G.FUNC_SUBTRACT;
            case BlendingOperation.ReverseSubtract:
                return G.FUNC_REVERSE_SUBTRACT;
            case BlendingOperation.Min:
                return 0x8007;
            case BlendingOperation.Max:
                return 0x8008;
        }
    }

    setBlendingMode(source: BlendingFactor, destination: BlendingFactor, operation: BlendingOperation,
        alphaSource: BlendingFactor, alphaDestination: BlendingFactor, alphaOperation: BlendingOperation): void {
        const G = GL.context
        if (source == BlendingFactor.BlendOne && destination == BlendingFactor.BlendZero) {
            G.disable(G.BLEND);
        }
        else {
            G.enable(G.BLEND);
            G.blendFuncSeparate(this.getBlendFunc(source), this.getBlendFunc(destination), this.getBlendFunc(alphaSource), this.getBlendFunc(alphaDestination));
            G.blendEquationSeparate(this.getBlendOp(operation), this.getBlendOp(alphaOperation));
        }
    }

    convertCompareMode(compareMode: CompareMode) {
        const G = GL.context
        switch (compareMode) {
            case CompareMode.Always:
                return G.ALWAYS;
            case CompareMode.Equal:
                return G.EQUAL;
            case CompareMode.Greater:
                return G.GREATER;
            case CompareMode.GreaterEqual:
                return G.GEQUAL;
            case CompareMode.Less:
                return G.LESS;
            case CompareMode.LessEqual:
                return G.LEQUAL;
            case CompareMode.Never:
                return G.NEVER;
            case CompareMode.NotEqual:
                return G.NOTEQUAL;
        }
    }

    convertStencilAction(action: StencilAction) {
        const G = GL.context
        switch (action) {
            case StencilAction.Decrement:
                return G.DECR;
            case StencilAction.DecrementWrap:
                return G.DECR_WRAP;
            case StencilAction.Increment:
                return G.INCR;
            case StencilAction.IncrementWrap:
                return G.INCR_WRAP;
            case StencilAction.Invert:
                return G.INVERT;
            case StencilAction.Keep:
                return G.KEEP;
            case StencilAction.Replace:
                return G.REPLACE;
            case StencilAction.Zero:
                return G.ZERO;
        }
    }


    setStencilParameters(compareMode: CompareMode, bothPass: StencilAction, depthFail: StencilAction, stencilFail: StencilAction, referenceValue: StencilValue, readMask: number = 0xff, writeMask: number = 0xff): void {
        const G = GL.context
        if (compareMode == CompareMode.Always && bothPass == StencilAction.Keep
            && depthFail == StencilAction.Keep && stencilFail == StencilAction.Keep) {
            G.disable(G.STENCIL_TEST);
        }
        else {
            G.enable(G.STENCIL_TEST);
            var stencilFunc = this.convertCompareMode(compareMode);
            G.stencilMask(writeMask);
            G.stencilOp(this.convertStencilAction(stencilFail), this.convertStencilAction(depthFail), this.convertStencilAction(bothPass));
            switch (referenceValue) {
                case StencilValue.Static(referenceValue.value):
                    G.stencilFunc(stencilFunc, referenceValue.value, readMask);
                    break;
                case StencilValue.Dynamic:
                    G.stencilFunc(stencilFunc, 0, readMask);
                    break;
            }
        }
    }

    setPipeline(pipe: PipelineState): void {
        this.setCullMode(pipe.cullMode);
        this.setDepthMode(pipe.depthWrite, pipe.depthMode);
        this.setStencilParameters(pipe.stencilMode, pipe.stencilBothPass, pipe.stencilDepthFail, pipe.stencilFail, pipe.stencilReferenceValue, pipe.stencilReadMask, pipe.stencilWriteMask);
        this.setBlendingMode(pipe.blendSource, pipe.blendDestination, pipe.blendOperation, pipe.alphaBlendSource, pipe.alphaBlendDestination, pipe.alphaBlendOperation);
        this.currentPipeline = pipe;
        pipe.set();
        this.colorMaskRed = pipe.colorWriteMaskRed;
        this.colorMaskGreen = pipe.colorWriteMaskGreen;
        this.colorMaskBlue = pipe.colorWriteMaskBlue;
        this.colorMaskAlpha = pipe.colorWriteMaskAlpha;
    }


    setBool(location: ConstantLocation, value: boolean): void {
        const G = GL.context

        G.uniform1i(location.value, value ? 1 : 0);
    }
    setInt(location: ConstantLocation, value: number): void {
        const G = GL.context

        G.uniform1i(location.value, value);

        // check errors
    }
    setInt2(location: ConstantLocation, value1: number, value2: number): void {
        const G = GL.context

        G.uniform2i(location.value, value1, value2);

        // check errors
    }
    setInt3(location: ConstantLocation, value1: number, value2: number, value3: number): void {
        const G = GL.context

        G.uniform3i(location.value, value1, value2, value3);

        // check errors
    }
    setInt4(location: ConstantLocation, value1: number, value2: number, value3: number, value4: number): void {
        const G = GL.context

        G.uniform4i(location.value, value1, value2, value3, value4);

        // check errors
    }
    setInts(location: ConstantLocation, values: Float32Array): void {
        const G = GL.context
        switch (location.type) {
            case G.FLOAT_VEC2:
                G.uniform2iv(location.value, values);
                break;
            case G.FLOAT_VEC3:
                G.uniform3iv(location.value, values);
                break;
            case G.FLOAT_VEC4:
                G.uniform4iv(location.value, values);
                break;
            default:
                G.uniform1iv(location.value, values);
                break;
        }
        // check errors
    }
    setFloat(location: ConstantLocation, value: number): void {
        const G = GL.context

        G.uniform1f(location.value, value);

        // check errors
    }
    setFloat2(location: ConstantLocation, value1: number, value2: number): void {
        const G = GL.context

        G.uniform2f(location.value, value1, value2);

        // check errors
    }
    setFloat3(location: ConstantLocation, value1: number, value2: number, value3: number): void {
        const G = GL.context

        G.uniform3f(location.value, value1, value2, value3);

        // check errors
    }
    setFloat4(location: ConstantLocation, value1: number, value2: number, value3: number, value4: number): void {
        const G = GL.context

        G.uniform4f(location.value, value1, value2, value3, value4);

        // check errors
    }
    setFloats(location: ConstantLocation, values: Float32Array): void {
        const G = GL.context
        switch (location.type) {
            case G.FLOAT_VEC2:
                G.uniform2fv(location.value, values);
                break;
            case G.FLOAT_VEC3:
                G.uniform3fv(location.value, values);
                break;
            case G.FLOAT_VEC4:
                G.uniform4fv(location.value, values);
                break;
            case G.FLOAT_MAT4:
                G.uniformMatrix4fv(location.value, false, values);
                break;
            default:
                G.uniform1fv(location.value, values);
                break;
        }
        // check errors
    }
    setVector2(location: ConstantLocation, value: Vector2): void {
        const G = GL.context
        G.uniform2f(location.value, value.x, value.y);
    }
    setVector3(location: ConstantLocation, value: Vector3): void {
        const G = GL.context
        G.uniform3f(location.value, value.x, value.y, value.z);
    }
    setVector4(location: ConstantLocation, value: Vector4): void {
        const G = GL.context
        G.uniform4f(location.value, value.x, value.y, value.z, value.w);
    }


    matrixCache = new Float32Array(16);

    setMatrix(location: ConstantLocation, matrix: Matrix4): void {
        const G = GL.context
        this.matrixCache[0] = matrix._00; this.matrixCache[1] = matrix._01; this.matrixCache[2] = matrix._02; this.matrixCache[3] = matrix._03;
        this.matrixCache[4] = matrix._10; this.matrixCache[5] = matrix._11; this.matrixCache[6] = matrix._12; this.matrixCache[7] = matrix._13;
        this.matrixCache[8] = matrix._20; this.matrixCache[9] = matrix._21; this.matrixCache[10] = matrix._22; this.matrixCache[11] = matrix._23;
        this.matrixCache[12] = matrix._30; this.matrixCache[13] = matrix._31; this.matrixCache[14] = matrix._32; this.matrixCache[15] = matrix._33;

        G.uniformMatrix4fv(location.value, false, this.matrixCache);
    }

    matrix3Cache = new Float32Array(9);

    setMatrix3(location: ConstantLocation, matrix: Matrix3): void {
        const G = GL.context

        this.matrix3Cache[0] = matrix._00; this.matrix3Cache[1] = matrix._01; this.matrix3Cache[2] = matrix._02;
        this.matrix3Cache[3] = matrix._10; this.matrix3Cache[4] = matrix._11; this.matrix3Cache[5] = matrix._12;
        this.matrix3Cache[6] = matrix._20; this.matrix3Cache[7] = matrix._21; this.matrix3Cache[8] = matrix._22;

        G.uniformMatrix4fv(location.value, false, this.matrix3Cache);
    }

    drawIndexedVertices(start: number, count: number): void {
        const G = GL.context
        const type = GL.elementIndexUint == null ? G.UNSIGNED_SHORT : G.UNSIGNED_INT;
        const size = type == G.UNSIGNED_SHORT ? 2 : 4;
        G.drawElements(G.TRIANGLES, count == -1 ? this.indicesCount : count, type, start * size);
        for (let i = 0; i < this.useVertexAttributes; i++) {
            G.disableVertexAttribArray(i);
        }
    }

    drawIndexedVerticesInstanced(instanceCount: number, start: number, count: number): void {
        const G = GL.context
        if (this.instancedRenderingAvailable()) {
            var type = GL.elementIndexUint == null ? G.UNSIGNED_SHORT : G.UNSIGNED_INT;
            var typeSize = GL.elementIndexUint == null ? 2 : 4;

            G.drawElementsInstanced(G.TRIANGLES, count == -1 ? this.indicesCount : count, type, start * typeSize, instanceCount);
        }
    }

    flush(): void {
        
    }

}