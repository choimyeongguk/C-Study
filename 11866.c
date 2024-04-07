#include <stdio.h>

int main()
{
	int N, K, head, tail, i;
	int Queue[1000000];
	
	scanf("%d %d", &N, &K);
	
	head = 0;
	tail = N-1;
	for(i=0;i<N;i++)
		Queue[i] = i+1;
	
	printf("<");
	while(head<=tail)
	{
		for(i=0;i<K-1;i++)
		{
			Queue[++tail] = Queue[head++];
		}
		if(head!=tail) printf("%d, ", Queue[head++]);
		else printf("%d", Queue[head++]);
	}
	printf(">");
	
	return 0;
} 
