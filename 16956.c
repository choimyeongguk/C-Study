#include <stdio.h>

int check(char* arr, int R, int C, int r, int c)
{
	if(r>0 && *(arr+501*(r-1)+c)=='W') return 1;
	if(r<R-1 && *(arr+501*(r+1)+c)=='W') return 1;
	if(c<C-1 && *(arr+501*r+c+1)=='W') return 1;
	if(c>0 && *(arr+501*r+c-1)=='W') return 1;
	return 0;
}

void block(char* arr, int R, int C, int r, int c)
{
	if(r>0 && *(arr+501*(r-1)+c)=='.') *(arr+501*(r-1)+c) = 'D';
	if(r<R-1 && *(arr+501*(r+1)+c)=='.') *(arr+501*(r+1)+c) = 'D';
	if(c<C-1 && *(arr+501*r+c+1)=='.') *(arr+501*r+c+1) = 'D';
	if(c>0 && *(arr+501*r+c-1)=='.') *(arr+501*r+c-1) = 'D';
}

int main()
{
	int R, C, i, j;
	char map[501][501];
	
	scanf("%d %d", &R, &C);
	for(i=0;i<R;i++) scanf("%s", map[i]);
	
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			if(map[i][j]=='S' && check(map, R, C, i, j)==1)
			{
				printf("0");
				return 0;
			}
		}
	}
	
	printf("1\n");
	for(i=0;i<R;i++) for(j=0;j<C;j++) if(map[i][j]=='W') block(map, R, C, i, j);
	for(i=0;i<R;i++) printf("%s\n", map[i]);
	
	return 0;
}
