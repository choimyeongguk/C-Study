#include <stdio.h>

int N;
char image[101][101];
char visited[101][101];

int dfs(int row, int col)
{
	if(visited[row][col]) return 0;
	
	visited[row][col]++;
	
	if(row>0 && image[row-1][col]==image[row][col]) dfs(row-1, col);
	if(col>0 && image[row][col-1]==image[row][col]) dfs(row, col-1);
	if(row<N-1 && image[row+1][col]==image[row][col]) dfs(row+1, col);
	if(col<N-1 && image[row][col+1]==image[row][col]) dfs(row, col+1);
	
	return 1;
}

int main()
{
	int numArea, i, j;
	
	scanf("%d", &N);
	
	for(i=0;i<N;i++)
	{
		scanf("%s", image[i]);
	}
	
	// 정상
	for(i=0;i<N;i++) for(j=0;j<N;j++) visited[i][j] = 0;
	for(numArea=0,i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(dfs(i, j)) numArea++;
		}
	}
	printf("%d ", numArea);
	
	// 적록색약
	for(i=0;i<N;i++) for(j=0;j<N;j++) if(image[i][j]=='R') image[i][j] = 'G';
	for(i=0;i<N;i++) for(j=0;j<N;j++) visited[i][j] = 0;
	for(numArea=0,i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(dfs(i, j)) numArea++;
		}
	}
	printf("%d", numArea);
	
	return 0;
}
