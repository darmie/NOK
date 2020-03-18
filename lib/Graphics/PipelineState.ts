import { PipelineStateBase } from "./PipelineStateBase";
import { VertexData } from "./VertexData"
import { GL } from "../GL";
import { ConstantLocation } from "./ConstantLocation";
import { TextureUnit } from "./TextureUnit";
import { Shader } from "./Shader";

export class PipelineState extends PipelineStateBase {
    private program: WebGLProgram = null;
    private textures: Array<string>;
    private textureValues: Array<any>;

    constructor() {
        super();
        this.textures = new Array<string>();
        this.textureValues = new Array<any>();
    }

    delete() {
        if (this.program != null) {
            GL.context.deleteProgram(this.program);
        }
    }

    set() {
        GL.context.useProgram(this.program);
        for (let index = 0; index < this.textureValues.length; index++) GL.context.uniform1i(this.textureValues[index], index);
        GL.context.colorMask(this.colorWriteMaskRed, this.colorWriteMaskGreen, this.colorWriteMaskBlue, this.colorWriteMaskAlpha);
    }

    compile() {
        if (this.program != null) {
            GL.context.deleteProgram(this.program);
        }
        this.program = GL.context.createProgram();

        this.compileShader(this.vertexShader);
        this.compileShader(this.fragmentShader);

     
        GL.context.attachShader(this.program, this.vertexShader.shader);
        GL.context.attachShader(this.program, this.fragmentShader.shader);

        let index = 0;
        for (let structure of this.inputLayout) {
            if(structure){
                for (let element of structure.elements) {
                    GL.context.bindAttribLocation(this.program, index, element.name);
                    if (element.data == VertexData.Float4x4) {
                        index += 4;
                    }
                    else {
                        ++index;
                    }
                }
            }  
        }

        GL.context.linkProgram(this.program);
        if (!GL.context.getProgramParameter(this.program, GL.context.LINK_STATUS)) {
            throw "Could not link the shader program:\n" + GL.context.getProgramInfoLog(this.program);
        }
    }

    compileShader(shader: any) {
        if (shader.shader == null) return;
        const s = GL.context.createShader(shader.type);
        const highp = GL.context.getShaderPrecisionFormat(GL.context.FRAGMENT_SHADER, GL.context.HIGH_FLOAT);
        const highpSupported = highp.precision != 0;
        var files: Array<string> = shader.files;

        for (let i = 0; i < files.length; i++) {
            if (files[i].indexOf("-webgl2") >= 0 || files[i].indexOf("runtime-string") >= 0) {
                GL.context.shaderSource(s, shader.sources[i]);
                break;
            }

            // else {
            // if (!highpSupported && (files[i].indexOf("-relaxed") >= 0 || files[i].indexOf("runtime-string") >= 0)) {
            //     console.log(shader.sources[i])
            //     GL.context.shaderSource(s, shader.sources[i]);
            //     break;
            // }
            // if (highpSupported && (files[i].indexOf("-relaxed") < 0 || files[i].indexOf("runtime-string") >= 0)) {
            //     console.log(shader.sources[i])
            //     GL.context.shaderSource(s, shader.sources[i]);
            //     break;
            // }
            // }
        }

        GL.context.compileShader(s);
        if (!GL.context.getShaderParameter(s, GL.context.COMPILE_STATUS)) {
            throw "Could not compile shader:\n" + GL.context.getShaderInfoLog(s);
        }
        shader.shader = s;
    }

    getConstantLocation(name: string): ConstantLocation {
        let location = GL.context.getUniformLocation(this.program, name);
        if (location == null) {
            console.warn("Warning: Uniform " + name + " not found.");
        }
        var type = GL.context.FLOAT;
        var count: number = GL.context.getProgramParameter(this.program, GL.context.ACTIVE_UNIFORMS);
        for (let i = 0; i < count; i++) {
            var info = GL.context.getActiveUniform(this.program, i);
            if (info.name == name || info.name == name + "[0]") {
                type = info.type;
                break;
            }
        }
        return new ConstantLocation(location, type);
    }

    getTexureUnit(name: string): TextureUnit {
        var index = this.findTexture(name);
        if (index < 0) {
            var location = GL.context.getUniformLocation(this.program, name);
            if (location == null) {
                console.warn("Warning: Sampler " + name + " not found.");
            }
            index = this.textures.length;
            this.textureValues.push(location);
            this.textures.push(name);
        }
        return new TextureUnit(index);
    }

    private findTexture(name: string): number {
        for (let index = 0; index < this.textures.length; index++) {
            if (this.textures[index] == name) return index;
        }
        return -1;
    }
}