#include <stdio.h>
#include <stdlib.h>

/*
	顺序表
		物理位置连续，逻辑位置连续
*/
typedef struct MyArray{
	int* pData;//存储数据的顺序表
	int length;
}MA;

//创建
MA* createMA(void){
	MA *pMA = (MA*)malloc(sizeof(MA));
	if(pMA == NULL){
		printf("创建顺序表失败\n");
		return NULL;
	}
	pMA -> pData = NULL;
	pMA -> length = 0;
	return pMA;
}
/*
	一级指针

void freeMA(MA* pMA){
	if(pMA == NULL ||  (pMA -> pData) == NULL){   //当 pData == NULL 时，直接返回而不释放结构体，造成结构体内存泄漏
		printf("顺序表为空，不能释放\n");
		return ;//返回值为void,ruturn不加表达式
	}
	free(pMA -> pData);
	free(pMA);
}*/


/*下述版本安全
//	二级指针初版
void freeMA(MA** pMA) {
if (*pMA == NULL || (*pMA)->pData == NULL) {
printf("顺序表为空，不能释放\n");
return;
}
free((*pMA)->pData);
free(*pMA);
*pMA = NULL;  // 关键改进
}

*/
//下面的代码更安全，可以看调试过程断点在freeMA(table);这一步

//	二级指针改进版

void freeMA(MA** pMA) {
	if (*pMA == NULL) {  // 
		printf("顺序表为空，不能释放\n");
		return;
	}
	if( NULL == (*pMA)->pData){
		free(*pMA);           // 即使数据数组不存在，也释放结构体
		return;
		//TODO
	}
	free((*pMA)->pData);  // 释放数据数组
	free(*pMA);           // 释放结构体
	*pMA = NULL;          // 将外部指针置为NULL
}

int main(){
	MA* table = createMA();//创建
	table -> pData = (int*)malloc(sizeof(int));
	//初始化一个数据，用来测试代码
	table->pData[0] = 123; // 初始化第一个数据为123
	table->length = 1;      // 更新长度为1
	
	//一级指针
	//freeMA(table);
	// ⚠️ 若使用一级指针的代码。危险！此时 MA 仍然指向已释放的内存（但内存已被释放）。后续误用会导致未定义行为（程序崩溃或数据损坏）

	//二级指针
	freeMA(&table);
	// ✅ 安全！myArray 已被置为 NULL，释放后自动置 NULL，避免后续误用， *pMA = NULL; 明确表示资源已释放
	return 0;
}
/*
一级指针 vs 二级指针的核心区别：
一级指针版本：

释放内存后，外部指针仍指向已释放的内存（悬垂指针）

当 pData 为 NULL 时，结构体内存泄漏

调用方式：freeMA(arr)

二级指针版本：

释放内存后，自动将外部指针置为 NULL（消除悬垂指针）

即使 pData 为 NULL，也确保释放结构体内存

调用方式：freeMA(&arr)

二级指针规避的核心问题：
悬垂指针风险：释放后指针不再指向无效内存

内存泄漏隐患：确保所有情况都完整释放内存

重复释放防护：*pMA = NULL 使二次调用 freeMA 安全
*/
