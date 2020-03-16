import {Color} from "../Color"
import {Canvas} from "../Canvas"
import {TextureUnit} from "../TextureUnit"
import {IndexBuffer} from "../IndexBuffer"
import {Image} from "../Image"
import {ConstantLocation} from "../ConstantLocation"
import {PipelineState} from "../PipelineState"
import {VertexBuffer} from "../VertexBuffer"
import {Vector2} from "../../Math/Vector2"
import {Vector3} from "../../Math/Vector3"
import {Vector4} from "../../Math/Vector4"
import {Matrix3} from "../../Math/Matrix3"
import {Matrix4} from "../../Math/Matrix4"
import {TextureAddressing} from "../TextureAddressing"
import {CubeMap} from "../CubeMap"
import {MipMapFilter} from "../MipMapFilter"
import {TextureFilter} from "../TextureFilter"

export interface IGraphics {
	 begin(additionalRenderTargets?:Array<Canvas>): void;
	 beginFace(face:number): void;
	 beginEye(eye:number): void;
	 end(): void;
	
	 vsynced(): boolean;
	 refreshRate():number;
	
	 clear(color: Color, depth?:number, stencil?:number): void;

	 viewport(x:number, y:number, width:number, height:number): void;
	 scissor(x:number, y:number, width:number, height:number): void;
	
	 disableScissor(): void;
	 setVertexBuffer(vertexBuffer: VertexBuffer): void;
	 setVertexBuffers(vertexBuffers: Array<VertexBuffer>): void;
	 setIndexBuffer(indexBuffer: IndexBuffer): void;
	
	 setTexture(unit: TextureUnit, texture: Image): void;
	 setTextureDepth(unit: TextureUnit, texture: Image): void;
	 setTextureArray(unit: TextureUnit, texture: Image): void;
	//  setVideoTexture(unit: TextureUnit, texture: Video): void;
	 setImageTexture(unit: TextureUnit, texture: Image): void;
	 setTextureParameters(texunit: TextureUnit, uAddressing: TextureAddressing, vAddressing: TextureAddressing, minificationFilter: TextureFilter, magnificationFilter: TextureFilter, mipmapFilter: MipMapFilter): void;
	 setTexture3DParameters(texunit: TextureUnit, uAddressing: TextureAddressing, vAddressing: TextureAddressing, wAddressing: TextureAddressing, minificationFilter: TextureFilter, magnificationFilter: TextureFilter, mipmapFilter: MipMapFilter): void;
	 setTextureCompareMode(texunit: TextureUnit, enabled: boolean): void;
	 setCubeMapCompareMode(texunit: TextureUnit, enabled: boolean): void;
	 setCubeMap(unit: TextureUnit, cubeMap: CubeMap): void;
	 setCubeMapDepth(unit: TextureUnit, cubeMap: CubeMap): void;
	// maxTextureSize():number;
	// supportsNonPow2Textures(): boolean;
	 setStencilReferenceValue(value:number): void;
	
	 instancedRenderingAvailable(): boolean;
	
	 setPipeline(pipeline: PipelineState): void;
	
	 setBool(location: ConstantLocation, value: boolean): void;
	 setInt(location: ConstantLocation, value:number): void;
	 setInt2(location: ConstantLocation, value1:number, value2:number): void;
	 setInt3(location: ConstantLocation, value1:number, value2:number, value3:number): void;
	 setInt4(location: ConstantLocation, value1:number, value2:number, value3:number, value4:number): void;
	 setInts(location: ConstantLocation, ints:Float32Array): void;
	 setFloat(location: ConstantLocation, value:number): void;
	 setFloat2(location: ConstantLocation, value1:number, value2:number): void;
	 setFloat3(location: ConstantLocation, value1:number, value2:number, value3:number): void;
	 setFloat4(location: ConstantLocation, value1:number, value2:number, value3:number, value4:number): void;
	 setFloats(location: ConstantLocation, floats:Float32Array): void;
	 setVector2(location: ConstantLocation, value: Vector2): void;
	 setVector3(location: ConstantLocation, value: Vector3): void;
	 setVector4(location: ConstantLocation, value: Vector4): void;
	 setMatrix(location: ConstantLocation, value: Matrix4): void;
	 setMatrix3(location: ConstantLocation, value: Matrix3): void;
	
	 drawIndexedVertices(start:number, count:number): void;
	 drawIndexedVerticesInstanced(instanceCount:number, start:number, count:number): void;
	
	 flush(): void;
}