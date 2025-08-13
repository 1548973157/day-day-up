#include <stdlib.h>
#include <stdio.h>
/*
	文件读写操作（读写要按照写入的顺序）
		fgetc	从文件读取一个字符
		fputc	向文件写入一个字符
		fgets	从文件读取一个字符串
		fputs	向文件写入一个字符串
		fprintf	格式化向文件写入数据
		fscanf	按格式化从文件读出数据
		fwrite	以二进制形式写入数据
		fread	以二进制形式读出数据
	
	相关函数
		fseek	文件定位（使文件内部指针指向文件中的某个位置）
			SEEK_SET文件起始位置
			SEEK_END文件末尾位置
			SEEK_CUR文件当前位置

		feof	检测文件是否到了末尾，如果文件到了末尾返回非零值，否则返回0
*/



int main(){
	FILE* pf = NULL;//pf 是一个指向 FILE 结构体的指针，后续会通过它读写文件。
	//pf = fopen("1.txt","w");
	fopen_s(&pf,"1.txt","w"); 
	fwrite("12345\n",6,1,pf);
	fputc('h',pf);
	fputs("\n ello\n",pf);
	int val = 100;
	double num = 3.14;
	fprintf(pf,"%d\n %lf\n",val,num);
	int val1 = 123;
	fwrite(&val1,4,1,pf);
	fclose(pf);
	
	pf = NULL;
	fopen_s(&pf,"1.txt","r"); 
	char c = 0;
	c = fgetc(pf);
	char arr[16] = {0};
	fgets(arr,6,pf);
	int val2 = 0;
	double num1 = 0.0;
	fscanf(pf,"%d\n %lf\n",&val2,&num1);
	int val3 = 0;
	fread(&val3,4,1,pf) ;
	fclose(pf);
	
	pf = NULL;
	fopen_s(&pf, "2. txt", "r");
	char arr1[16]= { 0 };
	int idx = 0;
	fseek(pf,5,SEEK_SET);//文件起始位置，往后偏移5个字符
	while(!feof(pf)){
		arr[idx++]=fgetc(pf); // 在调试中看
	}	
	fclose(pf);
 	return 0;

}
