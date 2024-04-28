#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N, M, a, b, i;
	int* sum;
	
	scanf("%d %d", &N, &M);
	sum = (int*)calloc(N+1, sizeof(int));
	
	sum[0] = 0;
	for(i=1;i<=N;i++)
	{
		scanf("%d", &sum[i]);
		sum[i] += sum[i-1];
	}
	
	for(i=0;i<M;i++)
	{
		scanf("%d %d", &a, &b);
		printf("%d\n", sum[b]-sum[a-1]);
	}
	
	free(sum);
	return 0;
}
