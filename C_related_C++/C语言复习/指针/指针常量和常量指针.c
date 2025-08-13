#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
   （谁在后谁是名词）
	指针常量 => 指针表示的地址是一个常量，意味着指针永远指向同一位地址
	常量指针 => 指针用来指地址，该地址的值是常量
*/
int main(){
	const int lv = 3;
	int a = 3,b = 4;
	int* const p = &b;//常量需要做初始化，后续不能被修改
	//p = &a;错误，不能修改常量
	*p = 123;
	
	
	const int* p1;//是一个指针，指向一个常量
	p1 = &a;//p1所指a的内存，通过p1无法修改a所在内存里面的值
	//*p1 = 123;//错误，通过p1找到的地址里面的值是常量，不能修改
	
	const int* const p3 = &b;//常量指针常量,指针和常量都不能被修改
	//  p3 = &a;
	// *p3 = 123;
	return 0;
}
