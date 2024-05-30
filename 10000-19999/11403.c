#include <stdio.h>
#define min(a,b) a<b?a:b
#define INF 127

int main()
{
	int N, i, j, k;
	char link[100][100];
	
	scanf("%d", &N);
	
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			scanf(" %c", &link[i][j]);
			link[i][j] -= 48;
			if(link[i][j]==0)
			{
				link[i][j] = INF;
			}
		}
	}
	
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			for(k=0;k<N;k++)
			{
				link[j][k] = min(link[j][k], link[j][i]+link[i][k]);
			}
		}
	}
	
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{	
			if(link[i][j]>N) printf("0 ");
			else printf("1 ");
		}
		printf("\n");
	}
	
	return 0;
}
