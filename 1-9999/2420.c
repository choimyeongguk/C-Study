#include <stdio.h>

int main()
{
	int N, M;
	
	scanf("%d %d", &N, &M);
	printf("%lld", N>M ? N-M:M-N);
	
	return 0;
}
