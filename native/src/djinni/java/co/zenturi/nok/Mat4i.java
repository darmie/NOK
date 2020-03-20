// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from math.djinni

package co.zenturi.nok;

import java.util.concurrent.atomic.AtomicBoolean;

public abstract class Mat4i {
    public static final int WIDTH = 4;

    public static final int HEIGHT = 4;

    public abstract float get(int row, int col);

    public abstract void set(int row, int col, int v);

    public abstract Mat4i add(Mat4i mat);

    public abstract Mat4i sub(Mat4i mat);

    public abstract Mat4i multiply(int i);

    public abstract Mat4i clone();

    public abstract Mat4i transpose();

    public abstract Mat4i transpose3x3();

    public abstract int trace();

    public abstract int determinant();

    public static Mat4i orthogonalProjection(float left, float right, float bottom, float top, float zn, float zf)
    {
        return CppProxy.orthogonalProjection(left,
                                             right,
                                             bottom,
                                             top,
                                             zn,
                                             zf);
    }

    public static Mat4i perspective(float left, float right, float top, float bottom, float near, float far)
    {
        return CppProxy.perspective(left,
                                    right,
                                    top,
                                    bottom,
                                    near,
                                    far);
    }

    public static Mat4i perspectiveFOV(float fov, float aspect, float near, float far)
    {
        return CppProxy.perspectiveFOV(fov,
                                       aspect,
                                       near,
                                       far);
    }

    public static Mat4i lookAt(Vec3i eye, Vec3i at, Vec3i up)
    {
        return CppProxy.lookAt(eye,
                               at,
                               up);
    }

    public static Mat4i lookAlong(Vec3i axis, Vec3i eye, Vec3i up)
    {
        return CppProxy.lookAlong(axis,
                                  eye,
                                  up);
    }

    public static Mat4i translation(float x, float y)
    {
        return CppProxy.translation(x,
                                    y);
    }

    public static Mat4i movement(float x, float y, float z)
    {
        return CppProxy.movement(x,
                                 y,
                                 z);
    }

    public static Mat4i identity()
    {
        return CppProxy.identity();
    }

    public static Mat4i scale(float scale)
    {
        return CppProxy.scale(scale);
    }

    public static Mat4i rotationX(float alpha)
    {
        return CppProxy.rotationX(alpha);
    }

    public static Mat4i rotationY(float alpha)
    {
        return CppProxy.rotationY(alpha);
    }

    public static Mat4i rotationZ(float alpha)
    {
        return CppProxy.rotationZ(alpha);
    }

    public static Mat4i rotation(float yaw, float pitch, float roll)
    {
        return CppProxy.rotation(yaw,
                                 pitch,
                                 roll);
    }

    public static Mat4i create()
    {
        return CppProxy.create();
    }

    public static Mat4i from(Mat4i mat)
    {
        return CppProxy.from(mat);
    }

    public static Mat4i linearInterpolate(Mat4i a, Mat4i b, float prop)
    {
        return CppProxy.linearInterpolate(a,
                                          b,
                                          prop);
    }

    private static final class CppProxy extends Mat4i
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
        public float get(int row, int col)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_get(this.nativeRef, row, col);
        }
        private native float native_get(long _nativeRef, int row, int col);

        @Override
        public void set(int row, int col, int v)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_set(this.nativeRef, row, col, v);
        }
        private native void native_set(long _nativeRef, int row, int col, int v);

        @Override
        public Mat4i add(Mat4i mat)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_add(this.nativeRef, mat);
        }
        private native Mat4i native_add(long _nativeRef, Mat4i mat);

        @Override
        public Mat4i sub(Mat4i mat)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_sub(this.nativeRef, mat);
        }
        private native Mat4i native_sub(long _nativeRef, Mat4i mat);

        @Override
        public Mat4i multiply(int i)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_multiply(this.nativeRef, i);
        }
        private native Mat4i native_multiply(long _nativeRef, int i);

        @Override
        public Mat4i clone()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_clone(this.nativeRef);
        }
        private native Mat4i native_clone(long _nativeRef);

        @Override
        public Mat4i transpose()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_transpose(this.nativeRef);
        }
        private native Mat4i native_transpose(long _nativeRef);

        @Override
        public Mat4i transpose3x3()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_transpose3x3(this.nativeRef);
        }
        private native Mat4i native_transpose3x3(long _nativeRef);

        @Override
        public int trace()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_trace(this.nativeRef);
        }
        private native int native_trace(long _nativeRef);

        @Override
        public int determinant()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_determinant(this.nativeRef);
        }
        private native int native_determinant(long _nativeRef);

        public static native Mat4i orthogonalProjection(float left, float right, float bottom, float top, float zn, float zf);

        public static native Mat4i perspective(float left, float right, float top, float bottom, float near, float far);

        public static native Mat4i perspectiveFOV(float fov, float aspect, float near, float far);

        public static native Mat4i lookAt(Vec3i eye, Vec3i at, Vec3i up);

        public static native Mat4i lookAlong(Vec3i axis, Vec3i eye, Vec3i up);

        public static native Mat4i translation(float x, float y);

        public static native Mat4i movement(float x, float y, float z);

        public static native Mat4i identity();

        public static native Mat4i scale(float scale);

        public static native Mat4i rotationX(float alpha);

        public static native Mat4i rotationY(float alpha);

        public static native Mat4i rotationZ(float alpha);

        public static native Mat4i rotation(float yaw, float pitch, float roll);

        public static native Mat4i create();

        public static native Mat4i from(Mat4i mat);

        public static native Mat4i linearInterpolate(Mat4i a, Mat4i b, float prop);
    }
}
