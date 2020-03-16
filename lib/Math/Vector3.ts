export class Vector3 {
    constructor(public x: number = 0, public y: number = 0, public z: number = 0) { }

    public setFrom(v: Vector3) {
        this.x = v.x;
        this.y = v.y;
        this.z = v.z;
    }

    get length(): number {
        return Math.sqrt(this.x * this.x + this.y * this.y + this.z * this.z);
    }

    set length(length: number) {
        var currentLength = this.length;
        if (currentLength == 0) return;
        var mul = length / currentLength;
        this.x *= mul;
        this.y *= mul;
        this.z *= mul;
    }

    add(vec: Vector3): Vector3 {
        return new Vector3(this.x + vec.x, this.y + vec.y, this.z + vec.z);
    }

    sub(vec: Vector3): Vector3 {
        return new Vector3(this.x - vec.x, this.y - vec.y, this.z - vec.z);
    }

    mult(value: number): Vector3 {
        return new Vector3(this.x * value, this.y * value, this.z * value);
    }

    dot(v: Vector3): number {
        return this.x * v.x + this.y * v.y + this.z * v.z;
    }

    cross(v: Vector3): Vector3 {
        var _x = this.y * v.z - this.z * v.y;
        var _y = this.z * v.x - this.x * v.z;
        var _z = this.x * v.y - this.y * v.x;
        return new Vector3(_x, _y, _z);
    }

    normalized(): Vector3 {
        var v = new Vector3(this.x, this.y, this.z);
        v.length = 1;
        return v;
    }

    toString() {
		return `Vector3(${this.x}, ${this.y}, ${this.z})`;
	}

}