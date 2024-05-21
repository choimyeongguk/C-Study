#include <stdio.h>
#include <stdlib.h>
#define MAX(a,b) a>b?a:b

int R, C;
int max = 0;
int** paper;
char d[2][4] = { {1, -1, 0, 0}, {0, 0, 1, -1} };

void dfs(int row, int col, int len, int val)
{
	if(len==4)
	{
		max = MAX(max, val+paper[row][col]);
		return;
	}
	
	int r, c, tmp, i;
	
	for(i=0;i<4;i++)
	{
		r = row + d[0][i];
		c = col + d[1][i];
		
		if(r>=0 && c>=0 && r<R && c<C && paper[r][c])
		{
			tmp = paper[row][col];
			paper[row][col] = 0;
			
			dfs(r, c, len+1, val+tmp);
			
			paper[row][col] = tmp;
		}
	}
}

int main()
{
	int i, j, k, r, c, tmp;
	
	scanf("%d %d", &R, &C);
	
	paper = (int**)calloc(R, sizeof(int*));
	for(i=0;i<R;i++)
	{
		paper[i] = (int*)calloc(C, sizeof(int));
		for(j=0;j<C;j++)
		{
			scanf("%d", &paper[i][j]);
		}
	}
	
	// ¿³¸ð¾ç
	for(i=1;i<R;i++)  // ¤Ç 
	{
		for(j=1;j<C-1;j++)
		{
			max = MAX(max, paper[i][j]+paper[i-1][j]+paper[i][j-1]+paper[i][j+1]);
		}
	}
	for(i=0;i<R-1;i++)  // ¤Ì 
	{
		for(j=1;j<C-1;j++)
		{
			max = MAX(max, paper[i][j]+paper[i+1][j]+paper[i][j-1]+paper[i][j+1]);
		}
	}
	for(i=1;i<R-1;i++)  //¤¿ 
	{
		for(j=0;j<C-1;j++)
		{
			max = MAX(max, paper[i][j]+paper[i+1][j]+paper[i-1][j]+paper[i][j+1]);
		}
	}
	for(i=1;i<R-1;i++)  // ¤Ã 
	{
		for(j=1;j<C;j++)
		{
			max = MAX(max, paper[i][j]+paper[i+1][j]+paper[i-1][j]+paper[i][j-1]);
		}
	}
	
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			dfs(i, j, 1, 0);
			//paper[i][j] = 0;
		}
	}
	
	printf("%d", max);
	
	for(i=0;i<R;i++) free(paper[i]);
	free(paper);
	return 0;
}
