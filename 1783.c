#include <stdio.h>

int main()
{
	int R, C, sqr;
	
	scanf("%d %d", &R, &C);
	
	if(R==1)
	{
		sqr = 1;
	}
	else if(R==2)
	{
		sqr = 1 + (C-1)/2;
		sqr = sqr>4 ? 4:sqr;
	}
	else
	{
		if(C>=7)
		{
			sqr = 3 + C-5;
		}
		else
		{
			sqr = C;
			sqr = sqr>4 ? 4:sqr;
		}
	}
	
	printf("%d", sqr);
	
	return 0;
}
