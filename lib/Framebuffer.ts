import { Canvas } from "./Graphics/Canvas";
import { graphics4 } from "./Graphics/Graphics4";
import { Screen } from "./Screen";

/**
 * A Framebuffer object represents the framebuffer of a kha.Window, which
 * typically contains a color, depth and stencil buffer. It is used to
 * query Graphics interfaces for rendering images which are directly visible.
 */
export class Framebuffer implements Canvas {
    

    constructor(private graphics2: graphics4.Graphics2, private graphics4:  graphics4.Graphics){}

    init(g2: graphics4.Graphics2, g4:  graphics4.Graphics){
        this.graphics2 = g2;
		this.graphics4 = g4;
    }

    /**
     * Returns a graphics4.Graphics2 interface for the framebuffer.
     */
    get g2(){
        return this.graphics2
    }

    /**
     * Returns a graphics4.Graphics interface for the framebuffer.
     */
    get g4(){
        return this.g4
    }

    get width(){
        return Screen.Width
    }

    get height(){
        return Screen.Height
    }


}