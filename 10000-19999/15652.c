#include <stdio.h>
#include <stdlib.h>

int N, M;
int* arr;

int dfs(int x, int len)
{
	if(len==M)
	{
		for(int i=0;i<M;i++)
		{
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}
	
	for(int i=x;i<=N;i++)
	{
		arr[len] = i;
		dfs(i, len+1);
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	arr = (int*)calloc(M, sizeof(int));
	dfs(1, 0);
	return 0;
}
