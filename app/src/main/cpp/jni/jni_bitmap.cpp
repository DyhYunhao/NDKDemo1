//
// Created by daiyh on 2021-3-1.
//
#include <locale>
#include <regex>
#include <__locale>
#include "base.h"
#include "android/bitmap.h"
#include "cstring"

jobject generateBitmap(JNIEnv *pEnv, uint32_t width, uint32_t height);

extern "C"
JNIEXPORT jobject JNICALL
Java_com_dyh_ndkdemo_jni_JNIBitmap_callNativeMirrorBitmap(JNIEnv *env, jobject thiz,
                                                          jobject bitmap) {
    AndroidBitmapInfo bitmapInfo;
    AndroidBitmap_getInfo(env, bitmap, &bitmapInfo);
    LOGD("width is %d", bitmapInfo.width);
    LOGD("height is %d", bitmapInfo.height);

    void *bitmapPixels;
    AndroidBitmap_lockPixels(env, bitmap, &bitmapPixels);
    uint32_t newWidth = bitmapInfo.width;
    uint32_t newHeight = bitmapInfo.height;

    uint32_t *newBitmapPixels = new uint32_t[newWidth * newHeight];

    int whereToGet = 0;
    for (int y = 0; y < newHeight; ++y) {
        for (int x = newWidth - 1; x >= 0; x--) {
            uint32_t pixel = ((uint32_t *) bitmapPixels)[whereToGet++];
            newBitmapPixels[newWidth * y + x] = pixel;
        }
    }

    AndroidBitmap_unlockPixels(env, bitmap);

    jobject newBitmap = generateBitmap(env, newWidth, newHeight);

    void *resultBitmapPixels;
    AndroidBitmap_lockPixels(env, newBitmap, &resultBitmapPixels);
    memcpy((uint32_t *) resultBitmapPixels, newBitmapPixels,
           sizeof(uint32_t) * newWidth * newHeight);
    AndroidBitmap_unlockPixels(env, newBitmap);
    delete[] newBitmapPixels;

    return newBitmap;
}

jobject generateBitmap(JNIEnv *env, uint32_t width, uint32_t height) {
    jclass bitmapCls = env->FindClass("android/graphics/Bitmap");
    jmethodID createBitmapFunction = env->GetStaticMethodID(bitmapCls,
                                                            "createBitmap",
                                                            "(IILandroid/graphics/Bitmap$Config;)Landroid/graphics/Bitmap;");
    jstring configName = env->NewStringUTF("ARGB_8888");
    jclass bitmapConfigClass = env->FindClass("android/graphics/Bitmap$Config");
    jmethodID valueOfBitmapConfigFunction = env->GetStaticMethodID(
            bitmapConfigClass, "valueOf",
            "(Ljava/lang/String;)Landroid/graphics/Bitmap$Config;");

    jobject bitmapConfig = env->CallStaticObjectMethod(bitmapConfigClass,
                                                       valueOfBitmapConfigFunction, configName);

    jobject newBitmap = env->CallStaticObjectMethod(bitmapCls,
                                                    createBitmapFunction,
                                                    width,
                                                    height, bitmapConfig);

    return newBitmap;
}

