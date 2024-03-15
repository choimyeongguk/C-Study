#include <stdio.h>
#include <stdlib.h>

int compare(const int* a, const int* b)
{
	return (*a - *b);
}

int binarySearch(int* arr, int start, int end, int target)
{
	if(start<=end)
	{
		int mid = (start+end)/2;

		if(arr[mid] > target) binarySearch(arr, start, mid-1, target);
		else if(arr[mid] < target) binarySearch(arr, mid+1, end, target);
		else return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	int N, M, num, i, j;
	int card[500000];
	int myCard[500000];
	
	scanf("%d", &N);
	for(i=0;i<N;i++) scanf("%d", &card[i]);
	scanf("%d", &M);
	for(i=0;i<M;i++) scanf("%d", &myCard[i]);
	
	qsort(card, N, sizeof(int), compare);
	
	for(i=0;i<M;i++) printf("%d ", binarySearch(card, 0, N-1, myCard[i]));
	
	return 0;
}
