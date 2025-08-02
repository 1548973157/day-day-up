#include <stdio.h>
#include <stdlib.h>

/* 
* 链表节点结构定义
* 知识点：
* 1. 链表由节点(Node)通过指针链接组成
* 2. 每个节点包含：
*    - data: 存储数据（本例用int类型）
*    - next: 指向下一个节点的指针
*/
typedef struct Node {
	int data;           // 数据域
	struct Node* next;  // 指针域
} Node;

/*
* 创建新节点
* 参数：data - 节点存储的数据
* 返回值：新节点指针
* 知识点：
* 1. 使用malloc动态分配内存
* 2. 新节点的next指针初始化为NULL
* 3. 必须检查内存分配是否成功
*/


Node* createNode(int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) {
		printf("内存分配失败！\n");
		exit(1); // 分配失败直接退出程序
	}
	newNode->data = data;
	newNode->next = NULL; // 新节点默认指向NULL
	return newNode;
}



/*
* 初始化带头节点的链表
* 返回值：链表头节点指针
* 知识点：
* 1. 头节点不存储实际数据（data=0）
* 2. 头节点的next初始为NULL
* 3. 头节点简化了链表操作（无需特殊处理空链表）
*/
Node* initLinkedList() {
	Node* head = createNode(0); // 创建头节点
	printf("空链表初始化完成\n");
	return head;
}

/*
* 打印链表
* 参数：head - 链表头节点
* 知识点：
* 1. 从头节点的下一个节点开始遍历
* 2. 使用箭头符号可视化节点链接关系
*/
void printList(Node* head) {
	Node* current = head->next; // 跳过头节点
	printf("链表内容：");
	while (current != NULL) {
		printf("%d", current->data);
		if (current->next != NULL) printf(" → ");
		current = current->next;
	}
	printf("\n");
}
int main() {
	// 测试链表功能
	Node* list = initLinkedList();  // 初始化链表
	
	// 测试打印空链表
	printList(list);
	
	// 测试创建节点
	Node* node1 = createNode(10);
	Node* node2 = createNode(20);
	
	// 手动连接节点
	list->next = node1;
	node1->next = node2;
	
	// 打印链表
	printList(list);
	
	return 0;
}
