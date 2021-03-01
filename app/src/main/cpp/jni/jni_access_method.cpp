//
// Created by daiyh on 2021-2-24.
//
#include "base.h"

extern "C"
JNIEXPORT void JNICALL
Java_com_dyh_ndkdemo_jni_JNIAccessMethod_accessInstanceMethod(JNIEnv *env, jobject thiz,
                                                              jobject animal) {
    jclass cls = env->GetObjectClass(animal);
    jmethodID mid = env->GetMethodID(cls, "callInstanceMethod", "(I)V");
    env->CallVoidMethod(animal, mid, 2);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_dyh_ndkdemo_jni_JNIAccessMethod_accessStaticMethod(JNIEnv *env, jobject thiz,
                                                            jobject animal) {
    jclass cls = env->GetObjectClass(animal);
    jmethodID mid = env->GetStaticMethodID(cls, "callStaticMethod",
                                           "(Ljava/lang/String;)Ljava/lang/String;");
    jstring str = env->NewStringUTF("jstring");
    env->CallStaticObjectMethod(cls, mid, str);

    jmethodID mid2 = env->GetStaticMethodID(cls, "callStaticMethod",
                                            "([Ljava/lang/String;I)Ljava/lang/String;");
    jclass strClass = env -> FindClass("java/lang/String");
    int size = 2;
    jobjectArray strArray = env -> NewObjectArray(size, strClass, nullptr);

    jstring strItem;
    for (int i = 0; i < size; ++ i) {
        strItem = env -> NewStringUTF("string in native");
        env -> SetObjectArrayElement(strArray, i, strItem);
    }
    env -> CallStaticObjectMethod(cls, mid2, strArray, size);
}
