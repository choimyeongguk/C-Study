#include <stdio.h>

int main()
{
	int i, j, num, T, L, N, min, max, shorter, longer;
	
	scanf("%d", &T);
	for(i=0;i<T;i++)
	{
		scanf("%d %d", &L, &N);
		scanf("%d", &num);
		min = num<L-num?num:L-num;
		max = num>L-num?num:L-num;
		for(j=1;j<N;j++)
		{
			scanf("%d", &num);
			
			shorter = num<L-num?num:L-num;
			longer = L-shorter;
			min = min>shorter?min:shorter;
			max = max>longer?max:longer;
		}
		printf("%d %d\n", min, max);
	}
	
	return 0;
}
