
#include <stdio.h>
/*
	线性表  
		表中数据元素之间关系是一对一的关系
	顺序表	线性表的一种
		物理位置连续，逻辑位置连续
		数组是顺序表的一种表现

	数据结构的基本操作
	增删改查
	
*/

int main(){
	int arr[10] = {10,20,30,40,50};//数组在增加时，首先需要有足够的空间
	int len = 5;//len代表数据个数
	//尾部增加
	arr[5] = 60;
	len ++;//增加数据就加一 6
	
	//中部增加，需要将插入位置后的内容往后移
	//如果空间不够，插入会让后部数据溢出
	int idx = 3;
	for(int i=len-1;i>=idx;i--){
		arr[i+1] = arr[i];
	}
	arr[idx] = 70;
	len ++;//7
	
	for(int i=0;i<len;i++){
		printf("%d\t",arr[i]);
	}
	printf("\n");
	
	//删除
	//尾部删除，通过len变量来控制访问
	len--;//6
	for (int i = 0; i < len; ++i){
		printf("%d\t", arr[i]);
	}
	printf("\n");
	
	//中部或者头部删除，将删除后的数据往前移，把删除的数据覆盖，len变量减一
	int Delidx = 4;
	for(int i=Delidx;i<len;i++){
		arr[i] = arr[i+1];		
	}
	len--;//5
	for (int i = 0; i < len; i++){
		printf("%d\t", arr[i]);
	}
	printf("\n");
	
	/*
		改查
	int findVal = 120;
	char isFind = 'N';
	for (int i = 0; i < len; i++){
		if(findVal == arr[i]){
			printf("找到了，下标在%d\t", i);
			isFind = 'Y';
			//或者是你要进行的修改操作
			break;
		}
	}
	if(findVal == 'N'){
		printf("没有找到");
	}
	*/
	return 0;
}
