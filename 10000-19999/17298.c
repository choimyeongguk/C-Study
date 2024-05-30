#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int value;
	int order;
} NUM;

int main()
{
	int N, i;
	int* nge;
	NUM* stack; int top = 0;
	NUM num;
	
	scanf("%d", &N);
	stack = (NUM*)malloc(N*sizeof(NUM));
	nge = (int*)malloc(N*sizeof(int));
	
	for(i=0;i<N;i++)
	{
		num.order = i;
		scanf("%d", &num.value);
		while(top>0 && stack[top-1].value<num.value)
			nge[stack[--top].order] = num.value;
			
		stack[top++] = num;
	}
	for(i=0;i<top;i++)
		nge[stack[i].order] = -1;
	
	for(i=0;i<N;i++) printf("%d ", nge[i]);
	
	free(stack);
	free(nge);
	return 0;
}
