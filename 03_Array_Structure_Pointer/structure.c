#include <stdio.h>

typedef struct studentTag {
	char name[10]; // 문자 배열로 된 이름
	int age; // 나이를 나타내는 정수값
       	double gpa; // 평균평점을 나타내는 실수값
} student;

int main() {
	student a = {"kang", 22, 4.21};
	student b = {"choi", 20, 3.7};
	
	printf("a의 이름 : %s\n", a.name); 
	printf("a의 나이 : %d\n", a.age); 
	printf("a의 학점 : %f\n", a.gpa); 
	return 0;
}
