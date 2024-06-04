#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DListNode{
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
}DListNode;

void init(DListNode* phead) {
	phead->llink = phead;
	phead->rlink = phead;
}

void print_dlist(DListNode* phead) {
	DListNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink) {
		printf(" %d ->", p->data);
	}
	printf("\n");
}

void dinsert(DListNode* before, element data) {
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	newnode->data = data;
	newnode->llink = before;
	newnode->rlink = before->rlink;
	before->rlink->llink = newnode;
	before->rlink = newnode;	
}

void ddelete(DListNode* head, DListNode* removed) {
	if (removed == head) return;
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}

int main() {
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	int choice, num;
	init(head);
	/*dinsert(head, 10);
	dinsert(head, 20);
	dinsert(head->rlink->rlink, 5);
	dinsert(head->llink, 2);*/
	
	while (1) {
		printf("\n메뉴\n");
		printf("1. 숫자 입력 받아서 리스트 처음에 추가\n");
		printf("2. 숫자 입력 받아서 리스트 마지막에 추가\n");
		printf("3. 리스트 처음 노드 삭제\n");
		printf("4. 리스트 마지막 노드 삭제\n");
		printf("5. 리스트 프린트\n");
		printf("6. 종료\n");
		printf("선택 : ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			printf("추가할 숫자를 입력하세요: ");
			scanf("%d", &num);
			dinsert(head, num);
			break;
		case 2:
			printf("추가할 숫자를 입력하세요: ");
			scanf("%d", &num);
			dinsert(head->llink, num);
			break;
		case 3:
			ddelete(head, head->rlink);
			printf("리스트 처음 노드를 삭제하였습니다.\n");
			break;
		case 4:
			ddelete(head, head->llink);
			printf("리스트 마지막 노드를 삭제하였습니다.\n");
			break;
		case 5:
			print_dlist(head);
			break;
		case 6:
			printf("프로그램을 종료합니다.\n");
			break;
		default:
			printf("잘못된 선택입니다.\n");
		}
	}
}