#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N, i;
	int minCost, location;
	long long int sumCost;
	long long int* distance;
	long long int* cost;
	
	scanf("%d", &N);
	
	distance = (long long int*)calloc(N-1, sizeof(long long int));
	cost = (long long int*)calloc(N, sizeof(long long int));
	
	for(i=0;i<N-1;i++) scanf("%lld", &distance[i]);
	for(i=0;i<N;i++) scanf("%lld", &cost[i]);
	
	sumCost = 0;
	location = 0;
	minCost = cost[location];
	
	while(location<N-1)
	{	
		sumCost += distance[location]*minCost;
		location++;
		if(cost[location]<minCost) minCost = cost[location];
	}
	
	printf("%lld", sumCost);
	
	free(distance);
	free(cost);
	return 0;
}
