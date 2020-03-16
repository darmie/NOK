import { Vector2 } from "./Vector2";

export class Matrix3 {
    static width: number = 3;
    static height: number = 3;

    constructor(public _00: number, public _10: number, public _20: number,
        public _01: number, public _11: number, public _21: number,
        public _02: number, public _12: number, public _22: number) {

    }

    public setFrom(m: Matrix3): void {
        this._00 = m._00; this._10 = m._10; this._20 = m._20;
        this._01 = m._01; this._11 = m._11; this._21 = m._21;
        this._02 = m._02; this._12 = m._12; this._22 = m._22;
    }

    public static translation(x: number, y: number): Matrix3 {
        return new Matrix3(
            1, 0, x,
            0, 1, y,
            0, 0, 1
        );
    }

    public static empty(): Matrix3 {
        return new Matrix3(
            0, 0, 0,
            0, 0, 0,
            0, 0, 0
        );
    }

    public static identity(): Matrix3 {
        return new Matrix3(
            1, 0, 0,
            0, 1, 0,
            0, 0, 1
        );
    }

    public static scale(x: number, y: number): Matrix3 {
        return new Matrix3(
            x, 0, 0,
            0, y, 0,
            0, 0, 1
        );
    }

    public static rotation(alpha: number): Matrix3 {
        return new Matrix3(
            Math.cos(alpha), -Math.sin(alpha), 0,
            Math.sin(alpha), Math.cos(alpha), 0,
            0, 0, 1
        );
    }

    public add(m: Matrix3): Matrix3 {
        return new Matrix3(
            this._00 + m._00, this._10 + m._10, this._20 + m._20,
            this._01 + m._01, this._11 + m._11, this._21 + m._21,
            this._02 + m._02, this._12 + m._12, this._22 + m._22
        );
    }

    public sub(m: Matrix3): Matrix3 {
        return new Matrix3(
            this._00 - m._00, this._10 - m._10, this._20 - m._20,
            this._01 - m._01, this._11 - m._11, this._21 - m._21,
            this._02 - m._02, this._12 - m._12, this._22 - m._22
        );
    }

    public mult(value: number): Matrix3 {
        return new Matrix3(
            this._00 * value, this._10 * value, this._20 * value,
            this._01 * value, this._11 * value, this._21 * value,
            this._02 * value, this._12 * value, this._22 * value
        );
    }

    public transpose(): Matrix3 {
        return new Matrix3(
            this._00, this._01, this._02,
            this._10, this._11, this._12,
            this._20, this._21, this._22
        );
    }

    public trace(): number {
        return this._00 + this._11 + this._22;
    }

    public multmat(m: Matrix3): Matrix3 {
        return new Matrix3(
            this._00 * m._00 + this._10 * m._01 + this._20 * m._02, this._00 * m._10 + this._10 * m._11 + this._20 * m._12, this._00 * m._20 + this._10 * m._21 + this._20 * m._22,
            this._01 * m._00 + this._11 * m._01 + this._21 * m._02, this._01 * m._10 + this._11 * m._11 + this._21 * m._12, this._01 * m._20 + this._11 * m._21 + this._21 * m._22,
            this._02 * m._00 + this._12 * m._01 + this._22 * m._02, this._02 * m._10 + this._12 * m._11 + this._22 * m._12, this._02 * m._20 + this._12 * m._21 + this._22 * m._22
        );
    }

    public multvec(value: Vector2): Vector2 {
        var w = this._02 * value.x + this._12 * value.y + this._22 * 1;
        var x = (this._00 * value.x + this._10 * value.y + this._20 * 1) / w;
        var y: number = (this._01 * value.x + this._11 * value.y + this._21 * 1) / w;
        return new Vector2(x, y);
    }

    public cofactor(m0: number, m1: number, m2: number, m3: number): number {
        return m0 * m3 - m1 * m2;
    }

    public determinant(): number {
        var c00 = this.cofactor(this._11, this._21, this._12, this._22);
        var c01 = this.cofactor(this._10, this._20, this._12, this._22);
        var c02 = this.cofactor(this._10, this._20, this._11, this._21);
        return this._00 * c00 - this._01 * c01 + this._02 * c02;
    }

    public inverse(): Matrix3 {
        var c00 = this.cofactor(this._11, this._21, this._12, this._22);
        var c01 = this.cofactor(this._10, this._20, this._12, this._22);
        var c02 = this.cofactor(this._10, this._20, this._11, this._21);

        var det: number = this._00 * c00 - this._01 * c01 + this._02 * c02;
        if (Math.abs(det) < 0.000001) {
            throw "determinant is too small";
        }

        var c10 = this.cofactor(this._01, this._21, this._02, this._22);
        var c11 = this.cofactor(this._00, this._20, this._02, this._22);
        var c12 = this.cofactor(this._00, this._20, this._01, this._21);

        var c20 = this.cofactor(this._01, this._11, this._02, this._12);
        var c21 = this.cofactor(this._00, this._10, this._02, this._12);
        var c22 = this.cofactor(this._00, this._10, this._01, this._11);

        var invdet: number = 1.0 / det;
        return new Matrix3(
            c00 * invdet, -c01 * invdet, c02 * invdet,
            -c10 * invdet, c11 * invdet, -c12 * invdet,
            c20 * invdet, -c21 * invdet, c22 * invdet
        );
    }
}
