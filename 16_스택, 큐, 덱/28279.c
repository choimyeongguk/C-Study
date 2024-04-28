#include <stdio.h>
#include <stdlib.h>

int size;

int move(int x)
{
	return (x+size)%size;
}

int main()
{
	int N, num, i;
	int cmd;
	int* deque; int head = 0, tail = 0;
	
	scanf("%d", &N);
	size = N+1;
	deque = (int*)calloc(size, sizeof(int));  // 0~N 까지 할당 
	for(i=0;i<N;i++)
	{
		scanf("%d", &cmd);
		switch(cmd)
		{
			case 1:
				scanf("%d", &num);
				head = move(--head);
				deque[head] = num;
				break;
			case 2:
				scanf("%d", &num);
				deque[tail] = num;
				tail = move(++tail);
				break;
			case 3:
				if(head==tail) printf("-1\n");
				else
				{
					printf("%d\n", deque[head]);
					head = move(++head);
				}
				break;
			case 4:
				if(head==tail) printf("-1\n");
				else
				{
					tail = move(--tail);
					printf("%d\n", deque[tail]);
				}
				break;
			case 5:
				num = tail-head;
				printf("%d\n", num>=0 ? num:size+num);
				break;
			case 6:
				printf("%d\n", head==tail ? 1:0);
				break;
			case 7:
				printf("%d\n", head==tail ? -1:deque[head]);
				break;
			case 8:
				printf("%d\n", head==tail ? -1:deque[move(tail-1)]);
				break;
		}
	}
	
	free(deque);
	return 0;
}
