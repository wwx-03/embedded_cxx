#pragma once

#include <log/segger/SEGGER_log.h>

namespace custom {

class log {

	template<typename... Args>
	static void information(const char *const fmt, Args... args) {
		
	}
	
	template<typename... Args>
	static void warning(const char *const fmt, Args... args) {
		
	}
	
	template<typename... Args>
	static void error(const char *const fmt, Args... args) {
		
	}
};

};

