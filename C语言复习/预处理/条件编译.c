/*


#if ... #else ... #endif
#ifdef ... #else ... #endif
#ifndef ... #else ... #endif

*/
/*
	条件编译
	#include <stdio.h>

	#define VERSION 2
	
	int main() {
		#if VERSION == 1
			printf("Running Version 1\n");
		#elif VERSION == 2
			printf("Running Version 2\n");  // 这行会被编译
		#else
			printf("Running Unknown Version\n");
		#endif
	
		return 0;
	}

*/
/*
	检查宏是否未定义
	#include <stdio.h>
	
	// 这里没有定义 LOG_DISABLE
	
	int main() {
		#ifndef LOG_DISABLE
			printf("Logging is active\n");  // 这行会被编译
		#else
			printf("Logging is disabled\n");
		#endif
	
		return 0;
	}
*/
/*
	头文件保护
	// myheader.h
	#ifndef MYHEADER_H  // 如果未定义这个宏
	#define MYHEADER_H  // 则定义它
	
	// 头文件内容...
	void important_function();
	
	#endif             // 结束条件编译
*/
