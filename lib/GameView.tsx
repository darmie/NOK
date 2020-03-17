import React, { Component } from "react"
import { GLView, ExpoWebGLRenderingContext } from 'expo-gl';


export class GameView extends Component {

    static context: ExpoWebGLRenderingContext;

    static elementIndexUint: any;

    static drawBuffers: WEBGL_draw_buffers = null;
    static anisotropic: EXT_texture_filter_anisotropic = null

    async componentDidMount() {
        GameView.context = await GLView.createContextAsync();
        GameView.drawBuffers = GameView.context.getExtension("WEBGL_draw_buffers")
        GameView.anisotropic = GameView.context.getExtension("EXT_texture_filter_anisotropic");
        GameView.elementIndexUint = GameView.context.getExtension("OES_element_index_uint");
    }

    render() {
        return (
            <React.Fragment></React.Fragment>
        )
    }
}