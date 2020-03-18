import { Canvas } from "./Graphics/Canvas";
import {Graphics} from "./Graphics/Graphics4/Graphics";
import {Graphics2} from "./Graphics/Graphics4/Graphics2";
import { Screen } from "./Screen";

/**
 * A Framebuffer object represents the framebuffer of a kha.Window, which
 * typically contains a color, depth and stencil buffer. It is used to
 * query Graphics interfaces for rendering images which are directly visible.
 */
export class Framebuffer implements Canvas {
    
    g2:Graphics2
    g4:Graphics

    constructor(private graphics2: Graphics2, private graphics4:  Graphics){}

    init(g2: Graphics2, g4:  Graphics){
        this.graphics2 = this.g2 = g2;
        this.graphics4 = this.g4 = g4;
    }

    get width(){
        return Screen.Width
    }

    get height(){
        return Screen.Height
    }


}