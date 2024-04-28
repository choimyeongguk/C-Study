#include <stdio.h>

void BFS(int X, int cnt, int* min)
{
	if(cnt>*min) return;
	if(X==1)
	{
		*min = *min<cnt ? *min:cnt;
		return;
	}
	BFS(X-1, cnt+1, min);
	if(X%2==0) BFS(X/2, cnt+1, min);
	if(X%3==0) BFS(X/3, cnt+1, min);
}

int main()
{
	int X, min=1000000;
	
	scanf("%d", &X);
	BFS(X, 0, &min);
	printf("%d", min);
	
	return 0;
}
