import { ShaderType } from "./ShaderType";
import { GameView } from "../GameView";

export class Shader {
    fromSource:boolean;
    length:number;
    glid:number;
    source:string
    
    constructor(data:Uint8Array, size:number, public type:ShaderType){
        this.fromSource = false;
        this.glid = 0;
        this.length = size;
        if(data){
            this.source = data.toString();
        }
        
    }

    static initFromSource(source:string, type:ShaderType){
        const shader = new Shader(null, source.length, type);
        shader.glid = 0;
        shader.fromSource = true;
        shader.source = source;
    }

    destroy(){
        this.source = null
        if(this.glid != 0){
            GameView.context.deleteShader(this.glid);
        }    
    }

}