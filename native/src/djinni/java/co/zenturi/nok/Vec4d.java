// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from math.djinni

package co.zenturi.nok;

import java.util.concurrent.atomic.AtomicBoolean;

public abstract class Vec4d {
    public abstract double getX();

    public abstract double getY();

    public abstract double getZ();

    public abstract void setX(double x);

    public abstract void setY(double y);

    public abstract void setZ(double z);

    public abstract void setW(double w);

    public abstract void add(Vec4d v);

    public abstract void addScaledVector(Vec4d v);

    public abstract void sub(Vec4d v);

    public abstract void multiply(double i);

    public abstract void divide(double i);

    public abstract double squareLength();

    public abstract double getLength();

    public abstract void setLength(double length);

    public abstract Vec4d normalize();

    public abstract boolean isZero();

    public abstract double get(double i);

    public abstract void set(double i, double v);

    public abstract double dot(Vec4d v);

    public abstract Vec4d cross(Vec4d v);

    public abstract double distance(Vec4d v);

    public abstract void invert();

    public static Vec4d create(double x, double y, double z)
    {
        return CppProxy.create(x,
                               y,
                               z);
    }

    private static final class CppProxy extends Vec4d
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
        public double getX()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getX(this.nativeRef);
        }
        private native double native_getX(long _nativeRef);

        @Override
        public double getY()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getY(this.nativeRef);
        }
        private native double native_getY(long _nativeRef);

        @Override
        public double getZ()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getZ(this.nativeRef);
        }
        private native double native_getZ(long _nativeRef);

        @Override
        public void setX(double x)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_setX(this.nativeRef, x);
        }
        private native void native_setX(long _nativeRef, double x);

        @Override
        public void setY(double y)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_setY(this.nativeRef, y);
        }
        private native void native_setY(long _nativeRef, double y);

        @Override
        public void setZ(double z)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_setZ(this.nativeRef, z);
        }
        private native void native_setZ(long _nativeRef, double z);

        @Override
        public void setW(double w)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_setW(this.nativeRef, w);
        }
        private native void native_setW(long _nativeRef, double w);

        @Override
        public void add(Vec4d v)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_add(this.nativeRef, v);
        }
        private native void native_add(long _nativeRef, Vec4d v);

        @Override
        public void addScaledVector(Vec4d v)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_addScaledVector(this.nativeRef, v);
        }
        private native void native_addScaledVector(long _nativeRef, Vec4d v);

        @Override
        public void sub(Vec4d v)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_sub(this.nativeRef, v);
        }
        private native void native_sub(long _nativeRef, Vec4d v);

        @Override
        public void multiply(double i)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_multiply(this.nativeRef, i);
        }
        private native void native_multiply(long _nativeRef, double i);

        @Override
        public void divide(double i)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_divide(this.nativeRef, i);
        }
        private native void native_divide(long _nativeRef, double i);

        @Override
        public double squareLength()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_squareLength(this.nativeRef);
        }
        private native double native_squareLength(long _nativeRef);

        @Override
        public double getLength()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getLength(this.nativeRef);
        }
        private native double native_getLength(long _nativeRef);

        @Override
        public void setLength(double length)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_setLength(this.nativeRef, length);
        }
        private native void native_setLength(long _nativeRef, double length);

        @Override
        public Vec4d normalize()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_normalize(this.nativeRef);
        }
        private native Vec4d native_normalize(long _nativeRef);

        @Override
        public boolean isZero()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_isZero(this.nativeRef);
        }
        private native boolean native_isZero(long _nativeRef);

        @Override
        public double get(double i)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_get(this.nativeRef, i);
        }
        private native double native_get(long _nativeRef, double i);

        @Override
        public void set(double i, double v)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_set(this.nativeRef, i, v);
        }
        private native void native_set(long _nativeRef, double i, double v);

        @Override
        public double dot(Vec4d v)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_dot(this.nativeRef, v);
        }
        private native double native_dot(long _nativeRef, Vec4d v);

        @Override
        public Vec4d cross(Vec4d v)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_cross(this.nativeRef, v);
        }
        private native Vec4d native_cross(long _nativeRef, Vec4d v);

        @Override
        public double distance(Vec4d v)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_distance(this.nativeRef, v);
        }
        private native double native_distance(long _nativeRef, Vec4d v);

        @Override
        public void invert()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_invert(this.nativeRef);
        }
        private native void native_invert(long _nativeRef);

        public static native Vec4d create(double x, double y, double z);
    }
}
