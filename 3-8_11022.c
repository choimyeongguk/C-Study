#include <stdio.h>

int main()
{
	int T, i, A, B;
	scanf("%d", &T);
	
	for(i=0;i<T;i++)
	{
		scanf("%d %d", &A, &B);
		printf("Case #%d: %d + %d = %d\n", i+1, A, B, A+B);
	}
	
	return 0;
}
