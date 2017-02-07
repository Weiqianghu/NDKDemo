//
// Created by huweiqiang on 2017/1/23.
//

#ifndef NDKDEMO_LOG_H
#define NDKDEMO_LOG_H

#endif //NDKDEMO_LOG_H

#include <android/log.h>

#define  LOG    "JavaCallCDemoLog" // 这个是自定义的LOG的标识
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG,__VA_ARGS__) // 定义LOGD类型
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG,__VA_ARGS__) // 定义LOGI类型
#define  LOGW(...)  __android_log_print(ANDROID_LOG_WARN,LOG,__VA_ARGS__) // 定义LOGW类型
#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG,__VA_ARGS__) // 定义LOGE类型
#define LOGF(...)  __android_log_print(ANDROID_LOG_FATAL,LOG,__VA_ARGS__) // 定义LOGF类型