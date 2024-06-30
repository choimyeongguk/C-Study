#include <stdio.h>

int main()
{
	int n, max, tmp, i;
	int previous;
	
	scanf("%d", &n);
	
	scanf("%d", &previous);
	max = previous;
	for(i=1;i<n;i++)
	{
		scanf("%d", &tmp);
		previous = previous>0 ? previous+tmp:tmp;
		max = max>previous ? max:previous;
	}
	
	printf("%d", max);
	
	return 0;
}
