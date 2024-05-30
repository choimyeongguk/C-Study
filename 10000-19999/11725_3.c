#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int left;
	int right;
} EDGE;

void findChild(EDGE* edge, int* tree, int grandParent, int parent, int N)
{	
	for(int i=0;i<N-1;i++)
	{
		// 부모와 자식이 있는 경우를 탐색해야 하므로 부모와 조부모가 들어있는 경우는 제외 
		if(edge[i].left==parent && edge[i].right!=grandParent)  // 왼쪽에 부모 노드가 있다면 
		{
			tree[edge[i].right-2] = parent;  // 오른쪽값 노드의 부모를 parent노드(왼쪽값 노드)로 설정 
			findChild(edge, tree, parent, edge[i].right, N);  // 오른쪽 값을 부모로 설정하고 자식 탐색 
		}
		if(edge[i].right==parent && edge[i].left!=grandParent)  // 오른쪽에 부모 노드가 있다면 
		{
			tree[edge[i].left-2] = parent;  // 왼쪽값 노드의 부모를 parent노드(오른쪽값 노드)로 설정 
			findChild(edge, tree, parent, edge[i].left, N);  // 왼쪽 값을 부모로 설정하고 자식 탐색 
		}
	}
} 

int main()
{
	int N, i;
	int* tree;
	EDGE* edge;
	
	scanf("%d", &N);  // 노드 개수 입력 
	
	// 트리 구조 저장할 1차원 배열. 트리에서 노드는(루트제외) 무조건 하나의 부모를 가진다 
	tree = (int*)malloc((N-1)*sizeof(int));  // 행->부모, 열->자식
	for(i=0;i<N-1;i++) tree[i] = 0;
	
	// 노드 간 연결관계 저장할 구조체 배열 
	edge = (EDGE*)malloc((N-1)*sizeof(EDGE));  // (N-1)행. 트리에서 간선의 개수는 (노드개수)-1 
	
	for(i=0;i<N-1;i++) scanf("%d %d", &edge[i].left, &edge[i].right);  // 노드 간 연결관계 입력 
	
	for(i=0;i<N-1;i++)
	{
		if(edge[i].left==1)  // 왼쪽에 루트 노드가 있다면 
		{
			tree[edge[i].right-2] = 1;  // 오른쪽값 노드의 부모를 1로 저장 
			findChild(edge, tree, 1, edge[i].right, N);  // 오른쪽값을 부모로 설정하고 자식 탐색 
		}
		if(edge[i].right==1)  // 오른쪽에 루트 노드가 있다면 
		{
			tree[edge[i].left-2] = 1;  // 왼쪽값 노드의 부모를 1로 저장 
			findChild(edge, tree, 1, edge[i].left, N);  // 왼쪽값을 부모로 설정하고 자식 탐색 
		}
	}
	
	for(i=0;i<N-1;i++) printf("%d\n", tree[i]);  // 각 노드의 부모 출력 
	
	free(edge);
	free(tree);
	
	return 0;
}
