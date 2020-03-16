import {Blob} from "../Internal/Blob"
import { Shader } from "./Shader";
import { ShaderType } from "./ShaderType";

export class TessellationControlShader {
    shader:Shader
    constructor(sources: Array<Blob>, files: Array<string>){
        this.init(sources[0], files[0]);
    }

    private init(source: Blob, file: String){
        const b = new Uint8Array(source.toBytes().getData())
        this.shader = new Shader(b, b.length, ShaderType.TessellationControlShader);
    }

	public delete(){
        this.shader.destroy();
    }
}