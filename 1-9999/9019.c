#include <stdio.h>

typedef struct
{
	int val;
	int cmd;
} BFS;

int main()
{
	int T, i, j, tmp;
	int A, B;
	int D, S, L, R;
	BFS queue[10000]; int head, tail;
	char visited[10000];
	char cmd[10000]; int top;
	
	scanf("%d", &T);
	
	for(i=0;i<T;i++)
	{
		head = 0, tail = 0, top = 0;
		for(j=0;j<10000;j++) visited[j] = 0;
		
		scanf("%d %d", &A, &B);
		
		queue[tail].val = A;
		queue[tail++].cmd = 1;
		visited[queue[head].val] = 1;
		
		while(queue[head].val!=B)
		{
			tmp = queue[head].val;
			
			D = (tmp*2)%10000;
			if(!visited[D])
			{
				queue[tail].val = D;
				queue[tail].cmd = queue[head].cmd*4 + 0;
				visited[queue[tail++].val] = 1;
			}
			
			S = (tmp+9999)%10000;
			if(!visited[S])
			{
				queue[tail].val = S;
				queue[tail].cmd = queue[head].cmd*4 + 1;
				visited[queue[tail++].val] = 1;
			}
			
			L = (tmp*10)%10000 + tmp/1000;
			if(!visited[L])
			{
				queue[tail].val = L;
				queue[tail].cmd = queue[head].cmd*4 + 2;
				visited[queue[tail++].val] = 1;
			}
			
			R = (tmp/10) + (tmp%10)*1000;
			if(!visited[R])
			{
				queue[tail].val = R;
				queue[tail].cmd = queue[head].cmd*4 + 3;
				visited[queue[tail++].val] = 1;
			}
			
			head++;
		}
		
		tmp = queue[head].cmd;
		while(tmp!=1)
		{
			switch(tmp%4)
			{
				case 0:
					cmd[top++] = 'D';
					break;
				case 1:
					cmd[top++] = 'S';
					break;
				case 2:
					cmd[top++] = 'L';
					break;
				case 3:
					cmd[top++] = 'R';
					break;
			}
			tmp /= 4;
		}
		for(j=top-1;j>=0;j--)
		{
			printf("%c", cmd[j]);
		}
		printf("\n");
	}
	
	return 0;
}
