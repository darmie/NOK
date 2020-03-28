// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from audio.djinni

package co.zenturi.nok;

import java.util.ArrayList;
import java.util.concurrent.atomic.AtomicBoolean;

public abstract class ResamplingAudioChannel {
    public abstract ArrayList<Float> getData();

    public abstract int getSamplesRate();

    public abstract float sample(int position, int sampleRate);

    public abstract void lerp(float v0, float v1, float t);

    public abstract int sampleLength(int sampleRate);

    public abstract void nextSamples(ArrayList<Float> requestedSamples, int requestedLength, int sampleRate);

    public abstract void play();

    public abstract void pause();

    public abstract void stop();

    public abstract float getLength();

    public abstract float getPosition();

    public abstract void setPosition(float pos);

    public abstract float getVolume();

    public abstract void setVolume(float vol);

    public abstract boolean getFinished();

    public abstract void max(int a, int b);

    public abstract void min(int a, int b);

    public static AudioChannel create(boolean looping, int sampleRate)
    {
        return CppProxy.create(looping,
                               sampleRate);
    }

    private static final class CppProxy extends ResamplingAudioChannel
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
        public ArrayList<Float> getData()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getData(this.nativeRef);
        }
        private native ArrayList<Float> native_getData(long _nativeRef);

        @Override
        public int getSamplesRate()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getSamplesRate(this.nativeRef);
        }
        private native int native_getSamplesRate(long _nativeRef);

        @Override
        public float sample(int position, int sampleRate)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_sample(this.nativeRef, position, sampleRate);
        }
        private native float native_sample(long _nativeRef, int position, int sampleRate);

        @Override
        public void lerp(float v0, float v1, float t)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_lerp(this.nativeRef, v0, v1, t);
        }
        private native void native_lerp(long _nativeRef, float v0, float v1, float t);

        @Override
        public int sampleLength(int sampleRate)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_sampleLength(this.nativeRef, sampleRate);
        }
        private native int native_sampleLength(long _nativeRef, int sampleRate);

        @Override
        public void nextSamples(ArrayList<Float> requestedSamples, int requestedLength, int sampleRate)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_nextSamples(this.nativeRef, requestedSamples, requestedLength, sampleRate);
        }
        private native void native_nextSamples(long _nativeRef, ArrayList<Float> requestedSamples, int requestedLength, int sampleRate);

        @Override
        public void play()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_play(this.nativeRef);
        }
        private native void native_play(long _nativeRef);

        @Override
        public void pause()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_pause(this.nativeRef);
        }
        private native void native_pause(long _nativeRef);

        @Override
        public void stop()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_stop(this.nativeRef);
        }
        private native void native_stop(long _nativeRef);

        @Override
        public float getLength()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getLength(this.nativeRef);
        }
        private native float native_getLength(long _nativeRef);

        @Override
        public float getPosition()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getPosition(this.nativeRef);
        }
        private native float native_getPosition(long _nativeRef);

        @Override
        public void setPosition(float pos)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_setPosition(this.nativeRef, pos);
        }
        private native void native_setPosition(long _nativeRef, float pos);

        @Override
        public float getVolume()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getVolume(this.nativeRef);
        }
        private native float native_getVolume(long _nativeRef);

        @Override
        public void setVolume(float vol)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_setVolume(this.nativeRef, vol);
        }
        private native void native_setVolume(long _nativeRef, float vol);

        @Override
        public boolean getFinished()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getFinished(this.nativeRef);
        }
        private native boolean native_getFinished(long _nativeRef);

        @Override
        public void max(int a, int b)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_max(this.nativeRef, a, b);
        }
        private native void native_max(long _nativeRef, int a, int b);

        @Override
        public void min(int a, int b)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_min(this.nativeRef, a, b);
        }
        private native void native_min(long _nativeRef, int a, int b);

        public static native AudioChannel create(boolean looping, int sampleRate);
    }
}
