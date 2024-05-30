#include <stdio.h>
#include <stdlib.h>

typedef long long int lld;

void merge(lld arr[], int start, int mid, int end)
{
	lld tmp[100000];
	int l = start;
	int r = mid+1;
	int idx = 0;
	
	while(l<=mid && r<=end)
	{
		if(arr[l]<arr[r]) tmp[idx++] = arr[l++];
		else tmp[idx++] = arr[r++];
	}
	
	while(l<=mid) tmp[idx++] = arr[l++];
	while(r<=mid) tmp[idx++] = arr[r++];
	while(--idx >= 0) arr[start+idx] = tmp[idx];
}

void mergeSort(lld arr[], int start, int end)
{
	if(start<end)
	{
		int mid = (start+end)/2;
		mergeSort(arr, start, mid);
		mergeSort(arr, mid+1, end);
		merge(arr, start, mid, end);
	}
}

int main()
{
	int i, j;
	int numPlace, numValidPlace, numVertex;
	lld tmp, x, y;
	lld* farthest;
	
	scanf("%d %d", &numPlace, &numValidPlace);
	
	farthest = (lld*)calloc(numPlace, sizeof(lld));
	
	for(i=0;i<numPlace;i++)
	{
		scanf("%d", &numVertex);
		
		for(farthest[i]=0,j=0;j<numVertex;j++)
		{
			scanf("%lld %lld", &x, &y);
			tmp = x*x + y*y;
			farthest[i] = farthest[i]>tmp ? farthest[i]:tmp;
		}
	}

	mergeSort(farthest, 0, numPlace-1);
	
	printf("%lld.00", farthest[numValidPlace-1]);
	
	free(farthest);
	return 0;
}
