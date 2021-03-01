package com.dyh.ndkdemo.jni;

/**
 * describe: jni创建和销毁线程
 * create by daiyh on 2021-2-26
 */
public class JNIThread {
    static {
        System.loadLibrary("dynamic-lib");
    }

    public native void createNativeThread();

    public native void createNativeThreadWithArgs();

    public native void joinNativeThread();

    public native void waitNativeThread();

    public native void notifyNativeThread();

    public native void startPAndCThread();
}
