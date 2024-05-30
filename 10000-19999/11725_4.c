#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int left;
	int right;
} EDGE;

void findChild(EDGE* edge, int head, int tail, int* tree, int grandParent, int parent, int N)
{	
	for(int i=0;i<N-1;i++)
	{
		if(edge[head].left==parent && edge[head].right!=grandParent)  // 왼쪽에 부모 노드가 있다면 
		{
			tree[edge[head].right-2] = parent;  // 오른쪽값 노드의 부모를 parent노드(왼쪽값 노드)로 설정 
			head = (head+1)%N;
			findChild(edge, head, tail, tree, parent, edge[(head-1+N)%N].right, N);  // 오른쪽 값을 부모로 설정하고 자식 탐색 
		}
		else if(edge[head].right==parent && edge[head].left!=grandParent)  // 오른쪽에 부모 노드가 있다면 
		{
			tree[edge[head].left-2] = parent;  // 왼쪽값 노드의 부모를 parent노드(오른쪽값 노드)로 설정 
			head = (head+1%N);
			findChild(edge, head, tail, tree, parent, edge[(head-1+N)%N].left, N);  // 왼쪽 값을 부모로 설정하고 자식 탐색 
		}
		else
		{
			tail = (tail+1)%N;
			edge[tail] = edge[head];
			head = (head+1)%N;
		}
	}
} 

int main()
{
	int N, i;
	int* tree;
	EDGE* edge; int head, tail;
	
	scanf("%d", &N);  // 노드 개수 입력 
	
	// 트리 구조 저장할 1차원 배열. 트리에서 노드는(루트제외) 무조건 하나의 부모를 가진다 
	tree = (int*)malloc((N-1)*sizeof(int));  // 행->부모, 열->자식
	for(i=0;i<N-1;i++) tree[i] = 0;
	
	// 노드 간 연결관계 저장할 구조체 배열 
	edge = (EDGE*)malloc((N-1)*sizeof(EDGE));  // (N-1)행. 트리에서 간선의 개수는 (노드개수)-1 
	head = 0; tail = N-2;  // 연결큐의 머리와 꼬리 설정 
	
	for(i=0;i<N-1;i++) scanf("%d %d", &edge[i].left, &edge[i].right);  // 노드 간 연결관계 입력 
	
	for(i=0;i<N-1;i++)
	{
		if(edge[head].left==1)  // 왼쪽에 루트 노드가 있다면 
		{
			tree[edge[head].right-2] = 1;  // 오른쪽값 노드의 부모를 1로 저장 
			head = (head+1)%N;
			findChild(edge, head, tail, tree, 1, edge[(head-1+N)%N].right, N);  // 오른쪽값을 부모로 설정하고 자식 탐색
		}
		else if(edge[head].right==1)  // 오른쪽에 루트 노드가 있다면 
		{
			tree[edge[head].left-2] = 1;  // 왼쪽값 노드의 부모를 1로 저장 
			head = (head+1)%N;
			findChild(edge, head, tail, tree, 1, edge[(head-1+N)%N].left, N);  // 왼쪽값을 부모로 설정하고 자식 탐색 
		}
		else
		{
			tail = (tail+1)%N;
			edge[tail] = edge[head];
			head = (head+1)%N;
		}
	}
	
	for(i=0;i<N-1;i++) printf("%d\n", tree[i]);  // 각 노드의 부모 출력 
	
	free(edge);
	free(tree);
	
	return 0;
}
