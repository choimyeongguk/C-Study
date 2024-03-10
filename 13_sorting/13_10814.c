#include <stdio.h>
#include <string.h>

void merge(int* age, char* name, int left, int mid, int right)
{
	int ageSorted[1000];
	char nameSorted[1000][101];
	int l = left;
	int r = mid+1;
	int index = 0;
	int i;
	
	while(l<=mid && r<=right)
	{
		if(age[l]<=age[r])	
		{
			ageSorted[index] = age[l];
			for(i=0;i<=strlen(name+l*101);i++) nameSorted[index][i] = *(name+l*101+i);
			l++; index++;
		}
		else
		{
			ageSorted[index] = age[r];
			for(i=0;i<=strlen(name+r*101);i++) nameSorted[index][i] = *(name+r*101+i);
			r++; index++;
		}
	}
	while(l<=mid)
	{
		ageSorted[index] = age[l];
		for(i=0;i<=strlen(name+l*101);i++) nameSorted[index][i] = *(name+l*101+i);
		l++; index++;
	}
	while(r<=right)
	{
		ageSorted[index] = age[r];
		for(i=0;i<=strlen(name+r*101);i++) nameSorted[index][i] = *(name+r*101+i);
		r++; index++;
	}
	index--;
	
	while(index>=0)
	{
		age[left+index] = ageSorted[index];
		for(i=0;i<=strlen(nameSorted[index]);i++) *(name+(left+index)*101+i) = nameSorted[index][i];
		index--;
	}
}

void mergeSort(int* age, char* name, int left, int right)
{
	int mid;
	if(left<right)
	{
		mid = (left+right)/2;
		mergeSort(age, name, left, mid);
		mergeSort(age, name, mid+1, right);
		merge(age, name, left, mid, right);
	}
}

int main()
{
	int N, i;
	int age[1000];
	char name[1000][101];
	
	scanf("%d", &N);
	for(i=0;i<N;i++) scanf("%d %s", &age[i], &name[i]);
	
	mergeSort(age, name, 0, N-1);
	
	for(i=0;i<N;i++) printf("%d %s\n", age[i], name[i]);
	
	return 0;
}
