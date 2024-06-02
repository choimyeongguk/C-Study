#include <stdio.h>

int N, M;
int arr[8];

void dfs(int x, int len)
{	
	if(len==M)
	{
		for(int i=0;i<M;i++)
		{
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}
	
	// (x���� �Ҹ�� ����) = len+1 
	// (���� ����) = M-len-1
	// ���� ���� ���̱��� ���ļ� N�������� �������
	// x + (M-len-1) <= N �̾�� ��. 
	for(;x+(M-len-1)<=N;x++)
	{
		arr[len] = x;
		dfs(x+1, len+1);
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	dfs(1, 0);
	
	return 0;
}
