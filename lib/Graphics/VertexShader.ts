
import {Blob} from "../Internal/Blob"
import { Shader } from "./Shader";
import { ShaderType } from "./ShaderType";
import { GL } from "../GL";

export class VertexShader {
    type:any = "";
    shader:any = null;
    sources:Array<string> = []
    constructor(sources:Array<Blob>, public files?:Array<string>){
        for(let source of sources){
            console.log(source)
            this.sources.push(source.toString())
        }
        this.type = GL.context.VERTEX_SHADER;
    
        this.shader = sources[0] ? Shader.initFromSource(sources[0].toString(), ShaderType.VertexShader) : null
    }

    public static fromSource(source: string): VertexShader {
		var shader = new VertexShader([], ["runtime-string"]);
        shader.sources.push(source);
        shader.shader = Shader.initFromSource(source, ShaderType.VertexShader);
		return shader;
	}
	
	public delete() {
		GL.context.deleteShader(this.shader);
		this.shader = null;
		this.sources = null;
	}
}