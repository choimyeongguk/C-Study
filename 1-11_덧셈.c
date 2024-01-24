#include <stdio.h>

int main()
{
	long long A, B, C;	//문제에서 제시하는 정수 크기가 int보다 큼 
	scanf("%lld %lld %lld", &A, &B, &C);
	printf("%lld", A+B+C);
	
	return 0;	
} 
