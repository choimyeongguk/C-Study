#include <stdio.h>
#include <stdlib.h>

int DP(int* value, int loc, int connect, int top)
{
	if(loc==top) return value[top];
	
	int twoStep, oneStep;
	
	if(loc==top-1)
	{
		twoStep = -1;
	}
	else twoStep = value[loc] + DP(value, loc+2, 1, top);
	
	if(connect==2) oneStep = -1;
	else oneStep = value[loc] + DP(value, loc+1, 2, top);
	
	return oneStep>twoStep ? oneStep:twoStep;
}

int main()
{
	int N, i;
	int* value;
	
	scanf("%d", &N);
	value = (int*)calloc(N, sizeof(int));
	
	for(i=0;i<N;i++)
	{
		scanf("%d", &value[i]);
	}
	printf("%d", DP(value, 0, 1, N-1));
	
	return 0;
}
