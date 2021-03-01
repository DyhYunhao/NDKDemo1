//
// Created by daiyh on 2021-2-22.
//

#ifndef NDKDEMO_JVM_H
#define NDKDEMO_JVM_H
#include "base.h"

#ifdef __cplusplus
extern "C" {
#endif

void setJvm(JavaVM *jvm);

JavaVM *getJvm();

#ifdef __cplusplus
}
#endif

#endif //NDKDEMO_JVM_H
