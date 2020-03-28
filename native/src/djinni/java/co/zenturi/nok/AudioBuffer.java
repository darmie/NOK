// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from audio.djinni

package co.zenturi.nok;

import java.util.ArrayList;
import java.util.concurrent.atomic.AtomicBoolean;

public abstract class AudioBuffer {
    public abstract int getChannels();

    public abstract int getSamplesPerSecond();

    public abstract ArrayList<Float> getData();

    public abstract int getSize();

    public abstract int getReadLocation();

    public abstract int getWriteLocation();

    public abstract void setChannels(int channels);

    public abstract void setSamplesPerSecond(int samples);

    public abstract void setData(ArrayList<Float> data);

    public abstract void setSize(int s);

    public abstract void setReadLocation(int loc);

    public abstract void setWriteLocation(int loc);

    public static void create(int size, int channels, int samplesPerSecond)
    {
        CppProxy.create(size,
                        channels,
                        samplesPerSecond);
    }

    private static final class CppProxy extends AudioBuffer
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
        public int getChannels()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getChannels(this.nativeRef);
        }
        private native int native_getChannels(long _nativeRef);

        @Override
        public int getSamplesPerSecond()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getSamplesPerSecond(this.nativeRef);
        }
        private native int native_getSamplesPerSecond(long _nativeRef);

        @Override
        public ArrayList<Float> getData()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getData(this.nativeRef);
        }
        private native ArrayList<Float> native_getData(long _nativeRef);

        @Override
        public int getSize()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getSize(this.nativeRef);
        }
        private native int native_getSize(long _nativeRef);

        @Override
        public int getReadLocation()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getReadLocation(this.nativeRef);
        }
        private native int native_getReadLocation(long _nativeRef);

        @Override
        public int getWriteLocation()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getWriteLocation(this.nativeRef);
        }
        private native int native_getWriteLocation(long _nativeRef);

        @Override
        public void setChannels(int channels)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_setChannels(this.nativeRef, channels);
        }
        private native void native_setChannels(long _nativeRef, int channels);

        @Override
        public void setSamplesPerSecond(int samples)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_setSamplesPerSecond(this.nativeRef, samples);
        }
        private native void native_setSamplesPerSecond(long _nativeRef, int samples);

        @Override
        public void setData(ArrayList<Float> data)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_setData(this.nativeRef, data);
        }
        private native void native_setData(long _nativeRef, ArrayList<Float> data);

        @Override
        public void setSize(int s)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_setSize(this.nativeRef, s);
        }
        private native void native_setSize(long _nativeRef, int s);

        @Override
        public void setReadLocation(int loc)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_setReadLocation(this.nativeRef, loc);
        }
        private native void native_setReadLocation(long _nativeRef, int loc);

        @Override
        public void setWriteLocation(int loc)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_setWriteLocation(this.nativeRef, loc);
        }
        private native void native_setWriteLocation(long _nativeRef, int loc);

        public static native void create(int size, int channels, int samplesPerSecond);
    }
}
