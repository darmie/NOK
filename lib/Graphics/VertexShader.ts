import { GameView } from "../GameView";
import {Blob} from "../Internal/Blob"
import { Shader } from "./Shader";
import { ShaderType } from "./ShaderType";

export class VertexShader {
    type:any;
    shader:any;
    sources:Array<string>
    constructor(sources:Array<Blob>, files?:Array<string>){
        for(let source of sources){
            this.sources.push(source.toString())
        }
        this.type = GameView.context.VERTEX_SHADER;
    
        this.shader = Shader.initFromSource(sources[0].toString(), ShaderType.VertexShader);
    }

    public static fromSource(source: string): VertexShader {
		var shader = new VertexShader([], ["runtime-string"]);
        shader.sources.push(source);
        shader.shader = Shader.initFromSource(source, ShaderType.VertexShader);
		return shader;
	}
	
	public delete() {
		GameView.context.deleteShader(this.shader);
		this.shader = null;
		this.sources = null;
	}
}