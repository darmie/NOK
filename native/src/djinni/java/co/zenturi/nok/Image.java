// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from nok.djinni

package co.zenturi.nok;

import java.util.concurrent.atomic.AtomicBoolean;

public abstract class Image {
    public abstract int at(int x, int y);

    public abstract byte[] getPixels();

    public abstract ImageFormat getFormat();

    public abstract boolean readable();

    public abstract ImageCompression getCompression();

    public abstract byte[] getData();

    public abstract int getDataSize();

    public abstract int getHeight();

    public abstract int getWidth();

    public abstract void setWidth(int width);

    public abstract void setHeight(int height);

    public abstract int getDepth();

    public abstract void setDepth(int depth);

    public static native int sizeOf(ImageFormat format);

    public static native Image create(int width, int height, ImageFormat format, boolean readable);

    public static native Image create3D(int width, int height, int depth, ImageFormat format, boolean readable);

    public static native Image fromData(byte[] data, int width, int height, ImageFormat format, boolean readable);

    public static native Image fromData3D(byte[] data, int width, int height, int depth, ImageFormat format, boolean readable);

    private static final class CppProxy extends Image
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

        @Override
        public int at(int x, int y)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_at(this.nativeRef, x, y);
        }
        private native int native_at(long _nativeRef, int x, int y);

        @Override
        public byte[] getPixels()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getPixels(this.nativeRef);
        }
        private native byte[] native_getPixels(long _nativeRef);

        @Override
        public ImageFormat getFormat()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getFormat(this.nativeRef);
        }
        private native ImageFormat native_getFormat(long _nativeRef);

        @Override
        public boolean readable()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_readable(this.nativeRef);
        }
        private native boolean native_readable(long _nativeRef);

        @Override
        public ImageCompression getCompression()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getCompression(this.nativeRef);
        }
        private native ImageCompression native_getCompression(long _nativeRef);

        @Override
        public byte[] getData()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getData(this.nativeRef);
        }
        private native byte[] native_getData(long _nativeRef);

        @Override
        public int getDataSize()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getDataSize(this.nativeRef);
        }
        private native int native_getDataSize(long _nativeRef);

        @Override
        public int getHeight()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getHeight(this.nativeRef);
        }
        private native int native_getHeight(long _nativeRef);

        @Override
        public int getWidth()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getWidth(this.nativeRef);
        }
        private native int native_getWidth(long _nativeRef);

        @Override
        public void setWidth(int width)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_setWidth(this.nativeRef, width);
        }
        private native void native_setWidth(long _nativeRef, int width);

        @Override
        public void setHeight(int height)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_setHeight(this.nativeRef, height);
        }
        private native void native_setHeight(long _nativeRef, int height);

        @Override
        public int getDepth()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getDepth(this.nativeRef);
        }
        private native int native_getDepth(long _nativeRef);

        @Override
        public void setDepth(int depth)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_setDepth(this.nativeRef, depth);
        }
        private native void native_setDepth(long _nativeRef, int depth);
    }
}
