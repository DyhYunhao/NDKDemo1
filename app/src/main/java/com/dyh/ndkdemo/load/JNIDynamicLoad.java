package com.dyh.ndkdemo.load;

/**
 * describe: jni的动态注册
 * create by daiyh on 2021-2-22
 */
@SuppressWarnings("ALL")
public class JNIDynamicLoad {

    static {
         System.loadLibrary("dynamic-lib");
    }

    public native int sum(int x, int y);
    public native String getNativeString();

}
