#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	short row;
	short col;
} TOMATO;  // 4bytes

int main()
{
	int R, C, i, j;
	int r, c, l, chk, max;
	int d[2][4] = {{ 0, 1, 0, -1 }, { 1, 0, -1, 0 }};
	int** map;
	TOMATO* queue; int head=0, tail=0;
	
	scanf("%d %d", &C, &R);
	
	queue = (TOMATO*)calloc(R*C, sizeof(TOMATO));
	map = (int**)calloc(R, sizeof(int*));
	for(i=0;i<R;i++)
	{
		map[i] = (int*)calloc(C, sizeof(int));
		for(j=0;j<C;j++)
		{
			scanf("%d", &map[i][j]);
			if(map[i][j]==1)
			{
				queue[tail].row = i;
				queue[tail++].col = j;
			}
		}
	}
	
	while(head!=tail)
	{
		l = map[queue[head].row][queue[head].col] + 1;
		
		for(i=0;i<4;i++)
		{
			r = queue[head].row + d[0][i];
			c = queue[head].col + d[1][i];
			
			if(r>=0 && c>=0 && r<R && c<C && map[r][c]==0)
			{
				queue[tail].row = r;
				queue[tail++].col = c;
				map[r][c] = l;
			}
		}
		head++;
	}
	
	for(chk=0,max=0, i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			if(map[i][j]==0)
			{
				chk++;
				break;
			}
			max = max>map[i][j] ? max:map[i][j];
		}
		if(chk) break;
	}
	
	if(chk) printf("-1");
	else printf("%d", max-1);
	
	for(i=0;i<R;i++) free(map[i]);
	free(map);
	free(queue);
	return 0;
}
