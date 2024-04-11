#include <stdio.h>

int gcd(int x, int y)
{
	int max = x>y ? x:y;
	int min = x+y-max;
	if(max%min==0)
	{
		return min;
	}
	else gcd(min, max%min);
}

int main()
{
	int T, A, B, i;
	
	scanf("%d", &T);
	for(i=0;i<T;i++)
	{
		scanf("%d %d", &A, &B);
		printf("%d\n", A*B/gcd(A, B));
	}
	
	return 0;
}
