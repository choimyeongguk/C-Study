#include <stdio.h>

int main()
{
	double a1, a0, c, n0;
	
	scanf("%lf %lf", &a1, &a0);
	scanf("%lf", &c);
	scanf("%lf", &n0);
	
	if(c>a1)
	{
		if(n0>=a0/(c-a1)) printf("1");
		else printf("0");
	}
	else if(c==a1&&a0<=0)
	{
		printf("1");
	}
	else printf("0");
	
	return 0;
}
