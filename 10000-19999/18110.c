#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const int* a, const int* b)
{
	return *a - *b;
}

int main()
{
	int n, i, cut, sum=0;
	int difficulty[300000];
	
	scanf("%d", &n);
	if(n==0)
	{
		printf("0");
		return 0;
	}
	for(i=0;i<n;i++) scanf("%d", &difficulty[i]);
	
	qsort(difficulty, n, sizeof(int), compare);
	
	cut = round(n*0.15);
	for(i=cut;i<n-cut;i++)
	{
		sum += difficulty[i];
	}
	printf("%.0f", round((double)sum/(n-2*cut)));
	
	return 0;
}
