#include <stdio.h>
#include <stdlib.h>

int* minHeap; int size = 1;

void swap(int x, int y)
{
	int tmp = minHeap[x];
	minHeap[x] = minHeap[y];
	minHeap[y] = tmp;
}

void add(int num)
{
	int tmp, location = size;
	minHeap[size++] = num;
	
	while(minHeap[location/2] > minHeap[location])
	{
		swap(location, location/2);
		location /= 2;
	}
}

void removeMin()
{
	if(size == 1)
	{
		printf("0\n");
		return;
	}
	else printf("%d\n", minHeap[1]);
	
	int small, left, right, location = 1;
	minHeap[1] = minHeap[--size];
	
	while(1)
	{
		small = location;
		left = location*2;
		right = location*2+1;
		if(left<size && minHeap[small]>minHeap[left]) small = left;
		if(right<size && minHeap[small]>minHeap[right]) small = right;
		
		if(location != small)
		{
			swap(location, small);
			location = small;
		}
		else break;
	}
}

int main()
{
	int N, num, i;
	
	scanf("%d", &N);
	minHeap = (int*)calloc(N+1, sizeof(int));
	minHeap[0] = 0;
	
	for(i=0;i<N;i++)
	{
		scanf("%d", &num);
		num ? add(num):removeMin();
	}
	
	free(minHeap);
	return 0;
}
