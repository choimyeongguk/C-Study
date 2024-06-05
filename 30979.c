#include <stdio.h>

int main()
{
	int T, N, sum=0, tmp, i;
	
	scanf("%d %d", &T, &N);
	for(i=0;i<N;i++)
	{
		scanf("%d", &tmp);
		sum += tmp;
	}
	printf("Padaeng_i %s", sum>=T ? "Happy":"Cry");
	
	return 0;
}
