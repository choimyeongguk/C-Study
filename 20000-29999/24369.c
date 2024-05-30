#include <stdio.h>
#include <math.h>

int main()
{
	int a2, a1, a0, c, n0, D;
	
	scanf("%d %d %d", &a2, &a1, &a0);
	scanf("%d", &c);
	scanf("%d", &n0);
	
	D = pow(a1, 2)-4*(a2-c)*a0;
	
	if(a2>c)
	{
		if(D<=0) printf("1");
		else if(D>0 && n0>=(double)(-1*a1+pow(D, 0.5))/(2*(a2-c))) printf("1");
		else printf("0");
	}
	else if(a2==c)
	{
		if(a1==0 && a0>=0) printf("1");
		else if(a1>0 && n0>=(double)-1*(a0/a1)) printf("1");
		else printf("0");
	}
	else printf("0");
	
	return 0;
}
