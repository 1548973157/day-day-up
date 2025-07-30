#include <stdio.h>
/*
	数组名即数组首地址
		可以把数组名赋给指针，通过指针的方式访问数据（数组名怎么使用，可以直接替换成指针名）
	
	指针名[下标]=>*（指针名+整数）
	指针偏移：
		指针在一定范围之内可以偏移，通过+整数的方式进行偏移
		+整数相当于+sizeof（类型）*整数
*/
int main(){
	int arr[5]={1,2,3,4,5};
	arr[0]=12;
	int* p = arr;//数组首地址赋给一个指针，指针可以指向int类型的数据
	p[0] = 123; 
	for(int i=0;i<=4;i++){
		//printf("%d\n",arr[i]);//正常输出数组
		printf("%d\t",p[i]);//指针
	}
	printf("\n");
	
	p = &arr[2];
	*p = 666;
	for(int i=0;i<=4;i++){
		//printf("%d\n",p[i]);//指针偏移
		printf("%d\t",*(p+i));//指针偏移  建议这种写法	
	}//输出从666开始、4、5后面的数据就乱了
	printf("\n");
	
	
	p = p - 2;
	for(int i=0;i<=4;i++){
		printf("%d\t",*(p+i));
	}//显示正常了
	printf("\n\n");
	
	char* ABC = "abcdefg";
	printf("%s\n",ABC);
	while(*ABC){
		printf("%c\t",*(ABC++));		
	}
	return 0;
}
