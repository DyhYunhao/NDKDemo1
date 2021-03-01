//
// Created by daiyh on 2021-2-22.
//

#include "jvm.h"
static JavaVM *gvm = nullptr;
#ifdef __cplusplus
extern "C" {
#endif
    void setJvm(JavaVM *jvm) {
        gvm = jvm;
    }

    JavaVM * getJvm() {
        return gvm;
    }

#ifdef __cplusplus
};
#endif