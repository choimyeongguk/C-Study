#include <stdio.h>
#include <stdlib.h>
#deinfe INF 2147483647

typedef struct
{
	int u, v, w;
} LINK;

int compare(const LINK* a, const LINK* b)
{
	return (*a).u - (*b).u;
}

int main()
{
	int V, E, K, u, v, w, i;
	int* path;
	int* start_u;
	int* start_v;
	char* visited;
	LINK* link_uSorted;
	LINK* link_vSorted;
	
	scanf("%d %d", &V, &E);
	scanf("%d", &K);
	
	path = (int*)calloc(V+1, sizeof(int));
	start = (int*)calloc(V+1, sizeof(int));
	visited = (char*)calloc(V+1, sizeof(char));
	link = (LINK*)calloc(E, sizeof(LINK));
	
	for(i=0;i<=V;i++)
	{
		path[i] = INF;
		start[i] = -1;
		visited[i] = 0;
	}
	
	for(i=0;i<E;i++)
	{
		scanf("%d %d %d", &u, &v, &w);
		link[i].u = u;
		link[i].v = v;
		link[i].w = w;
	}
	qsort(link, E, sizeof(LINK), compare);
	
	start[link[0].u] = 0;
	for(i=1;i<E;i++)
	{
		if(link[i-1].u!=link[i].u)
		{
			start[link[i].u] = i;
		}
	}
	
	for(i=start[K];link[i].u==K;i++)
	{
		path[link[i].v] = link[i].w;
	}
	visited[K]++;
	
	for(i=0;i<V-1;i++)
	{
		// 방문하지 않은 노드 중 경로가 가장 짧은 노드 
		for(m=0,j=1;j<=V;j++)
		{
			if(!visited[j] && path[j]<path[m])
			{
				m = j;
			}
		}
		
		// 선택된 노드를 경유한 최단 경로값 갱신
		for(j=start[m];link) 
	}
	
	free(path);
	free(visited);
	free(link);
	return 0;
}
