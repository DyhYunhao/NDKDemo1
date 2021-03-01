//
// Created by daiyh on 2021-2-23.
//

#include "base.h"
#include "string"

extern "C"
JNIEXPORT jstring JNICALL
Java_com_dyh_ndkdemo_jni_JNIString_callNativeString(JNIEnv *env, jobject thiz, jstring str) {
    // Java 的字符串并不能直接转成 C/C++ 风格的字符串
    // 需要用到 GetStringChars 或者 GetStringUTFChars 相应的函数来申请内存
    // 转成一个指向 JVM 地址的指针
    // 最后还要释放该指针的内存
    const char * str_ = env -> GetStringUTFChars(str, 0);
    LOGD("java string  is %s",str_);
    // Get 和 Release 要配套使用，避免内存泄漏
    env -> ReleaseStringUTFChars(str, str_);

    // 从 Native 返回字符串，将 C/C++ 风格的字符串返回到 Java 层
    // 也需要用到特定的函数来转换 NewStringUTF 或者 NewString 等
    const char *c_str = "this is C style string";
//    env->GetStringRegion()
    return env->NewStringUTF(c_str);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_dyh_ndkdemo_jni_JNIString_stringMethod(JNIEnv *env, jobject thiz, jstring jstr) {
    const char *str = env->GetStringUTFChars(jstr, 0);
    char buf[128];
    int len = env -> GetStringLength(jstr);
    LOGD("java string length is %d", len);

    env -> GetStringUTFRegion(jstr, 0, len - 1, buf);

    LOGD("jstring is %s", buf);

    env -> ReleaseStringUTFChars(jstr, str);
}


