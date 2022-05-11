#include <stdio.h>

int main() {
	int n, i;
	printf("숫자를 입력하세요 -> ");
	scanf("%d", &n);	
	int result = 0;
	for (int i = n; i > 0; i -= 3) {

		result = result + i;	
		
	}
		
	
	
	printf("이 반복문의 결과는 %d입니다.\n", result);
	return 1;

}
