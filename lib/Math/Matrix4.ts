import { Vector3 } from "./Vector3"
import { Vector4 } from "./Vector4"


export class Matrix4 {
    static width: number = 4;
    static height: number = 4;

    constructor(
        public _00: number, public _10: number, public _20: number, public _30: number,
        public _01: number, public _11: number, public _21: number, public _31: number,
        public _02: number, public _12: number, public _22: number, public _32: number,
        public _03: number, public _13: number, public _23: number, public _33: number) {

    }

    setFrom(m: Matrix4): void {
        this._00 = m._00; this._10 = m._10; this._20 = m._20; this._30 = m._30;
        this._01 = m._01; this._11 = m._11; this._21 = m._21; this._31 = m._31;
        this._02 = m._02; this._12 = m._12; this._22 = m._22; this._32 = m._32;
        this._03 = m._03; this._13 = m._13; this._23 = m._23; this._33 = m._33;
    }

    static translation(x: number, y: number, z: number): Matrix4 {
        return new Matrix4(
            1, 0, 0, x,
            0, 1, 0, y,
            0, 0, 1, z,
            0, 0, 0, 1
        );
    }

    static empty(): Matrix4 {
        return new Matrix4(
            0, 0, 0, 0,
            0, 0, 0, 0,
            0, 0, 0, 0,
            0, 0, 0, 0
        );
    }

    static identity(): Matrix4 {
        return new Matrix4(
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1
        );
    }


    static scale(x: number, y: number, z: number): Matrix4 {
        return new Matrix4(
            x, 0, 0, 0,
            0, y, 0, 0,
            0, 0, z, 0,
            0, 0, 0, 1
        );
    }

    static rotationX(alpha: number): Matrix4 {
        var ca = Math.cos(alpha);
        var sa = Math.sin(alpha);
        return new Matrix4(
            1, 0, 0, 0,
            0, ca, -sa, 0,
            0, sa, ca, 0,
            0, 0, 0, 1
        );
    }

    static rotationY(alpha: number): Matrix4 {
        var ca = Math.cos(alpha);
        var sa = Math.sin(alpha);
        return new Matrix4(
            ca, 0, sa, 0,
            0, 1, 0, 0,
            -sa, 0, ca, 0,
            0, 0, 0, 1
        );
    }

    static rotationZ(alpha: number): Matrix4 {
        var ca = Math.cos(alpha);
        var sa = Math.sin(alpha);
        return new Matrix4(
            ca, -sa, 0, 0,
            sa, ca, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1
        );
    }

    static rotation(yaw: number, pitch: number, roll: number): Matrix4 {
        var sy = Math.sin(yaw);
        var cy = Math.cos(yaw);
        var sx = Math.sin(pitch);
        var cx = Math.cos(pitch);
        var sz = Math.sin(roll);
        var cz = Math.cos(roll);
        return new Matrix4(
            cx * cy, cx * sy * sz - sx * cz, cx * sy * cz + sx * sz, 0,
            sx * cy, sx * sy * sz + cx * cz, sx * sy * cz - cx * sz, 0,
            -sy, cy * sz, cy * cz, 0,
            0, 0, 0, 1
        );
    }


    static orthogonalProjection(left: number, right: number, bottom: number, top: number, zn: number, zf: number): Matrix4 {
        var tx: number = -(right + left) / (right - left);
        var ty: number = -(top + bottom) / (top - bottom);
        var tz: number = -(zf + zn) / (zf - zn);
        return new Matrix4(
            2 / (right - left), 0, 0, tx,
            0, 2 / (top - bottom), 0, ty,
            0, 0, -2 / (zf - zn), tz,
            0, 0, 0, 1
        );
    }


    static perspectiveProjection(fovY: number, aspect: number, zn: number, zf: number): Matrix4 {
        var uh = 1.0 / Math.tan(fovY / 2);
        var uw = uh / aspect;
        return new Matrix4(
            uw, 0, 0, 0,
            0, uh, 0, 0,
            0, 0, (zf + zn) / (zn - zf), 2 * zf * zn / (zn - zf),
            0, 0, -1, 0
        );
    }

    static lookAt(eye: Vector3, at: Vector3, up: Vector3): Matrix4 {
        var zaxis = at.sub(eye).normalized();
        var xaxis = zaxis.cross(up).normalized();
        var yaxis = xaxis.cross(zaxis);

        return new Matrix4(
            xaxis.x, xaxis.y, xaxis.z, -xaxis.dot(eye),
            yaxis.x, yaxis.y, yaxis.z, -yaxis.dot(eye),
            -zaxis.x, -zaxis.y, -zaxis.z, zaxis.dot(eye),
            0, 0, 0, 1
        );
    }

    add(m: Matrix4): Matrix4 {
        return new Matrix4(
            this._00 + m._00, this._10 + m._10, this._20 + m._20, this._30 + m._30,
            this._01 + m._01, this._11 + m._11, this._21 + m._21, this._31 + m._31,
            this._02 + m._02, this._12 + m._12, this._22 + m._22, this._32 + m._32,
            this._03 + m._03, this._13 + m._13, this._23 + m._23, this._33 + m._33
        );
    }


    sub(m: Matrix4): Matrix4 {
        return new Matrix4(
            this._00 - m._00, this._10 - m._10, this._20 - m._20, this._30 - m._30,
            this._01 - m._01, this._11 - m._11, this._21 - m._21, this._31 - m._31,
            this._02 - m._02, this._12 - m._12, this._22 - m._22, this._32 - m._32,
            this._03 - m._03, this._13 - m._13, this._23 - m._23, this._33 - m._33
        );
    }

    mult(value: number): Matrix4 {
        return new Matrix4(
            this._00 * value, this._10 * value, this._20 * value, this._30 * value,
            this._01 * value, this._11 * value, this._21 * value, this._31 * value,
            this._02 * value, this._12 * value, this._22 * value, this._32 * value,
            this._03 * value, this._13 * value, this._23 * value, this._33 * value
        );
    }

    transpose(): Matrix4 {
        return new Matrix4(
            this._00, this._01, this._02, this._03,
            this._10, this._11, this._12, this._13,
            this._20, this._21, this._22, this._23,
            this._30, this._31, this._32, this._33
        );
    }

    transpose3x3(): Matrix4 {
        return new Matrix4(
            this._00, this._01, this._02, this._30,
            this._10, this._11, this._12, this._31,
            this._20, this._21, this._22, this._32,
            this._03, this._13, this._23, this._33
        );
    }

    trace(): number {
        return this._00 + this._11 + this._22 + this._33;
    }


    multmat(m: Matrix4): Matrix4 {
        return new Matrix4(
            this._00 * m._00 + this._10 * m._01 + this._20 * m._02 + this._30 * m._03, this._00 * m._10 + this._10 * m._11 + this._20 * m._12 + this._30 * m._13, this._00 * m._20 + this._10 * m._21 + this._20 * m._22 + this._30 * m._23, this._00 * m._30 + this._10 * m._31 + this._20 * m._32 + this._30 * m._33,
            this._01 * m._00 + this._11 * m._01 + this._21 * m._02 + this._31 * m._03, this._01 * m._10 + this._11 * m._11 + this._21 * m._12 + this._31 * m._13, this._01 * m._20 + this._11 * m._21 + this._21 * m._22 + this._31 * m._23, this._01 * m._30 + this._11 * m._31 + this._21 * m._32 + this._31 * m._33,
            this._02 * m._00 + this._12 * m._01 + this._22 * m._02 + this._32 * m._03, this._02 * m._10 + this._12 * m._11 + this._22 * m._12 + this._32 * m._13, this._02 * m._20 + this._12 * m._21 + this._22 * m._22 + this._32 * m._23, this._02 * m._30 + this._12 * m._31 + this._22 * m._32 + this._32 * m._33,
            this._03 * m._00 + this._13 * m._01 + this._23 * m._02 + this._33 * m._03, this._03 * m._10 + this._13 * m._11 + this._23 * m._12 + this._33 * m._13, this._03 * m._20 + this._13 * m._21 + this._23 * m._22 + this._33 * m._23, this._03 * m._30 + this._13 * m._31 + this._23 * m._32 + this._33 * m._33
        );
    }

    multvec(value: Vector4): Vector4 {
        var product = new Vector4();
        product.x = this._00 * value.x + this._10 * value.y + this._20 * value.z + this._30 * value.w;
        product.y = this._01 * value.x + this._11 * value.y + this._21 * value.z + this._31 * value.w;
        product.z = this._02 * value.x + this._12 * value.y + this._22 * value.z + this._32 * value.w;
        product.w = this._03 * value.x + this._13 * value.y + this._23 * value.z + this._33 * value.w;
        return product;
    }


    cofactor(m0: number, m1: number, m2: number,
        m3: number, m4: number, m5: number,
        m6: number, m7: number, m8: number): number {
        return m0 * (m4 * m8 - m5 * m7) - m1 * (m3 * m8 - m5 * m6) + m2 * (m3 * m7 - m4 * m6);
    }

    determinant(): number {
		var c00 = this.cofactor(this._11, this._21, this._31, this._12,this. _22, this._32, this._13, this._23, this._33);
		var c01 = this.cofactor(this._10, this._20, this._30, this._12, this._22, this._32, this._13, this._23, this._33);
		var c02 = this.cofactor(this._10, this._20, this._30, this._11, this._21, this._31, this._13, this._23, this._33);
		var c03 = this.cofactor(this._10, this._20, this._30, this._11, this._21, this._31, this._12, this._22, this._32);
		return this._00 * c00 - this._01 * c01 + this._02 * c02 - this._03 * c03;
    }
    
    inverse(): Matrix4 {
		var c00 = this.cofactor(this._11, this._21, this._31, this._12, this._22, this._32, this._13,this. _23, this._33);
		var c01 = this.cofactor(this._10, this._20, this._30, this._12, this._22, this._32, this._13, this._23, this._33);
		var c02 = this.cofactor(this._10, this._20, this._30, this._11, this._21, this._31, this._13, this._23, this._33);
		var c03 = this.cofactor(this._10, this._20, this._30, this._11, this._21, this._31, this._12, this._22, this._32);

		var det: number = this._00 * c00 - this._01 * c01 + this._02 * c02 - this._03 * c03;
		if (Math.abs(det) < 0.000001) {
			throw "determinant is too small";
		}

		var c10 = this.cofactor(this._01, this._21, this._31, this._02, this._22, this._32, this._03, this._23, this._33);
		var c11 = this.cofactor(this._00, this._20, this._30, this._02, this._22, this._32, this._03, this._23, this._33);
		var c12 = this.cofactor(this._00, this._20, this._30, this._01, this._21, this._31, this._03, this._23, this._33);
		var c13 = this.cofactor(this._00, this._20, this._30, this._01, this._21, this._31, this._02, this._22, this._32);

		var c20 = this.cofactor(this._01, this._11, this._31, this._02, this._12, this._32, this._03, this._13, this._33);
		var c21 = this.cofactor(this._00, this._10, this._30, this._02, this._12, this._32, this._03, this._13, this._33);
		var c22 = this.cofactor(this._00, this._10, this._30, this._01, this._11, this._31, this._03, this._13, this._33);
		var c23 = this.cofactor(this._00, this._10, this._30, this._01, this._11, this._31, this._02, this._12, this._32);

		var c30 = this.cofactor(this._01, this._11, this._21, this._02, this._12, this._22, this._03, this._13, this._23);
		var c31 = this.cofactor(this._00, this._10, this._20, this._02, this._12, this._22, this._03, this._13, this._23);
		var c32 = this.cofactor(this._00, this._10, this._20, this._01, this._11, this._21, this._03, this._13, this._23);
		var c33 = this.cofactor(this._00, this._10, this._20, this._01, this._11, this._21, this._02, this._12, this._22);

		var invdet: number = 1.0 / det;
		return new Matrix4(
			c00 * invdet,  -c01 * invdet,  c02 * invdet, -c03 * invdet,
			-c10 * invdet,  c11 * invdet, -c12 * invdet,  c13 * invdet,
			c20 * invdet,  -c21 * invdet,  c22 * invdet, -c23 * invdet,
			-c30 * invdet,  c31 * invdet, -c32 * invdet,  c33 * invdet
		);
	}

}