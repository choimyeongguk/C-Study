#include <stdio.h>

int main()
{
	int n, x=1, i;
	int num[10] = {0,};
	for(i=0;i<3;i++)
	{
		scanf("%d", &n);
		x *= n;
	}
	
	do num[x%10]++; while(x/=10);
	
	for(i=0;i<10;i++) printf("%d\n", num[i]);
	
	return 0;
}
