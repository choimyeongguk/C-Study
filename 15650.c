#include <stdio.h>

int N, M;
int arr[8];

void dfs(int x, int len)
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
	
	// (x까지 소모된 길이) = len+1 
	// (남은 길이) = M-len-1
	// 따라서 남은 길이까지 합쳐서 N안쪽으로 만드려면
	// x + (M-len-1) <= N 이어야 함. 
	for(;x+(M-len-1)<=N;x++)
	{
		arr[len] = x;
		dfs(x+1, len+1);
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	dfs(1, 0);
	
	return 0;
}
