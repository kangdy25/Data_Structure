// math.h에 포함된 수학 관계 함수를 사용하기 위해서는 compile 옵션 -lm을 붙여야 합니다.
// 그렇지 않으면 필요한 라이브러리가 링크되지 않습니다.

#include <stdio.h>
#include <math.h>

typedef struct DistancTwoPoint {
	int x; // x좌표
	int y; // y좌표

} distance;

int CalcDist(int coordX, int coordY);


int main() {
	distance a = {9, 8};
	distance b = {1, 2};
	int Xdist, Ydist;

	if(b.x >= a.x) {
		Xdist = b.x - a.x;
	} 
	else {
		Xdist = (b.x - a.x) * -1;
	}

	if(b.y >= a.y) {
		Ydist = b.y - a.y; 
	}
	else {
		Ydist = (b.y - a.y) * -1;
	}

	printf("a와 b 사이의 거리는 %d입니다. \n", CalcDist(Xdist, Ydist));
}

int CalcDist(int coordX, int coordY) {
	int powX = pow(coordX, 2);
	int powY = pow(coordY, 2);
	int routeXY = sqrt(powX + powY);

	return routeXY;
}
