#include <stdio.h>

int main()
{
	int N, K, cnt, i;
	int coin[10];
	
	scanf("%d %d", &N, &K);
	
	for(i=N-1;i>=0;i--)
	{
		scanf("%d", &coin[i]);
	}
	
	for(cnt=0, i=0;i<N;i++)
	{
		if(K>=coin[i])
		{
			cnt += K/coin[i];
			K %= coin[i];
		}
	}
	
	printf("%d", cnt);
	
	return 0;
}
