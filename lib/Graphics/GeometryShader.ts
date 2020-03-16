import { GameView } from "../GameView";
import {Blob} from "../Internal/Blob"
import { Shader } from "./Shader";
import { ShaderType } from "./ShaderType";

export class GeometryShader {
    shader:any;
    sources:Array<string>
    constructor(sources:Array<Blob>, files?:Array<string>){
        for(let source of sources){
            this.sources.push(source.toString())
        }
        
        this.shader = Shader.initFromSource(sources[0].toString(), ShaderType.GeometryShader);
    }

    public static fromSource(source: string): GeometryShader {
		var shader = new GeometryShader([], ["runtime-string"]);
        shader.sources.push(source);
        shader.shader = Shader.initFromSource(source, ShaderType.GeometryShader);
		return shader;
	}
	
	public delete() {
		GameView.context.deleteShader(this.shader);
		this.shader = null;
		this.sources = null;
	}
}