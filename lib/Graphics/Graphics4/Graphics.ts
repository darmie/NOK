import { Image, ICanvas } from "../Image";
import { ConstantLocation } from "../ConstantLocation";
import { Vector2 } from "../../Math/Vector2";
import { Vector3 } from "../../Math/Vector3";
import { Vector4 } from "../../Math/Vector4";
import { Matrix4 } from "../../Math/Matrix4";
import { Matrix3 } from "../../Math/Matrix3";
import { GameView } from "../../GameView";
import { IGraphics } from "./IGraphics"
import { PipelineState } from "../PipelineState"
import { VertexBuffer } from "../VertexBuffer"
import { Canvas } from "../Canvas"
import { Color } from "../Color";
import { IndexBuffer } from "../IndexBuffer";
import { TextureUnit } from "../TextureUnit";
import { CubeMap } from "../CubeMap";
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

const Screen = async () => {
    const native = await (import("react-native"))
    if (native) return native.Dimensions.get("screen")

    return {
        width: window.innerWidth,
        height: window.innerHeight
    }
}





export class Graphics implements IGraphics {
    currentPipeline: PipelineState = null;
    private depthTest: boolean = false;
    private depthMask: boolean = false;
    private colorMaskRed: boolean = true;
    private colorMaskGreen: boolean = true;
    private colorMaskBlue: boolean = true;
    private colorMaskAlpha: boolean = true;
    private indicesCount: number;
    private renderTarget: Canvas;
    private renderTargetFrameBuffer: any;
    private renderTargetMSAA: any;
    private renderTargetTexture: any;
    private isCubeMap: boolean = false;
    private isDepthAttachment: boolean = false;
    private instancedExtension: boolean;
    private blendMinMaxExtension: any;
    private useVertexAttributes: number = 0;

    constructor(public target: ICanvas) { }

    async begin(additionalRenderTargets?: Canvas[]) {
        const screen = (await Screen())
        const GL = GameView.context
        GL.enable(GL.BLEND);
        GL.blendFunc(GL.SRC_ALPHA, GL.ONE_MINUS_SRC_ALPHA);

        if (this.renderTarget == null) {
            GL.bindFramebuffer(GL.FRAMEBUFFER, null);
            GL.viewport(0, 0, screen.width, screen.height);
        } else {
            GL.bindFramebuffer(GL.FRAMEBUFFER, this.renderTargetFrameBuffer);
            GL.viewport(0, 0, this.renderTarget.width, this.renderTarget.height);
            if (additionalRenderTargets != null) {
                GL.framebufferTexture2D(GL.FRAMEBUFFER, GameView.drawBuffers.COLOR_ATTACHMENT0_WEBGL, GL.TEXTURE_2D, this.renderTargetTexture, 0)
                for (let i = 0; i < additionalRenderTargets.length; i++) {
                    GL.framebufferTexture2D(GL.FRAMEBUFFER, GameView.drawBuffers.COLOR_ATTACHMENT0_WEBGL + i + 1, GL.TEXTURE_2D, (additionalRenderTargets[i] as Image).texture, 0);
                }
                const attachments = [GameView.drawBuffers.COLOR_ATTACHMENT0_WEBGL];
                for (let i = 0; i < additionalRenderTargets.length; i++) {
                    attachments.push(GameView.drawBuffers.COLOR_ATTACHMENT0_WEBGL + i + 1);
                }
                GL.drawBuffers(attachments);
            }
        }
    }
    beginFace(face: number): void {
        const GL = GameView.context
        GL.enable(GL.BLEND);
        GL.blendFunc(GL.SRC_ALPHA, GL.ONE_MINUS_SRC_ALPHA);
        GL.bindFramebuffer(GL.FRAMEBUFFER, this.renderTargetFrameBuffer);
        GL.framebufferTexture2D(GL.FRAMEBUFFER, this.isDepthAttachment ? GL.DEPTH_ATTACHMENT : GL.COLOR_ATTACHMENT0, GL.TEXTURE_CUBE_MAP_POSITIVE_X + face, this.renderTargetTexture, 0);
        GL.viewport(0, 0, this.renderTarget.width, this.renderTarget.height);
    }
    async beginEye(eye: number) {
        const GL = GameView.context
        const screen = (await Screen())
        GL.enable(GL.BLEND);
        GL.blendFunc(GL.SRC_ALPHA, GL.ONE_MINUS_SRC_ALPHA);
        GL.bindFramebuffer(GL.FRAMEBUFFER, null);
        if (eye == 0) {
            GL.viewport(0, 0, screen.width * 0.5, screen.height);
        } else {
            GL.viewport(screen.width * 0.5, 0, screen.width * 0.5, screen.height);
        }
    }
    end(): void {
        const GL = GameView.context
        if (this.renderTargetMSAA != null) {
            GL.bindFramebuffer(GL.READ_FRAMEBUFFER, this.renderTargetFrameBuffer);
            GL.bindFramebuffer(GL.DRAW_FRAMEBUFFER, this.renderTargetMSAA);
            GL.blitFramebuffer(0, 0, this.renderTarget.width, this.renderTarget.height,
                0, 0, this.renderTarget.width, this.renderTarget.height,
                GL.COLOR_BUFFER_BIT, GL.NEAREST);
        }

        var error = GL.getError();
        switch (error) {
            case GL.NO_ERROR:

            case GL.INVALID_ENUM:
                console.error("GL error: Invalid enum");
            case GL.INVALID_VALUE:
                console.error("GL error: Invalid value");
            case GL.INVALID_OPERATION:
                console.error("GL error: Invalid operation");
            case GL.INVALID_FRAMEBUFFER_OPERATION:
                console.error("GL error: Invalid framebuffer operation");
            case GL.OUT_OF_MEMORY:
                console.error("GL error: Out of memory");
            case GL.CONTEXT_LOST_WEBGL:
                console.error("GL error: Context lost");
            default:
                console.error("Unknown GL error");
        }

    }
    vsynced(): boolean {
        return true;
    }
    refreshRate(): number {
        return 60;
    }
    clear(color?: Color, depth?: number, stencil?: number): void {
        const GL = GameView.context
        var clearMask: number = 0;
        if (color != null) {
            clearMask |= GL.COLOR_BUFFER_BIT;
            GL.colorMask(true, true, true, true);
            GL.clearColor(color.R, color.G, color.B, color.A);
        }
        if (depth != null) {
            clearMask |= GL.DEPTH_BUFFER_BIT;
            GL.enable(GL.DEPTH_TEST);
            GL.depthMask(true);
            GL.clearDepth(depth);
        }
        if (stencil != null) {
            clearMask |= GL.STENCIL_BUFFER_BIT;
            GL.enable(GL.STENCIL_TEST);
            GL.stencilMask(0xff);
            GL.clearStencil(stencil);
        }
        GL.clear(clearMask);
        GL.colorMask(this.colorMaskRed, this.colorMaskGreen, this.colorMaskBlue, this.colorMaskAlpha);
        if (this.depthTest) {
            GL.enable(GL.DEPTH_TEST);
        }
        else {
            GL.disable(GL.DEPTH_TEST);
        }
        GL.depthMask(this.depthMask);
    }
    async viewport(x: number, y: number, width: number, height: number) {
        const screen = (await Screen())
        const GL = GameView.context
        if (this.renderTarget == null) {
            GL.viewport(x, screen.height - y - height, width, height);
        }
        else {
            GL.viewport(x, y, width, height);
        }
    }
    scissor(x: number, y: number, width: number, height: number): void {
        const GL = GameView.context
        GL.enable(GL.SCISSOR_TEST);
        if (this.renderTarget == null) {
            GL.scissor(x, screen.height - y - height, width, height);
        }
        else {
            GL.scissor(x, y, width, height);
        }
    }
    disableScissor(): void {
        const GL = GameView.context
        GL.disable(GL.SCISSOR_TEST);
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
        const GL = GameView.context
        if (texture == null) {
            GL.activeTexture(GL.TEXTURE0 + stage.value);
            GL.bindTexture(GL.TEXTURE_2D, null);
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
        const GL = GameView.context
        GL.activeTexture(GL.TEXTURE0 + texunit.value);

        switch (uAddressing) {
            case TextureAddressing.Clamp:
                GL.texParameteri(GL.TEXTURE_2D, GL.TEXTURE_WRAP_S, GL.CLAMP_TO_EDGE);
                break;
            case TextureAddressing.Repeat:
                GL.texParameteri(GL.TEXTURE_2D, GL.TEXTURE_WRAP_S, GL.REPEAT);
                break;
            case TextureAddressing.Mirror:
                GL.texParameteri(GL.TEXTURE_2D, GL.TEXTURE_WRAP_S, GL.MIRRORED_REPEAT);
                break;
        }

        switch (vAddressing) {
            case TextureAddressing.Clamp:
                GL.texParameteri(GL.TEXTURE_2D, GL.TEXTURE_WRAP_T, GL.CLAMP_TO_EDGE);
                break;
            case TextureAddressing.Repeat:
                GL.texParameteri(GL.TEXTURE_2D, GL.TEXTURE_WRAP_T, GL.REPEAT);
                break;
            case TextureAddressing.Mirror:
                GL.texParameteri(GL.TEXTURE_2D, GL.TEXTURE_WRAP_T, GL.MIRRORED_REPEAT);
                break;
        }

        switch (minificationFilter) {
            case TextureFilter.PointFilter:
                switch (mipmapFilter) {
                    case MipMapFilter.NoMipFilter:
                        GL.texParameteri(GL.TEXTURE_2D, GL.TEXTURE_MIN_FILTER, GL.NEAREST);
                        break;
                    case MipMapFilter.PointMipFilter:
                        GL.texParameteri(GL.TEXTURE_2D, GL.TEXTURE_MIN_FILTER, GL.NEAREST_MIPMAP_NEAREST);
                        break;
                    case MipMapFilter.LinearMipFilter:
                        GL.texParameteri(GL.TEXTURE_2D, GL.TEXTURE_MIN_FILTER, GL.NEAREST_MIPMAP_LINEAR);
                        break;
                }
            case TextureFilter.LinearFilter:
            case TextureFilter.AnisotropicFilter:
                switch (mipmapFilter) {
                    case MipMapFilter.NoMipFilter:
                        GL.texParameteri(GL.TEXTURE_2D, GL.TEXTURE_MIN_FILTER, GL.LINEAR);
                        break;
                    case MipMapFilter.PointMipFilter:
                        GL.texParameteri(GL.TEXTURE_2D, GL.TEXTURE_MIN_FILTER, GL.LINEAR_MIPMAP_NEAREST);
                        break;
                    case MipMapFilter.LinearMipFilter:
                        GL.texParameteri(GL.TEXTURE_2D, GL.TEXTURE_MIN_FILTER, GL.LINEAR_MIPMAP_LINEAR);
                        break;
                }
                if (minificationFilter == TextureFilter.AnisotropicFilter) {
                    GL.texParameteri(GL.TEXTURE_2D, GameView.anisotropic.TEXTURE_MAX_ANISOTROPY_EXT, 4);
                }
        }

        switch (magnificationFilter) {
            case TextureFilter.PointFilter:
                GL.texParameteri(GL.TEXTURE_2D, GL.TEXTURE_MAG_FILTER, GL.NEAREST);
                break;
            case TextureFilter.LinearFilter:
            case TextureFilter.AnisotropicFilter:
                GL.texParameteri(GL.TEXTURE_2D, GL.TEXTURE_MAG_FILTER, GL.LINEAR);
                break;
        }
    }
    setTexture3DParameters(texunit: TextureUnit, uAddressing: TextureAddressing, vAddressing: TextureAddressing, wAddressing: TextureAddressing, minificationFilter: TextureFilter, magnificationFilter: TextureFilter, mipmapFilter: MipMapFilter): void {
        throw new Error("Method not implemented.");
    }
    setTextureCompareMode(texunit: TextureUnit, enabled: boolean): void {
        const GL = GameView.context
        if (enabled) {
            GL.texParameteri(GL.TEXTURE_2D, GL.TEXTURE_COMPARE_MODE, GL.COMPARE_REF_TO_TEXTURE);
            GL.texParameteri(GL.TEXTURE_2D, GL.TEXTURE_COMPARE_FUNC, GL.LEQUAL);
        }
        else {
            GL.texParameteri(GL.TEXTURE_2D, GL.TEXTURE_COMPARE_MODE, GL.NONE);
        }
    }
    setCubeMapCompareMode(texunit: TextureUnit, enabled: boolean): void {
        const GL = GameView.context
        if (enabled) {
            GL.texParameteri(GL.TEXTURE_CUBE_MAP, GL.TEXTURE_COMPARE_MODE, GL.COMPARE_REF_TO_TEXTURE);
            GL.texParameteri(GL.TEXTURE_CUBE_MAP, GL.TEXTURE_COMPARE_FUNC, GL.LEQUAL);
        }
        else {
            GL.texParameteri(GL.TEXTURE_CUBE_MAP, GL.TEXTURE_COMPARE_MODE, GL.NONE);
        }
    }
    setCubeMap(stage: TextureUnit, cubeMap: CubeMap): void {
        const GL = GameView.context
        if (cubeMap == null) {
            GL.activeTexture(GL.TEXTURE0 + stage.value);
            GL.bindTexture(GL.TEXTURE_CUBE_MAP, null);
        }
        else {
            cubeMap.set(stage.value);
        }
    }
    setCubeMapDepth(stage: TextureUnit, cubeMap: CubeMap): void {
        cubeMap.setDepth(stage.value);
    }
    setStencilReferenceValue(value: number): void {
        const GL = GameView.context
        GL.stencilFunc(this.convertCompareMode(this.currentPipeline.stencilMode), value, this.currentPipeline.stencilReadMask);
    }
    instancedRenderingAvailable(): boolean {
        return this.instancedExtension;
    }

    setDepthMode(write: boolean, mode: CompareMode): void {
        const GL = GameView.context
        switch (mode) {
            case CompareMode.Always:
                write ? GL.enable(GL.DEPTH_TEST) : GL.disable(GL.DEPTH_TEST);
                this.depthTest = write;
                GL.depthFunc(GL.ALWAYS);
                break;
            case CompareMode.Never:
                GL.enable(GL.DEPTH_TEST);
                this.depthTest = true;
                GL.depthFunc(GL.NEVER);
                break;
            case CompareMode.Equal:
                GL.enable(GL.DEPTH_TEST);
                this.depthTest = true;
                GL.depthFunc(GL.EQUAL);
                break;
            case CompareMode.NotEqual:
                GL.enable(GL.DEPTH_TEST);
                this.depthTest = true;
                GL.depthFunc(GL.NOTEQUAL);
                break;
            case CompareMode.Less:
                GL.enable(GL.DEPTH_TEST);
                this.depthTest = true;
                GL.depthFunc(GL.LESS);
                break;
            case CompareMode.LessEqual:
                GL.enable(GL.DEPTH_TEST);
                this.depthTest = true;
                GL.depthFunc(GL.LEQUAL);
                break;
            case CompareMode.Greater:
                GL.enable(GL.DEPTH_TEST);
                this.depthTest = true;
                GL.depthFunc(GL.GREATER);
                break;
            case CompareMode.GreaterEqual:
                GL.enable(GL.DEPTH_TEST);
                this.depthTest = true;
                GL.depthFunc(GL.GEQUAL);
                break;
        }
        GL.depthMask(write);
        this.depthMask = write;
    }

    setCullMode(mode: CullMode): void {
        const GL = GameView.context
        switch (mode) {
            case CullMode.None:
                GL.disable(GL.CULL_FACE);
                break;
            case CullMode.Clockwise:
                GL.enable(GL.CULL_FACE);
                GL.cullFace(GL.BACK);
                break;
            case CullMode.CounterClockwise:
                GL.enable(GL.CULL_FACE);
                GL.cullFace(GL.FRONT);
                break;
        }
    }

    getBlendFunc(factor: BlendingFactor): number {
        const GL = GameView.context
        switch (factor) {
            case BlendingFactor.BlendZero:
            case BlendingFactor.Undefined:
                return GL.ZERO;
            case BlendingFactor.BlendOne:
                return GL.ONE;
            case BlendingFactor.SourceAlpha:
                return GL.SRC_ALPHA;
            case BlendingFactor.DestinationAlpha:
                return GL.DST_ALPHA;
            case BlendingFactor.InverseSourceAlpha:
                return GL.ONE_MINUS_SRC_ALPHA;
            case BlendingFactor.InverseDestinationAlpha:
                return GL.ONE_MINUS_DST_ALPHA;
            case BlendingFactor.SourceColor:
                return GL.SRC_COLOR;
            case BlendingFactor.DestinationColor:
                return GL.DST_COLOR;
            case BlendingFactor.InverseSourceColor:
                return GL.ONE_MINUS_SRC_COLOR;
            case BlendingFactor.InverseDestinationColor:
                return GL.ONE_MINUS_DST_COLOR;
        }
    }

    getBlendOp(op: BlendingOperation): number {
        const GL = GameView.context
        switch (op) {
            case BlendingOperation.Add:
                return GL.FUNC_ADD;
            case BlendingOperation.Subtract:
                return GL.FUNC_SUBTRACT;
            case BlendingOperation.ReverseSubtract:
                return GL.FUNC_REVERSE_SUBTRACT;
            case BlendingOperation.Min:
                return 0x8007;
            case BlendingOperation.Max:
                return 0x8008;
        }
    }

    setBlendingMode(source: BlendingFactor, destination: BlendingFactor, operation: BlendingOperation,
        alphaSource: BlendingFactor, alphaDestination: BlendingFactor, alphaOperation: BlendingOperation): void {
        const GL = GameView.context
        if (source == BlendingFactor.BlendOne && destination == BlendingFactor.BlendZero) {
            GL.disable(GL.BLEND);
        }
        else {
            GL.enable(GL.BLEND);
            GL.blendFuncSeparate(this.getBlendFunc(source), this.getBlendFunc(destination), this.getBlendFunc(alphaSource), this.getBlendFunc(alphaDestination));
            GL.blendEquationSeparate(this.getBlendOp(operation), this.getBlendOp(alphaOperation));
        }
    }

    convertCompareMode(compareMode: CompareMode) {
        const GL = GameView.context
        switch (compareMode) {
            case CompareMode.Always:
                return GL.ALWAYS;
            case CompareMode.Equal:
                return GL.EQUAL;
            case CompareMode.Greater:
                return GL.GREATER;
            case CompareMode.GreaterEqual:
                return GL.GEQUAL;
            case CompareMode.Less:
                return GL.LESS;
            case CompareMode.LessEqual:
                return GL.LEQUAL;
            case CompareMode.Never:
                return GL.NEVER;
            case CompareMode.NotEqual:
                return GL.NOTEQUAL;
        }
    }

    convertStencilAction(action: StencilAction) {
        const GL = GameView.context
        switch (action) {
            case StencilAction.Decrement:
                return GL.DECR;
            case StencilAction.DecrementWrap:
                return GL.DECR_WRAP;
            case StencilAction.Increment:
                return GL.INCR;
            case StencilAction.IncrementWrap:
                return GL.INCR_WRAP;
            case StencilAction.Invert:
                return GL.INVERT;
            case StencilAction.Keep:
                return GL.KEEP;
            case StencilAction.Replace:
                return GL.REPLACE;
            case StencilAction.Zero:
                return GL.ZERO;
        }
    }


    setStencilParameters(compareMode: CompareMode, bothPass: StencilAction, depthFail: StencilAction, stencilFail: StencilAction, referenceValue: StencilValue, readMask: number = 0xff, writeMask: number = 0xff): void {
        const GL = GameView.context
        if (compareMode == CompareMode.Always && bothPass == StencilAction.Keep
            && depthFail == StencilAction.Keep && stencilFail == StencilAction.Keep) {
            GL.disable(GL.STENCIL_TEST);
        }
        else {
            GL.enable(GL.STENCIL_TEST);
            var stencilFunc = this.convertCompareMode(compareMode);
            GL.stencilMask(writeMask);
            GL.stencilOp(this.convertStencilAction(stencilFail), this.convertStencilAction(depthFail), this.convertStencilAction(bothPass));
            switch (referenceValue) {
                case StencilValue.Static(referenceValue.value):
                    GL.stencilFunc(stencilFunc, referenceValue.value, readMask);
                case StencilValue.Dynamic:
                    GL.stencilFunc(stencilFunc, 0, readMask);
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
        const GL = GameView.context

        GL.uniform1i(location.value, value ? 1 : 0);
    }
    setInt(location: ConstantLocation, value: number): void {
        const GL = GameView.context

        GL.uniform1i(location.value, value);

        // check errors
    }
    setInt2(location: ConstantLocation, value1: number, value2: number): void {
        const GL = GameView.context

        GL.uniform2i(location.value, value1, value2);

        // check errors
    }
    setInt3(location: ConstantLocation, value1: number, value2: number, value3: number): void {
        const GL = GameView.context

        GL.uniform3i(location.value, value1, value2, value3);

        // check errors
    }
    setInt4(location: ConstantLocation, value1: number, value2: number, value3: number, value4: number): void {
        const GL = GameView.context

        GL.uniform4i(location.value, value1, value2, value3, value4);

        // check errors
    }
    setInts(location: ConstantLocation, values: Float32Array): void {
        const GL = GameView.context
        switch (location.type) {
            case GL.FLOAT_VEC2:
                GL.uniform2iv(location.value, values);
                break;
            case GL.FLOAT_VEC3:
                GL.uniform3iv(location.value, values);
                break;
            case GL.FLOAT_VEC4:
                GL.uniform4iv(location.value, values);
                break;
            default:
                GL.uniform1iv(location.value, values);
                break;
        }
        // check errors
    }
    setFloat(location: ConstantLocation, value: number): void {
        const GL = GameView.context

        GL.uniform1f(location.value, value);

        // check errors
    }
    setFloat2(location: ConstantLocation, value1: number, value2: number): void {
        const GL = GameView.context

        GL.uniform2f(location.value, value1, value2);

        // check errors
    }
    setFloat3(location: ConstantLocation, value1: number, value2: number, value3: number): void {
        const GL = GameView.context

        GL.uniform3f(location.value, value1, value2, value3);

        // check errors
    }
    setFloat4(location: ConstantLocation, value1: number, value2: number, value3: number, value4: number): void {
        const GL = GameView.context

        GL.uniform4f(location.value, value1, value2, value3, value4);

        // check errors
    }
    setFloats(location: ConstantLocation, values: Float32Array): void {
        const GL = GameView.context
        switch (location.type) {
            case GL.FLOAT_VEC2:
                GL.uniform2fv(location.value, values);
                break;
            case GL.FLOAT_VEC3:
                GL.uniform3fv(location.value, values);
                break;
            case GL.FLOAT_VEC4:
                GL.uniform4fv(location.value, values);
                break;
            case GL.FLOAT_MAT4:
                GL.uniformMatrix4fv(location.value, false, values);
                break;
            default:
                GL.uniform1fv(location.value, values);
                break;
        }
        // check errors
    }
    setVector2(location: ConstantLocation, value: Vector2): void {
        const GL = GameView.context
        GL.uniform2f(location.value, value.x, value.y);
    }
    setVector3(location: ConstantLocation, value: Vector3): void {
        const GL = GameView.context
        GL.uniform3f(location.value, value.x, value.y, value.z);
    }
    setVector4(location: ConstantLocation, value: Vector4): void {
        const GL = GameView.context
        GL.uniform4f(location.value, value.x, value.y, value.z, value.w);
    }


    matrixCache = new Float32Array(16);

    setMatrix(location: ConstantLocation, matrix: Matrix4): void {
        const GL = GameView.context
        this.matrixCache[0] = matrix._00; this.matrixCache[1] = matrix._01; this.matrixCache[2] = matrix._02; this.matrixCache[3] = matrix._03;
        this.matrixCache[4] = matrix._10; this.matrixCache[5] = matrix._11; this.matrixCache[6] = matrix._12; this.matrixCache[7] = matrix._13;
        this.matrixCache[8] = matrix._20; this.matrixCache[9] = matrix._21; this.matrixCache[10] = matrix._22; this.matrixCache[11] = matrix._23;
        this.matrixCache[12] = matrix._30; this.matrixCache[13] = matrix._31; this.matrixCache[14] = matrix._32; this.matrixCache[15] = matrix._33;

        GL.uniformMatrix4fv(location.value, false, this.matrixCache);
    }

    matrix3Cache = new Float32Array(9);

    setMatrix3(location: ConstantLocation, matrix: Matrix3): void {
        const GL = GameView.context

        this.matrix3Cache[0] = matrix._00; this.matrix3Cache[1] = matrix._01; this.matrix3Cache[2] = matrix._02;
        this.matrix3Cache[3] = matrix._10; this.matrix3Cache[4] = matrix._11; this.matrix3Cache[5] = matrix._12;
        this.matrix3Cache[6] = matrix._20; this.matrix3Cache[7] = matrix._21; this.matrix3Cache[8] = matrix._22;

        GL.uniformMatrix4fv(location.value, false, this.matrixCache);
    }

    drawIndexedVertices(start: number, count: number): void {
        const GL = GameView.context
        const type = GameView.elementIndexUint == null ? GL.UNSIGNED_SHORT : GL.UNSIGNED_INT;
        const size = type == GL.UNSIGNED_SHORT ? 2 : 4;
        GL.drawElements(GL.TRIANGLES, count == -1 ? this.indicesCount : count, type, start * size);
        for (let i = 0; i < this.useVertexAttributes; i++) {
            GL.disableVertexAttribArray(i);
        }
    }
    drawIndexedVerticesInstanced(instanceCount: number, start: number, count: number): void {
        throw new Error("Method not implemented.");
    }
    flush(): void {
        throw new Error("Method not implemented.");
    }

}