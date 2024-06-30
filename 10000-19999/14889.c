#include <stdio.h>

int N, M, min=10000;
int synergy[20][20] = { 0 };
char team[20] = { 0 };

void dfs(int x, int n)
{
	if(n==M)
	{
		int diff, teamA=0, teamB=0, i, j;
		
		for(i=0;i<N;i++)
		{
			for(j=i+1;j<N;j++)
			{
				teamA += synergy[i][j]*team[i]*team[j];
				teamB += synergy[i][j]*!team[i]*!team[j];
			}
		}

		diff = teamA>teamB ? teamA-teamB:teamB-teamA;
		min = min<diff ? min:diff;
		return;
	}
	
	for(;x-n<=M && !team[x];x++)
	{	
		team[x]++;
		dfs(x+1, n+1);
		team[x]--;
	}
}

int main()
{
	int i, j;
	
	scanf("%d", &N);
	M = N/2;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			scanf("%d", &synergy[i][j]);
		}
	}
	
	for(i=0;i<N;i++)
	{
		for(j=i+1;j<N;j++)
		{
			synergy[i][j] += synergy[j][i];
		}
	}
	
	dfs(0, 0);
	printf("%d", min);
	
	return 0;
 } 
