#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N, tmp, i;
	int* queue; int head=0, tail=0;
	char* type;
	
	scanf("%d", &N);
	queue = (int*)calloc(N+1, sizeof(int));
	type = (char*)calloc(N+1, sizeof(char));
	
	getchar();
	for(i=0;i<N;i++)
	{
		scanf("%c", &type[i]);
		getchar();
	}
	for(i=0;i<N;i++)
	{
		scanf("%d", &tmp);
		if(type[i]=='0')
		{
			queue[tail++] = tmp;
		}
	}

	scanf("%d", &i);
	for(;i>0;i--)
	{
		scanf("%d", &tmp);
		
		head = (head+N)%(N+1);
		queue[head] = tmp;
		tail = (tail+N)%(N+1);
		printf("%d ", queue[tail]);
	}
	
	return 0;
}
