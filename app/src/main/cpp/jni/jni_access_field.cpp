//
// Created by daiyh on 2021-2-24.
//
#include "base.h"

/**
 * JNI中数据类型的对应
 * | Java   | JNI |
 * |boolean | Z   |
 * |byte    | B   |
 * |char    | C   |
 * |short   | S   |
 * |int     | I   |
 * |long    | J   |
 * |float   | F   |
 * |double  | D   |
 */

/**
 * JNI中类型的对应
 * | Java     | JNI                  |
 * |String    | Ljava/lang/String;   |
 * |Class     | Ljava/lang/Class;    |
 * |Throwable | Ljava/lang/Throwable;|
 * |int[]     | [I                   |
 * |object[]  | [Ljava/lang/Object;  |
 */

extern "C"
JNIEXPORT void JNICALL
Java_com_dyh_ndkdemo_jni_JNIAccessFeild_accessStaticField(JNIEnv *env, jobject thiz,
                                                          jobject animal) {
    jclass cls = env -> GetObjectClass(animal);
    jfieldID fid = env -> GetStaticFieldID(cls, "num", "I");
    int num = env -> GetStaticIntField(cls, fid);
    env -> SetStaticIntField(cls, fid, ++ num);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_dyh_ndkdemo_jni_JNIAccessFeild_accessInstanceField(JNIEnv *env, jobject thiz,
                                                            jobject animal) {
    jclass cls = env -> GetObjectClass(animal);
    jfieldID fid = env -> GetFieldID(cls, "name", "Ljava/lang/String;");
    jstring str = env -> NewStringUTF("this is new name");
    env -> SetObjectField(animal, fid, str);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_dyh_ndkdemo_jni_JNIAccessFeild_staticAccessInstanceField(JNIEnv *env, jclass clazz) {
    jfieldID fid = env -> GetStaticFieldID(clazz, "num", "I");
    int num = env -> GetStaticIntField(clazz, fid);
    env -> SetStaticIntField(clazz, fid, ++ num);
}