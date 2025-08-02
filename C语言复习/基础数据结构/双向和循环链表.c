#include <stdio.h>
#include <stdlib.h>
/*
	双向链表：
	适用于需要双向操作的场景
	插入/删除时要同步更新prev和next指针
	
	循环链表：
	适合环形数据处理
	遍历时需注意避免无限循环



*/
/* 单链表节点结构（用于循环链表） */
typedef struct Node {
	int data;
	struct Node* next;
} Node;

/* 双向链表节点结构 */
typedef struct DNode {
	int data;
	struct DNode* prev;
	struct DNode* next;
} DNode;

/* 创建单链表节点 */
Node* createNode(int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) {
		printf("内存分配失败\n");
		exit(1);
	}
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

/* 创建双向链表节点 */
DNode* createDNode(int data) {
	DNode* newNode = (DNode*)malloc(sizeof(DNode));
	if (newNode == NULL) {
		printf("内存分配失败\n");
		exit(1);
	}
	newNode->data = data;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

/* 双向链表插入 */
void insertDNode(DNode* prevNode, int data) {
	if (prevNode == NULL) {
		printf("错误：前驱节点不能为NULL\n");
		return;
	}
	
	// 创建新节点
	DNode* newNode = (DNode*)malloc(sizeof(DNode));
	newNode->data = data;
	
	// 设置新节点的前后指针
	newNode->prev = prevNode;       // 新节点的前驱是prevNode
	newNode->next = prevNode->next; // 新节点的后继是原prevNode的后继
	
	// 如果prevNode后面有节点，更新那个节点的前驱
	if (prevNode->next != NULL) {
		prevNode->next->prev = newNode;
	}
	
	// 更新prevNode的后继
	prevNode->next = newNode;
	
	printf("双向链表插入 %d 成功\n", data);
}

/* 打印双向链表 */
void printDList(DNode* head) {
	DNode* current = head->next;
	printf("双向链表(正向): ");
	while (current != NULL) {
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
}

/* 循环链表尾插法 */
void insertCircular(Node* head, int data) {
	Node* newNode = createNode(data);
	Node* current = head;
	
	// 找到最后一个节点（next指向NULL或head）
	while (current->next != NULL && current->next != head) {
		current = current->next;
	}
	
	// 插入新节点
	current->next = newNode;
	newNode->next = head; // 形成环
	
	printf("循环链表插入 %d 成功\n", data);
}

/* 打印循环链表 */
void printCircularList(Node* head) {
	if (head->next == NULL) {
		printf("循环链表为空\n");
		return;
	}
	
	Node* current = head->next;
	printf("循环链表: ");
	
	do {
		printf("%d ", current->data);
		current = current->next;
	} while (current != head && current != NULL); // 循环终止条件
	
	printf("\n");
}

int main() {
	printf("=== 双向链表测试 ===\n");
	// 初始化双向链表头节点
	DNode* dHead = createDNode(0);
	
	// 插入节点
	insertDNode(dHead, 10);
	insertDNode(dHead, 20);
	insertDNode(dHead->next, 15); // 在10和20之间插入15
	
	// 打印双向链表
	printDList(dHead);
	
	printf("\n=== 循环链表测试 ===\n");
	// 初始化循环链表头节点
	Node* cHead = createNode(0);
	
	// 插入节点
	insertCircular(cHead, 100);
	insertCircular(cHead, 200);
	insertCircular(cHead, 300);
	
	// 打印循环链表
	printCircularList(cHead);
	
	return 0;
}
