package com.dyh.ndkdemo.jni;

import com.dyh.ndkdemo.util.Animal;

/**
 * describe: c++调用java类的方法
 * create by daiyh on 2021-2-24
 */
public class JNIAccessMethod {

    static {
        System.loadLibrary("native-lib");
    }

    public native void accessInstanceMethod(Animal animal);

    public native void accessStaticMethod(Animal animal);

}
