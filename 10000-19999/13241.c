#include <stdio.h>

int gcd(long long int A, long long int B)
{
	long long int max = A>B ? A:B;
	long long int min = A+B-max;
	if(max%min==0) return min;
	else gcd(min, max%min);
}

int main()
{
	long long int A, B;
	
	scanf("%d %d", &A, &B);
	printf("%lld", A*B/gcd(A, B));
	
	return 0;
}
