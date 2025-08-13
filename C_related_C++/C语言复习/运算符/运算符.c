#include <stdio.h>

int main() {
/*
赋值相关
=表示赋值，把右边的值，赋值给到左边
+= -= *= >>= <<= ^=
	例 a ^= 3; => a = a ^ 3;
sizeof求内存大小
	
'?:'条件运算符 三目
	操作数1，表示真假，如果为真，执行操作数2;如果为假，执行操作数3

','逗号运算符	
	从左至右执行
*/
	int a = 10;
	printf("%d\n",sizeof(int));	//sizeof运算符，括号里给类型
	printf("%d\n",sizeof(a));	//sizeof运算符，括号里给变量
	printf("%d\n",sizeof(3.14));	//sizeof运算符，括号里给常量
	
	int b = 20;
	int max;
	(a>b) ? (max = a) : (max = b);
	printf("%d\n",max);	//
	
	int x,y,z;
	z=(x=2,y=4,x+y);
	printf("%d\n",z);	
	
	/*
	先乘除再加减，优先级
	在编程过程中习惯用圆括号去括上先算的，就能避免去记忆优先级
	结合性
	从哪边开始计算
	大部分都是左结合性。只有三类是从右往左
	单目，赋值，三目
	*/

	return 0;
}

