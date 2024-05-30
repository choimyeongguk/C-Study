#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int height;
	int weight;
	int num;
} BUILD;

int compare(const BUILD* a, const BUILD* b)
{
	if((*a).height<(*b).height && (*a).weight<(*b).weight) return 1;
	else if((*a).height>(*b).height && (*a).weight>(*b).weight) return -1;
	else return 0;
}

int main()
{
	int N, rank=1, num, i;
	int* ranking;
	BUILD* list;
	
	scanf("%d", &N);
	ranking = (int*)calloc(N, sizeof(int));
	list = (BUILD*)calloc(N, sizeof(BUILD));
	
	for(i=0;i<N;i++)
	{
		list[i].num = i;
		scanf("%d %d", &list[i].weight, &list[i].height);
	}
	
	qsort(list, N, sizeof(BUILD), compare);
	
	ranking[list[0].num] = rank;
	num = 1;
	for(i=1;i<N;i++)
	{
		if(compare(&list[i-1], &list[i])!=0)
		{
			rank += num;
			num = 0;
		}
		num++;
		ranking[list[i].num] = rank;
	}
	
	for(i=0;i<N;i++)
	{
		printf("%d ", ranking[i]);
	}
	
	free(ranking);
	free(list);
	return 0;
}
