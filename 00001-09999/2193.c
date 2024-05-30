#include <stdio.h>
#include <stdlib.h>
#define lld long long int

int main()
{
	int N, i;
	lld* pinaryCase;
	
	scanf("%d", &N);
	
	if(N==1)
	{
		printf("1");
		return 0;
	}
	
	pinaryCase = (lld*)calloc(N+1, sizeof(lld));
	
	pinaryCase[1] = 1;
	pinaryCase[2] = 1;
	
	for(i=3;i<=N;i++)
	{
		pinaryCase[i] = pinaryCase[i-1] + pinaryCase[i-2];
	}
	
	printf("%lld", pinaryCase[N]);
	
	free(pinaryCase);
	return 0;
}
