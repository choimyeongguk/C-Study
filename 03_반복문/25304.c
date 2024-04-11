#include <stdio.h>

int main()
{
	int X, N, a, b, i;
	int sum = 0;
	scanf("%d", &X);
	scanf("%d", &N);
	
	for(i=0;i<N;i++)
	{
		scanf("%d %d", &a, &b);
		sum += a*b;
	}
	
	printf("%s", X==sum?"Yes":"No");
	
	return 0;
}
