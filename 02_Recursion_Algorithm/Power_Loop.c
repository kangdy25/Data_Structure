#include <stdio.h>

int main() {
	int x, n, result = 1;
	
	printf("x의 n제곱을 계산하기 위한 숫자를 입력하세요.\n");
	scanf("%d %d", &x, &n);

	for (int i = 1 ; i <= n; i++) {
		result = result * x;
	}
	printf("%d의 %d 제곱은 %d입니다.\n", x, n, result); 

	return 1;
}
