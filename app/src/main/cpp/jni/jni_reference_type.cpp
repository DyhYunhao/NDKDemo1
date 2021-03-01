//
// Created by daiyh on 2021-2-23.
//

#include "base.h"

//对于基本数据类型，java中的数据类型对应native中的数据类型需要加上j的前标，如java中int对应native中的jint
//对于引用类型，对象和类，对应加上j，如：java中的Object对应native中的jobject
//对于数组引用，则对应native中的：j基本类型Array,如java的char[]对应native的jcharArray

extern "C"
JNIEXPORT jstring JNICALL
Java_com_dyh_ndkdemo_jni_JNIReferenceType_callNativeStringArray(JNIEnv *env, jobject thiz,
                                                                jobjectArray str_array) {
    int len = env -> GetArrayLength(str_array);
    LOGD("len is %d", len);

    jstring firstStr = static_cast<jstring>(env->GetObjectArrayElement(str_array, 0));
    const char *str = env -> GetStringUTFChars(firstStr, 0);
    LOGD("first str is %s", str);
    env -> ReleaseStringUTFChars(firstStr, str);
    return env -> NewStringUTF(str);
}