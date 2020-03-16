export class FPHelper {

    static helper = new DataView(new ArrayBuffer(8));


    static i64ToDouble(low:number, high:number){
        FPHelper.helper.setInt32(0, low, true);
		FPHelper.helper.setInt32(4, high, true);
		return FPHelper.helper.getFloat64(0, true);
    }

    static i32ToFloat(i:number){
        FPHelper.helper.setInt32(0, i, true);
		return FPHelper.helper.getFloat32(0, true);
    }

    static floatToI32(f:number){
        FPHelper.helper.setFloat32(0, f, true);
		return FPHelper.helper.getInt32(0, true);
    }

    static doubleToI64(d:number){
        FPHelper.helper.setFloat64(0, d, true);
        return FPHelper.helper.getFloat64(0, true);
    }
}