#include <stdio.h>
#define INF 10000

int main()
{	
	int N, M, t1, t2, sum, min, i, j;
	int m, s, e;
	int linked[101][101];
	
	scanf("%d %d", &N, &M);
	
	for(i=1;i<=N;i++) for(j=1;j<=N;j++) linked[i][j] = INF;
	for(i=1;i<=N;i++) linked[i][i] = 0;
	for(i=0;i<M;i++)
	{
		scanf("%d %d", &t1, &t2);
		linked[t1][t2] = 1;
		linked[t2][t1] = 1;
	}
	
	for(m=1;m<=N;m++)
	{
		for(s=1;s<=N;s++)
		{
			for(e=1;e<=N;e++)
			{
				if(linked[s][e] > linked[s][m]+linked[m][e])
				{
					linked[s][e] = linked[s][m] + linked[m][e];
				}
			}
		}
	}
	
	for(min=1,i=1;i<=N;i++)
	{
		for(sum=0,j=1;j<=N;j++) sum += linked[i][j];
		linked[i][i] = sum;
		min = linked[min][min]<=linked[i][i] ? min:i;
	}
	
	printf("%d", min);
	
	return 0;
}
