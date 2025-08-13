#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct MyStu{
	int id;
	char* pName;
};

int main(){
	struct MyStu ms;//在栈区占用内存
	ms.id = 1001;
	//ms.pName = "zhangsan";//有两个内存区块，pName在ms区内，在栈区。“zhangsan”在ms区外，在全局数据区
	ms.pName = (char*)malloc(sizeof(char)*32);//pName在栈区，malloc分配的内存在堆区
	strcpy(ms.pName,"lisi");
	free(ms.pName);
	printf("%d\n",sizeof(char*));//64位系统中，内存地址用64位（8字节）表示，因此所有指针类型（包括char*、int*等）的大小都是8字节。
	
	struct MyStu* pMs;//结构指针，可以指向一个结构变量的内存地址
	pMs = &ms;
	pMs->id = 1002;//指针可以通过 -> 运算符访问结构成员
	return 0;
	
}
