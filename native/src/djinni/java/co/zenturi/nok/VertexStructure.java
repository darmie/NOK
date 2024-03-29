// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from nok.djinni

package co.zenturi.nok;

import java.util.ArrayList;
import java.util.concurrent.atomic.AtomicBoolean;

public abstract class VertexStructure {
    public static final int MAXELEMENTSCOUNT = 16;

    public abstract ArrayList<VertexElement> getElements();

    public abstract int getSize();

    public abstract void setSize(int s);

    public abstract boolean instanced();

    public abstract void add(String name, VertexData data);

    public abstract void addAttribute(VertexAttribute attribute, VertexData data);

    public static native VertexStructure create();

    private static final class CppProxy extends VertexStructure
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
        public ArrayList<VertexElement> getElements()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getElements(this.nativeRef);
        }
        private native ArrayList<VertexElement> native_getElements(long _nativeRef);

        @Override
        public int getSize()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getSize(this.nativeRef);
        }
        private native int native_getSize(long _nativeRef);

        @Override
        public void setSize(int s)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_setSize(this.nativeRef, s);
        }
        private native void native_setSize(long _nativeRef, int s);

        @Override
        public boolean instanced()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_instanced(this.nativeRef);
        }
        private native boolean native_instanced(long _nativeRef);

        @Override
        public void add(String name, VertexData data)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_add(this.nativeRef, name, data);
        }
        private native void native_add(long _nativeRef, String name, VertexData data);

        @Override
        public void addAttribute(VertexAttribute attribute, VertexData data)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_addAttribute(this.nativeRef, attribute, data);
        }
        private native void native_addAttribute(long _nativeRef, VertexAttribute attribute, VertexData data);
    }
}
