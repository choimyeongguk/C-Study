#include <stdio.h>
#define MAX(a,b) a>b?a:b

int main()
{
	int N, i;
	int T[16];
	int P[16];
	int profit[17];
	
	scanf("%d", &N);
	
	for(i=1;i<=N;i++)
	{
		scanf("%d %d", &T[i], &P[i]);
	}
	
	profit[N+1] = 0;  // ����� ���������� ���� ��� ��� 
	profit[N] = T[N]==1 ? P[N]:0;  // �ʱⰪ(������ ��) ���� 
	for(i=N-1;i>0;i--)
	{
		if(i+T[i]-1<=N)
		{
			profit[i] = MAX(P[i] + profit[i+T[i]], profit[i+1]);
		}
		else profit[i] = profit[i+1];
	}
	
	printf("%d", profit[1]);
	
	return 0;
}
