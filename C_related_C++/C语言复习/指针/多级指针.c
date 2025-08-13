#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
	多级指针
*/


int main(){
	int a = 10;
	int* p = &a;
	*p = 123;
	printf("%d\n",a);
	int** pp = &p;//二级指针
	**pp = 999;
	printf("%d\n",a);
	return 0;
}
