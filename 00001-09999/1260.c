#include <stdio.h>
#include <stdlib.h>

int N;
char** graph;
char* visited;

void DFS(int x)
{
	visited[x] = 1;
	printf("%d ", x);
	
	for(int i=1;i<N+1;i++)
	{
		if(graph[x][i]==1 && visited[i]==0)
		{
			DFS(i);
		}
	}
}

void BFS(int x)
{
	int queue[1000]; int head = 0, tail = 1;
	queue[head] = x;
	visited[x] = 1;
	
	while(head!=tail)
	{
		printf("%d ", queue[head]);
		for(int i=1;i<N+1;i++)
		{
			if(graph[queue[head]][i]==1 && visited[i]==0)
			{
				queue[tail++] = i;
				visited[i] = 1;
			}
		}
		head++;
	}
}

int main()
{
	int M, V, n1, n2, i, j;
	
	scanf("%d %d %d", &N, &M, &V);
	
	visited = (char*)calloc(N+1, sizeof(char));
	graph = (char**)calloc(N+1, sizeof(char*));
	for(i=0;i<N+1;i++)
	{
		graph[i] = (char*)calloc(N+1, sizeof(char));
		for(j=0;j<N+1;j++)
		{
			graph[i][j] = 0;
		}
	}
	
	for(i=0;i<M;i++)
	{
		scanf("%d %d", &n1, &n2);
		graph[n1][n2] = 1;
		graph[n2][n1] = 1;
	}
	
	for(i=0;i<N+1;i++) visited[i] = 0;
	DFS(V);
	printf("\n");
	
	for(i=0;i<N+1;i++) visited[i] = 0;
	BFS(V);
	
	for(i=0;i<N+1;i++) free(graph[i]);
	free(graph);
	return 0;
}
