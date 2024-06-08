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
	int** dp;  // dp[i][j]: �賶�� �ִ� ���԰� i�̰� j��° ���Ǳ��� ������� �� �ִ� ��ġ 
	
	scanf("%d %d", &N, &K);
	
	m = (MATERIAL*)calloc(N+1, sizeof(MATERIAL));
	dp = (int**)calloc(K+1, sizeof(int*));
	for(i=0;i<=K;i++) dp[i] = (int*)calloc(N+1, sizeof(int));
	
	for(i=1;i<=N;i++)
	{
		scanf("%d %d", &m[i].w, &m[i].v);
	}
	
	for(i=0;i<=N;i++) dp[0][i] = 0;  // �賶�� �ִ� ���� 0�� ��� 
	for(i=0;i<=K;i++) dp[i][0] = 0;  // �賶�� ��� ���� ���� 0�� ��� 
	
	for(i=1;i<=K;i++)  // �賶�� �ִ� ���� 1���� K���� 
	{
		for(j=1;j<=N;j++)  // ���� 1������ N�� ���� 
		{
			if(m[j].w<=i)  // �ش� ������ ���� �� ����
			{
				tmp = i-m[j].w>=0 ? m[j].v+dp[i-m[j].w][j-1]:m[j].v;  // �ִ� ��� 
				dp[i][j] = dp[i][j-1]>tmp ? dp[i][j-1]:tmp;  // �� �ִ� ��� 
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
