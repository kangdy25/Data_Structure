#include <stdio.h>

int main() {
	int n, i;
	int result = 1;
	printf("숫자를 입력하세요. -> ");
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		result *= i;
	}
		
	printf("%d! = %d\n", n, result);
	return 1;
}
