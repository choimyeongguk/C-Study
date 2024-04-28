#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char domain[21];
	char password[21];
} PSWRD;

int compare(const PSWRD* a, const PSWRD* b)
{
	return strcmp((*a).domain, (*b).domain);
}

void binarySearch(PSWRD* pswrd, int start, int end, char* name)
{
	int mid = (start+end)/2;
	if(strcmp(name, pswrd[mid].domain)<0) binarySearch(pswrd, start, mid-1, name);
	else if(strcmp(name, pswrd[mid].domain)>0) binarySearch(pswrd, mid+1, end, name);
	else printf("%s\n", pswrd[mid].password);
}

int main()
{
	int N, M, i;
	char name[21];
	PSWRD* pswrd;
	
	scanf("%d %d", &N, &M);
	pswrd = (PSWRD*)calloc(N, sizeof(PSWRD));
	
	for(i=0;i<N;i++)
	{
		scanf("%s %s", pswrd[i].domain, pswrd[i].password);
	}
	qsort(pswrd, N, sizeof(PSWRD), compare);
	
	for(i=0;i<M;i++)
	{
		scanf("%s", name);
		binarySearch(pswrd, 0, N-1, name);
	}
	
	free(pswrd);
	return 0;
}
