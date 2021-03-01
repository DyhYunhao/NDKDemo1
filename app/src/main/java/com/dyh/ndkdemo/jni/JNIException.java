package com.dyh.ndkdemo.jni;

import java.util.PropertyResourceBundle;

/**
 * describe: JNI捕获异常
 * create by daiyh on 2021-2-26
 */
public class JNIException {
    static {
        System.loadLibrary("native-lib");
    }

    public native void nativeInvokeJavaException();

    public native void nativeThrowException() throws IllegalArgumentException;

    private int operation() {
        return 2 / 0;
    }
}
