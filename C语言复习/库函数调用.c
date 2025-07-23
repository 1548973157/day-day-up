#include<stdio.h>
#include<string.h>//字符串处理库函数的头文件
/*
strlen求字符串的长度
strcpy_s字符串拷贝	
strcat_s字符串连接
strcmp字符串比较，返回0相等、返回1参数1大于参数2、返回-1参数2大于参数1（从第一位开始比，例如ZZL>ZYL）
strstr 求子串

1、函数什么功能
2、参数什么意思
3、返回值什么意思
*/
int main(void){
	char name[16]= "zhangsan";
	printf("%d\n", sizeof(name));
	printf("%d\n", strlen (name));
	printf("%s\n",name);//C语言格式化输出%s输出字符串
	gets(name);//字符串输入
	puts(name);//字符串的输出
	char cArr[32];
	//for (int i = 0; i < 16; ++i)
	// cArr[i]= name[i];
	
	
	strcpy_s(cArr, 16, name);//参数1表示目标的字符串，参数2表示拷贝多少字节，参数3表示资源的字符串
	puts(cArr);

	strcat_s(cArr, 32, "12345");	//参数1表示目标的字符串，连接到参数1的后面，参数2表示拷贝多少字节，参数3表示资源的字符串
		puts(cArr) ;
	
	printf("%s\n",strstr(name,"ngs"));
	return 0;
}
