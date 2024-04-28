#include <stdio.h>

int R, C, min;
char maze[101][101];

void DFS(int r, int c, int cnt)
{
	cnt++;
	if(r==R-1 && c==C-1)
	{
		min = min<cnt ? min:cnt;
		return;
	}
	
	maze[r][c] = '0';
	if(r>0 && maze[r-1][c]=='1') DFS(r-1, c, cnt);
	if(c>0 && maze[r][c-1]=='1') DFS(r, c-1, cnt);
	if(r<R-1 && maze[r+1][c]=='1') DFS(r+1, c, cnt);
	if(c<C-1 && maze[r][c+1]=='1') DFS(r, c+1, cnt);
	maze[r][c] = '1';
}

int main()
{
	int i, j;
	
	scanf("%d %d", &R, &C);
	min = R*C;
	for(i=0;i<R;i++) scanf("%s", maze[i]);
	DFS(0, 0, 0);
	printf("%d", min);
	
	return 0;
}
