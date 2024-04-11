#include <stdio.h>

int main()
{
	int N, M, i, j, x, y, buf;
	int bascket[101];
	scanf("%d %d", &N, &M);
	
	for(i=1;i<=N;i++) bascket[i] = i;
	for(i=0;i<M;i++)
	{
		scanf("%d %d", &x, &y);
		for(j=0;j<(y-x+1)/2;j++)
		{
			buf = bascket[x+j];
			bascket[x+j] = bascket[y-j];
			bascket[y-j] = buf;
		}
	}
	for(i=1;i<=N;i++) printf("%d ", bascket[i]);
	
	return 0;
}
