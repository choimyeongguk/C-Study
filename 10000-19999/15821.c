#include <stdio.h>
#include <stdlib.h>

typedef long long int lld;

int compare(const lld* a, const lld* b)
{
	if(*a < *b) return -1;
	else if(*a > *b) return 1;
	else return 0;
}

int main()
{
	int i, j;
	int numPlace, numValidPlace, numVertex;
	lld tmp, x, y;
	lld* farthest;
	
	scanf("%d %d", &numPlace, &numValidPlace);
	
	farthest = (lld*)calloc(numPlace, sizeof(lld));
	
	for(i=0;i<numPlace;i++)
	{
		scanf("%d", &numVertex);
		
		for(farthest[i]=0,j=0;j<numVertex;j++)
		{
			scanf("%lld %lld", &x, &y);
			tmp = x*x + y*y;
			farthest[i] = farthest[i]>tmp ? farthest[i]:tmp;
		}
	}
	qsort(farthest, numPlace, sizeof(lld), compare);
	
	printf("%lld.00", farthest[numValidPlace-1]);
	
	free(farthest);
	return 0;
}
