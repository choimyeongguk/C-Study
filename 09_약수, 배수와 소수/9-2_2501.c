#include <stdio.h>

int main()
{
	int N, K, divisorNum=0, i;
	
	scanf("%d %d", &N, &K);
	for(i=1;i<N+1;i++)
	{
		if(N%i==0)
		{
			divisorNum++;
			if(divisorNum==K)
			{
				printf("%d", i);
				break;
			}
		}
	}
	if(K>divisorNum) printf("0");
	
	return 0;
}
