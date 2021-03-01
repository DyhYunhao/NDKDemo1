#include <jni.h>
#include <string>
#include "people/People.h"
#include "base.h"

extern "C" JNIEXPORT jstring JNICALL
Java_com_dyh_ndkdemo_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from DEMO";

    People people;
    std::string hello1 = people.getString();
    return env->NewStringUTF(hello1.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_dyh_ndkdemo_MainActivity_getString(JNIEnv *env, jobject thiz) {
    // TODO: implement getString()
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_dyh_ndkdemo_jni_JNIBasicType_callNativeInt(JNIEnv *env, jobject thiz, jint num) {
    LOGD("java int value is %d", num);
    int c_num = num * 2;
    return c_num;
}

extern "C"
JNIEXPORT jbyte JNICALL
Java_com_dyh_ndkdemo_jni_JNIBasicType_callNativeByte(JNIEnv *env, jobject thiz, jbyte b) {
    LOGD("java byte value is %d", b);
    jbyte c_byte = b + (jbyte)10;
    return c_byte;
}

extern "C"
JNIEXPORT jchar JNICALL
Java_com_dyh_ndkdemo_jni_JNIBasicType_callNativeChar(JNIEnv *env, jobject thiz, jchar c) {
    LOGD("java char value is %c", c);
    jchar c_char = c + (jchar)3;
    return c_char;
}

extern "C"
JNIEXPORT jshort JNICALL
Java_com_dyh_ndkdemo_jni_JNIBasicType_callNativeShort(JNIEnv *env, jobject thiz, jshort s) {
    LOGD("java short value is %d", s);
    jshort c_short = s + (jshort)10;
    return c_short;
}

extern "C"
JNIEXPORT jlong JNICALL
Java_com_dyh_ndkdemo_jni_JNIBasicType_callNativeLong(JNIEnv *env, jobject thiz, jlong l) {
    LOGD("java long value is %lld", l);
    jlong c_long = l + 100;
    return c_long;
}

extern "C"
JNIEXPORT jfloat JNICALL
Java_com_dyh_ndkdemo_jni_JNIBasicType_callNativeFloat(JNIEnv *env, jobject thiz, jfloat f) {
    LOGD("java float value is %f", f);
    jfloat c_float = f + (jfloat)10.0;
    return c_float;
}

extern "C"
JNIEXPORT jdouble JNICALL
Java_com_dyh_ndkdemo_jni_JNIBasicType_callNativeDouble(JNIEnv *env, jobject thiz, jdouble d) {
    LOGD("java double value is %f", d);
    jdouble c_double = d + 20.0;
    return c_double;
}

extern "C"
JNIEXPORT jboolean JNICALL
Java_com_dyh_ndkdemo_jni_JNIBasicType_callNativeBoolean(JNIEnv *env, jobject thiz, jboolean bl) {
    LOGD("java boolean value is %d", bl);
    jboolean c_bool = (jboolean)bl;
    return c_bool;
}
