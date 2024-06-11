#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int w;
	int v;
} MATERIAL;

int main()
{
	int N, K, tmp, i, j;
	MATERIAL* m;
	int** dp;  // dp[i][j]: 배낭의 최대 무게가 i이고 j번째 물건까지 살펴봤을 때 최대 가치 
	
	scanf("%d %d", &N, &K);
	
	m = (MATERIAL*)calloc(N+1, sizeof(MATERIAL));
	dp = (int**)calloc(K+1, sizeof(int*));
	for(i=0;i<=K;i++) dp[i] = (int*)calloc(N+1, sizeof(int));
	
	for(i=1;i<=N;i++)
	{
		scanf("%d %d", &m[i].w, &m[i].v);
	}
	
	for(i=0;i<=N;i++) dp[0][i] = 0;  // 배낭의 최대 무게 0인 경우 
	for(i=0;i<=K;i++) dp[i][0] = 0;  // 배낭에 담긴 물건 개수 0인 경우 
	
	for(i=1;i<=K;i++)  // 배낭의 최대 무게 1부터 K까지 
	{
		for(j=1;j<=N;j++)  // 물건 1개부터 N개 까지 
		{
			if(m[j].w<=i)  // 해당 물건을 넣을 수 있음
			{
				tmp = i-m[j].w>=0 ? m[j].v+dp[i-m[j].w][j-1]:m[j].v;  // 넣는 경우 
				dp[i][j] = dp[i][j-1]>tmp ? dp[i][j-1]:tmp;  // 안 넣는 경우 
			}
			else dp[i][j] = dp[i][j-1];
		}
	}
	printf("%d", dp[K][N]);
	
	for(i=0;i<K+1;i++) free(dp[i]);
	free(dp);
	free(m);
	return 0;
}
