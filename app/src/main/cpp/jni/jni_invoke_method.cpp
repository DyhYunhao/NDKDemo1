//
// Created by daiyh on 2021-2-24.
//

#include "base.h"
#include "jvm.h"
#include "pthread.h"

void *threadCallback(void *);

static jclass threadClazz;
static jmethodID threadMethod;
static jobject threadObject;

extern "C"
JNIEXPORT void JNICALL
Java_com_dyh_ndkdemo_jni_JNIInvokeMethod_nativeCallback(JNIEnv *env, jobject thiz,
                                                        jobject callback) {
    LOGD("native callback");
    jclass callbackClazz = env -> GetObjectClass(callback);
    jmethodID callbackMethod = env -> GetMethodID(callbackClazz, "callback", "()V");
    env -> CallVoidMethod(callback, callbackMethod);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_dyh_ndkdemo_jni_JNIInvokeMethod_nativeThreadCallback(JNIEnv *env, jobject thiz,
                                                              jobject callback) {
    threadObject = env -> NewGlobalRef(callback);
    threadClazz = env -> GetObjectClass(callback);
    threadMethod = env -> GetMethodID(threadClazz, "callback", "()V");
    pthread_t handle;
    pthread_create(&handle, nullptr, threadCallback, nullptr);
}

void *threadCallback(void *) {
    JavaVM *gVM = getJvm();
    JNIEnv *env = nullptr;
    if (gVM -> AttachCurrentThread(&env, nullptr) == 0) {
        env -> CallVoidMethod(threadObject, threadMethod);
        gVM -> DetachCurrentThread();
    }
    return JNI_OK;
}