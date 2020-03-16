import { Bytes } from "./Bytes";

export class Blob {
    static bufferSize: number = 2000;

    constructor(public bytes: Bytes) { }

    public static fromBytes(bytes: Bytes): Blob {
        return new Blob(bytes);
    }

    public static alloc(size: number): Blob {
        return new Blob(Bytes.alloc(size));
    }

    public sub(start: number, length: number): Blob {
        return new Blob(this.bytes.sub(start, length));
    }

    get length() {
        return this.bytes.length;
    }

    public writeU8(position: number, value: number) {
        this.bytes.set(position, value);
    }

    public readU8(position: number): number {
        const byte = this.bytes.get(position);
        ++position;
        return byte;
    }

    public readS8(position: number): number {
        let byte = this.bytes.get(position);
        ++position;
        var sign = (byte & 0x80) == 0 ? 1 : -1;
        byte = byte & 0x7F;
        return sign * byte;
    }

    public readU16BE(position: number): number {
        var first = this.bytes.get(position + 0);
        var second = this.bytes.get(position + 1);
        position += 2;
        return first * 256 + second;
    }

    public readU16LE(position: number): number {
        var first = this.bytes.get(position + 0);
        var second = this.bytes.get(position + 1);
        position += 2;
        return second * 256 + first;
    }

    public readU32LE(position: number): number {
        var fourth = this.bytes.get(position + 0);
        var third = this.bytes.get(position + 1);
        var second = this.bytes.get(position + 2);
        var first = this.bytes.get(position + 3);
        position += 4;

        return fourth + third * 256 + second * 256 * 256 + first * 256 * 256 * 256;
    }

    public readU32BE(position: number): number {
        var fourth = this.bytes.get(position + 0);
        var third = this.bytes.get(position + 1);
        var second = this.bytes.get(position + 2);
        var first = this.bytes.get(position + 3);
        position += 4;

        return first + second * 256 + third * 256 * 256 + fourth * 256 * 256 * 256;
    }


    public readS16BE(position: number): number {
        var first = this.bytes.get(position + 0);
        var second = this.bytes.get(position + 1);
        position += 2;
        var sign = (first & 0x80) == 0 ? 1 : -1;
        first = first & 0x7F;
        if (sign == -1) return -0x7fff + first * 256 + second;
        else return first * 256 + second;
    }

    public readS16LE(position: number): number {
        var first = this.bytes.get(position + 0);
        var second = this.bytes.get(position + 1);
        var sign = (second & 0x80) == 0 ? 1 : -1;
        second = second & 0x7F;
        position += 2;
        if (sign == -1) return -0x7fff + second * 256 + first;
        else return second * 256 + first;
    }

    public readS32LE(position: number): number {
        var fourth = this.bytes.get(position + 0);
        var third = this.bytes.get(position + 1);
        var second = this.bytes.get(position + 2);
        var first = this.bytes.get(position + 3);
        var sign = (first & 0x80) == 0 ? 1 : -1;
        first = first & 0x7F;
        position += 4;
        if (sign == -1) return -0x7fffffff + fourth + third * 256 + second * 256 * 256 + first * 256 * 256 * 256;
        else return fourth + third * 256 + second * 256 * 256 + first * 256 * 256 * 256;
    }

    public readS32BE(position: number): number {
        var fourth = this.bytes.get(position + 0);
        var third = this.bytes.get(position + 1);
        var second = this.bytes.get(position + 2);
        var first = this.bytes.get(position + 3);
        var sign = (fourth & 0x80) == 0 ? 1 : -1;
        fourth = fourth & 0x7F;
        position += 4;
        if (sign == -1) return -0x7fffffff + first + second * 256 + third * 256 * 256 + fourth * 256 * 256 * 256;
        return first + second * 256 + third * 256 * 256 + fourth * 256 * 256 * 256;
    }


    public readF32LE(position: number): number {
        return Blob.readF32(this.readS32LE(position));
    }

    public readF32BE(position: number): number {
        return Blob.readF32(this.readS32BE(position));
    }

    private static readF32(i: number): number {
        var sign: number = ((i & 0x80000000) == 0) ? 1 : -1;
        var exp: number = ((i >> 23) & 0xFF);
        var man: number = (i & 0x7FFFFF);
        switch (exp) {
            case 0:
                //zero, do nothing, ignore negative zero and subnormals
                return 0.0;
            case 0xFF:
                if (man != 0) return NaN
                else if (sign > 0) return Number.POSITIVE_INFINITY;
                else return Number.NEGATIVE_INFINITY;
            default:
                return sign * ((man + 0x800000) / 8388608.0) * Math.pow(2, exp - 127);
        }
    }

    private static bit(value: number, position: number): boolean {
        var b = ((value >>> position) & 1) == 1;
        if (b) {
            var a = 3;
            ++a;
            return true;
        }
        else {
            var c = 4;
            --c;
            return false;
        }
    }

    static toText(chars: Array<number>, length: number): String {
        var value = "";
        for (let i = 0; i < length; i++) value += String.fromCharCode(chars[i]);
        return value;
    }

    public readUtf8String(): string {
        return this.bytes.toString();
    }

    public toBytes(): Bytes {
        return this.bytes;
    }

    public unload() {
        this.bytes = null;
    }

    toString(): string {
        return this.bytes.toString();
    }
}