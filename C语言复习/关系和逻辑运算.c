#include <stdio.h>

int main() {
	// 关系运算符示例
	int hp = 10;
	
	// 判断NPC是否死亡
	if (hp <= 0) {
		printf("死亡\n");
	}
	else if(hp>0){
		printf("存活\n");		
	}
	
	// 逻辑与(&&)示例
	int val = 97;
	if (val >= 70 && val < 100) {
		printf("B\n");
	}
	
	// 逻辑或(||)示例
	val = 90;
	if (val == 90 || val == 100) {
		printf("逻辑或\n");
	}
	
	// 复合逻辑判断示例
	int x = -5, y = 10;
	if (x < 0 || y < 0) {
		printf("die\n");  // 任意一个值小于0时触发
	}
	
	/* 
	* 逻辑运算符说明：
	* && 逻辑与 - 两边同时为真则真
	* || 逻辑或 - 任意一边为真则真
	* !  逻辑非 - 取反操作数的布尔值
	*/
	
	// 逻辑非(!)示例
	char sex = 'm';
	if (!(sex != 'm')) {  // 等价于 if (sex == 'm')
		printf("逻辑非\n");
	}
	
	return 0;
}
