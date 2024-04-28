#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int weight;
	int height;
} BUILD;

int main()
{
	int N, i, j, cnt;
	BUILD* list;
	
	scanf("%d", &N);
	list = (BUILD*)calloc(N, sizeof(BUILD));
	
	for(i=0;i<N;i++)
	{
		scanf("%d %d", &list[i].weight, &list[i].height);
	}
	
	for(i=0;i<N;i++)
	{
		for(cnt=0, j=0;j<N;j++)
		{
			if(list[i].weight<list[j].weight && list[i].height<list[j].height) cnt++;
		}
		
		printf("%d ", cnt+1);
	}
	
	free(list);
	return 0;
}
