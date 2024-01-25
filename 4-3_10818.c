#include <stdio.h>

int main()
{
	int N, num, max, min, i;
	scanf("%d", &N);
	
	scanf("%d", &num);
	max = num;
	min = num;
	
	for(i=0;i<N-1;i++)
	{
		scanf("%d", &num);
		max = max>num?max:num;
		min = min<num?min:num;
	}
	printf("%d %d", min, max);
	
	return 0;
}
