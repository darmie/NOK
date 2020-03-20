// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from math.djinni

package co.zenturi.nok;

import java.util.concurrent.atomic.AtomicBoolean;

public abstract class Vec3 {
    public abstract float getX();

    public abstract float getY();

    public abstract float getZ();

    public abstract void setX(float x);

    public abstract void setY(float y);

    public abstract void setZ(float z);

    public abstract void add(Vec3 v);

    public abstract void addScaledVector(Vec3 v);

    public abstract void sub(Vec3 v);

    public abstract void multiply(float i);

    public abstract void divide(float i);

    public abstract float squareLength();

    public abstract float getLength();

    public abstract void setLength(float length);

    public abstract Vec3 normalize();

    public abstract boolean isZero();

    public abstract float get(float i);

    public abstract void set(float i, float v);

    public abstract float dot(Vec3 v);

    public abstract Vec3 cross(Vec3 v);

    public abstract float distance(Vec3 v);

    public static Vec3 create(float x, float y, float z)
    {
        return CppProxy.create(x,
                               y,
                               z);
    }

    private static final class CppProxy extends Vec3
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
        public float getX()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getX(this.nativeRef);
        }
        private native float native_getX(long _nativeRef);

        @Override
        public float getY()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getY(this.nativeRef);
        }
        private native float native_getY(long _nativeRef);

        @Override
        public float getZ()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getZ(this.nativeRef);
        }
        private native float native_getZ(long _nativeRef);

        @Override
        public void setX(float x)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_setX(this.nativeRef, x);
        }
        private native void native_setX(long _nativeRef, float x);

        @Override
        public void setY(float y)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_setY(this.nativeRef, y);
        }
        private native void native_setY(long _nativeRef, float y);

        @Override
        public void setZ(float z)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_setZ(this.nativeRef, z);
        }
        private native void native_setZ(long _nativeRef, float z);

        @Override
        public void add(Vec3 v)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_add(this.nativeRef, v);
        }
        private native void native_add(long _nativeRef, Vec3 v);

        @Override
        public void addScaledVector(Vec3 v)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_addScaledVector(this.nativeRef, v);
        }
        private native void native_addScaledVector(long _nativeRef, Vec3 v);

        @Override
        public void sub(Vec3 v)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_sub(this.nativeRef, v);
        }
        private native void native_sub(long _nativeRef, Vec3 v);

        @Override
        public void multiply(float i)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_multiply(this.nativeRef, i);
        }
        private native void native_multiply(long _nativeRef, float i);

        @Override
        public void divide(float i)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_divide(this.nativeRef, i);
        }
        private native void native_divide(long _nativeRef, float i);

        @Override
        public float squareLength()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_squareLength(this.nativeRef);
        }
        private native float native_squareLength(long _nativeRef);

        @Override
        public float getLength()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getLength(this.nativeRef);
        }
        private native float native_getLength(long _nativeRef);

        @Override
        public void setLength(float length)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_setLength(this.nativeRef, length);
        }
        private native void native_setLength(long _nativeRef, float length);

        @Override
        public Vec3 normalize()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_normalize(this.nativeRef);
        }
        private native Vec3 native_normalize(long _nativeRef);

        @Override
        public boolean isZero()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_isZero(this.nativeRef);
        }
        private native boolean native_isZero(long _nativeRef);

        @Override
        public float get(float i)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_get(this.nativeRef, i);
        }
        private native float native_get(long _nativeRef, float i);

        @Override
        public void set(float i, float v)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_set(this.nativeRef, i, v);
        }
        private native void native_set(long _nativeRef, float i, float v);

        @Override
        public float dot(Vec3 v)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_dot(this.nativeRef, v);
        }
        private native float native_dot(long _nativeRef, Vec3 v);

        @Override
        public Vec3 cross(Vec3 v)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_cross(this.nativeRef, v);
        }
        private native Vec3 native_cross(long _nativeRef, Vec3 v);

        @Override
        public float distance(Vec3 v)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_distance(this.nativeRef, v);
        }
        private native float native_distance(long _nativeRef, Vec3 v);

        public static native Vec3 create(float x, float y, float z);
    }
}
