#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* absHeap; int size = 1;

void swap(int x, int y)
{
	int tmp = absHeap[x];
	absHeap[x] = absHeap[y];
	absHeap[y] = tmp;
}

void add(int num)
{
	int tmp1, tmp2, location = size;
	absHeap[size++] = num;
	
	
	tmp1 = absHeap[location/2];
	tmp2 = absHeap[location];
	while(abs(tmp1)>abs(tmp2) || (abs(tmp1)==abs(tmp2)&&tmp1>tmp2));
	{
		swap(location, location/2);
		location /= 2;
		tmp1 = absHeap[location/2];
		tmp2 = absHeap[location];
		
		for(int i=0;i<size;i++) printf("%d ", absHeap[i]);
		printf("\n");
	}
}

void removeMin()
{
	if(size == 1)
	{
		printf("0\n");
		return;
	}
	else printf("%d\n", absHeap[1]);
	
	int small, left, right, location = 1;
	absHeap[1] = absHeap[--size];
	
	while(1)
	{
		small = location;
		left = location*2;
		right = location*2+1;
		if(left<size && abs(absHeap[small])>abs(absHeap[left])) small = left;
		if(right<size && abs(absHeap[small])>abs(absHeap[right])) small = right;
		
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
	absHeap = (int*)calloc(N+1, sizeof(int));
	absHeap[0] = 0;
	
	for(i=0;i<N;i++)
	{
		scanf("%d", &num);
		num ? add(num):removeMin();
	}
	
	free(absHeap);
	return 0;
}
