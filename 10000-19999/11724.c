#include <stdio.h>

int N, M;
char link[1001][1001] = { 0 };

int DFS(int node)
{
	int i, chk = 0;
	char linked[1001] = { 0 };
	
	for(i=1;i<=N;i++)
	{
		if(link[node][i]==1)
		{
			chk++;
			link[node][i]--;
			link[i][node]--;
			linked[i]++;
		}
	}
	for(i=1;i<=N;i++)
	{
		if(linked[i]==1)
		{
			DFS(i);
		}
	}
	return chk;
}

int main()
{
	int cnt = 0, l1, l2, i;
	
	scanf("%d %d", &N, &M);
	for(i=0;i<M;i++)
	{
		scanf("%d %d", &l1, &l2);
		link[l1][l2] = 1;
		link[l2][l1] = 1;
	}
	for(i=1;i<=N;i++)
	{
		link[i][i] = 1;
	}
	
	for(i=1;i<=N;i++)
	{
		if(DFS(i)>0) cnt++;
	}
	printf("%d", cnt);
	
	return 0;
}
