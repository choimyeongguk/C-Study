#include <stdio.h>

int main()
{
	int a1, a0, c1, c2, n0;
	
	scanf("%d %d", &a1, &a0);
	scanf("%d %d", &c1, &c2);
	scanf("%d", &n0);
	
	if(a1>c1 && n0>=(double)a0/(c1-a1))
	{
		if(a1<c2 && n0>=(double)a0/(c2-a1)) printf("1");
		else if(a1==c2 && a0<=0) printf("1");
		else printf("0");
	}
	else if(a1==c1 && a0>=0)
	{
		if(a1<c2 && n0>=(double)a0/(c2-a1)) printf("1");
		else if(a1==c2 && a0<=0) printf("1");
		else printf("0");
	}
	else printf("0");
	
	return 0;
}
