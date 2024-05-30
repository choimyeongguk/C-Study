#include <stdio.h>

int main()
{
	int N, M, buf, x, y, i;
	int bascket[100];
	
	scanf("%d %d", &N, &M);
	for(i=0;i<N;i++) bascket[i] = i+1;
	for(i=0;i<M;i++)
	{
		scanf("%d %d", &x, &y);
		buf = bascket[x-1];
		bascket[x-1] = bascket[y-1];
		bascket[y-1] = buf;
	}
	for(i=0;i<N;i++) printf("%d ", bascket[i]);
	
	return 0;
}
