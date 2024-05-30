#include <stdio.h>
#include <stdlib.h>

int compare(const int* a, const int* b)
{
	if(*a<*b) return 1;
	else if(*a>*b) return -1;
	else return 0;
}

int numTree(int* tree, int height)
{
	int sum=0, i=0;
	while(tree[i]>height)
	{
		
		sum += tree[i]-height;
		i++;
	}
	return sum;
}

int binarySearch(int* tree, int low, int high, int M)
{
	int mid;
//	if(low<=high)
//	{
		mid = (low+high)/2;
		if(numTree(tree, mid)<M)
		{
			high = mid-1;
			if(low>high) return high;
			binarySearch(tree, low, high, M);
		}
		else if(numTree(tree, mid)>M)
		{
			low = mid+1;
			if(low>high) return mid;
			binarySearch(tree, low, high, M);
		}
		else return mid;
//	}
//	else
//	{
//		return high;
//	}
}

int main()
{
	int N, M, i;
	int tree[1000000];
	
	scanf("%d %d", &N, &M);
	for(i=0;i<N;i++)
	{
		scanf("%d", &tree[i]);
	}
	
	qsort(tree, N, sizeof(int), compare);
	printf("%d", binarySearch(tree, 0, tree[0], M));
	
	return 0;
}
