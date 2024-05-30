#include <stdio.h>

int main()
{
	int N, M, i, j, x, y, z;
	int bascket[100] = {0};
	
	scanf("%d %d", &N, &M);
	for(i=0;i<M;i++)
	{
		scanf("%d %d %d", &x, &y, &z);
		for(j=x-1;j<y;j++)
		{
			bascket[j] = z;
		}
	}
	for(i=0;i<N;i++) printf("%d ", bascket[i]);
	
	return 0;
}
