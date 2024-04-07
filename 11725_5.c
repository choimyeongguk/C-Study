#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int left;
	int right;
} EDGE;

int compareL(const EDGE* a, const EDGE* b)
{
	return (*a).left - (*b).left;
}
int compareR(const EDGE* a, const EDGE* b)
{
	return (*a).right - (*b).right;
}

int binarySearch(EDGE* edge, int num, int start, int end, int target)
{
	int mid;
	if(start<=end)
	{
		mid = (start+end)/2; 
		if(num==-1)  // 왼쪽이 정렬된 상태 
		{
			if(edge[mid].left>target) binarySearch(edge, num, start, mid-1, target);
			else if(edge[mid].left<target) binarySearch(edge, num, mid+1, end, target);
			else return mid;
		}
		else  // 오른쪽이 정렬된 상태 
		{
			if(edge[mid].right>target) binarySearch(edge, num, start, mid-1, target);
			else if(edge[mid].right<target) binarySearch(edge, num, mid+1, end, target);
			else return mid;
		}
	}
	else return -1;
}

void findChild(EDGE* edgeL, EDGE* edgeR, int* tree, int grandParent, int parent, int N)
{
	int chk = 0;
	chk = binarySearch(edgeL, -1, 0, N-1, parent);
	if(chk!=-1)
	{
		if(edgeL[chk].right!=grandParent)
		{
			tree[edgeL[chk].right-2] = parent;
			findChild(edgeL, edgeR, tree, parent, edgeL[chk].right, N);
		}
	}
	chk = binarySearch(edgeR, 1, 0, N-1, parent);
	if(chk!=-1)
	{
		if(edgeR[chk].left!=grandParent)
		{
			tree[edgeR[chk].left-2] = parent;
			findChild(edgeL, edgeR, tree, parent, edgeR[chk].left, N);
		}
	}
//	for(int i=0;i<N-1;i++)
//	{
//		// 부모와 자식이 있는 경우를 탐색해야 하므로 부모와 조부모가 들어있는 경우는 제외 
//		if(edge[i].left==parent && edge[i].right!=grandParent)  // 왼쪽에 부모 노드가 있다면 
//		{
//			tree[edge[i].right-2] = parent;  // 오른쪽값 노드의 부모를 parent노드(왼쪽값 노드)로 설정 
//			findChild(edge, tree, parent, edge[i].right, N);  // 오른쪽 값을 부모로 설정하고 자식 탐색 
//		}
//		if(edge[i].right==parent && edge[i].left!=grandParent)  // 오른쪽에 부모 노드가 있다면 
//		{
//			tree[edge[i].left-2] = parent;  // 왼쪽값 노드의 부모를 parent노드(오른쪽값 노드)로 설정 
//			findChild(edge, tree, parent, edge[i].left, N);  // 왼쪽 값을 부모로 설정하고 자식 탐색 
//		}
//	}
} 

int main()
{
	int N, i;
	int* tree;
	EDGE* edgeL;
	EDGE* edgeR;
	
	scanf("%d", &N);  // 노드 개수 입력 
	
	// 트리 구조 저장할 1차원 배열. 트리에서 노드는(루트제외) 무조건 하나의 부모를 가진다 
	tree = (int*)malloc((N-1)*sizeof(int));  // 행->부모, 열->자식
	for(i=0;i<N-1;i++) tree[i] = 0;
	
	// 노드 간 연결관계 저장할 구조체 배열 
	edgeL = (EDGE*)malloc((N-1)*sizeof(EDGE));  // (N-1)행. 트리에서 간선의 개수는 (노드개수)-1 
	edgeR = (EDGE*)malloc((N-1)*sizeof(EDGE));
	
	for(i=0;i<N-1;i++)
	{
		scanf("%d %d", &edgeL[i].left, &edgeL[i].right);  // 노드 간 연결관계 입력 
		edgeR[i].left = edgeL[i].left;
		edgeR[i].right = edgeR[i].right;
	}
	
	qsort(edgeL, N-1, sizeof(EDGE), compareL);
	qsort(edgeR, N-1, sizeof(EDGE), compareR);
	
	for(i=0;i<N-1;i++)
	{
		if(edgeL[i].left==1)  // 왼쪽에 루트 노드가 있다면 
		{
			tree[edgeL[i].right-2] = 1;  // 오른쪽값 노드의 부모를 1로 저장 
			findChild(edgeL, edgeR, tree, 1, edgeL[i].right, N);  // 오른쪽값을 부모로 설정하고 자식 탐색 
		}
		if(edgeL[i].right==1)  // 오른쪽에 루트 노드가 있다면 
		{
			tree[edgeL[i].left-2] = 1;  // 왼쪽값 노드의 부모를 1로 저장 
			findChild(edgeL, edgeR, tree, 1, edgeL[i].left, N);  // 왼쪽값을 부모로 설정하고 자식 탐색 
		}
	}
	
	for(i=0;i<N-1;i++) printf("%d\n", tree[i]);  // 각 노드의 부모 출력 
	
	free(edgeL);
	free(edgeR);
	free(tree);
	
	return 0;
}
