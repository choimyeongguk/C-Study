#include <stdio.h>

long long int fac(int x)
{
	if(x<2) return 1;
	return x*fac(x-1);
}

int main()
{
	int N;
	
	scanf("%d", &N);
	printf("%lld", fac(N));
	return 0;
}
