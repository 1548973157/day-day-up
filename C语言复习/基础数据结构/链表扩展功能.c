#include <stdio.h>
#include <stdlib.h>

/* 链表节点结构 */
typedef struct Node {
	int data;
	struct Node* next;
} Node;

/* 创建新节点 */
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

/* 初始化链表 */
Node* initList() {
	return createNode(0); // 头节点数据为0
}

/* 链表扩展功能1：反转链表 */
void reverseList(Node* head) {
	if (head->next == NULL || head->next->next == NULL) {
		return; // 空链表或只有一个节点不需要反转
	}
	
	Node* prev = NULL;
	Node* current = head->next;
	Node* next = NULL;
	
	while (current != NULL) {
		next = current->next; // 保存下一个节点
		current->next = prev; // 反转当前节点的指针
		prev = current;       // 前移prev指针
		current = next;       // 前移current指针
	}
	
	head->next = prev; // 更新头节点指向
}

/* 链表扩展功能2：检测环 */
int hasCycle(Node* head) {
	if (head->next == NULL) {
		return 0;
	}
	
	Node* slow = head->next;
	Node* fast = head->next;
	
	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;        // 慢指针每次走一步
		fast = fast->next->next;  // 快指针每次走两步
		
		if (slow == fast) {
			return 1; // 快慢指针相遇说明有环
		}
	}
	return 0;
}

/* 链表扩展功能3：获取中间节点 */
Node* getMiddleNode(Node* head) {
	if (head->next == NULL) {
		return NULL;
	}
	
	Node* slow = head->next;
	Node* fast = head->next;
	
	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;        // 慢指针每次走一步
		fast = fast->next->next;  // 快指针每次走两步
	}
	
	return slow;
}

/* 链表扩展功能4：合并两个有序链表 */
Node* mergeSortedLists(Node* l1, Node* l2) {
	Node dummy; // 临时头节点
	Node* tail = &dummy;
	dummy.next = NULL;
	
	while (l1->next != NULL && l2->next != NULL) {
		if (l1->next->data <= l2->next->data) {
			tail->next = l1->next;
			l1->next = l1->next->next;
		} else {
			tail->next = l2->next;
			l2->next = l2->next->next;
		}
		tail = tail->next;
	}
	
	// 连接剩余部分
	tail->next = (l1->next != NULL) ? l1->next : l2->next;
	
	// 创建新的头节点
	Node* newHead = initList();
	newHead->next = dummy.next;
	return newHead;
}

/* 打印链表 */
void printList(Node* head) {
	Node* current = head->next;
	printf("链表内容: ");
	while (current != NULL) {
		printf("%d", current->data);
		if (current->next != NULL) printf(" → ");
		current = current->next;
	}
	printf("\n");
}

/* 创建带环链表用于测试 */
void createCycleForTest(Node* head, int pos) {
	if (pos < 0) return;
	
	Node* current = head;
	Node* cycleNode = NULL;
	int count = 0;
	
	while (current->next != NULL) {
		if (count == pos) {
			cycleNode = current->next;
		}
		current = current->next;
		count++;
	}
	
	if (cycleNode != NULL) {
		current->next = cycleNode; // 形成环
	}
}

int main() {
	// 初始化链表
	Node* list = initList();
	
	// 测试数据
	for (int i = 1; i <= 5; i++) {
		Node* newNode = createNode(i);
		newNode->next = list->next;
		list->next = newNode;
	}
	printList(list); // 输出: 5 → 4 → 3 → 2 → 1
	
	// 测试反转链表
	reverseList(list);
	printList(list); // 输出: 1 → 2 → 3 → 4 → 5
	
	// 测试检测环
	printf("链表是否有环: %s\n", hasCycle(list) ? "是" : "否");
	
	// 测试获取中间节点
	Node* middle = getMiddleNode(list);
	if (middle != NULL) {
		printf("中间节点值: %d\n", middle->data);
	}
	
	// 测试创建环
	createCycleForTest(list, 2);
	printf("链表是否有环(测试): %s\n", hasCycle(list) ? "是" : "否");
	
	// 测试合并有序链表
	Node* list1 = initList();
	Node* list2 = initList();
	
	for (int i = 3; i >= 1; i--) {
		Node* newNode = createNode(i*2);
		newNode->next = list1->next;
		list1->next = newNode;
	}
	
	for (int i = 3; i >= 1; i--) {
		Node* newNode = createNode(i*2+1);
		newNode->next = list2->next;
		list2->next = newNode;
	}
	
	printf("有序链表1: "); printList(list1);
	printf("有序链表2: "); printList(list2);
	
	Node* merged = mergeSortedLists(list1, list2);
	printf("合并后链表: "); printList(merged);
	
	return 0;
}
