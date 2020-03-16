import {FPHelper} from "./FPHelper"
import {Int64LE, Uint64LE} from "int64-buffer"

export class Bytes {
    constructor(public length: number, private b: ArrayBuffer) { }


    static alloc(size:number){
        var a = new ArrayBuffer(size);
		for (let i = 0; i < size; i++)
			a[i] = 0;
		return new Bytes(length, a);
    }

    /**
     * Returns the byte at index `pos`.
     * @param pos 
     */
    public get(pos: number): number {
        return this.b[pos];
    }

    public getData(){
        return this.b;
    }

    /**
     * Stores the given byte `v` at the given position `pos`.
     * @param pos 
     * @param v 
     */
    public set(pos: number, v: number) {
        this.b[pos] = v & 0xFF;
    }

    /**
     * Copies `len` bytes from `src` into this instance.
     * @param pos  Zero-based location in `this` instance at which to start writing bytes.
     * @param src  Source `Bytes` instance from which to copy bytes.
     * @param srcpos  Zero-based location at `src` from which bytes will be copied.
     * @param len  Number of bytes to be copied.
     */
    public blit(pos: number, src: Bytes, srcpos: number, len: number) {
        if (pos < 0 || srcpos < 0 || len < 0 || pos + len > length || srcpos + len > src.length) throw "Error: Out of bounds";

        var b1 = this.b;
        var b2 = src.b;
        if (b1 == b2 && pos > srcpos) {
            var i = len;
            while (i > 0) {
                i--;
                b1[i + pos] = b2[i + srcpos];
            }
            return;
        }
        for (let i = 0; i < len; i++)
            b1[i + pos] = b2[i + srcpos];
    }

    /**
     * Sets `len` consecutive bytes starting from index `pos` of `this` instance
     * to `value`.
     * @param pos 
     * @param len 
     * @param value 
     */
    public fill(pos: number, len: number, value: number) {
        for (let i = 0; i < len; i++)
            this.set(pos++, value);
    }

    /**
     * Returns a new `Bytes` instance that contains a copy of `len` bytes of
     * `this` instance, starting at index `pos`.
     * @param pos 
     * @param len 
     */
    public sub(pos: number, len: number): Bytes {
        return new Bytes(len, this.b.slice(pos, pos + len));
    }

    /**
     * Returns `0` if the bytes of `this` instance and the bytes of `other` are
		identical.
		Returns a negative value if the `length` of `this` instance is less than
		the `length` of `other`, or a positive value if the `length` of `this`
		instance is greater than the `length` of `other`.
		In case of equal `length`s, returns a negative value if the first different
		value in `other` is greater than the corresponding value in `this`
		instance; otherwise returns a positive value.
     * @param other 
     */
    public compare(other: Bytes): number {
        var b1 = this.b;
		var b2 = other.b;
		var len = (length < other.length) ? length : other.length;
		for (let i = 0; i < len; i++)
            if (b1[i] != b2[i])
                return b1[i] - b2[i];
        return length - other.length;
    }

    /**
     * Returns the IEEE double-precision value at the given position `pos` (in
     * little-endian encoding). Result is unspecified if `pos` is outside the
     * bounds.
     */
    public getDouble(pos:number):number{
        return FPHelper.i64ToDouble(this.getInt32(pos), this.getInt32(pos + 4));
    }

    public setDouble(pos:number, v:number){
        return FPHelper.doubleToI64(v);
    }

    /**
     * Returns the IEEE single-precision value at the given position `pos` (in
     * little-endian encoding). Result is unspecified if `pos` is outside the
     * bounds.
     * @param pos 
     */
    public getFloat(pos:number){
        return FPHelper.i32ToFloat(this.getInt32(pos));
    }

    public setFloat(pos:number, v:number){
        this.setInt32(pos, FPHelper.floatToI32(v));
    }

    /**
     * Returns the 32-bit integer at the given position `pos` (in little-endian
     * encoding).
     * @param pos 
     */
    public getInt32(pos:number){
        return this.get(pos) | (this.get(pos + 1) << 8) | (this.get(pos + 2) << 16) | (this.get(pos + 3) << 24);
    }

    /**
     * Returns the 64-bit integer at the given position `pos` (in little-endian
     * encoding).
     * @param pos 
     */
    public getInt64(pos:number){
        return BigInt(new Int64LE(this.get(pos + 4), this.get(pos)).toNumber());
    }

    /**
     * Returns the 16-bit unsigned integer at the given position `pos` (in
     * @param pos 
     */
    public getUInt16(pos:number):number{
        return this.get(pos) | (this.get(pos + 1) << 8);
    }

    public setUInt16(pos:number, v:number){
        this.set(pos, v);
		this.set(pos + 1, v >> 8);
    }



    /**
     * Stores the given 32-bit integer `v` at the given position `pos` (in
     * little-endian encoding).
     * @param pos 
     * @param v 
     */
    public setInt32(pos:number, v:number){
        this.set(pos, v);
		this.set(pos + 1, v >> 8);
		this.set(pos + 2, v >> 16);
		this.set(pos + 3, v >>> 24);
    }

    public setInt64(pos:number, v:number){
        var buf = new BigInt64Array()
        buf.fill(BigInt(v));

        for(let i = 0; i < buf.buffer.byteLength; i++){
            this.b[i] = buf.buffer[i];
        }   
    }

    /**
     * Returns the `len`-bytes long string stored at the given position `pos`,
     * interpreted with UTF-8.
     * @param pos 
     * @param len 
     */
    public getString(pos:number, len:number){
        var s = "";
		var b = b;
		var fcc = String.fromCharCode;
		var i = pos;
		var max = pos + len;
        // utf8-decode and utf16-encode
        while (i < max) {
			var c = b[i++];
			if (c < 0x80) {
				if (c == 0)
					break;
				s += fcc(c);
			} else if (c < 0xE0)
				s += fcc(((c & 0x3F) << 6) | (b[i++] & 0x7F));
			else if (c < 0xF0) {
				var c2 = b[i++];
				s += fcc(((c & 0x1F) << 12) | ((c2 & 0x7F) << 6) | (b[i++] & 0x7F));
			} else {
				var c2 = b[i++];
				var c3 = b[i++];
				var u = ((c & 0x0F) << 18) | ((c2 & 0x7F) << 12) | ((c3 & 0x7F) << 6) | (b[i++] & 0x7F);
				// surrogate pair
				s += fcc((u >> 10) + 0xD7C0);
				s += fcc((u & 0x3FF) | 0xDC00);
			}
        }
        
        return s;
    }

    public toString():string {
        return this.getString(0, this.length);
    }

    static ofData(b:ArrayBuffer){
        return new Bytes(b.byteLength, b);
    }
}

