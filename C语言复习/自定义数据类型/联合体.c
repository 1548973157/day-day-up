/*
	联合体(union)基本使用示例
	  
	联合体特点：
	1. 所有成员共享同一块内存空间
	2. 内存大小由最大成员决定
	3. 同一时间只能有效存储一个成员的值
	4. 修改一个成员会影响其他成员的值
	
	典型应用场景：
	- 类型转换
	- 硬件寄存器访问
	- 协议数据解析
 */
#include <stdio.h>
#include <string.h>

// 定义一个联合体
union Data {
	int i;      // 4字节
	float f;    // 4字节
	char str[4];// 4字节
}; // 整个union占4字节内存

//联合体在初始化时，只给第一个成员初始化、
//每个成员互斥存在，还可以理解为该段内存有不同的解释方式

int  main() {
	union Data data;
	 
	// 存储int
	data.i = 42;
	printf("存储int: data.i = %d\n", data.i);
	printf("此时float值: data.f = %f (无意义)\n", data.f);
	
	// 存储float
	data.f = 3.14f;
	printf("\n存储float: data.f = %.2f\n", data.f);
	printf("此时int值: data.i = %d (无意义)\n", data.i);
	
	// 存储字符串
	strcpy(data.str, "ABC");
	printf("\n存储字符串: data.str = %s\n", data.str);
	printf("此时int值: 0x%x\n", data.i);  // 显示内存原始数据
	
	// 查看内存共享特性
	printf("\n内存共享验证:\n");
	data.i = 0x41424344;  // ASCII码对应"A","B","C","D"
	printf("作为int: 0x%x\n", data.i);
	printf("作为字符串: %s\n", data.str);  // 输出"DCBA"（小端序）
	
	return 0;
}
