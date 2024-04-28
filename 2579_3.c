#include <stdio.h>

typedef struct
{
	int oneStep;
	int twoStep;
} MAX;

int main()
{
	int N, i, tmp1, tmp2, max;
	int value[300];
	MAX maxPoint[300];
	
	scanf("%d", &N);
	for(i=0;i<N;i++) scanf("%d", &value[i]);
	
	maxPoint[N-1].oneStep = value[N-1];
	maxPoint[N-1].twoStep = value[N-1];
	maxPoint[N-2].oneStep = value[N-2] + maxPoint[N-1].oneStep;
	maxPoint[N-2].twoStep = -999999999;
	
	for(i=N-3;i>=0;i--)
	{
		maxPoint[i].oneStep = value[i] + maxPoint[i+1].twoStep;  // �� ĭ �� �� ĭ 
		tmp1 = value[i] + maxPoint[i+2].oneStep;  // �� ĭ �� �� ĭ 
		tmp2 = value[i] + maxPoint[i+2].twoStep;  // �� ĭ �� �� ĭ 
		maxPoint[i].twoStep = tmp1>tmp2 ? tmp1:tmp2;
	}
	
	max = maxPoint[0].oneStep>maxPoint[0].twoStep ? maxPoint[0].oneStep:maxPoint[0].twoStep;
	printf("%d", max);
	
	free(value);
	free(maxPoint);
	return 0;
}
