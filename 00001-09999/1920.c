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
	int N, M, num, i;
	int arr[100000];
	
	scanf("%d", &N);
	for(i=0;i<N;i++) scanf("%d", &arr[i]);
	
	qsort(arr, N, sizeof(int), compare);
	
	scanf("%d", &M);
	for(i=0;i<M;i++)
	{
		scanf("%d", &num);
		if(bsearch(&num, arr, N, sizeof(int), compare)==NULL) printf("0\n");
		else printf("1\n");
	}
	
	return 0;
}
