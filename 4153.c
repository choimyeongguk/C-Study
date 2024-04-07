#include <stdio.h>

int main()
{
	int A, B, C;
	
	while(1)
	{
		scanf("%d %d %d", &A, &B, &C);
		if(A==0) return 0;
		
		if(A*A == B*B+C*C) printf("right\n");
		else if(B*B == A*A+C*C) printf("right\n");
		else if(C*C == A*A+B*B) printf("right\n");
		else printf("wrong\n");
	}
}
