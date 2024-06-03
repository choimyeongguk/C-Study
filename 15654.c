#include <stdio.h>
#include <stdlib.h>

int N, M;
int* arr;
int* seq;
char* used;

int compare(const int* a, const int* b)
{
	return *a - *b;
}

void dfs(int len)
{
	if(len==M)
	{
		for(int i=0;i<M;i++)
		{
			printf("%d ", seq[i]);
		}
		printf("\n");
		return;
	}
	
	for(int i=0;i<N;i++)
	{
		if(!used[i])
		{
			seq[len] = arr[i];
			
			used[i]++;
			dfs(len+1);
			used[i]--;
		}
	}
}

int main()
{
	int i;
	
	scanf("%d %d", &N, &M);
	arr = (int*)calloc(N, sizeof(int));
	seq = (int*)calloc(N, sizeof(int));
	used = (char*)calloc(N, sizeof(char));
	
	for(i=0;i<N;i++)
	{
		scanf("%d", &arr[i]);
	}
	qsort(arr, N, sizeof(int), compare);
	
	dfs(0);

	free(arr);
	free(seq);
	return 0;
}
