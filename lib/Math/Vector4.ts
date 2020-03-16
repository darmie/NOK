export class Vector4 {
    constructor(public x: number = 0, public y: number = 0, public z: number = 0, public w: number = 1) { }

    setFrom(v: Vector4) {
        this.x = v.x;
        this.y = v.y;
        this.z = v.z;
        this.w = v.w;
    }

    get length() {
        return Math.sqrt(this.x * this.x + this.y * this.y + this.z * this.z + this.w * this.w);
    }

    set length(length: number) {
        var currentLength = this.length;
        if (currentLength == 0) return;
        var mul = length / currentLength;
        this.x *= mul;
        this.y *= mul;
        this.z *= mul;
        this.w *= mul;
    }

    add(vec: Vector4): Vector4 {
        return new Vector4(this.x + vec.x, this.y + vec.y, this.z + vec.z, this.w + vec.w);
    }

    sub(vec: Vector4): Vector4 {
        return new Vector4(this.x - vec.x, this.y - vec.y, this.z - vec.z, this.w - vec.w);
    }

    mult(value: number): Vector4 {
        return new Vector4(this.x * value, this.y * value, this.z * value, this.w * value);
    }

    normalized(): Vector4 {
        var v = new Vector4(this.x, this.y, this.z, this.w);
        v.length = 1;
        return v;
    }

    toString() {
		return `Vector4(${this.x}, ${this.y}, ${this.z}, ${this.w})`;
	}
}