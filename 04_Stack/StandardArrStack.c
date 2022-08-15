#include <stdio.h>
#include <stdlib.h>

// 스택이 필요한 경우, 여기만 복사해서 붙여넣기를 하자.
// ========== 스택 코드 시작 ==========
#define MAX_STACK_SIZE 100

// 스택이 구조체로 정의된다.
typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

// 스택 초기화 함수
void init_stack(StackType *s) {
	s->top = -1;
}

// 모든 연산은 구조체의 포인터를 받는다.

// 공백 상태 검출 함수
int is_empty(StackType *s) {
	return (s->top == -1);
}

// 포화 상태 검출 함수
int is_full(StackType *s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}

// 삽입 함수
void push(StackType *s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->data[++(s->top)] = item;
}

// 삭제 함수
element pop(StackType *s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

// 피크 함수
element peek(StackType *s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[s->top];
}
// ========== 스택 코드의 끝 ==========

int main() {
	StackType s;
	// 스택을 동적으로 생성한다.
	// s = (StackType *)malloc(sizeof(StackType));
	init_stack(&s);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	// 동적 메모리는 반드시 반환한다.
	// free(s);
	return 0;
}
