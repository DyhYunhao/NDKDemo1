package com.dyh.ndkdemo.jni;

/**
 * describe: java与jni的string类型转换
 * create by daiyh on 2021-2-23
 */
public class JNIString {
    static {
        System.loadLibrary("native-lib");
    }

    public native String callNativeString(String str);

    public native void stringMethod(String str);
}
