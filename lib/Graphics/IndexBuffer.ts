import { GL } from "../GL"
import { Usage } from "./Usage"

export class IndexBuffer {
    private buffer: WebGLBuffer;
    _data: Uint32Array;
    size: number;
    private lockStart: number = 0;
    private lockEnd: number = 0;

    constructor(indexCount: number, private usage: Usage, canRead: boolean = false) {
        this.buffer = GL.context.createBuffer();
        this._data = new Uint32Array(indexCount);
    }

    /**
     * Delete buffer
     */
    public delete() {
        this._data = null;
        GL.context.deleteBuffer(this.buffer);
    }

    /**
     * Lock buffer
     * @param start 
     * @param count 
     */
    public lock(start?: number, count?: number) {
        this.lockStart = start ? start : 0;
        this.lockEnd = count ? start + count : this.size;
        return this._data.subarray(this.lockStart, this.lockEnd);
    }


    public unlock(count?: number) {
        if (count) this.lockEnd = this.lockStart + count;

        GL.context.bindBuffer(GL.context.ELEMENT_ARRAY_BUFFER, this.buffer);
        const data = this._data.subarray(this.lockStart, this.lockEnd);
        const glData = GL.context.getExtension("OES_element_index_uint") ? data.buffer : new Uint16Array(data.buffer);
        GL.context.bufferData(GL.context.ELEMENT_ARRAY_BUFFER, glData, this.usage == Usage.Dynamic ? GL.context.DYNAMIC_DRAW : GL.context.STATIC_DRAW);

    }

    public set() {
        GL.context.bindBuffer(GL.context.ELEMENT_ARRAY_BUFFER, this.buffer);
    }

    public count(): number {
        return this.size;
    }

}