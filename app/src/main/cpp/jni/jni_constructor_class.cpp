//
// Created by daiyh on 2021-2-25.
//
#include "base.h"

extern "C"
JNIEXPORT jobject JNICALL
Java_com_dyh_ndkdemo_jni_JNIConstructorClass_invokeAnimalConstructors(JNIEnv *env, jobject thiz) {
    jclass cls = env -> FindClass("com/dyh/ndkdemo/util/Animal");
    jmethodID mid = env -> GetMethodID(cls, "<init>", "(Ljava/lang/String;)V");
    jstring str = env -> NewStringUTF("this is animal name");
    jobject obj = env -> NewObject(cls, mid, str);
    return obj;
}

extern "C"
JNIEXPORT jobject JNICALL
Java_com_dyh_ndkdemo_jni_JNIConstructorClass_allocObjectConstructor(JNIEnv *env, jobject thiz) {
    jclass cls = env -> FindClass("com/dyh/ndkdemo/util/Animal");
    jmethodID mid = env -> GetMethodID(cls, "<init>", "(Ljava/lang/String;)V");
    jstring str = env -> NewStringUTF("this is animal name 2");
    jobject obj = env -> AllocObject(cls);
    env -> CallNonvirtualVoidMethod(obj, cls, mid, str);
    return obj;
}