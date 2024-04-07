#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N, max, i, j;
	int* arr;
	int* nge;
	
	scanf("%d", &N);
	arr = (int*)malloc(N*sizeof(int));
	nge = (int*)malloc(N*sizeof(int));
	for(i=0;i<N;i++) scanf("%d", &arr[i]);
	
	nge[N-1] = -1;
	max = arr[N-1];
	for(i=N-2;i>=0;i--)
	{
		if(max>arr[i])
		{
			for(j=i+1;j<N;j++)
			{
				if(arr[j]>arr[i])
				{
					nge[i] = arr[j];
					max = max>arr[j] ? max:arr[j];
					break;
				}
			}
		}
		else
		{
			max = arr[i];
			nge[i] = -1;
		}
	}
	for(i=0;i<N;i++) printf("%d ", nge[i]);
	
	free(arr);
	return 0;
}
