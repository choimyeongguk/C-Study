#include <stdio.h>
#include <stdlib.h>

int compare(const int* a, const int* b)
{
	if(*a<*b) return -1;
	else if(*a>*b) return 1;
	else return 0;
}

int main()
{
	int N, i;
	int left, right, cnt;
	int* arr;
	
	scanf("%d", &N);
	arr = (int*)malloc(N*sizeof(int));
	for(i=0;i<N;i++) scanf("%d", &arr[i]);
	qsort(arr, N, sizeof(int), compare);
	
	cnt=0;
	for(i=0;i<N;i++)
	{
		left = 0;
		right = N-1;
		while(left<right)
		{
			if(left==i)
			{
				left++;
				continue;
			}
			if(right==i)
			{
				right--;
				continue;
			}
			
			if(arr[left]+arr[right]==arr[i])
			{
				cnt++;
				break;
			}
			else if(arr[left]+arr[right]<arr[i])
			{
				left++;
			}
			else right--;
		}
	}
	printf("%d", cnt);
}
