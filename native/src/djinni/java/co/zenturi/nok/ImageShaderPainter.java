// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from nok.djinni

package co.zenturi.nok;

import java.util.concurrent.atomic.AtomicBoolean;

public abstract class ImageShaderPainter {
    public abstract PipelineState getPipeline();

    public abstract void setPipeline(PipelineState p);

    public abstract void setBilinearFilter(boolean bilinear);

    public abstract void setBilinearMipmapFilter(boolean bilinear);

    public abstract void setProjection(Mat4 projectionMatrix);

    public abstract void drawImageTexture(Texture img, float bottomleftx, float bottomlefty, float topleftx, float toprightx, float toprighty, float bottomrightx, float bottomrighty, float opacity, double color);

    public abstract void drawImageTextureScale(Texture img, float sx, float sy, float sw, float sh, float left, float top, float right, float bottom, float opacity, double color);

    public abstract void drawImageRenderTarget(RenderTarget img, float bottomleftx, float bottomlefty, float topleftx, float toprightx, float toprighty, float bottomrightx, float bottomrighty, float opacity, double color);

    public abstract void drawImageRenderTargetScale(RenderTarget img, float sx, float sy, float sw, float sh, float left, float top, float right, float bottom, float opacity, double color);

    public abstract void end();

    public static ImageShaderPainter create()
    {
        return CppProxy.create();
    }

    private static final class CppProxy extends ImageShaderPainter
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
        public void setBilinearFilter(boolean bilinear)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_setBilinearFilter(this.nativeRef, bilinear);
        }
        private native void native_setBilinearFilter(long _nativeRef, boolean bilinear);

        @Override
        public void setBilinearMipmapFilter(boolean bilinear)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_setBilinearMipmapFilter(this.nativeRef, bilinear);
        }
        private native void native_setBilinearMipmapFilter(long _nativeRef, boolean bilinear);

        @Override
        public void setProjection(Mat4 projectionMatrix)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_setProjection(this.nativeRef, projectionMatrix);
        }
        private native void native_setProjection(long _nativeRef, Mat4 projectionMatrix);

        @Override
        public void drawImageTexture(Texture img, float bottomleftx, float bottomlefty, float topleftx, float toprightx, float toprighty, float bottomrightx, float bottomrighty, float opacity, double color)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_drawImageTexture(this.nativeRef, img, bottomleftx, bottomlefty, topleftx, toprightx, toprighty, bottomrightx, bottomrighty, opacity, color);
        }
        private native void native_drawImageTexture(long _nativeRef, Texture img, float bottomleftx, float bottomlefty, float topleftx, float toprightx, float toprighty, float bottomrightx, float bottomrighty, float opacity, double color);

        @Override
        public void drawImageTextureScale(Texture img, float sx, float sy, float sw, float sh, float left, float top, float right, float bottom, float opacity, double color)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_drawImageTextureScale(this.nativeRef, img, sx, sy, sw, sh, left, top, right, bottom, opacity, color);
        }
        private native void native_drawImageTextureScale(long _nativeRef, Texture img, float sx, float sy, float sw, float sh, float left, float top, float right, float bottom, float opacity, double color);

        @Override
        public void drawImageRenderTarget(RenderTarget img, float bottomleftx, float bottomlefty, float topleftx, float toprightx, float toprighty, float bottomrightx, float bottomrighty, float opacity, double color)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_drawImageRenderTarget(this.nativeRef, img, bottomleftx, bottomlefty, topleftx, toprightx, toprighty, bottomrightx, bottomrighty, opacity, color);
        }
        private native void native_drawImageRenderTarget(long _nativeRef, RenderTarget img, float bottomleftx, float bottomlefty, float topleftx, float toprightx, float toprighty, float bottomrightx, float bottomrighty, float opacity, double color);

        @Override
        public void drawImageRenderTargetScale(RenderTarget img, float sx, float sy, float sw, float sh, float left, float top, float right, float bottom, float opacity, double color)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_drawImageRenderTargetScale(this.nativeRef, img, sx, sy, sw, sh, left, top, right, bottom, opacity, color);
        }
        private native void native_drawImageRenderTargetScale(long _nativeRef, RenderTarget img, float sx, float sy, float sw, float sh, float left, float top, float right, float bottom, float opacity, double color);

        @Override
        public void end()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_end(this.nativeRef);
        }
        private native void native_end(long _nativeRef);

        public static native ImageShaderPainter create();
    }
}
