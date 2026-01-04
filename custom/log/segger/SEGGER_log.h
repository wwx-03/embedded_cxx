#ifndef __LOG_H
#define __LOG_H

#include <log/segger/SEGGER_RTT.h>

#define LOG_DEBUG   1

#if LOG_DEBUG

#define LOG_PRINT(type,color,format,...)                    \
                SEGGER_RTT_printf(0,"%s%s" format "%s",     \
                                    color,                  \
                                    type,                   \
                                    ##__VA_ARGS__,          \
                                    RTT_CTRL_RESET)

/* 清屏*/
#define LOG_CLEAR() SEGGER_RTT_WriteString(0, RTT_CTRL_CLEAR)

/* 无颜色日志输出 */
#define LOG(format,...) LOG_PRINT("","",format,##__VA_ARGS__)

/* 有颜色格式日志输出 */
#define LOGI(format,...)    LOG_PRINT("LOG: ", RTT_CTRL_TEXT_BRIGHT_GREEN , format, ##__VA_ARGS__)
#define LOGW(format,...)    LOG_PRINT("WAR: ", RTT_CTRL_TEXT_BRIGHT_YELLOW, format, ##__VA_ARGS__)
#define LOGE(format,...)    LOG_PRINT("ERR: ", RTT_CTRL_TEXT_BRIGHT_RED   , format, ##__VA_ARGS__)

#else

#define LOG_CLEAR()
#define LOG(format,...)
#define LOGI(format,...)
#define LOGW(format,...)
#define LOGE(format,...)

#endif

#endif