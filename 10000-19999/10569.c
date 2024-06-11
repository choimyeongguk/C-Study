#include <stdio.h>

int main()
{
	int T, V, E, i;
	scanf("%d", &T);
	for(i=0;i<T;i++)
	{
		scanf("%d %d", &V, &E);
		printf("%d\n", E-V+2);
	}
	return 0;
}
