export class Color {
    public static Black: Color = new Color(0xff000000);
    public static White: Color = new Color(0xffffffff);
    public static Red: Color = new Color(0xffff0000);
    public static Blue: Color = new Color(0xff0000ff);
    public static Green: Color = new Color(0xff00ff00);
    public static Magenta: Color = new Color(0xffff00ff);
    public static Yellow: Color = new Color(0xffffff00);
    public static Cyan: Color = new Color(0xff00ffff);
    public static Purple: Color = new Color(0xff800080);
    public static Pink: Color = new Color(0xffffc0cb);
    public static Orange: Color = new Color(0xffffa500);

    public static Transparent: Color = new Color(0x00000000);

    private static invMaxChannelValue: number = 1 / 255;

    _value: number;

    constructor(value: number) {
        this.value = value;
    }

    get value() {
        return this._value
    }

    set value(value: number) {
        this._value = value;
    }

    /**
     * Creates a new Color object from a packed 32 bit ARGB value.
     * @param value 
     */
    public static fromValue(value: number): Color {
        return new Color(value);
    }

    /**
     * Creates a new Color object from components in the range 0 - 255.
     * @param r 
     * @param g 
     * @param b 
     * @param a 
     */
    public static fromBytes(r: number, g: number, b: number, a: number = 255): Color {
        return new Color((a << 24) | (r << 16) | (g << 8) | b);
    }

    /**
     * Creates a new Color object from components in the range 0 - 1
     * @param r 
     * @param g 
     * @param b 
     * @param a 
     */
    public static fromFloats(r: number, g: number, b: number, a: number = 1): Color {
        return new Color(((a * 255) << 24) | ((r * 255) << 16) | ((g * 255) << 8) | (b * 255));
    }

    public static fromString(value: string) {
        if ((value.length == 7 || value.length == 9) && value.charCodeAt(0) == "#".charCodeAt(0)) {
            var colorValue = parseInt("0x" + value.substr(1));
            if (value.length == 7) {
                colorValue += 0xFF000000;
            }
            return this.fromValue(colorValue);
        }
        else {
            throw "Invalid Color string: '" + value + "'";
        }
    }


    get Rb() {
        return (this.value & 0x00ff0000) >>> 16;
    }

    get Gb() {
        return (this.value & 0x0000ff00) >>> 16;
    }

    get Bb() {
        return this.value & 0x000000ff;
    }

    get Ab() {
        return this.value >>> 24;
    }

    set Rb(i: number) {
        this.value = (this.Ab << 24) | (i << 16) | (this.Gb << 8) | this.Bb;

    }

    set Gb(i: number) {
        this.value = (this.Ab << 24) | (this.Rb << 16) | (i << 8) | this.Bb;

    }

    set Bb(i: number) {
        this.value = (this.Ab << 24) | (this.Rb << 16) | (this.Gb << 8) | i;

    }

    set Ab(i: number) {
        this.value = (i << 24) | (this.Rb << 16) | (this.Gb << 8) | this.Bb;

    }

    get R(): number {
        return this.Rb * Color.invMaxChannelValue;
    }

    get G(): number {
        return this.Gb * Color.invMaxChannelValue;
    }

    get B(): number {
        return this.Bb * Color.invMaxChannelValue;
    }

    get A(): number {
        return this.Ab * Color.invMaxChannelValue;
    }

    set R(f: number) {
        this.value = ((this.A * 255) << 24) | ((f * 255) << 16) | ((this.G * 255) << 8) | (this.B * 255);

    }

    set G(f: number) {
        this.value = ((this.A * 255) << 24) | ((this.R * 255) << 16) | ((f * 255) << 8) | (this.B * 255);

    }

    set B(f: number) {
        this.value = ((this.A * 255) << 24) | ((this.R * 255) << 16) | ((this.G * 255) << 8) | (f * 255);

    }

    set A(f: number) {
        this.value = ((f * 255) << 24) | ((this.R * 255) << 16) | ((this.G * 255) << 8) | (this.B * 255);

    }

} 