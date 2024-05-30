#include <stdio.h>

int main()
{
	int T;
	int A = 300, B = 60, C = 10;
	
	scanf("%d", &T);
	
	if(T%10)
	{
		printf("-1");
		return 0;
	}
	printf("%d ", T/A);
	T %= A;
	printf("%d ", T/B);
	T %= B;
	printf("%d", T/C);
	T %= C;
	
	return 0;
}
