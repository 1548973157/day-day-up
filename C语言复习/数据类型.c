#include <stdio.h>
/*数据类型分类
	整型  10
		short 2字节
		int 4字节
		long 4字节
	浮点型  10.8
		float 4字节
		double 8字节	
	字符型  'A' 'a'
	char 1字节  ***可以用做小整型 例：char age 通过字符的AC码来输出年龄***

	所占内存大小
	电脑中最小单位（位）bit		数值非0即1
	最小储存单位（字节）byte	1byte = 8bit	可表示0~255    共256数据	
	例：8GB = 8*1024MB
		1MB = 1*1024KB
		1KB = 1024B(byte)

*/

int main()
{
	printf("short = %d\n",sizeof(short));
	printf("int = %d\n",sizeof(int));
	printf("long = %d\n",sizeof(long));
	printf("float = %d\n",sizeof(float));
	printf("double = %d\n",sizeof(double));
	
	for(int i=0;i<=128;++i){
		printf("%d = %c\n",i,i);		
	}
	return 0;
}

