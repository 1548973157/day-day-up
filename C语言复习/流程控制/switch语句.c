#include <stdio.h>
int main() {
	
	/*switch后面跟圆括号，圆括号里面一般算术表达式，有一个整数结果
	通过空上整数结果去case语句去匹配相应的数值，决定执行哪个分支
	如果和所有的case都匹配不上，执行default分支
	注意：case只是表示一个分支的入口，switch后面花括号内所有语句都是内容。会从分支入口一进入
	如果需要只执行某一个分支就结束，就需要搭配break语句来使用
	if else if 和 switch 的区别
		if else if适用于范围表示 例：成绩的范围
		switch适用于值表示 例：游戏中W前进，A左移，‘1’释放技能
	*/
	
	int val;
	scanf_s("%d",&val);
	switch (val) {
	case 1:
		printf("1");
		break;
	case 2:
		printf("2");
		break;
	default:
		printf("other");	
		break;
	}//如果没有break会按顺序执行后续case及default
	
	return 0;
}
