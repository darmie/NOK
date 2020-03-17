import React, { Component } from "react"
import { GLView, ExpoWebGLRenderingContext } from 'expo-gl';
import { Framebuffer } from "./Framebuffer"
import { Screen } from "./Screen";
import { Scheduler } from "./Internal/Scheduler";
import { graphics4 } from "./Graphics/Graphics4";

export class GameView extends Component {

    private static renderListeners: Array<((buffers: Array<Framebuffer>) => void)> = [];
    private static foregroundListeners: Array<() => void> = [];
    private static resumeListeners: Array<() => void> = [];
    private static pauseListeners: Array<() => void> = [];
    private static backgroundListeners: Array<() => void> = [];
    private static shutdownListeners: Array<() => void> = [];
    private static dropFilesListeners: Array<() => void> = [];
    private static cutListener: () => String = null;
    private static copyListener: () => String = null;
    private static pasteListener: (name: string) => void = null;
    private static loginListener: () => void = null;
    private static logoutListener: () => void = null;
    private static theTitle: String;

    static context: ExpoWebGLRenderingContext;

    static elementIndexUint: any;

    static drawBuffers: WEBGL_draw_buffers = null;
    static anisotropic: EXT_texture_filter_anisotropic = null


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

    static get time() {
        var performance = window.performance ? window.performance : window.Date
        return performance.now() / 1000;
    }

    static get width() {
        return Screen.Width
    }

    static get height() {
        return Screen.Height
    }

    frame: Framebuffer

    async componentDidMount() {
        new Screen((this.props as any).width ? (this.props as any).width : null, (this.props as any).height ? (this.props as any).height : null)

        Scheduler.init();

        if ((this.props as any).callback) {
            (this.props as any).callback();
        }


        GameView.context = await GLView.createContextAsync();
        const GL = GameView.context
        GL.pixelStorei(GL.UNPACK_PREMULTIPLY_ALPHA_WEBGL, 1);
        GameView.drawBuffers = GL.getExtension("WEBGL_draw_buffers")

        GameView.elementIndexUint = GL.getExtension("OES_element_index_uint");

        GL.getExtension("EXT_color_buffer_float");
        GL.getExtension("OES_texture_float_linear");
        GL.getExtension("OES_texture_half_float_linear");
        GameView.anisotropic = GL.getExtension("EXT_texture_filter_anisotropic");
        if (GameView.anisotropic == null) GameView.anisotropic = GL.getExtension("WEBKIT_EXT_texture_filter_anisotropic");

        const g4 = new graphics4.Graphics()
        this.frame = new Framebuffer(null, g4);
        const g2 = new graphics4.Graphics2(this.frame);
        this.frame.init(g2, g4);

        Scheduler.start();

        if (requestAnimationFrame == null) setTimeout(this.animate, 1000.0 / 60.0);
        else requestAnimationFrame(this.animate);

        GameView.foreground();
    }

    animate(timestamp:number) {
        if (requestAnimationFrame == null) setTimeout(this.animate, 1000.0 / 60.0);
        else requestAnimationFrame(this.animate);

        Scheduler.executeFrame();

        GameView.render([this.frame]);

        const GL = GameView.context
        GL.clearColor(1, 1, 1, 1);
        GL.colorMask(false, false, false, true);
        GL.clear(GL.COLOR_BUFFER_BIT);
        GL.colorMask(true, true, true, true);
    }

    render() {
        return (
            <React.Fragment></React.Fragment>
        )
    }
}