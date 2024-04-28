#include <stdio.h>
#include <stdlib.h>

int DP(int num, int* min)
{
	int tmp;
	min[num] = 1 + min[num-1];  // 처음부터 -1하는 경우 
	if(num%2==0)
	{
		tmp = 1 + min[num/2];
		min[num] = min[num]<tmp ? min[num]:tmp;
	}
	if(num%3==0)
	{
		tmp = 1 + min[num/3];
		min[num] = min[num]<tmp ? min[num]:tmp;
	}
}

int main()
{
	int X, i;
	int* min;
	
	scanf("%d", &X);
	min = (int*)calloc(X+1, sizeof(int));
	
	min[1] = 0;
	for(i=2;i<=X;i++)
	{
		DP(i, min);
	}
	
	printf("%d", min[X]);
	
	return 0;
}
