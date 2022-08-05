#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct studentTag {
	char name[10]; // 문자 배열 -> 이름
	int age; // 정수형 -> 나이
	double gpa; // 실수형 -> 학점
} student;

int main() {
	student *s;

	s = (student *)malloc(sizeof (student));
	if ( s == NULL) {
		fprintf(stderr, "메모리가 부족해서 할당할 수 없습니다. \n");
		exit(1);       	
	}

	strcpy(s->name, "Park");
	s->age = 20;

	free(s);
	
	return 0;
}
