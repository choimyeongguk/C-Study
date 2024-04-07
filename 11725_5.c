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
		if(num==-1)  // ������ ���ĵ� ���� 
		{
			if(edge[mid].left>target) binarySearch(edge, num, start, mid-1, target);
			else if(edge[mid].left<target) binarySearch(edge, num, mid+1, end, target);
			else return mid;
		}
		else  // �������� ���ĵ� ���� 
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
//		// �θ�� �ڽ��� �ִ� ��츦 Ž���ؾ� �ϹǷ� �θ�� ���θ� ����ִ� ���� ���� 
//		if(edge[i].left==parent && edge[i].right!=grandParent)  // ���ʿ� �θ� ��尡 �ִٸ� 
//		{
//			tree[edge[i].right-2] = parent;  // �����ʰ� ����� �θ� parent���(���ʰ� ���)�� ���� 
//			findChild(edge, tree, parent, edge[i].right, N);  // ������ ���� �θ�� �����ϰ� �ڽ� Ž�� 
//		}
//		if(edge[i].right==parent && edge[i].left!=grandParent)  // �����ʿ� �θ� ��尡 �ִٸ� 
//		{
//			tree[edge[i].left-2] = parent;  // ���ʰ� ����� �θ� parent���(�����ʰ� ���)�� ���� 
//			findChild(edge, tree, parent, edge[i].left, N);  // ���� ���� �θ�� �����ϰ� �ڽ� Ž�� 
//		}
//	}
} 

int main()
{
	int N, i;
	int* tree;
	EDGE* edgeL;
	EDGE* edgeR;
	
	scanf("%d", &N);  // ��� ���� �Է� 
	
	// Ʈ�� ���� ������ 1���� �迭. Ʈ������ ����(��Ʈ����) ������ �ϳ��� �θ� ������ 
	tree = (int*)malloc((N-1)*sizeof(int));  // ��->�θ�, ��->�ڽ�
	for(i=0;i<N-1;i++) tree[i] = 0;
	
	// ��� �� ������� ������ ����ü �迭 
	edgeL = (EDGE*)malloc((N-1)*sizeof(EDGE));  // (N-1)��. Ʈ������ ������ ������ (��尳��)-1 
	edgeR = (EDGE*)malloc((N-1)*sizeof(EDGE));
	
	for(i=0;i<N-1;i++)
	{
		scanf("%d %d", &edgeL[i].left, &edgeL[i].right);  // ��� �� ������� �Է� 
		edgeR[i].left = edgeL[i].left;
		edgeR[i].right = edgeR[i].right;
	}
	
	qsort(edgeL, N-1, sizeof(EDGE), compareL);
	qsort(edgeR, N-1, sizeof(EDGE), compareR);
	
	for(i=0;i<N-1;i++)
	{
		if(edgeL[i].left==1)  // ���ʿ� ��Ʈ ��尡 �ִٸ� 
		{
			tree[edgeL[i].right-2] = 1;  // �����ʰ� ����� �θ� 1�� ���� 
			findChild(edgeL, edgeR, tree, 1, edgeL[i].right, N);  // �����ʰ��� �θ�� �����ϰ� �ڽ� Ž�� 
		}
		if(edgeL[i].right==1)  // �����ʿ� ��Ʈ ��尡 �ִٸ� 
		{
			tree[edgeL[i].left-2] = 1;  // ���ʰ� ����� �θ� 1�� ���� 
			findChild(edgeL, edgeR, tree, 1, edgeL[i].left, N);  // ���ʰ��� �θ�� �����ϰ� �ڽ� Ž�� 
		}
	}
	
	for(i=0;i<N-1;i++) printf("%d\n", tree[i]);  // �� ����� �θ� ��� 
	
	free(edgeL);
	free(edgeR);
	free(tree);
	
	return 0;
}
