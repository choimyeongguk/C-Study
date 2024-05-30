#include <stdio.h>

int numCase[30][30] = { 0 };

int bridge(int N, int M)
{
	if(N==M) return 1;
	if(N==1) return M;
	if(numCase[N][M]>0) return numCase[N][M];
	
	int result = 0, i;
	for(i=M-1;i>=N-1;i--)
	{
		result += bridge(N-1, i);
	}
	numCase[N][M] = result;
	return result;
}

int main()
{
	int T, N, M, i;
	scanf("%d", &T);
	for(i=0;i<T;i++)
	{
		scanf("%d %d", &N, &M);
		printf("%d\n", bridge(N, M));
	}
	return 0;
}
