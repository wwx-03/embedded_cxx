#pragma once

#include <log/segger/SEGGER_RTT.h>

#define LOG_DEBUG   1

#if LOG_DEBUG

#define LOG_INIT() SEGGER_RTT_Init()
#define LOG_CLEAR() SEGGER_RTT_WriteString(0, RTT_CTRL_CLEAR)

#define LOG(format,...) SEGGER_RTT_printf(0, format  RTT_CTRL_RESET, ##__VA_ARGS__)

#define LOGI(format,...) SEGGER_RTT_printf(0, RTT_CTRL_TEXT_BRIGHT_GREEN format  RTT_CTRL_RESET, ##__VA_ARGS__)
#define LOGW(format,...) SEGGER_RTT_printf(0, RTT_CTRL_TEXT_BRIGHT_YELLOW format  RTT_CTRL_RESET, ##__VA_ARGS__)

#define LOGI_ARRAY(prefix, array, size) do {												\
	LOGI(prefix ": ");																		\
	for (size_t i = 0; i < size; ++i) {														\
		SEGGER_RTT_printf(0, RTT_CTRL_TEXT_BRIGHT_GREEN "%02X " RTT_CTRL_RESET, array[i]);	\
	}																						\
	SEGGER_RTT_printf(0, "\r\n");															\
} while (0)

#else

#define LOG_CLEAR()
#define LOG(format,...)
#define LOGI(format,...)
#define LOGW(format,...)
#define LOGI_ARRAY(prefix, array, size)

#endif

#define LOGE(format,...) SEGGER_RTT_printf(0, RTT_CTRL_TEXT_BRIGHT_RED format  RTT_CTRL_RESET, ##__VA_ARGS__)
