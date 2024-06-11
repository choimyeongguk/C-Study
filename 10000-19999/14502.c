#include <stdio.h>

typedef struct
{
	char r;
	char c;
} LOC;

int R, C, max=0, numSafeZone;
char mapIni[8][8];
char mapVir[8][8];
LOC locVir[10]; int numVir = 0;

void copyMap()
{
	int i, j;
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			mapVir[i][j] = mapIni[i][j];
		}
	}
}

void spreadVirus()
{
	int i, r, c;
	char d[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
	LOC queue[64]; int head = 0, tail = 0;
	
	for(i=0;i<numVir;i++)
	{
		queue[tail++] = locVir[i];
	}
	
	while(head<tail)
	{	
		for(i=0;i<4;i++)
		{
			r = queue[head].r + d[i][0];
			c = queue[head].c + d[i][1];
			
			if(0<=r && r<R && 0<=c && c<C && !mapVir[r][c])
			{
				mapVir[r][c] = 2;
				queue[tail].r = r;
				queue[tail++].c = c;
				numSafeZone--;
				if(numSafeZone<=max) return;
			}
		}
		head++;
	}
	
	max = max>numSafeZone?max:numSafeZone;
}

int main()
{
	int i, j, k, num=0;
	int r1, c1, r2, c2, r3, c3;
	
	scanf("%d %d", &R, &C);
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			scanf("%d", &mapIni[i][j]);
			if(mapIni[i][j]==2)
			{
				locVir[numVir].r = i;
				locVir[numVir++].c = j;
			}
			if(!mapIni[i][j]) num++;
		}
	}
	num -= 3;
	
	for(i=0;i<R*C;i++)
	{
		r1 = i/C, c1 = i%C;
		if(!mapIni[r1][c1]) mapIni[r1][c1] = 1;
		else continue;
		
		for(j=i+1;j<R*C;j++)
		{
			r2 = j/C, c2 = j%C;
			if(!mapIni[r2][c2]) mapIni[r2][c2] = 1;
			else continue;
			
			for(k=j+1;k<R*C;k++)
			{
				r3 = k/C, c3 = k%C;
				if(!mapIni[r3][c3]) mapIni[r3][c3] = 1;
				else continue;
				
				copyMap();
				numSafeZone = num;
				spreadVirus();
				
				mapIni[r3][c3] = 0;
			}
			
			mapIni[r2][c2] = 0;
		}
		
		mapIni[r1][c1] = 0;
	}
	printf("%d", max);
	
	return 0;
}
