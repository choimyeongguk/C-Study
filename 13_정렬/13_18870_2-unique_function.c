#include <stdio.h>

void mergeSort(int* sort, int left, int right)
{
	if(left<right)
	{
		int mid = (left+right)/2;
		mergeSort(sort, left, mid);
		mergeSort(sort, mid+1, right);
		
		int arr[1000000];
		int l = left;
		int r = mid+1;
		int index = 0;
		
		while(l<=mid && r<=right)
		{
			if(sort[l]<=sort[r])
			{
				arr[index] = sort[l];
				l++; index++;
			}
			else
			{
				arr[index] = sort[r];
				r++; index++;
			}
		}
		while(l<=mid)
		{
			arr[index] = sort[l];
			l++; index++;
		}
		while(r<=mid)
		{
			arr[index] = sort[r];
			r++; index++;
		}
		index--;
		while(index>=0)
		{
			sort[left+index] = arr[index];
			index--;
		}
	}
}

int binarySearch(int* dedupedSort, int start, int end, int target)
{
	int mid = (start+end)/2;
	if(dedupedSort[mid]==target) return mid;
	else if(dedupedSort[mid]>target) binarySearch(dedupedSort, start, mid-1, target);
	else binarySearch(dedupedSort, mid+1, end, target);
}

int unique(int* arr, int size) {
	int i, j = 0;
	for (i = 1; i < size;i++) {
		if (arr[j] == arr[i]) continue;
		arr[++j] = arr[i];
	}
	return ++j;
}

int main()
{
	int N, num=1, i;
	int coordinate[1000000];
	int sort[1000000];
//	int dedupedSort[1000000];
	
	scanf("%d", &N);
	for(i=0;i<N;i++)
	{
		scanf("%d", &coordinate[i]);
		sort[i] = coordinate[i];
	}
	
	mergeSort(sort, 0, N-1);
	
//	dedupedSort[0] = sort[0];
//	for(i=1;i<N;i++)
//	{
//		if(dedupedSort[num-1]!=sort[i])
//		{
//			dedupedSort[num] = sort[i];
//			num++;
//		}
//	}
	num = unique(sort, N);
	
	for(i=0;i<N;i++) printf("%d ", binarySearch(sort, 0, num-1, coordinate[i]));
	
	return 0;
}
