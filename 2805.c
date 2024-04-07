#include <stdio.h>
#include <stdlib.h>

int compare(const int* a, const int* b)
{
	if(*a<*b) return 1;
	else if(*a>*b) return -1;
	else return 0;
}

int main()
{
	int N, M, i;
	long long low, high, mid, cutH, sum;
	int* tree;
	
	scanf("%d %d", &N, &M);
	
	tree = (int*)malloc(N*sizeof(int));
	for(i=0;i<N;i++) scanf("%d", &tree[i]);
	qsort(tree, N, sizeof(int), compare);
	
	low = 0;
	high = tree[0];
	cutH = 0;
	while(low<=high)
	{
		mid = (low+high)/2;

		i=0; sum=0;
		while(tree[i]>mid)
		{
			sum+=tree[i++]-mid;
		}
		
		if(sum<M)
		{
			high = mid-1;
		}
		else
		{
			cutH = cutH>mid ? cutH:mid;
			low = mid+1;
		}
	}
	printf("%lld", cutH);
	
	free(tree);
	return 0;
}
