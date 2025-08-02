#include <stdio.h>
#include <stdlib.h>

// 链表节点结构
typedef struct Node {
	int data;           // 节点数据
	struct Node* next;  // 指向下一个节点的指针
} Node;

// 创建新节点
Node* createNode(int data) {
	Node* newNode = (Node*)malloc(sizeof(Node)); // 分配内存
	if (newNode == NULL) {
		printf("内存分配失败\n");
		exit(1);
	}
	newNode->data = data;  // 设置节点数据
	newNode->next = NULL;  // 初始化指针
	return newNode;
}

// 初始化链表（创建头节点）
Node* initList() {
	Node* head = createNode(0); // 头节点不存储实际数据
	printf("初始化空链表\n");
	return head;
}

// 尾插法插入节点
void append(Node* head, int data) {
	Node* current = head;
	while (current->next != NULL) { // 找到最后一个节点
		current = current->next;
	}
	current->next = createNode(data); // 在末尾插入新节点
	printf("插入节点: %d\n", data);
}

// 打印链表
void printList(Node* head) {
	Node* current = head->next; // 跳过头节点
	printf("当前链表: ");
	while (current != NULL) {
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
}

// 方法1：按值删除节点（删除第一个匹配项）
void deleteByValue(Node* head, int value) {
	Node* prev = head;       // 前驱节点
	Node* current = head->next; // 当前节点
	
	while (current != NULL && current->data != value) {
		prev = current;
		current = current->next;
	}
	
	if (current == NULL) {
		printf("未找到值 %d\n", value);
		return;
	}
	
	prev->next = current->next; // 跳过要删除的节点
	free(current);              // 释放内存
	printf("删除值 %d 成功\n", value);
}

// 方法2：按位置删除节点（位置从1开始）
void deleteByPos(Node* head, int pos) {
	if (pos < 1) {
		printf("位置必须大于0\n");
		return;
	}
	
	Node* prev = head;
	Node* current = head->next;
	int count = 1; // 位置计数器
	
	while (current != NULL && count < pos) {
		prev = current;
		current = current->next;
		count++;
	}
	
	if (current == NULL) {
		printf("位置 %d 超出链表长度\n", pos);
		return;
	}
	
	prev->next = current->next;
	free(current);
	printf("删除位置 %d 的节点成功\n", pos);
}

int main() {
	Node* list = initList(); // 初始化链表
	
	// 使用尾插法插入5个节点
	append(list, 10);
	append(list, 20);
	append(list, 30);
	append(list, 40);
	append(list, 50);
	printList(list); // 打印：10 20 30 40 50
	
	// 测试按值删除
	deleteByValue(list, 30); // 删除值为30的节点
	printList(list); // 打印：10 20 40 50
	
	// 测试按位置删除
	deleteByPos(list, 2); // 删除第2个节点（值为20）
	printList(list); // 打印：10 40 50
	
	// 测试错误情况
	deleteByValue(list, 99); // 尝试删除不存在的值
	deleteByPos(list, 0);   // 尝试删除无效位置
	
	return 0;
}
