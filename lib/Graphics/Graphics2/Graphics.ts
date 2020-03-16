
import { Matrix3 } from "../../Math/Matrix3";
import {PipelineState} from "../PipelineState";
import {Color} from "../Color"
import {Image} from "../Image"

export class Graphics {
    public begin(clear: boolean = true, clearColor: Color = null): void {

    }

    public end(): void {

    }

    public flush(): void {

    }

    //scale-filtering
    //draw/fillPolygon

    public clear(color: Color = null): void {

    }

    public drawImage(img: Image, x: number, y: number): void {
        this.drawSubImage(img, x, y, 0, 0, img.width, img.height);
    }

    public drawSubImage(img: Image, x: number, y: number, sx: number, sy: number, sw: number, sh: number): void {
        this.drawScaledSubImage(img, sx, sy, sw, sh, x, y, sw, sh);
    }

    public drawScaledImage(img: Image, dx: number, dy: number, dw: number, dh: number): void {
        this.drawScaledSubImage(img, 0, 0, img.width, img.height, dx, dy, dw, dh);
    }

    public drawScaledSubImage(image: Image, sx: number, sy: number, sw: number, sh: number, dx: number, dy: number, dw: number, dh: number): void {

    }

    public drawRect(x: number, y: number, width: number, height: number, strength: number = 1.0): void {

    }

    public fillRect(x: number, y: number, width: number, height: number): void {

    }

    /**
     * Draw a single line of text with the current `color`, `font` and `fontSize` properties.
     *
     * When drawing into rendertargets, you might have to use a different shader than the default one
     *  - use the default shader when drawing into a transparent section of your rendertarget
     *  - use a shader with `alphaBlendSource = BlendOne` when drawing into a non-transparent section of your rendertarget
     */
    public drawString(text: String, x: number, y: number): void {

    }

    /**
     * Draw a single line of characters with the current `color`, `font` and `fontSize` properties.
     *
     * When drawing into rendertargets, you might have to use a different shader than the default one
     *  - use the default shader when drawing into a transparent section of your rendertarget
     *  - use a shader with `alphaBlendSource = BlendOne` when drawing into a non-transparent section of your rendertarget
     */
    public drawCharacters(text: Array<number>, start: number, length: number, x: number, y: number): void {

    }

    public drawLine(x1: number, y1: number, x2: number, y2: number, strength: number = 1.0): void {

    }

    public drawVideo(video: Video, x: number, y: number, width: number, height: number): void {

    }

    public fillTriangle(x1: number, y1: number, x2: number, y2: number, x3: number, y3: number): void {

    }



    private get imageScaleQuality(): ImageScaleQuality {
        return ImageScaleQuality.Low;
    }

    private set imageScaleQuality(value: ImageScaleQuality): ImageScaleQuality {
        return ImageScaleQuality.High;
    }

    private get mipmapScaleQuality(): ImageScaleQuality {
        return ImageScaleQuality.Low;
    }

    private set mipmapScaleQuality(value: ImageScaleQuality): ImageScaleQuality {
        return ImageScaleQuality.High;
    }

    /**
    The color value is used for geometric primitives, images, and text. Remember to set it back to white to draw images unaltered.
    */


    private get color(): Color {
        return Color.Black;
    }

    private set color(color: Color): Color {
        return Color.Black;
    }



    private get font(): Font {
        return null;
    }

    private set font(font: Font): Font {
        return null;
    }



    private get fontSize(): number {
        return myFontSize;
    }

    private set fontSize(value: number): number {
        return myFontSize = value;
    }

    public static fontGlyphs: Array<number> = [
        32,
        33,
        34,
        35,
        36,
        37,
        38,
        39,
        40,
        41,
        42,
        43,
        44,
        45,
        46,
        47,
        48,
        49,
        50,
        51,
        52,
        53,
        54,
        55,
        56,
        57,
        58,
        59,
        60,
        61,
        62,
        63,
        64,
        65,
        66,
        67,
        68,
        69,
        70,
        71,
        72,
        73,
        74,
        75,
        76,
        77,
        78,
        79,
        80,
        81,
        82,
        83,
        84,
        85,
        86,
        87,
        88,
        89,
        90,
        91,
        92,
        93,
        94,
        95,
        96,
        97,
        98,
        99,
        100,
        101,
        102,
        103,
        104,
        105,
        106,
        107,
        108,
        109,
        110,
        111,
        112,
        113,
        114,
        115,
        116,
        117,
        118,
        119,
        120,
        121,
        122,
        123,
        124,
        125,
        126,
        127,
        128,
        129,
        130,
        131,
        132,
        133,
        134,
        135,
        136,
        137,
        138,
        139,
        140,
        141,
        142,
        143,
        144,
        145,
        146,
        147,
        148,
        149,
        150,
        151,
        152,
        153,
        154,
        155,
        156,
        157,
        158,
        159,
        160,
        161,
        162,
        163,
        164,
        165,
        166,
        167,
        168,
        169,
        170,
        171,
        172,
        173,
        174,
        175,
        176,
        177,
        178,
        179,
        180,
        181,
        182,
        183,
        184,
        185,
        186,
        187,
        188,
        189,
        190,
        191,
        192,
        193,
        194,
        195,
        196,
        197,
        198,
        199,
        200,
        201,
        202,
        203,
        204,
        205,
        206,
        207,
        208,
        209,
        210,
        211,
        212,
        213,
        214,
        215,
        216,
        217,
        218,
        219,
        220,
        221,
        222,
        223,
        224,
        225,
        226,
        227,
        228,
        229,
        230,
        231,
        232,
        233,
        234,
        235,
        236,
        237,
        238,
        239,
        240,
        241,
        242,
        243,
        244,
        245,
        246,
        247,
        248,
        249,
        250,
        251,
        252,
        253,
        254,
        255];

    // works on the top of the transformation stack
    private get transformation(): Matrix3 {
        return this.transformations[this.transformationIndex];
    }

    private set transformation(transformation: Matrix3) {
        this.setTransformation(transformation);
        this.transformations[this.transformationIndex].setFrom(transformation);
    }

    public pushTransformation(trans: Matrix3): void {
        this.transformationIndex++;
        if (this.transformationIndex == this.transformations.length) {
            this.transformations.push(Matrix3.identity());
        }
        this.transformations[this.transformationIndex].setFrom(trans);
        this.setTransformation(this.transformation);
    }

    public popTransformation(): Matrix3 {
        this.transformationIndex--;
        this.setTransformation(this.transformation);
        return this.transformations[this.transformationIndex + 1];
    }

    public scale(x: number, y: number): void {
        this.transformation.setFrom(Matrix3.scale(x, y).multmat(this.transformation));
    }

    private translation(tx: number, ty: number): Matrix3 {
        return Matrix3.translation(tx, ty).multmat(this.transformation);
    }

    public translate(tx: number, ty: number): void {
        this.transformation.setFrom(this.translation(tx, ty));
    }

    public pushTranslation(tx: number, ty: number): void {
        this.pushTransformation(this.translation(tx, ty));
    }

    private rotation(angle: number, centerx: number, centery: number): Matrix3 {
        return Matrix3.translation(centerx, centery).multmat(Matrix3.rotation(angle)).multmat(Matrix3.translation(-centerx, -centery)).multmat(this.transformation);
    }

    public rotate(angle: number, centerx: number, centery: number): void {
        this.transformation.setFrom(this.rotation(angle, centerx, centery));
    }

    public pushRotation(angle: number, centerx: number, centery: number): void {
        this.pushTransformation(this.rotation(angle, centerx, centery));
    }

   

    public pushOpacity(opacity: number): void {
        this.setOpacity(opacity);
        this.opacities.push(opacity);
    }

    public popOpacity(): number {
        var ret = this.opacities.pop();
        this.setOpacity(this.opacity);
        return ret;
    }

    public get opacity(): number {
        return this.opacities[this.opacities.length - 1];
    }

    public set opacity(opacity: number){
        this.setOpacity(this.opacity);
        this.opacities[this.opacities.length - 1] = this.opacity;
    }

    public scissor(x: number, y: number, width: number, height: number): void {

    }

    public disableScissor(): void {

    }



    private transformations: Array<Matrix3>;
    private transformationIndex: number;
    private opacities: Array<number>;
    private myFontSize: number;

    public new() {
        this.transformations = [Matrix3.identity()];
        this.transformationIndex = 0;
        this.opacities = [1];
        this.myFontSize = 12;
    }

    private setTransformation(transformation: Matrix3): void {

    }

    private setOpacity(opacity: number): void {

    }

    private setPipeline(pipeline: PipelineState): void {

    }
}