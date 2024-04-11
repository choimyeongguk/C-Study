#include <stdio.h>

int main()
{
	int A, B, C, max;
	
	scanf("%d %d %d", &A, &B, &C);
	max = A>B?A:B;
	max = max>C?max:C;
	if(max<A+B+C-max) printf("%d", A+B+C);
	else printf("%d", (A+B+C-max)*2-1);
	
	return 0;
}
