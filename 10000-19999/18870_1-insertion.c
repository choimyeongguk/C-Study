#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b)
{
	int num1 = *(int *)a;
	int num2 = *(int *)b;
	if(num1<num2) return -1;
	if(num1>num2) return 1;
	return 0;
}

int binarySearch(int* dedupedSort, int start, int end, int target)
{
	int mid = (start+end)/2;
	if(dedupedSort[mid]==target) return mid;
	else if(dedupedSort[mid]>target) binarySearch(dedupedSort, start, mid-1, target);
	else binarySearch(dedupedSort, mid+1, end, target);
}

int main()
{
	int N, num=1, i;
	int coordinate[1000000];
	int sort[1000000];
	int dedupedSort[1000000];
	
	scanf("%d", &N);
	for(i=0;i<N;i++)
	{
		scanf("%d", &coordinate[i]);
		sort[i] = coordinate[i];
	}
	
	qsort(sort, N, sizeof(int), compare);
	
	dedupedSort[0] = sort[0];
	for(i=1;i<N;i++)
	{
		if(dedupedSort[num-1]!=sort[i])
		{
			dedupedSort[num] = sort[i];
			num++;
		}
	}
	
	for(i=0;i<N;i++) printf("%d ", binarySearch(dedupedSort, 0, num-1, coordinate[i]));
	
	return 0;
}
