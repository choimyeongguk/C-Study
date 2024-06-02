#include <stdio.h>
#include <stdlib.h>

int compare(const int* a, const int* b)
{
	return *a - *b;
}
int main()
{
	int N, max, tmp, i;
	int* weight;
	
	scanf("%d", &N);
	
	weight = (int*)calloc(N, sizeof(int));
	for(i=0;i<N;i++)
	{
		scanf("%d", &weight[i]);
	}
	qsort(weight, N, sizeof(int), compare);
	
	for(max=0,i=0;i<N;i++)
	{
		tmp = weight[i]*(N-i);
		max = max>tmp ? max:tmp;
	}
	
	printf("%d", max);
	
	free(weight);
	return 0;
}
