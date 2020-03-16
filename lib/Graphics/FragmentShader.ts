import { GameView } from "../GameView";
import {Blob} from "../Internal/Blob"
import { Shader } from "./Shader";
import { ShaderType } from "./ShaderType";

export class FragmentShader {
    type:any;
    shader:any;
    sources:Array<string>
    constructor(sources:Array<Blob>, files?:Array<string>){
        for(let source of sources){
            this.sources.push(source.toString())
        }
        this.type = GameView.context.FRAGMENT_SHADER;
    
        this.shader = Shader.initFromSource(sources[0].toString(), ShaderType.FragmentShader);
    }

    public static fromSource(source: string): FragmentShader {
		var shader = new FragmentShader([], ["runtime-string"]);
        shader.sources.push(source);
        shader.shader = Shader.initFromSource(source, ShaderType.FragmentShader);
		return shader;
	}
	
	public delete() {
		GameView.context.deleteShader(this.shader);
		this.shader = null;
		this.sources = null;
	}
}