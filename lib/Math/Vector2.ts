export class Vector2 {
  constructor(public x: number = 0, public y: number = 0) {

  }

  setFrom(v: Vector2) {
    this.x = v.x;
    this.y = v.y;
  }

  get length(): number {
    return Math.sqrt(this.x * this.x + this.y * this.y);
  }

  set length(length: number) {
    var currentLength = this.length;
    if (currentLength == 0) return;
    var mul = length / currentLength;
    this.x *= mul;
    this.y *= mul;
  }

  add(vec: Vector2): Vector2 {
    return new Vector2(this.x + vec.x, this.y + vec.y);
  }

  sub(vec: Vector2): Vector2 {
    return new Vector2(this.x - vec.x, this.y - vec.y);
  }

  mult(value: number): Vector2 {
    return new Vector2(this.x * value, this.y * value);
  }

  div(value: number): Vector2 {
    return this.mult(1 / value);
  }

  dot(v: Vector2): number {
    return this.x * v.x + this.y * v.y;
  }

  normalized(): Vector2 {
    var v = new Vector2(this.x, this.y);
    v.length = 1;
    return v;
  }

  angle(v: Vector2): number {
    return Math.atan2(this.y, this.x) - Math.atan2(v.y, v.x);
  }

  toString() {
    return `Vector2(${this.x}, ${this.y})`;
  }
}