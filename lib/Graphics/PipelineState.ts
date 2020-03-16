import { PipelineStateBase } from "./PipelineStateBase";
import { VertexData } from "./VertexData"
import { GameView } from "../GameView";
import { ConstantLocation } from "./ConstantLocation";
import { TextureUnit } from "./TextureUnit";

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
            GameView.context.deleteProgram(this.program);
        }
    }

    set() {
        GameView.context.useProgram(this.program);
        for (let index = 0; index < this.textureValues.length; index++) GameView.context.uniform1i(this.textureValues[index], index);
        GameView.context.colorMask(this.colorWriteMaskRed, this.colorWriteMaskGreen, this.colorWriteMaskBlue, this.colorWriteMaskAlpha);
    }

    compile() {
        if (this.program != null) {
            GameView.context.deleteProgram(this.program);
        }
        this.program = GameView.context.createProgram();

        this.compileShader(this.vertexShader);
        this.compileShader(this.fragmentShader);
        GameView.context.attachShader(this.program, this.vertexShader.shader);
        GameView.context.attachShader(this.program, this.fragmentShader.shader);

        let index = 0;
        for (let structure of this.inputLayout) {
            for (let element of structure.elements) {
                GameView.context.bindAttribLocation(this.program, index, element.name);
                if (element.data == VertexData.Float4x4) {
                    index += 4;
                }
                else {
                    ++index;
                }
            }
        }

        GameView.context.linkProgram(this.program);
        if (!GameView.context.getProgramParameter(this.program, GameView.context.LINK_STATUS)) {
            throw "Could not link the shader program:\n" + GameView.context.getProgramInfoLog(this.program);
        }
    }

    compileShader(shader: any) {
        if (shader.shader != null) return;
        const s = GameView.context.createShader(shader.type);
        const highp = GameView.context.getShaderPrecisionFormat(GameView.context.FRAGMENT_SHADER, GameView.context.HIGH_FLOAT);
        const highpSupported = highp.precision != 0;
        var files: Array<string> = shader.files;
        for (let i = 0; i < files.length; i++) {
            // if (SystemImpl.gl2) {
            // 	if (files[i].indexOf("-webgl2") >= 0 || files[i].indexOf("runtime-string") >= 0) {
            // 		GameView.context.shaderSource(s, shader.sources[i]);
            // 		break;
            // 	}
            // }
            // else {
            if (!highpSupported && (files[i].indexOf("-relaxed") >= 0 || files[i].indexOf("runtime-string") >= 0)) {
                GameView.context.shaderSource(s, shader.sources[i]);
                break;
            }
            if (highpSupported && (files[i].indexOf("-relaxed") < 0 || files[i].indexOf("runtime-string") >= 0)) {
                GameView.context.shaderSource(s, shader.sources[i]);
                break;
            }
            // }
        }
        GameView.context.compileShader(s);
        if (!GameView.context.getShaderParameter(s, GameView.context.COMPILE_STATUS)) {
            throw "Could not compile shader:\n" + GameView.context.getShaderInfoLog(s);
        }
        shader.shader = s;
    }

    getConstantLocation(name: string): ConstantLocation{
		let location = GameView.context.getUniformLocation(this.program, name);
		if (location == null) {
			console.warn("Warning: Uniform " + name + " not found.");
		}
		var type = GameView.context.FLOAT;
		var count: number = GameView.context.getProgramParameter(this.program, GameView.context.ACTIVE_UNIFORMS);
		for (let i = 0;  i < count; i++) {
			var info = GameView.context.getActiveUniform(this.program, i);
			if (info.name == name || info.name == name + "[0]") {
				type = info.type;
				break;
			}
		}
		return new ConstantLocation(location, type);
    }
    
    getTexureUnit(name:string):TextureUnit {
        var index = this.findTexture(name);
		if (index < 0) {
			var location = GameView.context.getUniformLocation(this.program, name);
			if (location == null) {
				console.warn("Warning: Sampler " + name + " not found.");
			}
			index = this.textures.length;
			this.textureValues.push(location);
			this.textures.push(name);
		}
		return new TextureUnit(index);
    }

    private findTexture(name: string):number {
		for (let index = 0; index < this.textures.length; index++) {
			if (this.textures[index] == name) return index;
		}
		return -1;
	}
}