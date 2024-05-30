#include <stdio.h>

int main()
{
	int a1, a0, c, n0;
	
	scanf("%d %d", &a1, &a0);
	scanf("%d", &c);
	scanf("%d", &n0);
	
	if(c<a1 && n0>=(double)a0/(c-a1)) printf("1");
	else if(c==a1 && a0>=0) printf("1");
	else printf("0");
	
	return 0;
}
