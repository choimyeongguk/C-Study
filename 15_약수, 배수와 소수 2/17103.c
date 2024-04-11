#include <stdio.h>
#define MAX 1000001

int main()
{
	int T, input, num, cnt, i, j;
	int prime[78499];
	char eratos[MAX]= { 0 };
	
	for(i=2;i*i<MAX;i++)
	{
		if(eratos[i]==0)
		{
			for(j=2;i*j<=MAX;j++)
			{
				eratos[i*j]++;
			}
		}
	}
	
	for(i=2,cnt=0;i<=MAX;i++)
	{
		if(eratos[i]==0)
		{
			prime[cnt++] = i;
		}
	}

	scanf("%d", &T);
	
	for(i=0;i<T;i++)
	{
		scanf("%d", &input);
		
		for(num=0, cnt=0;prime[num]<=input/2;num++)
		{
			if(eratos[input-prime[num]]==0) cnt++;
		}
		
		printf("%d\n", cnt);
	}
	
	return 0;
}
