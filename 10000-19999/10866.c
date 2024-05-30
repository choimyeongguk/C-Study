#include <stdio.h>
#define LEN 10000

int moveIndex(int a){
	return (a + LEN) % LEN;
}

int main()
{
	int N, num, i;
	int deque[LEN];
	int head = 0;
	int tail = 0;
	int size = 0;
	char cmd[11];
	
	scanf("%d", &N);
	for(i=0;i<N;i++)
	{
		for(num=0;num<11;num++) cmd[num] = 0;
		scanf("%s", cmd);
		
		if(cmd[5]=='f')  // push_front
		{
			if(size++>0) head = moveIndex(head-1);
			scanf("%d", &deque[head]);
		}
		if(cmd[5]=='b')  // push_back
		{
			if(size++>0) tail = moveIndex(tail+1);
			scanf("%d", &deque[tail]);
		}
		if(cmd[4]=='f')  // pop_front
		{
			if(size>0)
			{
				printf("%d\n", deque[head]);
				if(size--!=1) head = moveIndex(head+1);
			}
			else printf("-1\n");
		}
		if(cmd[4]=='b')  // pop_back
		{
			if(size>0)
			{
				printf("%d\n", deque[tail]);
				if(size--!=1) tail = moveIndex(tail-1);
			}
			else printf("-1\n");
		}
		if(cmd[0]=='s')  // size
		{
			printf("%d\n", size);
		}
		if(cmd[0]=='e')  // empty
		{
			printf("%d\n", size==0 ? 1:0);
		}
		if(cmd[0]=='f')  // front
		{
			printf("%d\n", size==0 ? -1:deque[head]);
		}
		if(cmd[0]=='b')  // back
		{
			printf("%d\n", size==0 ? -1:deque[tail]);
		}
	}
	
	return 0;
}
