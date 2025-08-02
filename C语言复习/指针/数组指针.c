#include <stdlib.h>
#include <stdio.h>
/*
	数组指针：是一个指针，指向数组，数组为二维及以上
	定义格式：
		数据类型（*指针变量名）[所指的数组的列大小]；
*/

int main(){
	int arr[4] = { 1, 2, 3,4 };
	int arrl[2][3]= { 1,2,3,4,5,6};
	int* p = arr;
	printf("%d\n", *p);
    //p = arrl;
    //printf("%d\n",*arrl);
	int*pArr[4];//指针数组
	int(*pArr1)[3] = NULL;//数组指针，可以指向所有列为3的二维数组
	pArr1 = arrl;//二维数组的首地址赋值给到指向所有列为3的二维数组指针上
	pArr1[0][0] = 123;
	for(int i=0;i<2;i++){
		for(int j=0;j<3;j++){
			printf("%d\t",pArr1[i][j]);
		}
		printf("\n");
		
	}
	return 0;
}
