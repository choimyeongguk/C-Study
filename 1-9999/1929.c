#include <stdio.h>
#include <math.h>

int main()
{
	int N, M, numPrime=0, chk, i, j;
	int prime[78498];
	
	scanf("%d %d", &N, &M);
	
	prime[numPrime++] = 2;
	if(N<3)
	{
		N=3;
		printf("2\n");
	}
	for(i=3;i<N;i++)
	{
		chk = 0;
		for(j=0;j<numPrime;j++)
		{
			if(i%prime[j]==0)  // ¼Ò¼ö ¾Æ´Ô 
			{
				chk = 1;
				break;
			}
			if(prime[j]>=pow(i, 0.5)) break;
		}
		if(chk==0)
		{
			prime[numPrime++] = i;
		}
	}
	for(i=N;i<=M;i++)
	{
		chk = 0;
		for(j=0;j<numPrime;j++)
		{
			if(i%prime[j]==0)
			{
				chk = 1;
				break;
			}
			if(prime[j]>=pow(i, 0.5)) break;
		}
		if(chk==0)
		{
			printf("%d\n", i);
			prime[numPrime++] = i;
		}
	}
	
	return 0;
}
