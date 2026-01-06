#pragma once

#include <log/segger/SEGGER_RTT.h>

#define LOG_DEBUG   1

#if LOG_DEBUG

#define LOG_INIT() SEGGER_RTT_Init()
#define LOG_CLEAR() SEGGER_RTT_WriteString(0, RTT_CTRL_CLEAR)

#define LOG(format,...) SEGGER_RTT_printf(0, format  RTT_CTRL_RESET, ##__VA_ARGS__)

#define LOGI(format,...) SEGGER_RTT_printf(0, RTT_CTRL_TEXT_BRIGHT_GREEN "LOG: " format  RTT_CTRL_RESET, ##__VA_ARGS__)
#define LOGW(format,...) SEGGER_RTT_printf(0, RTT_CTRL_TEXT_BRIGHT_YELLOW "WAR: " format  RTT_CTRL_RESET, ##__VA_ARGS__)
#define LOGE(format,...) SEGGER_RTT_printf(0, RTT_CTRL_TEXT_BRIGHT_RED "ERR: " format  RTT_CTRL_RESET, ##__VA_ARGS__)

#else

#define LOG_CLEAR()
#define LOG(format,...)
#define LOGI(format,...)
#define LOGW(format,...)
#define LOGE(format,...)

#endif
