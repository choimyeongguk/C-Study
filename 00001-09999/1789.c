#include <stdio.h>

int main()
{
	long long int S, N=1;
	
	scanf("%lld", &S);
	while((N*(N+1))/2<=S) N++;
	printf("%lld", N-1);
	
	return 0;
}
