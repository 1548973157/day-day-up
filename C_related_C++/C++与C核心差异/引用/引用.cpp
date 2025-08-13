// 引用.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 

#include <iostream>
using namespace std;  // 引入 std 命名空间
int main()
{
	int ABCDEFG = 100; // 定义一个整型变量 ABCDEFG
	int &A = ABCDEFG;// 引用变量 A 引用 ABCDEFG
	
	// 引用必须初始化，且一旦引用了某个变量，就不能再引用其他变量

	cout << A << endl; // 输出 ABCDEFG
	A = 123;           // 修改 A 的值，实际上是修改 ABCDEFG 的值
	cout << ABCDEFG << endl; // 输出 123
	// 引用必须初始化，且一旦引用了某个变量，就不能再引用其他变量
	// 引用本质上是一个变量的别名，对引用的操作实际上是对原变量的操作
	return 0;
}
