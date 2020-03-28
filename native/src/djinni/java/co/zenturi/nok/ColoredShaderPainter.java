// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from nok.djinni

package co.zenturi.nok;

import java.util.concurrent.atomic.AtomicBoolean;

public abstract class ColoredShaderPainter {
    public abstract PipelineState getPipeline();

    public abstract void setPipeline(PipelineState p);

    public abstract void setProjection(Mat4 projectionMatrix);

    public abstract void setRectVertices(float bottomleftx, float bottomlefty, float topleftx, float toprightx, float toprighty, float bottomrightx, float bottomrighty);

    public abstract void setRectColors(float opacity, double color);

    public abstract void fillRect(float opacity, double color, float bottomleftx, float bottomlefty, float topleftx, float toprightx, float toprighty, float bottomrightx, float bottomrighty);

    public abstract void fillTriangle(float opacity, double color, float x1, float y1, float x2, float y2, float x3, float y3);

    public abstract void endTris(boolean rectsDone);

    public abstract void endRects(boolean trisDone);

    public abstract void end();

    public static ColoredShaderPainter create()
    {
        return CppProxy.create();
    }

    private static final class CppProxy extends ColoredShaderPainter
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
        public PipelineState getPipeline()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getPipeline(this.nativeRef);
        }
        private native PipelineState native_getPipeline(long _nativeRef);

        @Override
        public void setPipeline(PipelineState p)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_setPipeline(this.nativeRef, p);
        }
        private native void native_setPipeline(long _nativeRef, PipelineState p);

        @Override
        public void setProjection(Mat4 projectionMatrix)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_setProjection(this.nativeRef, projectionMatrix);
        }
        private native void native_setProjection(long _nativeRef, Mat4 projectionMatrix);

        @Override
        public void setRectVertices(float bottomleftx, float bottomlefty, float topleftx, float toprightx, float toprighty, float bottomrightx, float bottomrighty)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_setRectVertices(this.nativeRef, bottomleftx, bottomlefty, topleftx, toprightx, toprighty, bottomrightx, bottomrighty);
        }
        private native void native_setRectVertices(long _nativeRef, float bottomleftx, float bottomlefty, float topleftx, float toprightx, float toprighty, float bottomrightx, float bottomrighty);

        @Override
        public void setRectColors(float opacity, double color)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_setRectColors(this.nativeRef, opacity, color);
        }
        private native void native_setRectColors(long _nativeRef, float opacity, double color);

        @Override
        public void fillRect(float opacity, double color, float bottomleftx, float bottomlefty, float topleftx, float toprightx, float toprighty, float bottomrightx, float bottomrighty)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_fillRect(this.nativeRef, opacity, color, bottomleftx, bottomlefty, topleftx, toprightx, toprighty, bottomrightx, bottomrighty);
        }
        private native void native_fillRect(long _nativeRef, float opacity, double color, float bottomleftx, float bottomlefty, float topleftx, float toprightx, float toprighty, float bottomrightx, float bottomrighty);

        @Override
        public void fillTriangle(float opacity, double color, float x1, float y1, float x2, float y2, float x3, float y3)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_fillTriangle(this.nativeRef, opacity, color, x1, y1, x2, y2, x3, y3);
        }
        private native void native_fillTriangle(long _nativeRef, float opacity, double color, float x1, float y1, float x2, float y2, float x3, float y3);

        @Override
        public void endTris(boolean rectsDone)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_endTris(this.nativeRef, rectsDone);
        }
        private native void native_endTris(long _nativeRef, boolean rectsDone);

        @Override
        public void endRects(boolean trisDone)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_endRects(this.nativeRef, trisDone);
        }
        private native void native_endRects(long _nativeRef, boolean trisDone);

        @Override
        public void end()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_end(this.nativeRef);
        }
        private native void native_end(long _nativeRef);

        public static native ColoredShaderPainter create();
    }
}