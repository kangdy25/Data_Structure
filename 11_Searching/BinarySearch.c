#include <stdio.h>
#include <time.h>

#define MAX_ELEMENTS 10000000L
int list[MAX_ELEMENTS];

int search_binary(int key, int low, int high) {
	int middle;

	if (low <= high) {
		
		middle = (low + high) / 2;
		if (key == list[middle]) // 탐색 성공
			return middle;
		else if (key < list[middle]) // 왼쪽 부분 리스트 탐색
			return search_binary(key, low, middle - 1);
		else // 오른쪽 부분 리스트 탐색
			return search_binary(key, middle + 1, high);
	}
	return -1; // 탐색 실패
}

int search_binary2(int key, int low, int high)
{
	int middle;

	while (low <= high) {       // 아직 숫자들이 남아 있으면
		middle = (low + high) / 2;
		if (key == list[middle])
			return middle;
		else if (key > list[middle])
			low = middle + 1;
		else
			high = middle - 1;
	}
	return -1;   // 발견되지 않음
}

