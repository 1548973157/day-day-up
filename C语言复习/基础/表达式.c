#include <stdio.h>

int main() {
/*表达式是通过运算符将变量及常量结合而成
	变量或常量在表示表达式时，在通过运算符结合时，如果类型不一致？
	通过运算符结合时，如果操作数类型不一致，会发生类型转换
	类型转换：
		自动转换 小类型转大类型
		强制转换 大类型转小类型
			（类型名）=>表示强制转换
		对于基本数据类型，vs会自动帮助实现强制转换，但建议还是加上强制转换的表示
	
	语句分类：
	1、空语句
	2、表达式语句 a += 2;val++;
	x+y；注意：这个是语句，语法没有错，但不是有用的语句
	3、函数调用语句
	printf
	%d格式化输出整数，%f输出浮点数，%c输出字符
	scanf
	格式化输入，需要注意，若该函数语句不安全，使用scanf_s;输入时阻塞，等待用户输入
	*/
	int a = 10;
	a = a + 2.0; // double转换到int 大类型转小类型
	a = a + (int)2.0; //强制转换
	
	char b = 100;
	a = a + b;//小类型转大类型
	
	return 0;
}
