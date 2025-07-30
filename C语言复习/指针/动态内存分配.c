#include <stdlib.h>
#include <stdio.h>
/*
	动态内存分配：
		程序员根据需求，向系统主动申请所需大小的内存空间
	
	头文件 stdlib.h

	操作相关函数
		malloc   分配一个大小为size的内存区域
		calloc   分配N个大小为size的连续内存区域
		realloc  重新分配通过malloc或calloc开辟的内存空间，改变其内存空间大小
		free     用于释放动态内存空间（上述三个函数）

	动态内存分配的内存在堆区
		堆区的内存由程序员主动分配，也应该由程序员主动释放

	数据在内存中无类型，使用内存数据时，通过类型去内存中取相应的内存大小的值，转成类型的数据

*/
int main(){
	int* p=NULL;
	p =(int*)malloc(sizeof(int));//分配一个4字节大小的内存区域，把首地址当成int*地址赋值给到P
	*p = 123;
	printf("%d\n",*p);
	free(p);
	
	int* q=NULL;
	q =(int*)calloc(4,sizeof(int));//q相当于指向了一个没有名字的数组
	q[0]=1;
	q[1]=2;
	for(int i=0;i<=3;i++){
		printf("%d\t",*(q+i));//TODO
	}
	printf("\n");
	
	realloc(q,sizeof(int)*10);
	q[6]=666;
	q[9]=999;
	for(int i=0;i<=9	;i++){
		printf("%d\t",*(q+i));//TODO
	}
	free(q);
	
	int a =4407873;
	printf("\n%s",(char*)&a);//&a 获取 a 的 内存地址，类型是 int*（指向整型的指针）、(char*)&a 将这个指针强制转换为 char*（指向字符的指针）
    //告诉你，数据在内存中无类型，怎么用是程序员的事
	return 0;
}
