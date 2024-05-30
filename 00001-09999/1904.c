#include <stdio.h>

int main()
{
	int N, i;
	int fib[3];
	
	scanf("%d", &N);
	
	fib[0] = 1, fib[1] = 2;
	for(i=2;i<N;i++)
	{
		fib[i%3] = (fib[(i+1)%3]+fib[(i+2)%3])%15746;
	}
	printf("%d", fib[(N-1)%3]);
	
	return 0;
}
