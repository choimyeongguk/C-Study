#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
	int value;
	int num;
} MODE;

int compare1(const int* a, const int* b)
{
	return *a - *b;
}

int compare2(const MODE* a, const MODE* b)
{
	if((*a).num!=(*b).num) return (*b).num - (*a).num;
	else return (*a).value - (*b).value;
}

int main()
{
	int N, num, i;
	int* arr;
	MODE* frequency; int idx = 0;
	
	scanf("%d", &N);
	arr = (int*)calloc(N, sizeof(int));
	frequency = (MODE*)calloc(N, sizeof(MODE));
	for(i=0;i<N;i++) frequency[i].num = 0;
	
	for(i=0;i<N;i++) scanf("%d", &arr[i]);
	qsort(arr, N, sizeof(int), compare1);
	
	for(i=0,num=0;i<N;i++) num += arr[i];
	if(num<0) printf("%d\n", -1*(int)((double)abs(num)/N+0.5));
	else printf("%d\n", (int)((double)num/N+0.5));  // »ê¼úÆò±Õ 
	
	printf("%d\n", arr[N/2]);  // Áß¾Ó°ª
	 
	frequency[idx].value = arr[0];
	frequency[idx].num++;
	for(i=0;i<N-1;i++)
	{
		if(arr[i]==arr[i+1])
		{
			frequency[idx].num++;
		}
		else
		{
			frequency[++idx].value = arr[i+1];
			frequency[idx].num++;
		}
	}
	qsort(frequency, idx+1, sizeof(MODE), compare2);
	if(frequency[0].num==frequency[1].num) printf("%d\n", frequency[1].value);
	else printf("%d\n", frequency[0].value);
	
	printf("%d", arr[N-1]-arr[0]);  // ¹üÀ§ 
	
	free(arr);
	free(frequency);
	return 0;
}
