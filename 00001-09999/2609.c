#include <stdio.h>

int g(int x, int y)
{
	int big = x>y ? x:y
	int small = x+y-n;
	if(big%small) g(small, big%small);
	else return small;
}

int main()
{
	int A, B, n;
	
	scanf("%d %d", &A, &B);
	
	n = g(A, B);
	printf("%d\n%d", n, A*B/n);
	
	return 0;
}
