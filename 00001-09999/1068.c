#include <stdio.h>

void deleteNode(int* parent, int num, int N)
{
	for(int i=0;i<N;i++)
	{
		if(parent[i]==num)
		{
			deleteNode(parent, i, N);
		}
	}
	parent[num] = -2;
}

int isLeaf(int* parent, int num, int N)
{
	if(parent[num]==-2) return 0;
	for(int i=0;i<N;i++)
	{
		if(parent[i]==num) return 0;
	}
	return 1;
}

int main()
{
	int N, i;
	int num, cnt = 0;
	int parent[51];
	
	scanf("%d", &N);
	
	for(i=0;i<N;i++) scanf("%d", &parent[i]);
	scanf("%d", &num);
	
	deleteNode(parent, num, N);
	
	for(i=0;i<N;i++)
	{
		if(isLeaf(parent, i, N)==1) cnt++;
	}
	printf("%d", cnt);
	
	return 0;
}
