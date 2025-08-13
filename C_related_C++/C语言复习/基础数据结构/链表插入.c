#include <stdio.h>   // 标准输入输出库，提供printf等函数
#include <stdlib.h>  // 标准库，提供malloc、exit等内存管理函数

/* 
* 链表节点结构定义
* 包含两个成员：
*   data - 整型数据域，存储节点值
*   next - 指针域，指向下一个节点的地址
*/
typedef struct Node {
	int data;           // 节点存储的数据
	struct Node* next;  // 指向下一个节点的指针
} Node;

/*
* 创建新节点
* 参数：data - 要存储在节点中的整数值
* 返回值：成功返回新节点指针，失败退出程序
* 实现细节：
*   1. 使用malloc动态分配节点内存
*   2. 检查内存分配是否成功
*   3. 初始化节点数据和指针
*/
Node* createNode(int data) {
	// 申请节点内存空间，大小为Node结构体大小
	Node* newNode = (Node*)malloc(sizeof(Node));
	
	// 检查内存分配是否成功
	if (newNode == NULL) {
		printf("内存分配失败！\n");  // 打印错误信息
		exit(1);                   // 异常退出程序，参数1表示异常状态
	}
	
	newNode->data = data;  // 设置节点数据域
	newNode->next = NULL;  // 初始化指针域为NULL
	return newNode;        // 返回新创建的节点
}

/*
* 初始化带头节点的链表
* 返回值：链表头节点指针
* 特点：
*   1. 头节点不存储实际数据（data=0）
*   2. 头节点的next初始化为NULL
*   3. 头节点简化空链表处理
*/
Node* initLinkedList() {
	// 创建头节点，数据域默认为0
	Node* head = createNode(0); 
	printf("空链表初始化完成\n");  // 打印初始化信息
	return head;                  // 返回头节点指针
}

/*
* 打印链表内容
* 参数：head - 链表头节点指针
* 实现细节：
*   1. 从头节点的下一个节点开始遍历
*   2. 使用箭头符号连接各个节点值
*   3. 处理空链表情况
*/
void printList(Node* head) {
	// current指向第一个有效节点（跳过头节点）
	Node* current = head->next; 
	
	printf("链表内容：");  // 打印前缀
	
	// 遍历链表直到末尾
	while (current != NULL) {
		printf("%d", current->data);  // 打印当前节点数据
		
		// 如果不是最后一个节点，打印连接箭头
		if (current->next != NULL) {
			printf(" → ");
		}
		
		current = current->next;  // 移动到下一个节点
	}
	
	printf("\n");  // 打印换行符
}

/*
* 头插法插入节点
* 参数：
*   head - 链表头节点指针
*   data - 要插入的数据
* 特点：
*   1. 新节点插入在头节点之后
*   2. 时间复杂度O(1)
*/
void insertAtHead(Node* head, int data) {
	// 创建新节点
	Node* newNode = createNode(data);  
	
	// 新节点的next指向原第一个节点
	newNode->next = head->next;  
	
	// 头节点的next指向新节点
	head->next = newNode;        
	
	printf("头插 %d 成功\n", data);  // 打印操作结果
}

/*
* 尾插法插入节点
* 参数：
*   head - 链表头节点指针
*   data - 要插入的数据
* 特点：
*   1. 需要遍历找到链表末尾
*   2. 时间复杂度O(n)
*/
void insertAtTail(Node* head, int data) {
	// current从头节点开始遍历
	Node* current = head;  
	
	// 找到最后一个节点（next为NULL的节点）
	while (current->next != NULL) { 
		current = current->next;
	}
	
	// 在末尾插入新节点
	current->next = createNode(data);  
	
	printf("尾插 %d 成功\n", data);  // 打印操作结果
}

/*
* 在指定位置插入节点
* 参数：
*   head - 链表头节点指针
*   data - 要插入的数据
*   pos - 插入位置（从1开始计数）
* 实现细节：
*   1. 位置有效性检查
*   2. 找到位置的前驱节点
*   3. 处理位置超出链表长度的情况
*/
void insertAtPosition(Node* head, int data, int pos) {
	// 检查位置是否有效（最小为1）
	if (pos < 1) {
		printf("位置无效！最小为1\n");
		return;  // 直接返回
	}
	
	Node* current = head;  // 从头节点开始查找
	int count = 0;         // 位置计数器
	
	// 找到插入位置的前一个节点
	while (current != NULL && count < pos - 1) {
		current = current->next;  // 移动到下一个节点
		count++;                  // 计数器递增
	}
	
	// 检查是否找到有效位置
	if (current == NULL) {
		printf("位置 %d 超出链表长度\n", pos);
		return;  // 直接返回
	}
	
	// 创建新节点
	Node* newNode = createNode(data);  
	
	// 新节点指向原位置的节点
	newNode->next = current->next;  
	
	// 前一个节点指向新节点
	current->next = newNode;        
	
	printf("在位置 %d 插入 %d 成功\n", pos, data);  // 打印操作结果
}

/*
* 主函数：测试链表操作
* 测试流程：
*   1. 初始化链表
*   2. 测试头插法
*   3. 测试尾插法
*   4. 测试指定位置插入
*   5. 测试无效位置处理
*/
int main() {
	// 1. 初始化链表
	Node* list = initLinkedList();
	printList(list);  // 打印空链表（应输出：链表内容：）
	
	// 2. 测试头插法
	insertAtHead(list, 10);  // 头插10
	insertAtHead(list, 20);  // 头插20
	printList(list);         // 打印链表（应输出：20 → 10）
	
	// 3. 测试尾插法
	insertAtTail(list, 30);  // 尾插30
	insertAtTail(list, 40);  // 尾插40
	printList(list);         // 打印链表（应输出：20 → 10 → 30 → 40）
	
	// 4. 测试指定位置插入
	insertAtPosition(list, 50, 2);  // 在位置2插入50
	printList(list);                // 打印链表（应输出：20 → 50 → 10 → 30 → 40）
	
	// 5. 测试无效位置处理
	insertAtPosition(list, 60, 10); // 尝试在位置10插入（应输出错误信息）
	
	return 0;  // 程序正常退出
}
