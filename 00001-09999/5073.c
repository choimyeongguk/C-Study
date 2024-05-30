#include <stdio.h>

int main()
{
	int A, B, C, max;
	while(1)
	{
		scanf("%d %d %d", &A, &B, &C);
		
		if(A==0) break;
		max = A>B?A:B;
		max = max>C?max:C;
		if(max>=A+B+C-max)
		{
			printf("Invalid\n");
			continue;
		}
		
		if(A==B&&B==C) printf("Equilateral\n");
		else if(A==B||B==C||C==A) printf("Isosceles\n");
		else printf("Scalene\n");
	}
	
	return 0;
}
