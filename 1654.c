#include <stdio.h>
#include <stdlib.h>

int main()
{
	int K, N, max, result, cnt, i;
	int* cable;
	
	scanf("%d %d", &K, &N);
	cable = (int*)calloc(K, sizeof(int));
	for(i=0;i<K;i++)
	{
		scanf("%d", &cable[i]);
		max = max>cable[i] ? max:cable[i];
	}
	
	long long start, end, mid;
	start = 1; end = max;
	
	while(start<=end)
	{
		mid =  (start+end)/2;
		cnt = 0;
		for(i=0;i<K;i++)
		{
			cnt += cable[i]/mid;
		}
		if(cnt>=N) result = mid;
		if(cnt<N) end = mid-1;
		else start = mid+1;
	}
	
	printf("%d", result);
	
	free(cable);
	return 0;
}
