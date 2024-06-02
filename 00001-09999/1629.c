#include <stdio.h>

typedef long long int lld;

lld power(lld A, lld B, lld C)
{
	if(B==0) return 1;
	if(B==1) return A%C;
	
	lld tmp = power(A, B/2, C);
	
	if(B%2)  // È¦¼ö 
	{
		return tmp * tmp % C * A % C;
	}
	else  // Â¦¼ö 
	{
		return tmp * tmp % C;
	}
}

int main()
{
	lld A, B, C;
	
	scanf("%lld %lld %lld", &A, &B, &C);
	
	printf("%lld", power(A, B, C));
	
	return 0;
}
