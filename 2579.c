#include <stdio.h>

int main()
{
	int numStair, val1, val2, i;
	int valStair[301];
	int DP[301];
	
	scanf("%d", &numStair);
	for(i=1;i<=numStair;i++)
	{
		scanf("%d", &valStair[i]);
	}
	
	DP[0] = 0;
	DP[1] = valStair[1];
	DP[2] = valStair[1] + valStair[2];
	
	for(i=3;i<=numStair;i++)
	{
		val1 = DP[i-2];
		val2 = valStair[i-1] + DP[i-3];
		DP[i] = valStair[i] + (val1>val2 ? val1:val2);
	}
	
	printf("%d", DP[numStair]);
	
	return 0;
}
