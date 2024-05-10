#include <stdio.h>
#include <stdlib.h>

int* maxHeap; int size = 1;

void swap(int x, int y)
{
	int tmp = maxHeap[x];
	maxHeap[x] = maxHeap[y];
	maxHeap[y] = tmp;
}

void add(int num)
{
	int tmp, location = size;
	maxHeap[size++] = num;
	
	while(maxHeap[location/2] < maxHeap[location] && location/2>=1)
	{
		swap(location, location/2);
		location /= 2;
	}
}

void removeMax()
{
	if(size == 1)
	{
		printf("0\n");
		return;
	}
	else printf("%d\n", maxHeap[1]);
	
	int big, left, right, location = 1;
	maxHeap[1] = maxHeap[--size];
	
	while(1)
	{
		big = location;
		left = location*2;
		right = location*2+1;
		if(left<size && maxHeap[big]<maxHeap[left]) big = left;
		if(right<size && maxHeap[big]<maxHeap[right]) big = right;
		
		if(location != big)
		{
			swap(location, big);
			location = big;
		}
		else break;
	}
}

int main()
{
	int N, num, i;
	
	scanf("%d", &N);
	maxHeap = (int*)calloc(N+1, sizeof(int));
	maxHeap[0] = 0;
	
	for(i=0;i<N;i++)
	{
		scanf("%d", &num);
		num ? add(num):removeMax();
	}
	
	free(maxHeap);
	return 0;
}
