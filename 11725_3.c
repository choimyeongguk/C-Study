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
		// �θ�� �ڽ��� �ִ� ��츦 Ž���ؾ� �ϹǷ� �θ�� ���θ� ����ִ� ���� ���� 
		if(edge[i].left==parent && edge[i].right!=grandParent)  // ���ʿ� �θ� ��尡 �ִٸ� 
		{
			tree[edge[i].right-2] = parent;  // �����ʰ� ����� �θ� parent���(���ʰ� ���)�� ���� 
			findChild(edge, tree, parent, edge[i].right, N);  // ������ ���� �θ�� �����ϰ� �ڽ� Ž�� 
		}
		if(edge[i].right==parent && edge[i].left!=grandParent)  // �����ʿ� �θ� ��尡 �ִٸ� 
		{
			tree[edge[i].left-2] = parent;  // ���ʰ� ����� �θ� parent���(�����ʰ� ���)�� ���� 
			findChild(edge, tree, parent, edge[i].left, N);  // ���� ���� �θ�� �����ϰ� �ڽ� Ž�� 
		}
	}
} 

int main()
{
	int N, i;
	int* tree;
	EDGE* edge;
	
	scanf("%d", &N);  // ��� ���� �Է� 
	
	// Ʈ�� ���� ������ 1���� �迭. Ʈ������ ����(��Ʈ����) ������ �ϳ��� �θ� ������ 
	tree = (int*)malloc((N-1)*sizeof(int));  // ��->�θ�, ��->�ڽ�
	for(i=0;i<N-1;i++) tree[i] = 0;
	
	// ��� �� ������� ������ ����ü �迭 
	edge = (EDGE*)malloc((N-1)*sizeof(EDGE));  // (N-1)��. Ʈ������ ������ ������ (��尳��)-1 
	
	for(i=0;i<N-1;i++) scanf("%d %d", &edge[i].left, &edge[i].right);  // ��� �� ������� �Է� 
	
	for(i=0;i<N-1;i++)
	{
		if(edge[i].left==1)  // ���ʿ� ��Ʈ ��尡 �ִٸ� 
		{
			tree[edge[i].right-2] = 1;  // �����ʰ� ����� �θ� 1�� ���� 
			findChild(edge, tree, 1, edge[i].right, N);  // �����ʰ��� �θ�� �����ϰ� �ڽ� Ž�� 
		}
		if(edge[i].right==1)  // �����ʿ� ��Ʈ ��尡 �ִٸ� 
		{
			tree[edge[i].left-2] = 1;  // ���ʰ� ����� �θ� 1�� ���� 
			findChild(edge, tree, 1, edge[i].left, N);  // ���ʰ��� �θ�� �����ϰ� �ڽ� Ž�� 
		}
	}
	
	for(i=0;i<N-1;i++) printf("%d\n", tree[i]);  // �� ����� �θ� ��� 
	
	free(edge);
	free(tree);
	
	return 0;
}
