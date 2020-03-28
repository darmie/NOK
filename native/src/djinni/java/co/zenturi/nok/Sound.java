// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from audio.djinni

package co.zenturi.nok;

import java.util.ArrayList;
import java.util.concurrent.atomic.AtomicBoolean;

public abstract class Sound {
    public abstract byte[] getCompressedData();

    public abstract ArrayList<Float> getUncompressedData();

    public abstract float getLength();

    public abstract int getChannels();

    public abstract int getSampleRate();

    public abstract void setCompressedData(byte[] b);

    public abstract void setUncompressedData(ArrayList<Float> d);

    public abstract void setLength(float length);

    public abstract void setChannels(int channels);

    public abstract void setSampleRate(int rate);

    public abstract void unload();

    public static Sound create()
    {
        return CppProxy.create();
    }

    private static final class CppProxy extends Sound
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
        public byte[] getCompressedData()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getCompressedData(this.nativeRef);
        }
        private native byte[] native_getCompressedData(long _nativeRef);

        @Override
        public ArrayList<Float> getUncompressedData()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getUncompressedData(this.nativeRef);
        }
        private native ArrayList<Float> native_getUncompressedData(long _nativeRef);

        @Override
        public float getLength()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getLength(this.nativeRef);
        }
        private native float native_getLength(long _nativeRef);

        @Override
        public int getChannels()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getChannels(this.nativeRef);
        }
        private native int native_getChannels(long _nativeRef);

        @Override
        public int getSampleRate()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getSampleRate(this.nativeRef);
        }
        private native int native_getSampleRate(long _nativeRef);

        @Override
        public void setCompressedData(byte[] b)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_setCompressedData(this.nativeRef, b);
        }
        private native void native_setCompressedData(long _nativeRef, byte[] b);

        @Override
        public void setUncompressedData(ArrayList<Float> d)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_setUncompressedData(this.nativeRef, d);
        }
        private native void native_setUncompressedData(long _nativeRef, ArrayList<Float> d);

        @Override
        public void setLength(float length)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_setLength(this.nativeRef, length);
        }
        private native void native_setLength(long _nativeRef, float length);

        @Override
        public void setChannels(int channels)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_setChannels(this.nativeRef, channels);
        }
        private native void native_setChannels(long _nativeRef, int channels);

        @Override
        public void setSampleRate(int rate)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_setSampleRate(this.nativeRef, rate);
        }
        private native void native_setSampleRate(long _nativeRef, int rate);

        @Override
        public void unload()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_unload(this.nativeRef);
        }
        private native void native_unload(long _nativeRef);

        public static native Sound create();
    }
}
