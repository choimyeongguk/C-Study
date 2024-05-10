#include <stdio.h>

int main()
{
	int n, i;
	int dp[1001];
	
	scanf("%d", &n);
	
	dp[1] = 1;
	dp[2] = 3;
	
	for(i=3;i<=n;i++)
	{
		dp[i] = (dp[i-1] + 2*dp[i-2])%10007;
	}
	
	printf("%d", dp[n]);
	
	return 0;
}
