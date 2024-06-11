#include <stdio.h>
#include <stdlib.h>

int* heap; int size = 1;

void swap(int x, int y)
{
	int tmp = heap[x];
	heap[x] = heap[y];
	heap[y] = tmp;
}

void push(int x)
{
	int loc = size;
	heap[size++] = x;
	
	while(heap[loc/2] > heap[loc])
	{
		swap(loc/2, loc);
		loc /= 2;
	}
}

int pop()
{
	if(size == 1) return -1;
	
	int min = heap[1];
	int small, left, right, loc = 1;
	heap[1] = heap[--size];
	
	while(1)
	{
		small = loc;
		left = loc*2;
		right = loc*2+1;
		if(left<size && heap[small]>heap[left]) small = left;
		if(right<size && heap[small]>heap[right]) small = right;
		
		if(loc != small)
		{
			swap(loc, small);
			loc = small;
		}
		else break;
	}
	
	return min;
}

int main()
{
	int N, tmp, sum=0, t1, t2, i;
	
	scanf("%d", &N);
	heap = (int*)calloc(N+1, sizeof(int));
	heap[0] = 0;
	
	for(i=0;i<N;i++)
	{
		scanf("%d", &tmp);
		push(tmp);
	}
	
	while(size>2)
	{	
		sum += tmp = pop() + pop();
		push(tmp);
	}
	
	printf("%d", sum);
	
	free(heap);
	return 0;
}
