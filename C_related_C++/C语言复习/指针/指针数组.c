#include <stdlib.h>
#include <stdio.h>
/*
	指针数组：是一个数组，数组里的元素是指针
*/

int main(){
	int a = 1;
	int arr[4] = {2};
	int* pArr[4] = {0};//指针数组，数组里有3个 int* 指针元素
	
	pArr[0] = &a;
	pArr[1] = (int*)malloc(sizeof(int)*4);
	pArr[2] = arr;
	
	printf("%p\n",pArr[0]);
	printf("%p\n",pArr[1]);
	printf("%d\n",*pArr[2]);
	
	//动态二维数组
	int row = 3,col = 4;
	int** p= (int**)malloc(sizeof(int*) * row);//右边表示在堆区分配了row个int*的连续内存（堆内存动态的指针数组）
	for(int i=0;i<row;i++){
		*(p+i) = (int*)malloc(sizeof(int) * col);//TODO
	};

	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			*(*(p+i)+j) = i * col + j + 1;
		};
	};
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			printf("%d\t",*(*(p+i)+j));
		};
		printf("\n");
	};

	char* pName[3]={"zhangsan","1isi","wangwu"};//指针数组，字符串数组
	printf("%s\n", pName[0]);//pName[0] 指向字符串常量 "zhangsan" 的首地址
	return 0;
}
