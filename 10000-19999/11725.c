// �Է¿��� ���⿡ ���� ������ �־����� ���� -> ���� ����Ʈ�� �ƴ� ��ĸ� �̿��� ��������!
#include <stdio.h>
#include <stdlib.h>

void relationSet(char** tree, int parentNode, int N)
{
	int i;
	
	//�θ� �࿡ ����� �ڽ� ��� Ž�� 
	for(i=1;i<=N;i++)
	{
		if(tree[parentNode][i]==1)  // �θ�->�ڽ� ����� �߰� 
		{
			tree[i][parentNode] = 0;  // �ڽ�->�θ� ����� ���� 
			relationSet(tree, i, N);  // ã�� �ڽ��� �ٽ� �θ�� �����ϰ� �Լ� ȣ�� 
		}
	}
}

int main()
{
	int N, a, b, i, j;
	char** tree;  // Ʈ���� ������ ������ �迭(���) 
	
	scanf("%d", &N);  // Ʈ�� ��� ���� �Է� 
	tree = (char**)malloc((N+1)*sizeof(char*));  // ��� �����Ҵ�. 1���� ���°� ���ϱ� ������ N+1�� �Ҵ� 
	for(i=0;i<N+1;i++) tree[i] = (char*)malloc((N+1)*sizeof(char));
	for(i=1;i<=N;i++) for(j=1;j<=N;j++) tree[i][j] = '\0';  // NULL�� �ʱ�ȭ 
	
	for(i=0;i<N-1;i++)
	{
		scanf("%d %d", &a, &b);  // �� ��� �θ�/�ڽ� ���� ������� �Է� 
		tree[a][b]++;  // ��Ŀ� ���� 
		tree[b][a]++;
	}
	
	relationSet(tree, 1, N);  // �θ�/�ڽ� ���� ����. �ܼ� ����Ŭ�� ���� �׷������� Ʈ������ ��ȯ 
	
	for(j=2;j<=N;j++)  // ��(�ڽ�) 
	{
		for(i=1;i<=N;i++)  // ��(�θ�) 
		{
			if(tree[i][j]==1)
			{
				printf("%d\n", i);
				break;
			}
		} 
	}
	
	for(i=0;i<N+1;i++) free(tree[i]);
	free(tree);
	return 0;
} 
