#include <stdio.h>
#define MAX 1000000000

int main()
{
	int n, ans=0, i, j;
	int stair[101][10];
	for(i=0;i<10;i++) stair[1][i] = 1;
	
	scanf("%d", &n);
	for(i=2;i<=n;i++)
	{
		stair[i][0] = stair[i-1][1];
		for(j=1;j<=8;j++)
		{
			stair[i][j] = (stair[i-1][j-1] + stair[i-1][j+1])%MAX;
		}
		stair[i][9] = stair[i-1][8];
	}

	for(i=1;i<=9;i++)
	{
		ans += stair[n][i];
		ans %= MAX;
	}
	printf("%d", ans);
	
	return 0;
}
