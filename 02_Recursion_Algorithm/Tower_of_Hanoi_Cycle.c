#include <stdio.h>

void Hanoi_tower(int n, char from, char tmp, char to);

int main() {
	Hanoi_tower(5, 'A', 'B', 'C');

	return 1;
}

void Hanoi_tower(int n, char from, char tmp, char to) {
	if (n == 1) {
		printf("원판 1을 %c에서 %c로 옮깁니다.\n", from, to);
	}
	else {
		Hanoi_tower(n - 1, from, to, tmp);
		printf("원판 %d를 %c에서 %c로 옮깁니다.\n", n, from, to);
		Hanoi_tower(n - 1, tmp, from, to);
		printf("\n");
		
	}


}
