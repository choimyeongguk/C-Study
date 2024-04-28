#include <stdio.h>
#include <stdlib.h>

int compare(const int *a, const int *b)
{
	return *a - *b;
}

int main()
{
	int N, i, sum=0;
	int P[1000];
	
	scanf("%d", &N);
	for(i=0;i<N;i++)
	{
		scanf("%d", &P[i]);
	}
	
	qsort(P, N, sizeof(int), compare);
	
	for(i=0;i<N;i++)
	{
		sum += P[i] * (N-i);
	}
	
	printf("%d", sum);
	
	return 0;
}
