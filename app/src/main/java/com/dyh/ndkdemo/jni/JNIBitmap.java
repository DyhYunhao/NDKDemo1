package com.dyh.ndkdemo.jni;

import android.graphics.Bitmap;

/**
 * describe: jni操作bitmap
 * create by daiyh on 2021-3-1
 */
public class JNIBitmap {

    static {
        System.loadLibrary("native-lib");
    }

    public native Bitmap callNativeMirrorBitmap(Bitmap bitmap);

}
