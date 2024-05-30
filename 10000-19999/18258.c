#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N, num, i;
	int* queue; int head = 0, tail = 0;
	char cmd[6];
	
	scanf("%d", &N);
	queue = (int*)calloc(N, sizeof(int));
	for(i=0;i<N;i++)
	{
		scanf("%s", cmd);
		
		switch(cmd[0])
		{
			case 'p':
				if(cmd[1]=='u')
				{
					scanf("%d", &num);
					queue[tail++] = num;
				}
				else
				{
					printf("%d\n", head==tail ? -1:queue[head++]);
				}
				break;
			case 's':
				printf("%d\n", tail-head);
				break;
			case 'e':
				printf("%d\n", head==tail ? 1:0);
				break;
			case 'f':
				printf("%d\n", head==tail ? -1:queue[head]);
				break;
			case 'b':
				printf("%d\n", head==tail ? -1:queue[tail-1]);
				break;
		}
	}
	
	free(queue);
	return 0;
}
