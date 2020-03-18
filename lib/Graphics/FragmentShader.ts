import { GL} from "../GL";
import {Blob} from "../Internal/Blob"
import { Shader } from "./Shader";
import { ShaderType } from "./ShaderType";

export class FragmentShader {
    type:any = "";
    shader:any = null;
    sources:Array<string> = []
    constructor(sources:Array<Blob>, public files?:Array<string>){
        for(let source of sources){
            this.sources.push(source.toString())
        }
        this.type = GL.context.FRAGMENT_SHADER;
    
        this.shader = sources[0] ? Shader.initFromSource(sources[0].toString(), ShaderType.FragmentShader) : null;
    }

    public static fromSource(source: string): FragmentShader {
		var shader = new FragmentShader([], ["runtime-string"]);
        shader.sources.push(source);
        shader.shader = Shader.initFromSource(source, ShaderType.FragmentShader);
		return shader;
	}
	
	public delete() {
		GL.context.deleteShader(this.shader);
		this.shader = null;
		this.sources = null;
	}
}