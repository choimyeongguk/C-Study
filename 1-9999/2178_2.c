#include <stdio.h>

typedef struct
{
	int row;
	int col;
} QUEUE;

int main()
{
	int R, C, r, c, i, layer, num, tmp;
	char maze[101][101];
	QUEUE queue[10000]; int head = 0, tail = 1;
	
	scanf("%d %d", &R, &C);
	for(i=0;i<R;i++) scanf("%s", maze[i]);
	
	queue[head].row = 0;
	queue[head].col = 0;
	maze[0][0] = '0';
	layer = 1;  // 계층 
	num = 1;  // 계층에 존재하는 요소 개수 
	
	while(tail-head>0)
	{
		for(tmp=0, i=0;i<num;i++)
		{
			r = queue[head].row;
			c = queue[head++].col;
			
			if(r==R-1 && c==C-1)
			{
				printf("%d", layer);
				return 0; 
			}
			if(r>0 && maze[r-1][c]=='1')
			{
				queue[tail].row = r-1;
				queue[tail++].col = c;
				maze[r-1][c] = '0';
				tmp++;
			}
			if(c>0 && maze[r][c-1]=='1')
			{
				queue[tail].row = r;
				queue[tail++].col = c-1;
				maze[r][c-1] = '0';
				tmp++;
			}
			if(r<R-1 && maze[r+1][c]=='1')
			{
				queue[tail].row = r+1;
				queue[tail++].col = c;
				maze[r+1][c] = '0';
				tmp++;
			}
			if(c<C-1 && maze[r][c+1]=='1')
			{
				queue[tail].row = r;
				queue[tail++].col = c+1;
				maze[r][c+1] = '0';
				tmp++;
			}
		}
		num = tmp;
		layer++;
	}
}
