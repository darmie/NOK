// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from math.djinni

package co.zenturi.nok;

import java.util.concurrent.atomic.AtomicBoolean;

public abstract class Mat2 {
    public static final float WIDTH = 2;

    public static final float HEIGHT = 2;

    public abstract float get(float row, float col);

    public abstract void set(float row, float col, float v);

    public abstract Mat2 add(Mat2 mat);

    public abstract Mat2 sub(Mat2 mat);

    public abstract Mat2 multiply(float i);

    public abstract Mat2 clone();

    public abstract Mat2 transpose();

    public abstract Mat2 transpose3x3();

    public abstract float trace();

    public abstract float determinant();

    public static Mat2 orthogonalProjection(float left, float right, float bottom, float top, float zn, float zf)
    {
        return CppProxy.orthogonalProjection(left,
                                             right,
                                             bottom,
                                             top,
                                             zn,
                                             zf);
    }

    public static Mat2 perspective(float left, float right, float top, float bottom, float near, float far)
    {
        return CppProxy.perspective(left,
                                    right,
                                    top,
                                    bottom,
                                    near,
                                    far);
    }

    public static Mat2 perspectiveFOV(float fov, float aspect, float near, float far)
    {
        return CppProxy.perspectiveFOV(fov,
                                       aspect,
                                       near,
                                       far);
    }

    public static Mat2 lookAt(Vec3i eye, Vec3i at, Vec3i up)
    {
        return CppProxy.lookAt(eye,
                               at,
                               up);
    }

    public static Mat2 lookAlong(Vec3i axis, Vec3i eye, Vec3i up)
    {
        return CppProxy.lookAlong(axis,
                                  eye,
                                  up);
    }

    public static Mat2 translation(float x, float y)
    {
        return CppProxy.translation(x,
                                    y);
    }

    public static Mat2 movement(float x, float y, float z)
    {
        return CppProxy.movement(x,
                                 y,
                                 z);
    }

    public static Mat2 identity()
    {
        return CppProxy.identity();
    }

    public static Mat2 scale(float scale)
    {
        return CppProxy.scale(scale);
    }

    public static Mat2 rotationX(float alpha)
    {
        return CppProxy.rotationX(alpha);
    }

    public static Mat2 rotationY(float alpha)
    {
        return CppProxy.rotationY(alpha);
    }

    public static Mat2 rotationZ(float alpha)
    {
        return CppProxy.rotationZ(alpha);
    }

    public static Mat2 rotation(float yaw, float pitch, float roll)
    {
        return CppProxy.rotation(yaw,
                                 pitch,
                                 roll);
    }

    public static Mat2 create()
    {
        return CppProxy.create();
    }

    public static Mat2 from(Mat2 mat)
    {
        return CppProxy.from(mat);
    }

    public static Mat2 linearInterpolate(Mat2 a, Mat2 b, float prop)
    {
        return CppProxy.linearInterpolate(a,
                                          b,
                                          prop);
    }

    private static final class CppProxy extends Mat2
    {
        private final long nativeRef;
        private final AtomicBoolean destroyed = new AtomicBoolean(false);

        private CppProxy(long nativeRef)
        {
            if (nativeRef == 0) throw new RuntimeException("nativeRef is zero");
            this.nativeRef = nativeRef;
        }

        private native void nativeDestroy(long nativeRef);
        public void _djinni_private_destroy()
        {
            boolean destroyed = this.destroyed.getAndSet(true);
            if (!destroyed) nativeDestroy(this.nativeRef);
        }
        protected void finalize() throws java.lang.Throwable
        {
            _djinni_private_destroy();
            super.finalize();
        }

        @Override
        public float get(float row, float col)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_get(this.nativeRef, row, col);
        }
        private native float native_get(long _nativeRef, float row, float col);

        @Override
        public void set(float row, float col, float v)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_set(this.nativeRef, row, col, v);
        }
        private native void native_set(long _nativeRef, float row, float col, float v);

        @Override
        public Mat2 add(Mat2 mat)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_add(this.nativeRef, mat);
        }
        private native Mat2 native_add(long _nativeRef, Mat2 mat);

        @Override
        public Mat2 sub(Mat2 mat)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_sub(this.nativeRef, mat);
        }
        private native Mat2 native_sub(long _nativeRef, Mat2 mat);

        @Override
        public Mat2 multiply(float i)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_multiply(this.nativeRef, i);
        }
        private native Mat2 native_multiply(long _nativeRef, float i);

        @Override
        public Mat2 clone()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_clone(this.nativeRef);
        }
        private native Mat2 native_clone(long _nativeRef);

        @Override
        public Mat2 transpose()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_transpose(this.nativeRef);
        }
        private native Mat2 native_transpose(long _nativeRef);

        @Override
        public Mat2 transpose3x3()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_transpose3x3(this.nativeRef);
        }
        private native Mat2 native_transpose3x3(long _nativeRef);

        @Override
        public float trace()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_trace(this.nativeRef);
        }
        private native float native_trace(long _nativeRef);

        @Override
        public float determinant()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_determinant(this.nativeRef);
        }
        private native float native_determinant(long _nativeRef);

        public static native Mat2 orthogonalProjection(float left, float right, float bottom, float top, float zn, float zf);

        public static native Mat2 perspective(float left, float right, float top, float bottom, float near, float far);

        public static native Mat2 perspectiveFOV(float fov, float aspect, float near, float far);

        public static native Mat2 lookAt(Vec3i eye, Vec3i at, Vec3i up);

        public static native Mat2 lookAlong(Vec3i axis, Vec3i eye, Vec3i up);

        public static native Mat2 translation(float x, float y);

        public static native Mat2 movement(float x, float y, float z);

        public static native Mat2 identity();

        public static native Mat2 scale(float scale);

        public static native Mat2 rotationX(float alpha);

        public static native Mat2 rotationY(float alpha);

        public static native Mat2 rotationZ(float alpha);

        public static native Mat2 rotation(float yaw, float pitch, float roll);

        public static native Mat2 create();

        public static native Mat2 from(Mat2 mat);

        public static native Mat2 linearInterpolate(Mat2 a, Mat2 b, float prop);
    }
}
