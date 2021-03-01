package com.dyh.ndkdemo.jni;

/**
 * describe: java与jni引用类型的转换
 * create by daiyh on 2021-2-23
 */
public class JNIReferenceType {

    static {
        System.loadLibrary("native-lib");
    }

    public native String callNativeStringArray(String[] strArray);

}
