#include <stdio.h>

int sub();

int main() {
	printf("%d\n", sub(4));

	return 1;
}

int sub(int n) {
	if(n < 0) return 0;
	return n + sub(n- 3);
}
