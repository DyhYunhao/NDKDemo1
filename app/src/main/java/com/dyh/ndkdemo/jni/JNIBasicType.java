package com.dyh.ndkdemo.jni;

/**
 * describe: java和JNI的基础数据类型转换
 * create by daiyh on 2021-2-23
 */
public class JNIBasicType {
    static {
        System.loadLibrary("native-lib");
    }

    public native int callNativeInt(int num);

    public native byte callNativeByte(byte b);

    public native char callNativeChar(char c);

    public native short callNativeShort(short s);

    public native long callNativeLong(long l);

    public native float callNativeFloat(float f);

    public native double callNativeDouble(double d);

    public native boolean callNativeBoolean(boolean bl);
}
