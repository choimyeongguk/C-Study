#include <stdio.h>

int N;
char map[16][16] = { 0 };

int nQueen(int row)
{
	int ans=0, i, j;
	
	for(i=1;i<=N;i++)
	{
		if(!map[row][i])
		{
			for(j=1;j<=N;j++)
			{
				map[row][j]++;
				map[j][i]++;
			}
			for(j=1;row+j<=N&&i+j<=N;j++) map[row+j][i+j]++;
			for(j=1;row+j<=N&&i-j>=0;j++) map[row+j][i-j]++;
			for(j=1;row-j>=0&&i+j<=N;j++) map[row-j][i+j]++;
			for(j=1;row-j>=0&&i-j>=0;j++) map[row-j][i-j]++;
			
			if(row==N) ans++;
			else ans += nQueen(row+1);
			
			for(j=1;j<=N;j++)
			{
				map[row][j]--;
				map[j][i]--;
			}
			for(j=1;row+j<=N&&i+j<=N;j++) map[row+j][i+j]--;
			for(j=1;row+j<=N&&i-j>=0;j++) map[row+j][i-j]--;
			for(j=1;row-j>=0&&i+j<=N;j++) map[row-j][i+j]--;
			for(j=1;row-j>=0&&i-j>=0;j++) map[row-j][i-j]--;
		}
	}
	
	return ans;
}

int main()
{
	int i;
	
	scanf("%d", &N);
	printf("%d", nQueen(1));
	
	return 0;
}
