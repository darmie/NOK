import { VertexElement } from "./VertexElement"
import { VertexData } from "./VertexData"

export class VertexStructure {
    public elements: Array<VertexElement>;
    public instanced: boolean;

    constructor() {
        this.elements = new Array<VertexElement>();
        this.instanced = false;
    }

    public add(name: string, data: VertexData) {
        this.elements.push(new VertexElement(name, data));
    }


    public size(): number {
        return this.elements.length;
    }

    public byteSize(): number {
        var byteSize = 0;

        for (let i = 0; i < this.elements.length; i++) {
            byteSize += this.dataByteSize(this.elements[i].data);
        }

        return byteSize;
    }

    private dataByteSize(data: VertexData): number {
        switch (data) {
            case VertexData.Float1:
                return 4 * 1;
            case VertexData.Float2:
                return 4 * 2;
            case VertexData.Float3:
                return 4 * 3;
            case VertexData.Float4:
                return 4 * 4;
            case VertexData.Float4x4:
                return 4 * 4 * 4;
            case VertexData.Short2Norm:
                return 2 * 2;
            case VertexData.Short4Norm:
                return 2 * 4;
        }
        return 0;
    }


    public get(index: number): VertexElement {
        return this.elements[index];
    }
}