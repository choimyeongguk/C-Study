#include <stdio.h>

typedef long long int lld;

int main()
{
	int N, i;
	int x[10001], y[10001];
	double area = 0;
	
	scanf("%d", &N);
	for(i=0;i<N;i++)
	{
		scanf("%d %d", &x[i], &y[i]);
	}
	x[N] = x[0];
	y[N] = y[0];
	
	for(i=0;i<N;i++)
	{
		area += (lld)x[i]*y[i+1] - (lld)x[i+1]*y[i];
	}
	
	area = (area<0 ? -1*area:area)/2;
	printf("%.1f", area);
	
	return 0;
}
