#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N, max, ans, i, j;
	int* arr;
	int* dp;
	
	scanf("%d", &N);
	arr = (int*)calloc(N, sizeof(int));
	dp = (int*)calloc(N, sizeof(int));
	for(i=0;i<N;i++)
	{
		scanf("%d", &arr[i]);
	}
	
	dp[0] = 1, ans = 1;
	for(i=1;i<N;i++)
	{
		for(max=0,j=0;j<i;j++)
		{
			if(arr[j]<arr[i])
			{
				max = max>dp[j] ? max:dp[j];
			}
		}
		dp[i] = max + 1;
		ans = ans>dp[i] ? ans:dp[i];
	}
	
	printf("%d", ans);
	
	free(arr);
	free(dp);
	return 0;
}
