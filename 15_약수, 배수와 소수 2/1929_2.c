#include <stdio.h>
#include <math.h>

int main()
{
	int N, M, chk, i, j;
	
	scanf("%d %d", &N, &M);
	if(N==1) N++;
	for(i=N;i<=M;i++)
	{
		chk = 0;
		for(j=2;j<=pow(i, 0.5);j++)
		{
			if(i%j==0)
			{
				chk++;
				break;
			}
		}
		if(chk==0)
		{
			printf("%d\n", i);
		}
	}
	return 0;
}
