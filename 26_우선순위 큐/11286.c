#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* absHeap;
int size;

void swap(int x, int y)
{
	int tmp = absHeap[x];
	absHeap[x] = absHeap[y];
	absHeap[y] = tmp;
}

int compare(int x, int y)
{
	if(abs(absHeap[x])<abs(absHeap[y])) return -1;  // 순방향
	else if(abs(absHeap[x])==abs(absHeap[y]) && absHeap[x]<absHeap[y])  return -1;  // 순방향
	else return 1;  // 역방향 
}

void insert(int x)
{
	int loc = ++size;
	absHeap[size] = x;
	
	while(compare(loc/2, loc)>0)
	{
		swap(loc/2, loc);
		loc /= 2;
	}
}

void extract(void)
{
	if(!size)
	{
		printf("0\n");
		return;
	}
	
	int loc = 1, absMin;
	
	printf("%d\n", absHeap[1]);
	absHeap[1] = absHeap[size--];
	
	absMin = loc;
	while(loc*2<=size)
	{
		if(compare(absMin, loc*2)>0) absMin = loc*2;
		if(loc*2+1<=size && compare(absMin, loc*2+1)>0) absMin = loc*2+1;
		
		if(absMin!=loc)
		{
			swap(absMin, loc);
			loc = absMin;
		}
		else break;
	}
}

int main()
{
	int N, cmd, i;
	
	scanf("%d", &N);
	
	absHeap = (int*)calloc(N, sizeof(int));
	absHeap[0] = 0; size = 0;
	
	for(i=0;i<N;i++)
	{
		scanf("%d", &cmd);
		
		if(cmd)
		{
			insert(cmd);
		}
		else
		{
			extract();
		}
	}
	
	free(absHeap);
	return 0;
}
