#include <stdlib.h>
#include <stdio.h>
/*
	指针函数：是一个函数，返回值是指针
	函数指针：是一个指针，返回值是函数
		函数名即函数首地址
	
	函数指针作为函数的参数（回调函数）,把函数作为参数的一部分
*/

int myAdd(int a,int b){
	return a + b;
}
int mySub(int a,int b){
	return a - b;
}

int fun(int a,int b,int (*myOp)(int ,int)){ //myOp在这里指函数，用的时候可以代表你定义的myAdd或者mySub
	return myOp(a,b);
}

int main(){
	printf("%d\n",myAdd(1,2));
	int (*pFun)(int a,int b) = NULL;//函数指针，指向所有返回值为int且有两个int形参的函数、
	pFun = myAdd;
	printf("%d\n",pFun(1,2));
	printf("%d\n",fun(10,2,myAdd));
	printf("%d\n",fun(10,2,mySub));
	
	return 0;
}
