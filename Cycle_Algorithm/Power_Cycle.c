#include <stdio.h>

double Power(double x, int n);

int main() {
	printf("%.1f\n", Power(2, 10));
	
	return 1;
}

double Power(double x, int n) {
	if (n == 0) {
		return 1;
	} 
	else if (n % 2 == 0) {
		return Power(x*x, n / 2);
	}
	else {
		return x * Power(x*x, (n-1)/2);
	}
}
