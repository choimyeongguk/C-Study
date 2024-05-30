#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const int* a, const int* b)
{
	return *a - *b;
}

int main()
{
	int N, i;
	int* rank;
	long long int sum;
	
	scanf("%d", &N);
	
	rank = (int*)calloc(N+1, sizeof(int));
	
	for(i=1;i<=N;i++)
	{
		scanf("%d", &rank[i]);
	}
	qsort(rank+1, N, sizeof(int), compare);
	
	for(sum=0, i=1;i<=N;i++)
	{
		sum += abs(rank[i]-i);
	}
	printf("%lld", sum);
	
	free(rank);
	return 0;
}
