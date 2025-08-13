#include <stdlib.h>
#include <stdio.h>
/*
	w+（写入+读取）
	行为：
		如果文件存在，清空文件内容（相当于重新创建）。
		如果文件不存在，创建新文件。
		初始指针位置：文件开头（0）。
	
	r+（读取+写入）
	行为：
		文件必须已存在，否则打开失败（返回 NULL）。
		保留原文件内容，写入时从指针位置覆盖数据（不会自动清空）。
		初始指针位置：文件开头（0）。

	a+（追加+读取）
	行为：
		如果文件存在，保留原内容，写入时始终追加到文件末尾（即使移动指针后写入也会跳到末尾）。
		如果文件不存在，创建新文件。
		初始指针位置：文件开头（可读取），但写入时强制跳到末尾。


	建议：文件操作时，尽量一次读一次写

*/
int main(){
	FILE* pf = NULL;
	fopen_s(&pf, "2.txt","r+");
	char* pArr ="12345";
	fwrite (pArr, 6, 1, pf);
		fclose(pf);
	/*
	FILE* pf = NULL;//pf 是一个指向 FILE 结构体的指针，后续会通过它读写文件。
	fopen_s(&pf,"3.txt","wb");//以二进制模式（"wb"）向文件 3.txt 写入数据
	int num = 999;
	fwrite(&num,4,1,pf);// 写入4字节的二进制整数
	char* pArr = "abcde";
	fwrite(pArr,strlen(pArr)+1,1,pf);
	*/

	
	/*
	fopen_s(&pf,"2.txt","a"); 
	char* pArr = "12345";
	fwrite(pArr,strlen(pArr)+1,1,pf);
	*/

	fclose(pf);
	
	return 0;
}
