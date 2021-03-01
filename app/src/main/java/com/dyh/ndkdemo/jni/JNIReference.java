package com.dyh.ndkdemo.jni;

/**
 * describe: JNI调用java的三种引用
 * create by daiyh on 2021-2-25
 */
public class JNIReference {
    static {
        System.loadLibrary("native-lib");
    }

    public native String errorCacheLocalReference();

    public native String cacheWithGlobalReference();

    public native void useWeakGlobalReference();
}
