#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const char** a, const char** b)
{
	return strcmp(*a, *b);
}	

int binarySearch(char** unheard, int start, int end, char* target)
{
	if(start<=end)
	{
		int mid = (start+end)/2;
		if(strcmp(unheard[mid], target)<0) binarySearch(unheard, mid+1, end, target);
		else if(strcmp(unheard[mid], target)>0) binarySearch(unheard, start, mid-1, target);
		else return 1;
	} else return -1;
}

int main()
{
	int N, M, num=0, i, j;
	char name[21];
	char** unheard;
	char** anonymous;
	
	scanf("%d %d", &N, &M);
	
	unheard = (char**)malloc(N*sizeof(char*));
	for(i=0;i<N;i++) unheard[i] = (char*)malloc(21*sizeof(char));
	anonymous = (char**)malloc(N*sizeof(char*));
	for(i=0;i<N;i++) anonymous[i] = (char*)malloc(21*sizeof(char));
	
	for(i=0;i<N;i++) scanf("%s", unheard[i]);
	qsort(unheard, N, sizeof(unheard[0]), compare);
	
	for(i=0;i<M;i++)
	{
		scanf("%s", name);
		if(binarySearch(unheard, 0, N-1, name)>0)
		{
			for(j=0;j<=strlen(name);j++)
			{
				anonymous[num][j] = name[j];
			}
			num++;
		}
	}
	qsort(anonymous, num, sizeof(anonymous[0]), compare);
	
	printf("%d\n", num);
	for(i=0;i<num;i++) printf("%s\n", anonymous[i]);
	
	for(i=0;i<N;i++) free(unheard[i]);
	for(i=0;i<N;i++) free(anonymous[i]);
	free(unheard);
	free(anonymous);
	return 0;
}
