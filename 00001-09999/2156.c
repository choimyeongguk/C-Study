#include <stdio.h>

int main()
{
	int n, t1, t2, max = 0, i;
	int wine[10003];
	int dp[10003];
	
	wine[2] = 0;
	dp[0] = dp[1] = dp[2] = 0;  // dp[3] ���� ���� 
	
	scanf("%d", &n);
	for(i=3;i<n+3;i++)
	{
		scanf("%d", &wine[i]);
		
		t1 = wine[i] + wine[i-1] + dp[i-3];
		t2 = wine[i] + dp[i-2];
		dp[i] = t1>t2 ? t1:t2;  // wine[i]�� ���� ��� �ִ밪 
		dp[i] = dp[i]>dp[i-1] ? dp[i]:dp[i-1];  // ���� ��� �ִ밪�� ������ ���� ��� �ִ밪 �� 
	}
	
	printf("%d", dp[n+2]);
	
	return 0;
}
