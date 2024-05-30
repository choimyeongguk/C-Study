#include <stdio.h>

int main()
{
    int N, i;
    int dp[1001];
    
    dp[0] = 1;
	dp[1] = 1;

    scanf("%d",&N);
    
    for (i=2;i<=N;i++)
    {
        dp[i]=(dp[i-1]+dp[i-2])%10007;
    }
    
    printf("%d",dp[N]);
    
    return 0;
}

