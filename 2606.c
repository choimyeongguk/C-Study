#include <stdio.h>
#include <stdlib.h>

void DFS(char** network, int N, int host, int* cnt)
{
	int i;
	
	for(i=1;i<=N;i++)
	{
		network[i][host] = 0;
	}
	for(i=1;i<=N;i++)
	{
		if(network[host][i]==1)
		{
			(*cnt)++;
			DFS(network, N, i, cnt);
		}
	}
}

int main()
{
	int N, M, a, b, i, j, cnt=0;
	char** network;
	
	scanf("%d", &N);
	scanf("%d", &M);
	network = (char**)calloc(N+1, sizeof(char*));
	for(i=0;i<=N;i++) network[i] = (char*)calloc(N+1, sizeof(char));
	for(i=0;i<=N;i++) for(j=0;j<=N;j++) network[i][j] = 0;
	
	for(i=0;i<M;i++)
	{
		scanf("%d %d", &a, &b);
		network[a][b] = 1;
		network[b][a] = 1;
	}
	
	DFS(network, N, 1, &cnt);
	
	printf("%d", cnt);
	
	return 0;
}
