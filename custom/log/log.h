#pragma once

#include <log/segger/SEGGER_log.h>

#ifndef LOG_INIT
#define LOG_INIT()
#endif

#ifndef LOG_CLEAR
#define LOG_CLEAR()
#endif

#ifndef LOG
#define LOG(fmt, ...)
#endif

#ifndef LOGI
#define LOGI(fmt, ...)
#endif

#ifndef LOGW
#define LOGW(fmt, ...)
#endif

#ifndef LOGE
#define LOGE(fmt, ...)
#endif
