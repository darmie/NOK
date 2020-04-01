// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from math.djinni

package co.zenturi.nok;

import com.facebook.react.bridge.Callback;
import com.facebook.react.bridge.Promise;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.facebook.react.bridge.ReadableArray;
import com.facebook.react.bridge.ReadableMap;
import com.facebook.react.bridge.WritableArray;
import com.facebook.react.bridge.WritableMap;
import com.facebook.react.module.annotations.ReactModule;
import com.rushingvise.reactcpp.ReactDjinni;
import java.util.HashMap;
import java.util.Map;
import java.util.concurrent.atomic.AtomicBoolean;

@ReactModule(name = "Mat3x2Module")
public final class Mat3x2Module extends ReactContextBaseJavaModule {
    public static final double WIDTH = 3;

    public static final double HEIGHT = 2;

    private final CppProxy mModule;

    public Mat3x2Module(ReactApplicationContext reactContext) {
        super(reactContext);
        mModule = create(ReactDjinni.createReactBridge(reactContext));
    }

    @Override
    public String getName() {
        return "Mat3x2Module";
    }

    @Override
    public Map<String, Object> getConstants() {
        final Map<String, Object> constants = new HashMap<>();
        constants.put("width", width);
        constants.put("height", height);
        return constants;
    }

    private static native CppProxy create(com.rushingvise.reactcpp.ReactBridge bridge);

    @ReactMethod
    public void get(double row, double col, Promise promise) {
        mModule.get(row, col, ReactDjinni.wrap(promise));
    }

    @ReactMethod
    public void set(double row, double col, double v) {
        mModule.set(row, col, v);
    }

    @ReactMethod
    public void orthogonalProjection(double left, double right, double bottom, double top, double zn, double zf, Promise promise) {
        mModule.orthogonalProjection(left, right, bottom, top, zn, zf, ReactDjinni.wrap(promise));
    }

    @ReactMethod
    public void perspective(double left, double right, double top, double bottom, double near, double far, Promise promise) {
        mModule.perspective(left, right, top, bottom, near, far, ReactDjinni.wrap(promise));
    }

    @ReactMethod
    public void perspectiveFOV(double fov, double aspect, double near, double far, Promise promise) {
        mModule.perspectiveFOV(fov, aspect, near, far, ReactDjinni.wrap(promise));
    }

    @ReactMethod
    public void lookAt(ReadableMap eye, ReadableMap at, ReadableMap up, Promise promise) {
        mModule.lookAt(ReactDjinni.wrap(eye), ReactDjinni.wrap(at), ReactDjinni.wrap(up), ReactDjinni.wrap(promise));
    }

    @ReactMethod
    public void lookAlong(ReadableMap axis, ReadableMap eye, ReadableMap up, Promise promise) {
        mModule.lookAlong(ReactDjinni.wrap(axis), ReactDjinni.wrap(eye), ReactDjinni.wrap(up), ReactDjinni.wrap(promise));
    }

    @ReactMethod
    public void translation(double x, double y, Promise promise) {
        mModule.translation(x, y, ReactDjinni.wrap(promise));
    }

    @ReactMethod
    public void movement(double x, double y, double z, Promise promise) {
        mModule.movement(x, y, z, ReactDjinni.wrap(promise));
    }

    @ReactMethod
    public void identity(Promise promise) {
        mModule.identity(ReactDjinni.wrap(promise));
    }

    @ReactMethod
    public void scale(double scale, Promise promise) {
        mModule.scale(scale, ReactDjinni.wrap(promise));
    }

    @ReactMethod
    public void rotationX(double alpha, Promise promise) {
        mModule.rotationX(alpha, ReactDjinni.wrap(promise));
    }

    @ReactMethod
    public void rotationY(double alpha, Promise promise) {
        mModule.rotationY(alpha, ReactDjinni.wrap(promise));
    }

    @ReactMethod
    public void rotationZ(double alpha, Promise promise) {
        mModule.rotationZ(alpha, ReactDjinni.wrap(promise));
    }

    @ReactMethod
    public void rotation(double yaw, double pitch, double roll, Promise promise) {
        mModule.rotation(yaw, pitch, roll, ReactDjinni.wrap(promise));
    }

    @ReactMethod
    public void from(ReadableArray mat, Promise promise) {
        mModule.from(ReactDjinni.wrap(mat), ReactDjinni.wrap(promise));
    }

    @ReactMethod
    public void add(ReadableArray mat, Promise promise) {
        mModule.add(ReactDjinni.wrap(mat), ReactDjinni.wrap(promise));
    }

    @ReactMethod
    public void sub(ReadableArray mat, Promise promise) {
        mModule.sub(ReactDjinni.wrap(mat), ReactDjinni.wrap(promise));
    }

    @ReactMethod
    public void multiply(double i, Promise promise) {
        mModule.multiply(i, ReactDjinni.wrap(promise));
    }

    @ReactMethod
    public void clone(Promise promise) {
        mModule.clone(ReactDjinni.wrap(promise));
    }

    @ReactMethod
    public void transpose(Promise promise) {
        mModule.transpose(ReactDjinni.wrap(promise));
    }

    @ReactMethod
    public void transpose3x3(Promise promise) {
        mModule.transpose3x3(ReactDjinni.wrap(promise));
    }

    @ReactMethod
    public void trace(Promise promise) {
        mModule.trace(ReactDjinni.wrap(promise));
    }

    @ReactMethod
    public void determinant(Promise promise) {
        mModule.determinant(ReactDjinni.wrap(promise));
    }

    @ReactMethod
    public void linearInterpolate(ReadableArray a, ReadableArray b, double prop, Promise promise) {
        mModule.linearInterpolate(ReactDjinni.wrap(a), ReactDjinni.wrap(b), prop, ReactDjinni.wrap(promise));
    }

    private static final class CppProxy
    {
        private final long nativeRef;
        private final AtomicBoolean destroyed = new AtomicBoolean(false);

        private CppProxy(long nativeRef)
        {
            if (nativeRef == 0) throw new RuntimeException("nativeRef is zero");
            this.nativeRef = nativeRef;
        }

        private native void nativeDestroy(long nativeRef);
        public void destroy()
        {
            boolean destroyed = this.destroyed.getAndSet(true);
            if (!destroyed) nativeDestroy(this.nativeRef);
        }
        protected void finalize() throws java.lang.Throwable
        {
            destroy();
            super.finalize();
        }

        public void get(double row, double col, com.rushingvise.reactcpp.JavascriptPromise promise)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_get(this.nativeRef, row, col, promise);
        }
        private native void native_get(long _nativeRef, double row, double col, com.rushingvise.reactcpp.JavascriptPromise promise);

        public void set(double row, double col, double v)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_set(this.nativeRef, row, col, v);
        }
        private native void native_set(long _nativeRef, double row, double col, double v);

        public void orthogonalProjection(double left, double right, double bottom, double top, double zn, double zf, com.rushingvise.reactcpp.JavascriptPromise promise)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_orthogonalProjection(this.nativeRef, left, right, bottom, top, zn, zf, promise);
        }
        private native void native_orthogonalProjection(long _nativeRef, double left, double right, double bottom, double top, double zn, double zf, com.rushingvise.reactcpp.JavascriptPromise promise);

        public void perspective(double left, double right, double top, double bottom, double near, double far, com.rushingvise.reactcpp.JavascriptPromise promise)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_perspective(this.nativeRef, left, right, top, bottom, near, far, promise);
        }
        private native void native_perspective(long _nativeRef, double left, double right, double top, double bottom, double near, double far, com.rushingvise.reactcpp.JavascriptPromise promise);

        public void perspectiveFOV(double fov, double aspect, double near, double far, com.rushingvise.reactcpp.JavascriptPromise promise)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_perspectiveFOV(this.nativeRef, fov, aspect, near, far, promise);
        }
        private native void native_perspectiveFOV(long _nativeRef, double fov, double aspect, double near, double far, com.rushingvise.reactcpp.JavascriptPromise promise);

        public void lookAt(com.rushingvise.reactcpp.JavascriptMap eye, com.rushingvise.reactcpp.JavascriptMap at, com.rushingvise.reactcpp.JavascriptMap up, com.rushingvise.reactcpp.JavascriptPromise promise)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_lookAt(this.nativeRef, eye, at, up, promise);
        }
        private native void native_lookAt(long _nativeRef, com.rushingvise.reactcpp.JavascriptMap eye, com.rushingvise.reactcpp.JavascriptMap at, com.rushingvise.reactcpp.JavascriptMap up, com.rushingvise.reactcpp.JavascriptPromise promise);

        public void lookAlong(com.rushingvise.reactcpp.JavascriptMap axis, com.rushingvise.reactcpp.JavascriptMap eye, com.rushingvise.reactcpp.JavascriptMap up, com.rushingvise.reactcpp.JavascriptPromise promise)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_lookAlong(this.nativeRef, axis, eye, up, promise);
        }
        private native void native_lookAlong(long _nativeRef, com.rushingvise.reactcpp.JavascriptMap axis, com.rushingvise.reactcpp.JavascriptMap eye, com.rushingvise.reactcpp.JavascriptMap up, com.rushingvise.reactcpp.JavascriptPromise promise);

        public void translation(double x, double y, com.rushingvise.reactcpp.JavascriptPromise promise)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_translation(this.nativeRef, x, y, promise);
        }
        private native void native_translation(long _nativeRef, double x, double y, com.rushingvise.reactcpp.JavascriptPromise promise);

        public void movement(double x, double y, double z, com.rushingvise.reactcpp.JavascriptPromise promise)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_movement(this.nativeRef, x, y, z, promise);
        }
        private native void native_movement(long _nativeRef, double x, double y, double z, com.rushingvise.reactcpp.JavascriptPromise promise);

        public void identity(com.rushingvise.reactcpp.JavascriptPromise promise)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_identity(this.nativeRef, promise);
        }
        private native void native_identity(long _nativeRef, com.rushingvise.reactcpp.JavascriptPromise promise);

        public void scale(double scale, com.rushingvise.reactcpp.JavascriptPromise promise)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_scale(this.nativeRef, scale, promise);
        }
        private native void native_scale(long _nativeRef, double scale, com.rushingvise.reactcpp.JavascriptPromise promise);

        public void rotationX(double alpha, com.rushingvise.reactcpp.JavascriptPromise promise)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_rotationX(this.nativeRef, alpha, promise);
        }
        private native void native_rotationX(long _nativeRef, double alpha, com.rushingvise.reactcpp.JavascriptPromise promise);

        public void rotationY(double alpha, com.rushingvise.reactcpp.JavascriptPromise promise)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_rotationY(this.nativeRef, alpha, promise);
        }
        private native void native_rotationY(long _nativeRef, double alpha, com.rushingvise.reactcpp.JavascriptPromise promise);

        public void rotationZ(double alpha, com.rushingvise.reactcpp.JavascriptPromise promise)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_rotationZ(this.nativeRef, alpha, promise);
        }
        private native void native_rotationZ(long _nativeRef, double alpha, com.rushingvise.reactcpp.JavascriptPromise promise);

        public void rotation(double yaw, double pitch, double roll, com.rushingvise.reactcpp.JavascriptPromise promise)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_rotation(this.nativeRef, yaw, pitch, roll, promise);
        }
        private native void native_rotation(long _nativeRef, double yaw, double pitch, double roll, com.rushingvise.reactcpp.JavascriptPromise promise);

        public void from(com.rushingvise.reactcpp.JavascriptArray mat, com.rushingvise.reactcpp.JavascriptPromise promise)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_from(this.nativeRef, mat, promise);
        }
        private native void native_from(long _nativeRef, com.rushingvise.reactcpp.JavascriptArray mat, com.rushingvise.reactcpp.JavascriptPromise promise);

        public void add(com.rushingvise.reactcpp.JavascriptArray mat, com.rushingvise.reactcpp.JavascriptPromise promise)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_add(this.nativeRef, mat, promise);
        }
        private native void native_add(long _nativeRef, com.rushingvise.reactcpp.JavascriptArray mat, com.rushingvise.reactcpp.JavascriptPromise promise);

        public void sub(com.rushingvise.reactcpp.JavascriptArray mat, com.rushingvise.reactcpp.JavascriptPromise promise)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_sub(this.nativeRef, mat, promise);
        }
        private native void native_sub(long _nativeRef, com.rushingvise.reactcpp.JavascriptArray mat, com.rushingvise.reactcpp.JavascriptPromise promise);

        public void multiply(double i, com.rushingvise.reactcpp.JavascriptPromise promise)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_multiply(this.nativeRef, i, promise);
        }
        private native void native_multiply(long _nativeRef, double i, com.rushingvise.reactcpp.JavascriptPromise promise);

        public void clone(com.rushingvise.reactcpp.JavascriptPromise promise)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_clone(this.nativeRef, promise);
        }
        private native void native_clone(long _nativeRef, com.rushingvise.reactcpp.JavascriptPromise promise);

        public void transpose(com.rushingvise.reactcpp.JavascriptPromise promise)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_transpose(this.nativeRef, promise);
        }
        private native void native_transpose(long _nativeRef, com.rushingvise.reactcpp.JavascriptPromise promise);

        public void transpose3x3(com.rushingvise.reactcpp.JavascriptPromise promise)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_transpose3x3(this.nativeRef, promise);
        }
        private native void native_transpose3x3(long _nativeRef, com.rushingvise.reactcpp.JavascriptPromise promise);

        public void trace(com.rushingvise.reactcpp.JavascriptPromise promise)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_trace(this.nativeRef, promise);
        }
        private native void native_trace(long _nativeRef, com.rushingvise.reactcpp.JavascriptPromise promise);

        public void determinant(com.rushingvise.reactcpp.JavascriptPromise promise)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_determinant(this.nativeRef, promise);
        }
        private native void native_determinant(long _nativeRef, com.rushingvise.reactcpp.JavascriptPromise promise);

        public void linearInterpolate(com.rushingvise.reactcpp.JavascriptArray a, com.rushingvise.reactcpp.JavascriptArray b, double prop, com.rushingvise.reactcpp.JavascriptPromise promise)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_linearInterpolate(this.nativeRef, a, b, prop, promise);
        }
        private native void native_linearInterpolate(long _nativeRef, com.rushingvise.reactcpp.JavascriptArray a, com.rushingvise.reactcpp.JavascriptArray b, double prop, com.rushingvise.reactcpp.JavascriptPromise promise);
    }
}
