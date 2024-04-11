#include <stdio.h>

int main()
{
	int N, sum=0, max=0, i;
	int score[1000];
	double newAvg;
	scanf("%d", &N);
	
	for(i=0;i<N;i++)
	{
		scanf("%d", &score[i]);
		sum += score[i];
		max = max>score[i]?max:score[i];
	}
	
	newAvg = 100.0f/max*sum/N;
	printf("%f", newAvg);
	
	return 0;
}
