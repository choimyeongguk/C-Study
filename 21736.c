#include <stdio.h>

typedef struct
{
	short row;
	short col;
} LOCATION;

int main()
{
	int R, C, i, j, r, c, cnt=0;
	char map[601][601];
	char move[4][4] = {{1, 0, -1, 0},{0, 1, 0, -1}};
	LOCATION queue[360000]; int head=0, tail=1;
	
	scanf("%d %d", &R, &C);
	
	for(i=1;i<=R;i++)
	{
		getchar();
		for(j=1;j<=C;j++)
		{
			scanf("%c", &map[i][j]);
			
			if(map[i][j]=='I')
			{
				queue[head].row = i;
				queue[head].col = j;
				map[i][j] = 'X';
			}
		}
	}
	
	while(head!=tail)
	{	
		for(i=0;i<4;i++)
		{
			r = queue[head].row + move[0][i];
			c = queue[head].col + move[1][i];
			
			if(r>0 && c>0 && r<=R && c<=C && map[r][c]!='X')
			{
				if(map[r][c]=='P') cnt++;
				queue[tail].row = r;
				queue[tail++].col = c;
				map[r][c] = 'X';
			}
		}
		
		head++;
	}

	if(cnt) printf("%d", cnt);
	else printf("TT");
}
