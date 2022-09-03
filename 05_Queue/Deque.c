#include <stdio.h>
#include <stdlib.h>

#define MAX_DEQUE_SIZE 5
typedef int element;
typedef struct { // 덱 타입
    element data[MAX_DEQUE_SIZE];
    int front, rear;
} DequeType;

// 오류 함수 
void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

// 초기화 
void init_deque(DequeType *d) {
    d->front = d->rear = 0;
}

// 공백 상태 검출 함수
int is_empty(DequeType *d) {
    return (d->front == d->rear);
}

// 포화 상태 검출 함수
int is_full(DequeType *d) {
    return ((d->rear + 1) % MAX_DEQUE_SIZE == d->front);
}

// 덱 출력 함수
void deque_print(DequeType *d) {
    printf("DEQUE(front=%d rear=%d) = ", d->front, d->rear);
    if(!is_empty(d)) {
        int i = d->front;
        do {
            i = (i + 1) % (MAX_DEQUE_SIZE);
            printf("%d | ", d->data[i]);
            if(i == d->rear)
                break;
        } while (i != d->front);
    }
    printf("\n");
}

// 삽입 함수
void add_rear(DequeType *d, element item) {
    if(is_full(d))
        error("덱이 포화상태입니다.");
    d->rear = (d->rear + 1) % MAX_DEQUE_SIZE;
    d->data[d->rear] = item;
}

// 삭제 함수
element delete_front(DequeType *d) {
    if (is_empty(d)) 
        error("덱이 공백상태입니다.");
    d->front = (d->front + 1) % MAX_DEQUE_SIZE;
    return d->data[d->front];
}

element get_front(DequeType *d) {
    if (is_empty(d)) 
        error("덱이 공백상태입니다.");
    return d->data[(d->front + 1) % MAX_DEQUE_SIZE];
}

void add_front(DequeType *d, element val) {
    if (is_full(d))
        error("덱이 포화상태입니다.");
    d->data[d->front] = val;
    d->front = (d->front - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
}

element delete_rear(DequeType *d) {
    int prev = d->rear;
    if (is_empty(d))
        error("덱이 공백상태입니다.");
    d->rear = (d->rear - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
    return d->data[prev];
}

element get_rear(DequeType *d) {
    if (is_empty(d))
        error("덱이 공백상태입니다.");
    return d->data[d->rear];
}

int main() {
    DequeType deque;

    init_deque(&deque);
    for (int i = 0; i < 3; i++) {
        add_front(&deque, i);
        deque_print(&deque);
    }
    for (int i = 0; i < 3; i++) {
        delete_rear(&deque);
        deque_print(&deque);
    }  
    return 0;
}

