export class Screen {

    constructor(private innerWidth?: number, private innerHeight?: number) {
        this.init()
    }

    async init() {
        const native = await (import("react-native"))
        if (native) {
            const dim = native.Dimensions.get("screen")

            this.innerWidth ? this.innerWidth : dim.width
            this.innerHeight ? this.innerHeight : dim.height
            return
        }

        this.innerWidth ? this.innerWidth : 800
        this.innerHeight ? this.innerHeight : 600

        Screen.Width = this.innerWidth
        Screen.Height = this.innerWidth
    }

    get width() {
        return this.innerWidth
    }

    get height() {
        return this.innerHeight
    }

    static Width:number 
    static Height: number
}