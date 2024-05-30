#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int parent;
	int weight;
} TREE;

typedef struct
{
	int node;
	int distance;
} QUEUE;


TREE* tree;
int n;

int BFS(int x)
{
	int i, max=0, node, distance;
	
	int* visited = (int*)calloc(n+1, sizeof(int));
	for(i=1;i<n+1;i++) visited[i] = 0;
	visited[0] = 1;
	
	QUEUE* queue = (QUEUE*)calloc(n+1, sizeof(QUEUE));
	int head = 0, tail = 1;
	
	queue[head].node = x;
	queue[head].distance = 0;
	visited[x] = 1;
	
	while(head!=tail)
	{
		node = queue[head].node;
		distance = queue[head].distance;
		max = max>distance ? max:distance;
		
		// 부모 찾기
		if(tree[node].parent && !visited[tree[node].parent])  // 부모 있다면 
		{
			queue[tail].node = tree[node].parent;
			queue[tail++].distance = distance + tree[node].weight;
			visited[tree[node].parent] = 1;
		}
		
		// 자식 찾기 
		for(i=1;i<=n;i++)
		{
			if(tree[i].parent==node && !visited[i])
			{
				queue[tail].node = i;
				queue[tail++].distance = distance + tree[i].weight;
				visited[i] = 1;
			}
		}
		
		head++;
	}
	
	return max;
}

int main()
{
	int p, c, w, diameter, tmp, i;
	char* isLeaf;
	
	scanf("%d", &n);
	
	isLeaf = (char*)calloc(n+1, sizeof(char));
	for(i=0;i<n+1;i++) isLeaf[i] = 1;
	tree = (TREE*)calloc(n+1, sizeof(TREE));
	for(i=0;i<n+1;i++) tree[i].parent = 0;  // 부모가 없으면(루트노드) 0 
	
	for(i=0;i<n-1;i++)
	{
		scanf("%d %d %d", &p, &c, &w);
		tree[c].parent = p;
		tree[c].weight = w;
		isLeaf[p] = 0;
	}
	
	for(diameter=0,i=1;i<=n;i++)
	{
		if(isLeaf[i])
		{
			tmp = BFS(i);
			diameter = diameter>tmp ? diameter:tmp;
		}
	}
	
	printf("%d", diameter);
	
	free(tree);
	return 0;
}
