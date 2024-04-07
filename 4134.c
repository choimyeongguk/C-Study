#include <stdio.h>
#include <math.h>

int main()
{
	int T, i, k;
	long long int n, j;
	
	scanf("%d", &T);
	for(i=0;i<T;i++)
	{
		scanf("%lld", &n);
		
		if(n==0 || n==1 || n==2)
		{
			printf("2\n");
			continue;
		}
		if(n%2==0) n++;
		for(j=n;;j=j+2)
		{
			for(k=3;k<=sqrt(n);k=k+2)
			{
				if(j%k==0) goto NOPRIME;
			}
			printf("%lld\n", j);
			break;
			NOPRIME:;
		}
	}
	
	return 0;
} 
