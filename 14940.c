#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	short row;
	short col;
} COORDINATE;  // 4bytes

int main()
{
	int i, j;
	int r, c, l;
	int dr[4] = { 1, 0, -1, 0 };
	int dc[4] = { 0, 1, 0, -1 };
	int** map; int R, C;
	COORDINATE* bfs; int head=0, tail=0;
	
	scanf("%d %d", &R, &C);
	
	map = (int**)calloc(R, sizeof(int*));
	for(i=0;i<R;i++) map[i] = (int*)calloc(C, sizeof(int));
	bfs = (COORDINATE*)calloc(R*C, sizeof(COORDINATE));
	
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			scanf(" %c", &map[i][j]);
			if(map[i][j]=='2')
			{
				bfs[tail].row = i;
				bfs[tail++].col = j;
			}
		}
	}
	
	do
	{	
		for(i=0;i<4;i++)
		{
			r = bfs[head].row + dr[i];
			c = bfs[head].col + dc[i];
			l = map[bfs[head].row][bfs[head].col] + 1;
			
			if(r>=0 && c>=0 && r<=R-1 && c<=C-1 && map[r][c]=='1')
			{
				bfs[tail].row = r;
				bfs[tail++].col = c;
				map[r][c] = l;
			}
		}
	} while(++head!=tail);
	
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			if(map[i][j]=='0') map[i][j] = 0;
			else if(map[i][j]=='1') map[i][j] = -1;
			else map[i][j] -= 50;
		}
	}
	
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	
	for(i=0;i<R;i++) free(map[i]);
	free(map);
	free(bfs);
	return 0;
}
