#include <stdio.h>

//函数中允许嵌套调用。主调函数与被调函数的关系
//被调应该在主调之前要有定义或声明
//函数不能嵌套定义
void bFun(void);

void aFun(void){ //主调函数
	bFun();//被调函数
	//void cFun(void){          不能嵌套定义	
	//}
}
void bFun(void){
	
}
int myfun(int n);

int main(){
	printf("%d\n",myfun(5));
	return 0;
}

//函数的递归调用
//主调函数在函数体内直接或者间接调用了该主调函数
//1、递归函数带参数，通过参数来判断递归是否结束
int myfun(int n){
	if(1>=n) return n; //递归结束条件
	return n*myfun(n-1);	
}
