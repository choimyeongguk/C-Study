#include <stdio.h>
#include <stdlib.h>

int compare(const int* a, const int* b)
{
	return *b - *a;
}

int main()
{
	int N, sum, chk, i;
	int* straw;
	
	scanf("%d", &N);
	
	straw = (int*)calloc(N, sizeof(int));
	for(i=0;i<N;i++)
	{
		scanf("%d", &straw[i]);
	}
	qsort(straw, N, sizeof(int), compare);
	
	for(chk=0,i=0;i<N-2;i++)
	{
		if(straw[i]<straw[i+1]+straw[i+2])
		{
			sum = straw[i]+straw[i+1]+straw[i+2];
			chk++;
			break;
		}
	}
	printf("%d", chk?sum:-1);
	
	free(straw);
	return 0;
}
