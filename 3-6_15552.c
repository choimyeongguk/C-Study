#include <stdio.h>

int main()
{
	int T, A, B, i;
	scanf("%d", &T);
	
	for(i=0;i<T;i++)
	{
		scanf("%d %d", &A, &B);
		printf("%d\n", A+B);
	}
	
	return 0;
}
/*
#include <stdio.h>

int main()
{
	int T, i;
	scanf("%d", &T);
	int A[T], B[T];
	for(i=0;i<T;i++) scanf("%d %d", &A[i], &B[i]);
	for(i=0;i<T;i++) printf("%d\n", A[i]+B[i]);
	return 0;
}
*/
