#include <stdio.h>

typedef struct
{
	char h;
	char r;
	char c;
} BOX;

int main()
{
	int H, R, C, i, j, k;
	int h, r, c, day, dayMin=1, chk;
	int d[3][6] =
	{
		{ 1, -1, 0, 0, 0, 0 },
		{ 0, 0, 1, -1, 0, 0 },
		{ 0, 0, 0, 0, 1, -1 }
	};
	int*** box;  // Height, Row, Col
	BOX* queue; int head=0, tail=0;
	
	scanf("%d %d %d", &C, &R, &H);
	
	queue = (BOX*)calloc(H*R*C, sizeof(BOX));
	box = (int***)calloc(H, sizeof(int**));
	for(i=0;i<H;i++)
	{
		box[i] = (int**)calloc(R, sizeof(int*));
		for(j=0;j<R;j++)
		{
			box[i][j] = (int*)calloc(C, sizeof(int));
		}
	}
	
	for(i=0;i<H;i++)
	{
		for(j=0;j<R;j++)
		{
			for(k=0;k<C;k++)
			{
				scanf("%d", &box[i][j][k]);
				
				if(box[i][j][k]==1)
				{
					queue[tail].h = i;
					queue[tail].r = j;
					queue[tail++].c = k;
				}
			}
		}
	}
	
	while(head!=tail)
	{	
		day = box[queue[head].h][queue[head].r][queue[head].c] + 1;
		
		for(i=0;i<6;i++)
		{
			h = queue[head].h + d[0][i];
			r = queue[head].r + d[1][i];
			c = queue[head].c + d[2][i];
			
			if(h>=0 && r>=0 && c>=0 && h<H && r<R && c<C && box[h][r][c]==0)
			{
				queue[tail].h = h;
				queue[tail].r = r;
				queue[tail++].c = c;
				box[h][r][c] = day;
				dayMin = day;
			}
		}
		
		head++;
	}
	
	for(chk=0,i=0;i<H;i++)
	{
		for(j=0;j<R;j++)
		{
			for(k=0;k<C;k++)
			{
				if(box[i][j][k]==0)
				{
					chk++;
					break;
				}
			}
			if(chk) break;
		}
		if(chk) break;
	}
	
	if(chk) printf("-1");
	else printf("%d", dayMin-1);
	
	free(queue);
	for(i=0;i<H;i++)
	{
		for(j=0;j<R;j++)
		{
			free(box[i][j]);
		}
		free(box[i]);
	}
	free(box);
	
	return 0;
}
