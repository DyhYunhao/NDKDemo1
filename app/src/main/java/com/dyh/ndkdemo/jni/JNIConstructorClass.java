package com.dyh.ndkdemo.jni;

import com.dyh.ndkdemo.util.Animal;

/**
 * describe: JNI创建java类
 * create by daiyh on 2021-2-25
 */
public class JNIConstructorClass {
    static {
        System.loadLibrary("native-lib");
    }

    public native Animal invokeAnimalConstructors();

    public native Animal allocObjectConstructor();

}
