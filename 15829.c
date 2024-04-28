#include <stdio.h>

int main()
{
	int L, i, j;
	long long int num, sum = 0;
	char input;
	
	const int r = 31;
	const int M = 1234567891;  // 1,234,567,891(M) < 2,147,483,647(int) < M*2
	
	scanf("%d", &L);
	getchar();  // 키보드 I/O buffer에 들어온 enter값 소모 
	
	for(i=0;i<L;i++)
	{
		input = getchar();
		num = input - 96;  // 1 <= num <= 26
		for(j=0;j<i;j++)
		{
			num *= r;
			if(num > M) num %= M;
		}
		sum += num;
	}
	
	printf("%d", sum%M);
	
	return 0;
}
