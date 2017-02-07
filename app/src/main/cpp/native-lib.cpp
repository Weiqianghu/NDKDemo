#include <jni.h>
#include <string>
#include <iostream>
#include "log.h"


extern "C" {
JNIEXPORT jstring JNICALL
Java_com_huweiqiang_ndkdemo_MainActivity_sayHello(JNIEnv *env, jobject instance, jstring name_) {
    jsize len = env->GetStringLength(name_);
    LOGD("name length: %d\n", len);
    char buff[128] = "Hello ";
    char *pBuff = buff + 6;
    env->GetStringUTFRegion(name_, 0, len, pBuff);
    return env->NewStringUTF(buff);
}

JNIEXPORT jobjectArray JNICALL
Java_com_huweiqiang_ndkdemo_MainActivity_initInt2DArray(JNIEnv *env, jobject instance, jint size) {
    jobjectArray result;
    jclass clsIntArray;
    jint i, j;
    // 1.获得一个int型二维数组类的引用
    clsIntArray = env->FindClass("[I");
    if (clsIntArray == NULL) {
        return NULL;
    }
    // 2.创建一个数组对象（里面每个元素用clsIntArray表示）
    result = env->NewObjectArray(size, clsIntArray, NULL);
    if (result == NULL) {
        return NULL;
    }

    // 3.为数组元素赋值
    for (i = 0; i < size; ++i) {
        jint buff[256];
        jintArray intArr = env->NewIntArray(size);
        if (intArr == NULL) {
            return NULL;
        }
        for (j = 0; j < size; j++) {
            buff[j] = i + j;
        }
        env->SetIntArrayRegion(intArr, 0, size, buff);
        env->SetObjectArrayElement(result, i, intArr);
        env->DeleteLocalRef(intArr);
    }

    return result;
}

JNIEXPORT jint JNICALL
Java_com_huweiqiang_ndkdemo_MainActivity_sumArray(JNIEnv *env, jobject instance, jintArray array_) {
    jint *array = env->GetIntArrayElements(array_, NULL);
    if (array == NULL) {
        return 0;
    }


    jint length = env->GetArrayLength(array_);
    jint sum = 0;
    for (jint i = 0; i < length; i++) {
        sum += array[i];
    }
    env->ReleaseIntArrayElements(array_, array, 0);
    return sum;
}

jstring
Java_com_huweiqiang_ndkdemo_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
}
