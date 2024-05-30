#include <stdio.h>

int fac(int x)
{
	if(x<2) return 1;
	return x*fac(x-1);
}

int main()
{
	int x;
	
	scanf("%d", &x);
	printf("%d", fac(x));
	
	return 0;
}
