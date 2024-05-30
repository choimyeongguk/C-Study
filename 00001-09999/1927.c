#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
	int* data;
	int size;
} HEAP;

int getLayer(int x)
{
	int layer = 1;
	int cnt = 1;
	while(x>layer)
	{
		x -= layer;
		layer *= 2;
		cnt++;
	}
	return cnt;
}

int getIdx(int layer, int order)
{
	return pow(2, layer-1)-1 + order;
}

void swap(HEAP* heap, int a, int b)
{
	int tmp = heap->data[a];
	heap->data[a] = heap->data[b];
	heap->data[b] = tmp;
}

void add(HEAP* heap, int data)
{
	heap->data[heap->size++] = data;
	
	int tmp, idxParent, idxSon;
	int layer = getLayer(heap->size);
	int order = heap->size - (pow(2, layer-1)-1) - 1;  // zero-based numbering
	
	while(layer>1)
	{
		idxSon = getIdx(layer, order);
		idxParent = getIdx(layer-1, order/2);
		if(heap->data[idxSon]<heap->data[idxParent])
		{
			swap(heap, idxSon, idxParent);
			layer--;
			order/=2;
		}
		else break;
	}
	
}

void removeMin(HEAP* heap)
{
	heap->data[0] = heap->data[--heap->size];
	
	int tmp, idxParent, idxSon;
	int layer = 1;
	int order = 0;
	
	while(layer<getLayer(heap->size))
	{
		idxParent = getIdx(layer, order);
		idxSon = getIdx(layer+1, order*2);
		if(heap->data[idxParent]>heap->data[idxSon])
		{
			swap(heap, idxParent, idxSon);
			layer++;
			order *= 2;
		}
		else
		{
			idxSon = getIdx(layer+1, order*2+1);	
			if(heap->data[idxParent]>heap->data[idxSon])
			{
				swap(heap, idxParent, idxSon);	
				layer++;
				order = order*2 + 1;	
			}
			else break;
		}
	}
}

int main()
{
	int N, cmd, i;
	HEAP minHeap;
	
	scanf("%d", &N);
	minHeap.data = (int*)calloc(N, sizeof(int));
	minHeap.size = 0;
	
	for(i=0;i<N;i++)
	{
		scanf("%d", &cmd);
		if(cmd==0)
		{
			if(minHeap.size==0)
			{
				printf("0\n");
				continue;
			}
			printf("%d\n", minHeap.data[0]);
			removeMin(&minHeap);
			continue;
		}
		add(&minHeap, cmd);
	}
	
	free(minHeap.data);
	return 0;
}
