import { Usage } from "./Usage"
import { VertexStructure } from "./VertexStructure"
import { VertexData } from "./VertexData"
import { GLView } from "expo-gl";
import { GameView } from "../GameView";

export class VertexBuffer {
    private buffer: any;
    public _data: Float32Array;
    private mySize: number;
    private myStride: number;
    private sizes: Array<number>;
    private offsets: Array<number>;
    private types: Array<number>;
    private lockStart: number = 0;
    private lockEnd: number = 0;

    constructor(vertexCount: number, structure: VertexStructure, private usage: Usage, private instanceDataStepRate: number = 0, canRead: boolean = false) {
        this.mySize = vertexCount;
        this.myStride = 0;
        for (let element of structure.elements) {
            switch (element.data) {
                case VertexData.Float1:
                    this.myStride += 4 * 1;
                case VertexData.Float2:
                    this.myStride += 4 * 2;
                case VertexData.Float3:
                    this.myStride += 4 * 3;
                case VertexData.Float4:
                    this.myStride += 4 * 4;
                case VertexData.Float4x4:
                    this.myStride += 4 * 4 * 4;
                case VertexData.Short2Norm:
                    this.myStride += 2 * 2;
                case VertexData.Short4Norm:
                    this.myStride += 2 * 4;
            }
        }

        this.buffer = GameView.context.createBuffer();
        this._data = new Float32Array(vertexCount * this.myStride / 4);
        this.sizes = new Array<number>();
        this.offsets = new Array<number>();
        this.types = new Array<number>();

        this.sizes[structure.elements.length - 1] = 0;
        this.offsets[structure.elements.length - 1] = 0;
        this.types[structure.elements.length - 1] = 0;

        var offset = 0;
        var index = 0;
        for (let element of structure.elements) {
            var size;
            var type;
            switch (element.data) {
                case VertexData.Float1:
                    size = 1;
                    type = GameView.context.FLOAT;
                case VertexData.Float2:
                    size = 2;
                    type = GameView.context.FLOAT;
                case VertexData.Float3:
                    size = 3;
                    type = GameView.context.FLOAT;
                case VertexData.Float4:
                    size = 4;
                    type = GameView.context.FLOAT;
                case VertexData.Float4x4:
                    size = 4 * 4;
                    type = GameView.context.FLOAT;
                case VertexData.Short2Norm:
                    size = 2;
                    type = GameView.context.SHORT;
                case VertexData.Short4Norm:
                    size = 4;
                    type = GameView.context.SHORT;
            }
            this.sizes[index] = size;
            this.offsets[index] = offset;
            this.types[index] = type;
            switch (element.data) {
                case VertexData.Float1:
                    offset += 4 * 1;
                case VertexData.Float2:
                    offset += 4 * 2;
                case VertexData.Float3:
                    offset += 4 * 3;
                case VertexData.Float4:
                    offset += 4 * 4;
                case VertexData.Float4x4:
                    offset += 4 * 4 * 4;
                case VertexData.Short2Norm:
                    offset += 2 * 2;
                case VertexData.Short4Norm:
                    offset += 2 * 4;
            }
            ++index;
        }
    }

    /**
 * Delete buffer
 */
    public delete() {
        this._data = null;
        GameView.context.deleteBuffer(this.buffer);
    }

    /**
     * Lock buffer
     * @param start 
     * @param count 
     */
    public lock(start?: number, count?: number) {
        this.lockStart = start ? start : 0;
        this.lockEnd = count ? start + count : this.mySize;
        return this._data.subarray(this.lockStart * this.stride(), this.lockEnd * this.stride());
    }

    public lockInt16(start?: number, count?: number): Int16Array {
        return new Int16Array(this.lock(start, count).buffer);
    }

    public unlock(count?: number) {
        if (count) this.lockEnd = this.lockStart + count;
        GameView.context.bindBuffer(GameView.context.ARRAY_BUFFER, this.buffer);
        GameView.context.bufferData(GameView.context.ARRAY_BUFFER, this._data.subarray(this.lockStart * this.stride(), this.lockEnd * this.stride()), this.usage == Usage.Dynamic ? GameView.context.DYNAMIC_DRAW : GameView.context.STATIC_DRAW);
    }

    public set(offset:number):number {
        let ext = GameView.context.getExtension("ANGLE_instanced_arrays");
        GameView.context.bindBuffer(GameView.context.ARRAY_BUFFER, this.buffer);
        let attributesOffset = 0;
        for (let i=0; i < this.sizes.length; i++) {
            if (this.sizes[i] > 4) {
				var size = this.sizes[i];
				var addonOffset = 0;
				while (size > 0) {
					GameView.context.enableVertexAttribArray(offset + attributesOffset);
					GameView.context.vertexAttribPointer(offset + attributesOffset, 4, GameView.context.FLOAT, false, this.myStride, this.offsets[i] + addonOffset);
					if (ext) {
						// if (SystemImpl.gl2) {
						// 	GameView.context.vertexAttribDivisor(offset + attributesOffset, instanceDataStepRate);
						// }
						// else {
							ext.vertexAttribDivisorANGLE(offset + attributesOffset, this.instanceDataStepRate);
						// }
					}
					size -= 4;
					addonOffset += 4 * 4;
					++attributesOffset;
				}
            }
            else {
				var normalized = this.types[i] == GameView.context.FLOAT ? false : true;
				GameView.context.enableVertexAttribArray(offset + attributesOffset);
				GameView.context.vertexAttribPointer(offset + attributesOffset, this.sizes[i], this.types[i], normalized, this.myStride, this.offsets[i]);
				if (ext) {
					// if (SystemImpl.gl2) {
					// 	GameView.context.vertexAttribDivisor(offset + attributesOffset, this.instanceDataStepRate);
					// }
					// else {
						ext.vertexAttribDivisorANGLE(offset + attributesOffset, this.instanceDataStepRate);
					// }
				}
				++attributesOffset;
			}
        }
        return attributesOffset;
    }

    public stride(): number {
        return this.myStride;
    }

    public count() {
        return this.mySize;
    }
}