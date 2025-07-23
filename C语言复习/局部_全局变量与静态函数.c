#include <stdio.h>
int num = 0;//全局变量
int myAdd(int a,int b){
	int c = a + b;//局部变量
	c += 20;
	return a+b;
}

//static 静态
//静态变量 static 数据类型变量名；
//静态函数   static函数返回值类型函数名（形参表){} 静态函数只能在当前文件使用例如static void add(){}

int main(){
	num+=20;
	printf("%d\n",num);
	for(int i=0;i<10;++i){
		//int val=0;
		//printf("%d\n",val++);//输出为0，因为val是局部变量，一次循环后val被释放，又重新定义为1
		static int val1 = 0; //static只在第一次初始化
		printf("%d\n",val1++);
	}
	return 0;
}
