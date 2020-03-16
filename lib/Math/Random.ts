//
// Random number generator
//


// Mersenne twister
export class Random {
    constructor(seed: number) {
        this.MT = new Array<number>();
        this.MT[624 - 1] = 0;
        this.MT[0] = seed;
        for (let i = 1; i < 624; i++) this.MT[i] = 0x6c078965 * (this.MT[i - 1] ^ (this.MT[i - 1] >> 30)) + i;
    }

    public Get(): number {
        if (this.index == 0) this.GenerateNumbers();

        var y: number = this.MT[this.index];
        y = y ^ (y >> 11);
        y = y ^ ((y << 7) & (0x9d2c5680));
        y = y ^ ((y << 15) & (0xefc60000));
        y = y ^ (y >> 18);

        this.index = (this.index + 1) % 624;
        return y;
    }

    public GetFloat(): number {
        return this.Get() / 0x7ffffffe;
    }

    public GetUpTo(max: number): number {
        return this.Get() % (max + 1);
    }

    public GetIn(min: number, max: number): number {
        return this.Get() % (max + 1 - min) + min;
    }

    public GetFloatIn(min: number, max: number): number {
        return min + this.GetFloat() * (max - min);
    }

    private MT: Array<number>;
    private index: number = 0;

    private GenerateNumbers(): void {
        for (let i = 0; i < 624; i++) {
            var y: number = (this.MT[i] & 1) + (this.MT[(i + 1) % 624]) & 0x7fffffff;
            this.MT[i] = this.MT[(i + 397) % 624] ^ (y >> 1);
            if ((y % 2) != 0) this.MT[i] = this.MT[i] ^ 0x9908b0df;
        }
    }

    public static Default: Random;

    public static init(seed: number): void {
        Random.Default = new Random(seed);
    }

    public static get(): number {
        return Random.Default.Get();
    }

    public static getFloat(): number {
        return Random.Default.GetFloat();
    }

    public static getUpTo(max: number): number {
        return Random.Default.GetUpTo(max);
    }

    public static getIn(min: number, max: number): number {
        return Random.Default.GetIn(min, max);
    }

    public static getFloatIn(min: number, max: number): number {
        return min + Random.Default.GetFloat() * (max - min);
    }
}