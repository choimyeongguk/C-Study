#include <stdio.h>

int disassembleSum(int x);  // 분해합 도출 

int main()
{
	int N, constructor=0;
	
	scanf("%d", &N);
	while(1)
	{
		constructor++;
		if(constructor>N) break;
		if(N==disassembleSum(constructor)) break;
	}
	if(constructor>N) printf("0");
	else printf("%d", constructor);
	
	return 0;
}

int disassembleSum(int x)
{
	int sum = x;
	
	while(x!=0)
	{
		sum += x % 10;
		x -= x % 10;
		x /= 10;
	}
	
	return sum;
}
