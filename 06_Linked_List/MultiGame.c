#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element[100];
typedef struct ListNode { // 노드 타입
    element data;
    struct ListNode *link;
} ListNode;

// 리스트 처음 삽입 함수
ListNode* insert_first(ListNode* head, element data) {
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    strcpy(node->data, data);
    if (head == NULL) {
        head = node;
        node->link = head;
    }
    else {
        node->link = head->link;
        head->link = node;
    }
    return head; // 변경된 헤드 포인터 반환
}

// 원형 연결 리스트 테스트 프로그램
int main() {
    ListNode *head = NULL;
    
    head = insert_first(head, "Kang");
    head = insert_first(head, "Kwon");
    head = insert_first(head, "Kim");
    head = insert_first(head, "Lee");
    head = insert_first(head, "Choi");

    ListNode *p = head;
    for (int i = 0; i < 10; i++) {
        printf("현재 차례 = %s \n", p->data);
        p = p->link;
    }
    return 0;
}

