#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int val;
	int cnt;
} LIST;

int compare(const int* a, const int* b)
{
	return *a - *b;
}

int binarySearch(LIST* count, int start, int end, int target)
{
	if(start<=end)
	{
		int mid = (start+end)/2;
		if(target<count[mid].val) binarySearch(count, start, mid-1, target);
		else if(target>count[mid].val) binarySearch(count, mid+1, end, target);
		else return count[mid].cnt;
	} else return 0;
}

int main()
{
	int N, M, index, num, i;
	int* card;
	LIST* count;
	
	scanf("%d", &N);
	
	card = (int*)malloc(N*sizeof(int));
	count = (LIST*)malloc(N*sizeof(LIST));
	for(i=0;i<N;i++) count[i].cnt = 0;
	
	for(i=0;i<N;i++) scanf("%d", &card[i]);
	qsort(card, N, sizeof(int), compare);
	
	index = 0;
	count[index].val = card[0];
	count[index].cnt++;
	for(i=1;i<N;i++)
	{	
		if(card[i] != count[index].val) count[++index].val = card[i];
		count[index].cnt++;
	}
	
	scanf("%d", &M);
	for(i=0;i<M;i++)
	{
		scanf("%d", &num);
		printf("%d ", binarySearch(count, 0, index, num));
	}
	
	return 0;
}
