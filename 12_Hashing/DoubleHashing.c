#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define KEY_SIZE	10	// 탐색키의 최대길이  
#define TABLE_SIZE	13	// 해싱 테이블의 크기=소수 
#define empty(item) (strlen(item.key)==0)
#define equal(item1, item2) (!strcmp(item1.key,item2.key))

typedef struct
{
	char key[KEY_SIZE];
	// 다른 필요한 필드들 
} element;

element hash_table[TABLE_SIZE];		// 해싱 테이블 

// 해시테이블 초기화
void init_table(element ht[])
{
	int i;
	for (i = 0; i<TABLE_SIZE; i++) {
		ht[i].key[0] = NULL;
	}
}

// 문자로 된 키를 숫자로 변환
int transform1(char *key)
{
	int number = 0;
	while (*key)
		number = number + *key++;
	return number;
}

// 제산 함수를 사용한 해싱 함수
int hash_function(char *key)
{
	// 키를 자연수로 변환한 다음 테이블의 크기로 나누어 나머지를 반환
	return transform1(key) % TABLE_SIZE;
}


void hash_dh_add(element item, element ht[])
{
	int i, hash_value, inc;
	hash_value = i = hash_function(item.key);
	inc = hash_function(item.key);
	//printf("hash_address=%d\n", i);
	while (!empty(ht[i])) {
		if (equal(item, ht[i])) {
			fprintf(stderr, "탐색키가 중복되었습니다\n");
			exit(1);
		}
		i = (i + inc) % TABLE_SIZE;
		if (i == hash_value) {
			fprintf(stderr, "테이블이 가득찼습니다\n");
			exit(1);
		}
	}
	ht[i] = item;
}
