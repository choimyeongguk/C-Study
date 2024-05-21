#include <stdio.h>

long long int fibonacci[91] = { 0 };

long long int fib(int x)
{
	if(x<3) return 1;
	if(fibonacci[x]) return fibonacci[x];
	
	fibonacci[x] = fib(x-1) + fib(x-2);
	return fibonacci[x];
}

int main()
{
	int n;
	
	scanf("%d", &n);
	printf("%lld", fib(n));
	
	return 0;
}
