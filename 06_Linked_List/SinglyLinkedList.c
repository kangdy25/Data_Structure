#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode { // 노드 타입
    element data;
    struct ListNode *link;
} ListNode;

// 오류 처리 함수
void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

// 첫 번째 노드 삽입 함수
ListNode* insert_first(ListNode *head, int value) {
    ListNode *p = (ListNode *)malloc(sizeof(ListNode)); // 동적 메모리 할당
    p->data = value;
    p->link = head; // 헤드 포인터의 값 복사
    head = p; // 헤드 포인터 변경
    return head; // 변경된 헤드 포인터 반환
}

// pre 노드 뒤에 새로운 노드 삽입    
ListNode* insert(ListNode *head, ListNode *pre, int value) {
    ListNode *p = (ListNode *)malloc(sizeof(ListNode)); // 동적 메모리 할당
    p->data = value;
    p->link = pre->link; // 헤드 포인터의 값 복사
    pre->link = p; // 헤드 포인터 변경
    return head; // 변경된 헤드 포인터 반환
}

// 첫 번째 노드 삭제 함수
ListNode* delete_first(ListNode *head) {
    ListNode *removed;
    if (head == NULL) return NULL;
    removed = head; // 헤드 포인터의 값을 removed에 복사 
    head = removed->link; // 헤드 포인터의 값을 removed->link로 변경
    free(removed); // 삭제할 노드의 동적 메모리 반환
    return head; // 변경될 헤드 포인터 반환
}

// pre 노드의 다음 노드 삭제 
ListNode* delete(ListNode *head, ListNode *pre) {
    ListNode *removed; 
    removed = pre->link;
    pre->link = removed->link; // pre 노드의 링크 필드가 removed 링크 필드가 가리키는 노드를 가리키도록 변경
    free(removed); // 삭제할 노드의 동적 메모리 반환
    return head; // 변경될 헤드 포인터 반환
}

// 리스트 출력 함수
void print_list(ListNode *head) {
    for (ListNode *p = head; p != NULL; p = p->link) 
        printf("%d -> ", p->data);
        printf("NULL \n");
}

// 테스트 프로그램
int main() {
    ListNode *head = NULL;
    
    for (int i = 0; i < 5; i++) {
        head = insert_first(head, i); // insert_first()가 반환된 헤드 포인터를 head에 대입
        print_list(head);
    }
    for (int i =0; i < 5; i++) {
        head = delete_first(head);
        print_list(head);
    }
    return 0;
}

