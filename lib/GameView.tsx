import React, { Component } from "react"
import { GLView, ExpoWebGLRenderingContext } from 'expo-gl';
import { Framebuffer } from "./Framebuffer"
import { Screen } from "./Screen";
import { Scheduler } from "./Internal/Scheduler";
import {Graphics} from "./Graphics/Graphics4/Graphics";
import {Graphics2} from "./Graphics/Graphics4/Graphics2";
import { Color } from "./Graphics/Color";
import { Image } from "./Graphics/Image";
import { ImageFormat } from "./Graphics/ImageFormat";
import {GL as OGL} from "./GL"
export class GameView extends Component {
    state = {
        width:0,
        height:0
    }
    constructor(props){
        super(props)
    }

    private static renderListeners: Array<((buffers: Array<Framebuffer>) => void)> = [];
    private static foregroundListeners: Array<() => void> = [];
    private static resumeListeners: Array<() => void> = [];
    private static pauseListeners: Array<() => void> = [];
    private static backgroundListeners: Array<() => void> = [];
    private static shutdownListeners: Array<() => void> = [];
    private static theTitle: String;

    public static context: ExpoWebGLRenderingContext = null;


    /**
     * The provided listener is called when new framebuffers are ready for rendering into.
     * Single-window applications always receive an array of only one framebuffer.
     * @param listener 
     */
    static notifyOnFrames(listener: (buffers: Array<Framebuffer>) => void) {
        this.renderListeners.push(listener);
    }

    static removeFramesListener(listener: (buffers: Array<Framebuffer>) => void): void {
        this.renderListeners.splice(this.renderListeners.indexOf(listener));
    }

    static render(framebuffers: Array<Framebuffer>) {
        for (let listener of this.renderListeners) {
            listener(framebuffers);
        }
    }

    private static foreground() {
        for (let listener of this.foregroundListeners) {
            listener();
        }
    }

    private static resume() {
        for (let listener of this.resumeListeners) {
            listener();
        }
    }

    private static pause() {
        for (let listener of this.resumeListeners) {
            listener();
        }
    }

    private static background() {
        for (let listener of this.backgroundListeners) {
            listener();
        }
    }

    private static shutdown() {
        for (let listener of this.shutdownListeners) {
            listener();
        }
    }

    static notifyOnApplicationState(foregroundListener: () => void, resumeListener: () => void, pauseListener: () => void, backgroundListener: () => void, shutdownListener: () => void): void {
        if (foregroundListener != null) this.foregroundListeners.push(foregroundListener);
        if (resumeListener != null) this.resumeListeners.push(resumeListener);
        if (pauseListener != null) this.pauseListeners.push(pauseListener);
        if (backgroundListener != null) this.backgroundListeners.push(backgroundListener);
    }

    static get width() {
        return Screen.Width
    }

    static get height() {
        return Screen.Height
    }

    frame: Framebuffer

    componentDidMount() {
        
    }

    async loaded(GL:ExpoWebGLRenderingContext){
        OGL.context = GL;
        
        let screen:Screen = null;
        if(this.props){
            screen = new Screen(GL, (this.props as any).width ? (this.props as any).width : null, (this.props as any).height ? (this.props as any).height : null)
        } else {
            screen = new Screen(GL);
        }
        await screen.init()

        this.setState({width:Screen.Width, height:Screen.Height})

        Scheduler.init();

        if (this.props && (this.props as any).callback) {
            (this.props as any).callback();
        }

        this.draw()
       
        GL.pixelStorei(GL.UNPACK_PREMULTIPLY_ALPHA_WEBGL, 1);
        OGL.drawBuffers = GL.getExtension("WEBGL_draw_buffers")

        OGL.elementIndexUint = GL.getExtension("OES_element_index_uint");

        GL.getExtension("EXT_color_buffer_float");
        GL.getExtension("OES_texture_float_linear");
        GL.getExtension("OES_texture_half_float_linear");
        OGL.anisotropic = GL.getExtension("EXT_texture_filter_anisotropic");
        if (OGL.anisotropic == null) OGL.anisotropic = GL.getExtension("WEBKIT_EXT_texture_filter_anisotropic");
    
        
        const g4 = new Graphics()
        
        this.frame = new Framebuffer(null, g4);
        const g2 = new Graphics2(this.frame);
        this.frame.init(g2, g4);

        Scheduler.start();

        if (requestAnimationFrame == null) setTimeout(this.animate.bind(this), 1000.0 / 60.0);
        else requestAnimationFrame(this.animate.bind(this));

        GameView.foreground();
    }

    animate(timestamp:number) {
        if (requestAnimationFrame == null) setTimeout(this.animate.bind(this), 1000.0 / 60.0);
        else requestAnimationFrame(this.animate.bind(this));

        Scheduler.executeFrame();

        GameView.render([this.frame]);

        const GL = OGL.context
        GL.clearColor(1, 1, 1, 1);
        GL.colorMask(false, false, false, true);
        GL.clear(GL.COLOR_BUFFER_BIT);
        GL.colorMask(true, true, true, true);
    }


    draw = ()=>{
        GameView.notifyOnFrames((buffers:Framebuffer[])=>{
            const buf = buffers[0];
            if(this.props && this.props.hasOwnProperty("draw"))
            (this.props as any).draw(buf);
        })
        Scheduler.addTimeTask(this.update, 0, 1/60);
    }

    update(){}

    render() {
        return (
            <React.Fragment>
                <GLView  style={{width: Screen.Width, height:Screen.Height}}  onContextCreate={this.loaded.bind(this)} />
            </React.Fragment>
        )
    }
}