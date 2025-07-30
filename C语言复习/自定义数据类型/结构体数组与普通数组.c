#include <stdio.h>
#include <string.h>
/*
	类型重定义：
		typedef：新类型名替换原有类型名	
		typedef 原类型名 新类型名；
			例：typedef int HP;//重定义int
				HP hp =10;
				printf("%d\n",hp);
*/
// 定义学生结构体
struct Student {
	int id;
	char name[20];
	float score;
}sd;//结构体中定义变量最好从大到小，避免内存对齐导致浪费

int main() {
	// 声明并初始化结构体数组
	struct Student sd[3]= {   //结构体数组sd[]={{101,"张三",85.5},{102,"李四",92.0},{103,"王五",76.5}};
		{101, "张三", 85.5},  //普通数组a[]={1,2,3}或{'张三','李四','王五'};
		{102, "李四", 92.0},
		{103, "王五", 76.5}
	};
	
	// 遍历数组
	for(int i = 0; i < 3; i++) {
		printf("学号:%d 姓名:%s 成绩:%.1f\n", 
			sd[i].id, sd[i].name, sd[i].score);
	}
	
	return 0;
}
