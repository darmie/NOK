export class StencilValue {
    static readonly Dynamic = new StencilValue(0);
    static Static(value: number):StencilValue {
        return new StencilValue(value);
    }

    constructor(public value:number){} 
}