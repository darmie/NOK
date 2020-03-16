import { Vector3 } from "./Vector3"
import { Matrix4 } from "./Matrix4"

export class Quaternion {
    private values: Array<number>;

    constructor(x: number = 0, y: number = 0, z: number = 0, w: number = 1) {
        this.values = new Array<number>();
        this.values.push(x);
        this.values.push(y);
        this.values.push(z);
        this.values.push(w);
    }
    /**
     * Axis has to be normalized
     * @param axis 
     * @param radians 
     */
    static fromAxisAngle(axis: Vector3, radians: number): Quaternion {
        var q: Quaternion = new Quaternion();
        q.w = Math.cos(radians / 2.0);
        q.x = q.y = q.z = Math.sin(radians / 2.0);
        q.x *= axis.x;
        q.y *= axis.y;
        q.z *= axis.z;
        return q;
    }


    slerp(t: number, q: Quaternion) {
        var epsilon: number = 0.0005;

        var dot = dot(q);

        if (dot > 1 - epsilon) {
            var result: Quaternion = q.add((this.sub(q)).scaled(t));
            result.normalize();
            return result;
        }
        if (dot < 0) dot = 0;
        if (dot > 1) dot = 1;

        var theta0: number = Math.acos(dot);
        var theta: number = theta0 * t;

        var q2: Quaternion = q.sub(this.scaled(dot));
        q2.normalize();

        var result: Quaternion = this.scaled(Math.cos(theta)).add(q2.scaled(Math.sin(theta)));

        result.normalize();

        return result;
    }

    rotated(b: Quaternion): Quaternion {
        var q: Quaternion = new Quaternion();
        q.w = this.w * b.w - this.x * b.x - this.y * b.y - this.z * b.z;
        q.x = this.w * b.x + this.x * b.w + this.y * b.z - this.z * b.y;
        q.y = this.w * b.y + this.y * b.w + this.z * b.x - this.x * b.z;
        q.z = this.w * b.z + this.z * b.w + this.x * b.y - this.y * b.x;
        q.normalize();
        return q;
    }

    scaled(scale: number): Quaternion {
        return new Quaternion(this.x * scale, this.y * scale, this.z * scale, this.w * scale);
    }

    scale(scale: number) {
        this.x = this.x * scale;
        this.y = this.y * scale;
        this.z = this.z * scale;
        this.w = this.w * scale;
    }

    matrix(): Matrix4 {
        var s: number = 2.0;

        var xs: number = this.x * s;
        var ys: number = this.y * s;
        var zs: number = this.z * s;
        var wx: number = this.w * xs;
        var wy: number = this.w * ys;
        var wz: number = this.w * zs;
        var xx: number = this.x * xs;
        var xy: number = this.x * ys;
        var xz: number = this.x * zs;
        var yy: number = this.y * ys;
        var yz: number = this.y * zs;
        var zz: number = this.z * zs;

        return new Matrix4(
            1 - (yy + zz), xy - wz, xz + wy, 0,
            xy + wz, 1 - (xx + zz), yz - wx, 0,
            xz - wy, yz + wx, 1 - (xx + yy), 0,
            0, 0, 0, 1
        );
    }

    get(index: number): number {
        return this.values[index];
    }

    set(index: number, value: number): void {
        this.values[index] = value;
    }

    public get x(): number {
        return this.values[0];
    }

    public set x(value: number) {
        this.values[0] = value;
    }

    public get y(): number {
        return this.values[1];
    }

    public set y(value: number) {
        this.values[1] = value;
    }

    public get z(): number {
        return this.values[2];
    }

    public set z(value: number) {
        this.values[2] = value;
    }

    public get w(): number {
        return this.values[3];
    }

    public set w(value: number) {
        this.values[3] = value;
    }

    get length(): number {
        return Math.sqrt(this.x * this.x + this.y * this.y + this.z * this.z + this.w * this.w);
    }

    set length(length: number) {
        if (this.length == 0) return;
        var mul = length / this.length;
        this.x *= mul;
        this.y *= mul;
        this.z *= mul;
    }
    /**
     * For adding a (scaled) axis-angle representation of a quaternion
     * @param vec 
     */
    addVector(vec: Vector3): Quaternion {
        var result: Quaternion = new Quaternion(this.x, this.y, this.z, this.w);
        var q1: Quaternion = new Quaternion(0, vec.x, vec.y, vec.z);

        q1 = q1.mult(result);

        result.x += q1.x * 0.5;
        result.y += q1.y * 0.5;
        result.z += q1.z * 0.5;
        result.w += q1.w * 0.5;
        return result;
    }

    add(q: Quaternion): Quaternion {
        return new Quaternion(this.x + q.x, this.y + q.y, this.z + q.z, this.w + q.w);
    }

    sub(q: Quaternion): Quaternion {
        return new Quaternion(this.x - q.x, this.y - q.y, this.z - q.z, this.w - q.w);
    }

    mult(r: Quaternion): Quaternion {
        var q: Quaternion = new Quaternion();
        q.x = this.w * r.x + this.x * r.w + this.y * r.z - this.z * r.y;
        q.y = this.w * r.y - this.x * r.z + this.y * r.w + this.z * r.x;
        q.z = this.w * r.z + this.x * r.y - this.y * r.x + this.z * r.w;
        q.w = this.w * r.w - this.x * r.x - this.y * r.y - this.z * r.z;
        return q;
    }

    normalize() {
        this.scale(1.0 / length);
    }

    dot(q: Quaternion) {
        return this.x * q.x + this.y * q.y + this.z * q.z + this.w * q.w;
    }


    // GetEulerAngles extracts Euler angles from the quaternion, in the specified order of
    // axis rotations and the specified coordinate system. Right-handed coordinate system
    // is the default, with CCW rotations while looking in the negative axis direction.
    // Here a,b,c, are the Yaw/Pitch/Roll angles to be returned.
    // rotation a around axis A1
    // is followed by rotation b around axis A2
    // is followed by rotation c around axis A3
    // rotations are CCW or CW (D) in LH or RH coordinate system (S)

    public static AXIS_X: number = 0;
    public static AXIS_Y: number = 1;
    public static AXIS_Z: number = 2;

    getEulerAngles(A1: number, A2: number, A3: number, S: number = 1, D: number = 1): Vector3 {
        var result: Vector3 = new Vector3();

        var Q: Array<number> = new Array<number>();
        Q[0] = this.x;
        Q[1] = this.y;
        Q[2] = this.z;

        var ww: number = this.w * this.w;

        var Q11: number = Q[A1] * Q[A1];
        var Q22: number = Q[A2] * Q[A2];
        var Q33: number = Q[A3] * Q[A3];

        var psign: number = -1;

        var SingularityRadius: number = 0.0000001;
        var PiOver2: number = Math.PI / 2.0;

        // Determine whether even permutation
        if (((A1 + 1) % 3 == A2) && ((A2 + 1) % 3 == A3)) {
            psign = 1;
        }

        var s2: number = psign * 2.0 * (psign * this.w * Q[A2] + Q[A1] * Q[A3]);

        if (s2 < -1 + SingularityRadius) { // South pole singularity
            result.x = 0;
            result.y = -S * D * PiOver2;
            result.z = S * D * Math.atan2(2 * (psign * Q[A1] * Q[A2] + this.w * Q[A3]), ww + Q22 - Q11 - Q33);
        }
        else if (s2 > 1 - SingularityRadius) { // North pole singularity
            result.x = 0;
            result.y = S * D * PiOver2;
            result.z = S * D * Math.atan2(2 * (psign * Q[A1] * Q[A2] + this.w * Q[A3]), ww + Q22 - Q11 - Q33);
        }
        else {
            result.x = -S * D * Math.atan2(-2 * (this.w * Q[A1] - psign * Q[A2] * Q[A3]), ww + Q33 - Q11 - Q22);
            result.y = S * D * Math.asin(s2);
            result.z = S * D * Math.atan2(2 * (this.w * Q[A3] - psign * Q[A1] * Q[A2]), ww + Q11 - Q22 - Q33);
        }

        return result;
    }

}