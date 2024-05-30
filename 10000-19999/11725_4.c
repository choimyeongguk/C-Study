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
		if(edge[head].left==parent && edge[head].right!=grandParent)  // ���ʿ� �θ� ��尡 �ִٸ� 
		{
			tree[edge[head].right-2] = parent;  // �����ʰ� ����� �θ� parent���(���ʰ� ���)�� ���� 
			head = (head+1)%N;
			findChild(edge, head, tail, tree, parent, edge[(head-1+N)%N].right, N);  // ������ ���� �θ�� �����ϰ� �ڽ� Ž�� 
		}
		else if(edge[head].right==parent && edge[head].left!=grandParent)  // �����ʿ� �θ� ��尡 �ִٸ� 
		{
			tree[edge[head].left-2] = parent;  // ���ʰ� ����� �θ� parent���(�����ʰ� ���)�� ���� 
			head = (head+1%N);
			findChild(edge, head, tail, tree, parent, edge[(head-1+N)%N].left, N);  // ���� ���� �θ�� �����ϰ� �ڽ� Ž�� 
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
	
	scanf("%d", &N);  // ��� ���� �Է� 
	
	// Ʈ�� ���� ������ 1���� �迭. Ʈ������ ����(��Ʈ����) ������ �ϳ��� �θ� ������ 
	tree = (int*)malloc((N-1)*sizeof(int));  // ��->�θ�, ��->�ڽ�
	for(i=0;i<N-1;i++) tree[i] = 0;
	
	// ��� �� ������� ������ ����ü �迭 
	edge = (EDGE*)malloc((N-1)*sizeof(EDGE));  // (N-1)��. Ʈ������ ������ ������ (��尳��)-1 
	head = 0; tail = N-2;  // ����ť�� �Ӹ��� ���� ���� 
	
	for(i=0;i<N-1;i++) scanf("%d %d", &edge[i].left, &edge[i].right);  // ��� �� ������� �Է� 
	
	for(i=0;i<N-1;i++)
	{
		if(edge[head].left==1)  // ���ʿ� ��Ʈ ��尡 �ִٸ� 
		{
			tree[edge[head].right-2] = 1;  // �����ʰ� ����� �θ� 1�� ���� 
			head = (head+1)%N;
			findChild(edge, head, tail, tree, 1, edge[(head-1+N)%N].right, N);  // �����ʰ��� �θ�� �����ϰ� �ڽ� Ž��
		}
		else if(edge[head].right==1)  // �����ʿ� ��Ʈ ��尡 �ִٸ� 
		{
			tree[edge[head].left-2] = 1;  // ���ʰ� ����� �θ� 1�� ���� 
			head = (head+1)%N;
			findChild(edge, head, tail, tree, 1, edge[(head-1+N)%N].left, N);  // ���ʰ��� �θ�� �����ϰ� �ڽ� Ž�� 
		}
		else
		{
			tail = (tail+1)%N;
			edge[tail] = edge[head];
			head = (head+1)%N;
		}
	}
	
	for(i=0;i<N-1;i++) printf("%d\n", tree[i]);  // �� ����� �θ� ��� 
	
	free(edge);
	free(tree);
	
	return 0;
}
