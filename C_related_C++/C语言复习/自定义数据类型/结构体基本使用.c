
/*
结构体语法
struct MyPoint{
	//成员列表
	int x;
	int y;
};

struct MyPoint{
//成员列表
int x;
int y;
}MP ={1，2};//可以这样用

*/
//1、定义类型，通过类型给出变量
//2、定义类型的同时，给出变量.18行的ms就是定义类型的同时，给出结构变量
//3、定义类型时，如果给出变量名，可以缺省类型名
//注意：无类型名，只能通过变量名去操作，无法通过类型去定义新的变量
//结构体变量的初始化赋值（在定义结构体变量的同时依次给成员列表中的数据赋初值）
#include <stdio.h>
#include <string.h>

// 定义结构体类型
struct Student {
	int id;          // 学号
	char name[20];   // 姓名
	float score;     // 成绩
}; // 注意分号

int main() {
	// 结构体变量声明与初始化
	struct Student stu1 = {101, "张三", 85.5};
	
	// 访问结构体成员
	printf("学号: %d\n", stu1.id);
	printf("姓名: %s\n", stu1.name);
	printf("成绩: %.1f\n", stu1.score);
	
	// 修改结构体成员
	stu1.score = 90.0;
	strcpy(stu1.name, "张小三");
	
	return 0;
}
