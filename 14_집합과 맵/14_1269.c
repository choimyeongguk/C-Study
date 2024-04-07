#include <stdio.h>
#include <stdlib.h>

int compare(const int* a, const int* b)
{
	return *a - *b;
}

int binarySearch(int* arr, int start, int end, int target)
{
	if(start<=end)
	{
		int mid = (start+end)/2;
		if(target<arr[mid]) binarySearch(arr, start, mid-1, target);
		else if(target>arr[mid]) binarySearch(arr, mid+1, end, target);
		else return 1;
	}
	else return 0;
}

int main()
{
	int numA, numB, numInter=0, i;
	int* A;
	int B;
	
	scanf("%d", &numA);
	A = (int*)malloc(numA*sizeof(int));
	scanf("%d", &numB);
	
	for(i=0;i<numA;i++) scanf("%d", &A[i]);
	qsort(A, numA, sizeof(int), compare);
	
	for(i=0;i<numB;i++)
	{
		scanf("%d", &B);
		numInter += binarySearch(A, 0, numA-1, B);
	}
	
	printf("%d", numA+numB-2*numInter);
	
	free(A);
	return 0;
}
