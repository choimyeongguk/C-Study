#include <stdio.h>
#include <stdlib.h>

void dfs(char** map, int N, int M, int row, int col)
{
	map[row][col]--;
	if(row>0 && map[row-1][col]==1) dfs(map, N, M, row-1, col);
	if(col>0 && map[row][col-1]==1) dfs(map, N, M, row, col-1);
	if(row<N-1 && map[row+1][col]==1) dfs(map, N, M, row+1, col);
	if(col<M-1 && map[row][col+1]==1) dfs(map, N, M, row, col+1);
}

int main()
{
	int T, M, N, K, X, Y, cnt, i, j, k;
	char** map;
	
	scanf("%d", &T);
	
	for(i=0;i<T;i++)
	{
		scanf("%d %d %d", &M, &N, &K);  // 열, 행, 개수 
		
		map = (char**)calloc(N, sizeof(char*));
		for(j=0;j<N;j++) map[j] = (char*)calloc(M, sizeof(char));
		for(j=0;j<N;j++) for(k=0;k<M;k++) map[j][k] = 0;
		
		for(j=0;j<K;j++)
		{
			scanf("%d %d", &X, &Y);
			map[Y][X]++;
		}
		
		for(cnt=0, j=0;j<N;j++)
		{
			for(k=0;k<M;k++)
			{
				if(map[j][k]==1)
				{
					dfs(map, N, M, j, k);
					cnt++;
				}
			}
		}
		
		printf("%d\n", cnt);
	}
	
	for(i=0;i<N;i++) free(map[i]);
	free(map);
	return 0;
}
