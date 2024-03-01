#include <stdio.h>

int main()
{
	int N, M, i, j, k, sum, max=0;
	int card[300000];
	
	scanf("%d %d", &N, &M);
	for(i=0;i<N;i++) scanf("%d", &card[i]);
	
	for(i=0;i<N-2;i++)
	{
		for(j=i+1;j<N-1;j++)
		{
			for(k=j+1;k<N;k++)
			{
				sum = card[i] + card[j] + card[k];
				if(sum<=M) max = max>sum?max:sum;
			}
		}
	}
	printf("%d", max);
	
	return 0;
}
