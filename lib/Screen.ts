import { RenderTarget, RenderTargetFormat } from "./Graphics/Graphics4/RenderTarget"
import { VertexStructure } from "./Graphics/VertexStructure"
import { VertexData } from "./Graphics/VertexData"
import { VertexBuffer } from "./Graphics/VertexBuffer"
import { Usage } from "./Graphics/Usage"
import { IndexBuffer } from "./Graphics/IndexBuffer"
import { PipelineState } from "./Graphics/PipelineState"
import { VertexShader } from "./Graphics/VertexShader"
import { FragmentShader } from "./Graphics/FragmentShader"
import { ExpoWebGLRenderingContext } from "expo-gl"

export class Screen {

    renderTarget: RenderTarget = null
    vertexArray: WebGLVertexArrayObject = null
    frameBuffer: WebGLFramebuffer = null

    constructor(private GL:ExpoWebGLRenderingContext, private innerWidth?: number, private innerHeight?: number, private depthBufferBits: number = 16, private stencilBufferBits: number = 8) {
    }

    async init() {
        const native = await (import("react-native"))
       
        if (native) {
            const dim = native.Dimensions.get("screen")

            this.innerWidth = this.innerWidth  ? this.innerWidth : dim.width
            this.innerHeight = this.innerHeight  ? this.innerHeight : dim.height

   
           
        } else {
            this.innerWidth =  this.innerWidth ? this.innerWidth : 800
            this.innerHeight =  this.innerHeight !=0 ? this.innerHeight : 600
        }
 
     
        Screen.Width = this.innerWidth
        Screen.Height = this.innerHeight
       
       
        // this.renderTarget = RenderTarget.init(this.innerWidth, this.innerHeight, depthBufferBits, false, RenderTargetFormat.FORMAT_32BIT, stencilBufferBits, 0)
        // const vertexStructure = new VertexStructure();
        // vertexStructure.add("pos", VertexData.Float2);
        // const vertexBuffer = new VertexBuffer(4, vertexStructure, Usage.Static, 0)
        // const vertices = vertexBuffer.lock();
        // vertices[0] = -1.0;
        // vertices[1] = -1.0;
        // vertices[2] = -1.0;
        // vertices[3] = 1.0;
        // vertices[4] = 1.0;
        // vertices[5] = 1.0;
        // vertices[6] = 1.0;
        // vertices[7] = -1.0;

        // vertexBuffer.unlock();

        // const indexBuffer = new IndexBuffer(6, null)
        // const indices = indexBuffer.lock();

        // indices[0] = 0;
        // indices[1] = 1;
        // indices[2] = 2;
        // indices[3] = 0;
        // indices[4] = 2;
        // indices[5] = 3;

        // indexBuffer.unlock();

        // const vertexShader = VertexShader.fromSource(
        // "#version 100\n"+
        // "precision highp float;"+
        // "attribute vec2 pos;\n"+
        // "varying vec2 texCoord;\n"+
        // "void main(){\n"+
        // "gl_Position = vec4(pos, 0.5, 1.0);\n"+
        // "texCoord = (pos + 1.0) / 2.0;\n}"
        // )

        // const fragmentShader = FragmentShader.fromSource(
        // "#version 100\n"+
        // "precision highp float;"+
		// "uniform sampler2D tex;\n"+
		// "varying vec2 texCoord;\n"+
		// // "varying vec4 frag;\n"+
        // "void main(){\n"+
        // "vec4 color = texture2D(tex, texCoord);\n"+
		// "gl_FragColor = color;\n"+
		// "}"
        // )

        // const pipeline = new PipelineState()
        // pipeline.inputLayout[0] = vertexStructure
        // pipeline.inputLayout[1] = null;
        // pipeline.vertexShader = vertexShader
        // pipeline.fragmentShader = fragmentShader
        // pipeline.compile();

        // this.vertexArray = this.GL.createVertexArray()
        // this.GL.bindVertexArray(this.vertexArray)

      

        // this.GL.bindFramebuffer(this.GL.FRAMEBUFFER, this.frameBuffer)

        // pipeline.set();
        // this.GL.bindFramebuffer(this.GL.FRAMEBUFFER, this.renderTarget._framebuffer)
        // if (this.renderTarget.isCubeMap) {
        //     this.GL.framebufferTextureLayer(this.GL.FRAMEBUFFER, this.renderTarget.isDepthAttachment ? this.GL.DEPTH_ATTACHMENT : this.GL.COLOR_ATTACHMENT0, this.renderTarget._texture, 0, 0);
        // }

        // this.GL.viewport(0, 0, this.renderTarget.width, this.renderTarget.height)

        // for (let i = 0; i < 8; ++i) {
        //     this.GL.framebufferTexture2D(this.GL.FRAMEBUFFER, this.GL.COLOR_ATTACHMENT0 + i, this.GL.TEXTURE_2D, null, 0);
        // }

    }

    get width() {
        return this.innerWidth
    }

    get height() {
        return this.innerHeight
    }

    static Width: number = 0
    static Height: number = 0
}