#include <stdio.h>
#include <math.h>

int main()
{
	int N, sqNum, dotsOnLine, dotNum;
	
	scanf("%d", &N);  // 횟수 입력 
	sqNum = pow(4, N);  // 정사각형 개수
	dotsOnLine =  pow(2, N) + 1;  // 한 변에 있는 점의 개수
	dotNum = pow(dotsOnLine, 2);  // 총 점 개수 
	
	printf("%d", dotNum);
	
	return 0;
}
