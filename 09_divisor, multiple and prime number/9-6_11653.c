#include <stdio.h>
#include <math.h>

int main()
{
	int N, num, i;
	
	scanf("%d", &N);
	num = N;
	while(N>1)
	{
		for(i=2;i<=num;i++)
		{
			if(N%i==0)
			{
				N = N/i;
				printf("%d\n", i);
				break;
			}
		}
	}
	
	return 0;
}
