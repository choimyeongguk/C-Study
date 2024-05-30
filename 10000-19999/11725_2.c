#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
	int value;
	struct NODE* next;
} LINKEDLIST;

void findChild(int** edge, LINKEDLIST* tree, int grandParnet, int parent)
{
	int i;
	int N = sizeof(edge)/(sizeof(int)*2)+1;
	
	for(i=0;i<N-1;i++)
	{
		if(edge[i][0]==parent && edge[i][1]!=grandParent)
		{
			
		}
		if(edge[i][1]==parent && edge[i][0]!=grandParent)
		{
			
		}
	}
} 

int main()
{
	int N, fixed, i; 
	int** edge;
	LINKEDLIST* tree;
	head -> next = NULL;
	
	scanf("%d", &N);
	
	edge = (int**)malloc((N-1)*sizeof(int*));  // 그래프 동적할당 
	for(i=0;i<2;i++) edge = (int*)malloc(2*sizeof(int));
	for(i=0;i<N-1;i++) scanf("%d %d", &edge[i][0], &edge[i][1]);  // 간선 입력 
	
	tree = (LINKEDLIST*)malloc(N*sizeof(LINKEDLIST));  // 트리 동적할당 
	
	tree[0].value = 1;  // 루트노드 1로 초기화 
	tree[0].next = NULL;
	fixed = 1;
	
	for(i=0;i<N-1;i++)
	{
		if(edge[i][0]==1)
		{
			tree[0].next = tree[fixed]
			tree[fixed].value = edge[i][1];
			tree[fixed].next = NULL;
			fixed++;
			findChild(edge, tree, 1, edge[i][1]);
		}
		if(edge[i][1]==1)
		{
			findChild(edge, tree, 1, edge[i][0]);
		}
	}
	
	for(i=0;i<2;i++) free(edge[i]);
	free(edge);
	free(tree);
	return 0;
}
