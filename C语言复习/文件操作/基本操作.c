#include <stdlib.h>
#include <stdio.h>
/*
	程序文件：.c
	数据文件
		分为二进制文件，文本文件
	
	指向文件的指针
		FILE *p;
	
	文件相关操作通过库函数完成
		打开文件 fopen（fopen_s）
			打开模式：w只写      r只读       a追加
					  wb rb ab
					  w+ r+ a+
					  w 如果文件不存在，则创建文件，如果存在，把之前文件打开且内容清掉
					  r如果文件不存在，返回空的文件指针
					  a如果文件不存在，则创建文件，如果存在，打开文件。有文件之后定位到最后写入
		关闭文件 fclose
*/
/*
	当调用 fopen 或 fopen_s 时，操作系统会：
	
	在内存中创建一个 FILE 结构体，记录文件的读写状态、缓冲区等信息。
	
	返回该结构体的地址，赋值给 pf。
*/

int main(){
	FILE* pf = NULL;//pf 是一个指向 FILE 结构体的指针，后续会通过它读写文件。
	//pf = fopen("1.txt","w");
	fopen_s(&pf,"1.txt","w"); 
	fwrite("12345",5,1,pf);
	fclose(pf);
	
	return 0;
}
