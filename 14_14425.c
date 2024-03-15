#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const char* a, const char* b)
{
	int num = strcmp(a, b);
	if(num!=0) return num;
	else
	{
		if(strlen(a)<strlen(b)) return -1;
		else if(strlen(a)>strlen(b)) return 1;
		else return 0;
	}
}

//int binarySearch(char* arr, int start, int end, char* target)
//{
//	int mid;
//	while(start<=end)
//	{
//		mid = (start+end)/2;
//		if(strcmp(arr+mid*501, target)<0) start = mid+1;
//		else if(strcmp(arr+mid*501, target)>0) end = mid-1;
//		else
//		{
//			if(strlen(arr+mid*501)<strlen(target)) start = mid+1;
//			else if(strlen(arr+mid*501)>strlen(target)) end = mid-1;
//			else return 1;
//		}
//	}
//	return 0;
//}

int binarySearch(char* arr, int start, int end, char* target)
{
	int mid;
	if(start<=end)
	{
		mid = (start+end)/2;
		if(strcmp(arr+mid*501, target)<0) binarySearch(arr, mid+1, end, target);
		else if(strcmp(arr+mid*501, target)>0) binarySearch(arr, start, mid-1, target);
		else
		{
			if(strlen(arr+mid*501)<strlen(target)) binarySearch(arr, mid+1, end, target);
			else if(strlen(arr+mid*501)>strlen(target)) binarySearch(arr, start, mid-1, target);
			else return 1;
		}
	}
	else return 0;
}

int main()
{
	int N, M, num=0, i;
	char S[10000][501];
	char word[501];
	
	scanf("%d %d", &N, &M);
	for(i=0;i<N;i++) scanf("%s", S[i]);
	
	qsort(S, N, sizeof(S[0]), compare);
	
	for(i=0;i<M;i++)
	{
		scanf("%s", word);
		num = num + binarySearch(S, 0, N-1, word);
	}
	printf("%d", num);
	
	return 0;
}
