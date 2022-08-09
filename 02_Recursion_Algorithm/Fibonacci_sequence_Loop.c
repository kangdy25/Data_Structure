#include <stdio.h>

int fib_iter(int n);

int main() {
	printf("피보나치 수열 계산 결과 : %d\n", fib_iter(5));
	return 1;
}

int fib_iter(int n) {

	if(n == 0) return 0;
	if(n == 1) return 1;	
	
	int a_zero = 0;
	int a_one = 1;
	int result = 0;

	for (int i = 2; i <= n; i++) {
		result = a_zero + a_one;
		a_zero = a_one;
		a_one = result;

	}

	return result;
}
