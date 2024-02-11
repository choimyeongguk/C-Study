#include <stdio.h>

int main()
{
	int N, i, j;
	int x_max, x_min, y_max, y_min;
	int x[100000], y[100000];
	
	scanf("%d", &N);
	for(i=0;i<N;i++) scanf("%d %d", &x[i], &y[i]);
	
	x_max = x[0];
	x_min = x[0];
	y_max = y[0];
	y_min = y[0];
	for(i=1;i<N;i++)
	{
		x_max = x_max>x[i]?x_max:x[i];
		x_min = x_min<x[i]?x_min:x[i];
		y_max = y_max>y[i]?y_max:y[i];
		y_min = y_min<y[i]?y_min:y[i];
	}
	printf("%d", (x_max-x_min)*(y_max-y_min));
	
	return 0;
}
