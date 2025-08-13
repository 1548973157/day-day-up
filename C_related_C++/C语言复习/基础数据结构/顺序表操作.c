#include <stdio.h>
#include <stdlib.h>

/*
* 顺序表（Sequential List）知识点详解：
*
* 1. 基本概念：
*    - 顺序表是一种线性表数据结构，元素在内存中连续存储
*    - 逻辑上相邻的元素在物理内存中也相邻
*    - 由三个核心属性组成：
*        data: 指向存储元素的连续内存空间
*        length: 当前实际存储的元素数量
*        capacity: 当前分配的内存容量
*
* 2. 核心特点：
*    - 随机访问：通过下标可在O(1)时间内访问任意元素
*    - 存储密度高：只存储数据本身，无额外指针开销
*    - 插入/删除成本高：平均需要移动n/2个元素，时间复杂度O(n)
*
* 3. 关键操作复杂度：
*    - 按索引访问：O(1)
*    - 按值查找：O(n)
*    - 尾部插入：均摊O(1)（考虑扩容）
*    - 随机位置插入：O(n)
*    - 删除元素：O(n)
*
* 4. 动态扩容策略：
*    - 当元素数量达到容量上限时触发扩容
*    - 采用容量翻倍策略（newCapacity = oldCapacity * 2）
*    - 均摊时间复杂度：O(1)
*
* 5. 适用场景：
*    - 需要频繁随机访问元素
*    - 元素总量相对稳定或可预测
*    - 插入/删除主要在尾部进行
*
* 6. 不适用场景：
*    - 需要频繁在头部/中部插入删除
*    - 元素数量变化剧烈且不可预测
*    - 内存空间受限的嵌入式环境
*/

// 顺序表结构定义
typedef struct MyArray {
	int* pData;     // 指向动态分配的数组，存储实际元素
	int length;     // 当前元素个数（有效长度）
	int capacity;   // 当前分配的容量（总长度）
} MA;

/**
 * 创建顺序表
 * 功能：初始化一个空的顺序表
 * 返回：成功返回指向顺序表的指针，失败返回NULL
 * 注意：初始分配10个元素空间
 */
MA* createMA(void) {
	// 分配顺序表结构体内存
	MA *pMA = (MA*)malloc(sizeof(MA));
	if (pMA == NULL) {
		printf("内存分配失败，创建顺序表失败\n");
		return NULL;
	}
	
	// 初始容量设为10
	pMA->capacity = 10;
	// 为数据数组分配内存
	pMA->pData = (int*)malloc(pMA->capacity * sizeof(int));
	if (pMA->pData == NULL) {
		printf("数据内存分配失败\n");
		free(pMA);  // 释放已分配的结构体
		return NULL;
	}
	
	pMA->length = 0;  // 初始长度为0
	printf("顺序表创建成功！初始容量：%d\n", pMA->capacity);
	return pMA;
}

/**
 * 销毁顺序表
 * 功能：释放顺序表占用的所有内存
 * 参数：ppMA - 指向顺序表指针的指针（二级指针）
 * 注意：释放后会将外部指针置为NULL，避免悬垂指针
 */
void freeMA(MA** ppMA) {
	// 检查指针有效性
	if (ppMA == NULL || *ppMA == NULL) {
		printf("顺序表指针无效，无需释放\n");
		return;
	}
	
	MA* pMA = *ppMA;
	// 释放数据数组内存
	if (pMA->pData != NULL) {
		free(pMA->pData);
		pMA->pData = NULL; // 避免野指针
	}
	
	// 释放结构体内存
	free(pMA);
	*ppMA = NULL; // 将外部指针置为NULL
	printf("顺序表已销毁！\n");
}

/**
 * 清空顺序表
 * 功能：移除所有元素，保留内存空间
 * 参数：pMA - 顺序表指针
 * 注意：只重置长度，不释放内存，便于后续重用
 */
void clearMA(MA* pMA) {
	if (pMA == NULL) {
		printf("顺序表为空，不能清除\n");
		return;
	}
	
	pMA->length = 0; // 重置长度为0
	printf("顺序表已清空！\n");
}

/**
 * 检查并扩容（内部函数）
 * 功能：当顺序表满时自动扩容
 * 参数：pMA - 顺序表指针
 * 策略：容量翻倍（newCapacity = oldCapacity * 2）
 */
static void checkCapacity(MA* pMA) {
	// 检查是否需要扩容
	if (pMA->length >= pMA->capacity) {
		// 容量翻倍策略
		int newCapacity = pMA->capacity * 2;
		// 重新分配更大的内存空间
		int* newData = (int*)realloc(pMA->pData, newCapacity * sizeof(int));
		
		if (newData == NULL) {
			printf("扩容失败！\n");
			return;
		}
		
		// 更新指针和容量
		pMA->pData = newData;
		pMA->capacity = newCapacity;
		printf("顺序表已扩容至 %d\n", newCapacity);
	}
}

/**
 * 尾部添加元素
 * 功能：在顺序表末尾添加新元素
 * 参数：pMA - 顺序表指针，elem - 要添加的元素
 * 时间复杂度：均摊O(1)（考虑扩容成本）
 */
void pushMA(MA* pMA, int elem) {
	if (pMA == NULL) {
		printf("顺序表为空，不能添加数据\n");
		return;
	}
	
	checkCapacity(pMA); // 检查扩容
	
	// 在末尾添加元素
	pMA->pData[pMA->length] = elem;
	pMA->length++;
	printf("添加成功：值 %d\n", elem);
}

/**
 * 指定位置插入元素
 * 功能：在指定索引位置插入新元素
 * 参数：pMA - 顺序表指针，index - 插入位置(0-length)，elem - 要插入的元素
 * 时间复杂度：O(n)（需要移动元素）
 */
void insertAt(MA* pMA, int index, int elem) {
	if (pMA == NULL) {
		printf("顺序表为空，不能插入\n");
		return;
	}
	
	// 检查位置合法性（允许在末尾插入）
	if (index < 0 || index > pMA->length) {
		printf("插入位置 %d 不合法！有效范围 [0, %d]\n", index, pMA->length);
		return;
	}
	
	checkCapacity(pMA); // 检查扩容
	
	// 将插入位置后的元素后移（从后向前移动）
	for (int i = pMA->length; i > index; i--) {
		pMA->pData[i] = pMA->pData[i-1];
	}
	
	// 插入新元素
	pMA->pData[index] = elem;
	pMA->length++;
	printf("插入成功：位置 %d, 值 %d\n", index, elem);
}

/**
 * 删除指定位置元素
 * 功能：移除指定索引位置的元素
 * 参数：pMA - 顺序表指针，index - 要删除的位置索引
 * 返回：被删除的元素值，出错返回-1
 * 时间复杂度：O(n)（需要移动元素）
 */
int removeAt(MA* pMA, int index) {
	if (pMA == NULL || pMA->length == 0) {
		printf("顺序表为空或无效，不能删除\n");
		return -1; // 错误码
	}
	
	// 检查位置合法性
	if (index < 0 || index >= pMA->length) {
		printf("删除位置 %d 不合法！有效范围 [0, %d]\n", index, pMA->length-1);
		return -1;
	}
	
	int removed = pMA->pData[index]; // 保存被删除的值
	
	// 将删除位置后的元素前移（从前向后移动）
	for (int i = index; i < pMA->length - 1; i++) {
		pMA->pData[i] = pMA->pData[i+1];
	}
	
	pMA->length--; // 长度减少
	printf("删除成功：位置 %d, 值 %d\n", index, removed);
	return removed;
}

/**
 * 获取指定位置元素
 * 功能：返回指定索引位置的元素值
 * 参数：pMA - 顺序表指针，index - 元素位置
 * 返回：元素值，出错返回-1
 * 时间复杂度：O(1)
 */
int getAt(MA* pMA, int index) {
	if (pMA == NULL || pMA->length == 0) {
		printf("顺序表为空或无效\n");
		return -1;
	}
	
	if (index < 0 || index >= pMA->length) {
		printf("获取位置 %d 不合法！有效范围 [0, %d]\n", index, pMA->length-1);
		return -1;
	}
	
	return pMA->pData[index]; // 随机访问
}

/**
 * 修改指定位置元素
 * 功能：更新指定索引位置的元素值
 * 参数：pMA - 顺序表指针，index - 元素位置，elem - 新值
 * 时间复杂度：O(1)
 */
void setAt(MA* pMA, int index, int elem) {
	if (pMA == NULL || pMA->length == 0) {
		printf("顺序表为空或无效，不能修改\n");
		return;
	}
	
	if (index < 0 || index >= pMA->length) {
		printf("修改位置 %d 不合法！有效范围 [0, %d]\n", index, pMA->length-1);
		return;
	}
	
	int oldValue = pMA->pData[index]; // 保存旧值
	pMA->pData[index] = elem;         // 更新为新值
	printf("修改成功：位置 %d, 原值 %d → 新值 %d\n", index, oldValue, elem);
}

/**
 * 查找元素位置
 * 功能：返回元素第一次出现的索引
 * 参数：pMA - 顺序表指针，elem - 要查找的元素
 * 返回：元素索引（找到），-1（未找到）
 * 时间复杂度：O(n)
 */
int findIndex(MA* pMA, int elem) {
	if (pMA == NULL || pMA->length == 0) {
		printf("顺序表为空或无效\n");
		return -1;
	}
	
	// 线性查找
	for (int i = 0; i < pMA->length; i++) {
		if (pMA->pData[i] == elem) {
			printf("查找成功：值 %d 位于位置 %d\n", elem, i);
			return i;
		}
	}
	
	printf("未找到值 %d\n", elem);
	return -1;
}

/**
 * 打印顺序表
 * 功能：输出顺序表当前内容和状态
 * 参数：pMA - 顺序表指针
 */
void printMA(MA* pMA) {
	if (pMA == NULL) {
		printf("顺序表指针无效\n");
		return;
	}
	
	if (pMA->length == 0) {
		printf("顺序表为空！\n");
		return;
	}
	
	// 打印表头信息
	printf("顺序表内容 [长度=%d, 容量=%d]：\n", pMA->length, pMA->capacity);
	
	// 打印所有元素
	for (int i = 0; i < pMA->length; i++) {
		printf("%d ", pMA->pData[i]);
	}
	printf("\n");
}

/**
 * 获取顺序表长度
 * 功能：返回当前元素数量
 * 参数：pMA - 顺序表指针
 * 返回：元素数量（空表返回0）
 */
int getLength(MA* pMA) {
	if (pMA == NULL) return 0;
	return pMA->length;
}

int main() {
	// 测试顺序表功能
	MA* table = createMA();
	
	// 尾部添加元素
	pushMA(table, 10);
	pushMA(table, 20);
	pushMA(table, 30);
	printMA(table);
	
	// 指定位置插入
	insertAt(table, 1, 15);  // 位置1插入15
	insertAt(table, 0, 5);   // 头部插入5
	insertAt(table, 5, 40);  // 尾部插入40
	printMA(table);
	
	// 测试扩容
	printf("开始测试扩容...\n");
	for (int i = 0; i < 10; i++) {
		pushMA(table, 100 + i); // 添加10个元素触发扩容
	}
	printMA(table);
	
	// 查找元素
	int index = findIndex(table, 15);
	if (index != -1) {
		printf("元素15位于位置：%d\n", index);
	}
	
	// 修改元素
	setAt(table, 3, 99);
	printMA(table);
	
	// 删除元素
	removeAt(table, 2);  // 删除位置2
	removeAt(table, 0);  // 删除头部
	removeAt(table, getLength(table)-1); // 删除尾部
	printMA(table);
	
	// 获取元素
	printf("位置1的元素：%d\n", getAt(table, 1));
	
	// 清空和销毁
	clearMA(table);
	printMA(table);
	
	freeMA(&table);
	
	// 测试销毁后访问（应安全）
	printf("测试销毁后访问：");
	getAt(table, 0);
	
	return 0;
}
