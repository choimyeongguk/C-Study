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
	int N, M, sum=0, height, cutTree, i;
	int trees[1000000];
	
	scanf("%d %d", &N, &M);
	for(i=0;i<N;i++)
	{
		scanf("%d", &trees[i]);
	}
	
	qsort(trees, N, sizeof(int), compare);
	height = trees[0];
	
	cutTree = 0;
	while(sum<M)
	{
		height--;
		sum += cutTree+1;
		for(i=cutTree+1;i<N;i++)
		{
			if(trees[i]>height)
			{
				sum += trees[i]-height;
				cutTree = i;
			}
			else break;
		}
	}
	printf("%d", height);
	
	return 0;
}
