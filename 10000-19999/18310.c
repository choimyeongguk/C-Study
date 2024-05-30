#include <stdio.h>

void merge(int house[], int start, int mid, int end)
{
	int arr[200000];
	int i = start;
	int j = mid+1;
	int k = 0;
	
	while(i<=mid && j<=end)
	{
		if(house[i]<house[j])
		{
			arr[k++] = house[i++];
		}
		else arr[k++] = house[j++];
	}
	while(i<=mid) arr[k++] = house[i++];
	while(j<=end) arr[k++] = house[j++];
	k--;
		
	while(k>=0)
	{
		house[start+k--] = arr[k];
		k--;
	}
}

void mergeSort(int house[], int start, int end)
{
	int mid;
	if(start<end)
	{
		mid = (start+end)/2;
		mergeSort(house, start, mid);
		mergeSort(house, mid+1, end);
		merge(house, start, mid, end);
	}
}

int main()
{
	int N, i;
	int* house;
	
	scanf("%d", &N);
	
	house = (int*)calloc(N, sizeof(int));
	for(i=0;i<N;i++) scanf("%d", &house[i]);
	mergeSort(house, 0, N-1);
	
	printf("%d", house[N%2?N/2:N/2-1]);
	
	free(house);
	return 0;
}
