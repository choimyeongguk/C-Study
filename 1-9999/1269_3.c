#include <stdio.h>
#include <stdlib.h>

int compare(const int* a, const int* b)
{
	return *a - *b;
}

int main()
{
	int numA, numB, num, cnt=0, i;
	int* arr;
	
	scanf("%d %d", &numA, &numB);
	num = numA+numB;
	arr = (int*)malloc(num*sizeof(int));
	for(i=0;i<num;i++) scanf("%d", &arr[i]);
	qsort(arr, num, sizeof(int), compare);
	
	for(i=0;i<num;i++)
	{
		if(arr[i]==arr[i+1])
		{
			cnt++;
			i++;
		}
	}
	printf("%d", numA+numB-2*cnt);
	
	free(arr);
	return 0;
}
