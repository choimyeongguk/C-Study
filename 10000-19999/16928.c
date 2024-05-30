#include <stdio.h>

typedef struct
{
	int loc;
	int mov;
} QUEUE;

int main()
{
	int N, M, t1, t2, nextLoc, i;
	int move[101] = { 0 };  // move[a]==b -> a칸에 도달하면 b칸으로 이동 
	char visited[101] = { 0 };
	QUEUE queue[100]; int head=0, tail=0;
	
	scanf("%d %d", &N, &M);
	
	for(i=0;i<N+M;i++)
	{
		scanf("%d %d", &t1, &t2);
		move[t1] = t2;
	}
	
	queue[tail].loc = 1;
	queue[tail++].mov = 0;
	visited[1]++;
	
	while(queue[head].loc != 100)
	{
		for(i=1;i<=6;i++)
		{
			nextLoc = queue[head].loc + i;
			if(nextLoc>100) break;
			nextLoc = move[nextLoc] ? move[nextLoc]:nextLoc;
			if(visited[nextLoc]) continue;
			
			queue[tail].loc = nextLoc;
			queue[tail++].mov = queue[head].mov + 1;
			visited[nextLoc]++;
		}
		head++;
	}
	
	printf("%d", queue[head].mov);
	
	return 0;
}
