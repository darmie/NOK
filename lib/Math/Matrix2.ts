import {Vector2} from "./Vector2"

export class Matrix2 {
    private width: number = 2;
    private height: number = 2;

    public _00: number; public _10: number;
    public _01: number; public _11: number;

    constructor(_00: number, _10: number, _01: number, _11: number) {
        this._00 = _00; this._10 = _10;
		this._01 = _01; this._11 = _11;
    }

    setFrom(m: Matrix2) {
		this._00 = m._00; this._10 = m._10;
		this._01 = m._01; this._11 = m._11;
    }

    static empty(): Matrix2 {
		return new Matrix2(
			0, 0,
			0, 0
		);
    }
    

    static identity(): Matrix2 {
		return new Matrix2(
			1, 0,
			0, 1
		);
    }
    
    static scale(x: number, y: number): Matrix2 {
		return new Matrix2(
			x, 0,
			0, y
		);
    }
    
    static rotation(alpha: number): Matrix2 {
		return new Matrix2(
			Math.cos(alpha), -Math.sin(alpha),
			Math.sin(alpha), Math.cos(alpha)
		);
	}


    add(m: Matrix2): Matrix2 {
		return new Matrix2(
			this._00 + m._00, this._10 + m._10,
			this._01 + m._01, this._11 + m._11
		);
    }
    
    sub(m: Matrix2): Matrix2 {
		return new Matrix2(
			this._00 - m._00, this._10 - m._10,
			this._01 - m._01, this._11 - m._11
		);
    }
    
    mult(value: number): Matrix2 {
		return new Matrix2(
			this._00 * value, this._10 * value,
			this._01 * value, this._11 * value
		);
    }
    
    transpose(): Matrix2 {
		return new Matrix2(
			this._00, this._01,
			this._10, this._11
		);
    }
    
    trace(): number {
		return this._00 + this._11;
    }
    
    multmat(m: Matrix2): Matrix2 {
		return new Matrix2(
			this._00 * m._00 + this._10 * m._01, this._00 * m._10 + this._10 * m._11,
			this._01 * m._00 + this._11 * m._01, this._01 * m._10 + this._11 * m._11
		);
    }
    
    multvec(value: Vector2): Vector2 {
		var x = this._00 * value.x + this._10 * value.y;
		var y = this._01 * value.x + this._11 * value.y;
		return new Vector2(x, y);
	}

}