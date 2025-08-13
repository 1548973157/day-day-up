#include <stdio.h>
/*
	1、指针作为函数的参数 => 址传递。在函数内部通过地址的间接操作可以操作外部实参
	2、函数的返回值类型为指针
*/

int myAdd(int* a,int* b){
	return *a + *b;
	
}

void mySwap(int* a,int* b){
	int c = *a;
	*a = *b;
	*b = c;
}
int main(){ 
	int a=1,b=2;
	printf("%d\n",myAdd(&a,&b));
	
	mySwap(&a,&b);
	printf("a = %d\tb = %d",a,b);
	
	return 0;
	
	
}
