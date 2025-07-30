#include <stdio.h>
/*
	枚举：穷举，把可能的值一一列出来
	相当于让范围受限

*/

enum WeedDay{
	
sun,mon,tue,wen,thu,fri,sat	
};//成员列表为值列表，也叫枚举元素列表
//默认第1个值为整数0，后面每一个的值是前面值的结果+1
//且在列出枚举元素表时，可以显式直接赋值

int main(void){
	enum WeedDay wd = sun;//变量的结果在值列表内
	printf("%d\n",fri);
	switch (wd) { //
	case sun:
		//TODO
		break;
	case mon:
		//TODO
		break;
	default:
		//TODO
		break;
	}
	return 0;
}
