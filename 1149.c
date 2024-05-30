#include <stdio.h>
#define MIN(a,b) a<b?a:b

int main()
{
	int N, min, t1, t2, i, j;
	int house[1000][3];
	
	scanf("%d", &N);
	
	for(i=0;i<N;i++)
	{
		scanf("%d %d %d", &house[i][0], &house[i][1], &house[i][2]);
	}
	
	for(i=1;i<N;i++)
	{
		for(j=0;j<3;j++)
		{
			house[i][j] += MIN(house[i-1][(j+1)%3], house[i-1][(j+2)%3]);
		}
	}
	
    min = MIN(house[N-1][0], house[N-1][1]);
    min = MIN(min, house[N-1][2]);
	
	printf("%d", min);
	
	return 0;
}
