import { ExpoWebGLRenderingContext } from "expo-gl";


export class GL {
    static context:ExpoWebGLRenderingContext = null;
    static elementIndexUint: any;

    static drawBuffers: WEBGL_draw_buffers = null;
    static anisotropic: EXT_texture_filter_anisotropic = null

    static get time() {
        var performance = window.performance ? window.performance : window.Date
        return performance.now() / 1000;
    }
}