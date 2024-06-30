#include <stdio.h>

int main()
{
	int N, M, hMax=0, vMax=0, tmp, i;
	
	scanf("%d %d", &N, &M);
	for(i=0;i<N;i++)
	{
		scanf("%d", &tmp);
		hMax = hMax>tmp ? hMax:tmp;
	}
	for(i=0;i<M;i++)
	{
		scanf("%d", &tmp);
		vMax = vMax>tmp ? vMax:tmp;
	}
	printf("%d", hMax+vMax);
	
	return 0;
}
