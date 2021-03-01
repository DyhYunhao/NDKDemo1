package com.dyh.ndkdemo.jni;

import com.dyh.ndkdemo.thread.ICallbackMethod;
import com.dyh.ndkdemo.thread.IThreadCallback;

/**
 * describe: jni子线程调用java的方法
 * create by daiyh on 2021-2-24
 */
public class JNIInvokeMethod {
    static {
        System.loadLibrary("dynamic-lib");
    }

    public native void nativeCallback(ICallbackMethod callback);

    public native void nativeThreadCallback(IThreadCallback callback);
}
