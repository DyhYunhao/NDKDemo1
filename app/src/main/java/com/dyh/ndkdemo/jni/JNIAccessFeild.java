package com.dyh.ndkdemo.jni;

import com.dyh.ndkdemo.util.Animal;

/**
 * describe: jni调用java类的属性
 * create by daiyh on 2021-2-24
 */
public class JNIAccessFeild {
    static {
        System.loadLibrary("native-lib");
    }

    public static int num;

    public native void accessStaticField(Animal animal);

    public native void accessInstanceField(Animal animal);

    public static native void staticAccessInstanceField();
}
