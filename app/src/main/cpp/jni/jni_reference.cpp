//
// Created by daiyh on 2021-2-25.
//
#include "base.h"

extern "C"
JNIEXPORT jstring JNICALL
Java_com_dyh_ndkdemo_jni_JNIReference_errorCacheLocalReference(JNIEnv *env, jobject thiz) {
    //局部引用
    jclass localRefs = env -> FindClass("java/lang/String");
    jmethodID mid = env -> GetMethodID(localRefs, "<init>", "(Ljava/lang/String;)V");
    jstring str = env -> NewStringUTF("string");

    //局部引用超过512最好手动释放
    for (int i = 0; i < 1000; ++ i) {
        jclass cls = env -> FindClass("java/lang/String");
        env -> DeleteLocalRef(cls);
    }

    return static_cast<jstring>(env->NewObject(localRefs, mid, str));
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_dyh_ndkdemo_jni_JNIReference_cacheWithGlobalReference(JNIEnv *env, jobject thiz) {
    // 全局引用
    static jclass stringClass = nullptr;
    if (stringClass == nullptr) {
        jclass cls = env -> FindClass("java/lang/String");
        stringClass = static_cast<jclass>(env -> NewGlobalRef(cls));
        env -> DeleteLocalRef(cls);
    } else {
        LOGD("use cached");
    }

    jmethodID mid = env -> GetMethodID(stringClass, "<init>", "(Ljava/lang/String;)V");
    jstring str = env -> NewStringUTF("string");
    return static_cast<jstring>(env -> NewObject(stringClass, mid, str));

}

extern "C"
JNIEXPORT void JNICALL
Java_com_dyh_ndkdemo_jni_JNIReference_useWeakGlobalReference(JNIEnv *env, jobject thiz) {
    static jclass stringClass = nullptr;
    if (stringClass == nullptr) {
        jclass cls = env -> FindClass("java/lang/String");
        stringClass = static_cast<jclass>(env -> NewWeakGlobalRef(cls));
        env -> DeleteLocalRef(cls);
    } else {
        LOGD("use cached");
    }

    jmethodID mid = env -> GetMethodID(stringClass, "<init>", "(Ljava/lang/String;)V");
    jboolean isGC = env -> IsSameObject(stringClass, nullptr);
}