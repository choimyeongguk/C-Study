#include <stdio.h>

int main()
{
	int i;
	int x[4], y[4];
	
	for(i=0;i<3;i++) scanf("%d %d", &x[i], &y[i]);
	if(y[0]==y[1])  // case 1 
	{
		if(x[2]==x[0])  // case 1-1
		{
			x[3] = x[1];
			y[3] = y[2];
		}
		else  // case 1-2
		{
			x[3] = x[0];
			y[3] = y[2];
		}
	}
	else if(x[0]==x[1])  // case 2
	{
		if(y[2]==y[0])  // case 2-1
		{
			x[3] = x[2];
			y[3] = y[1];
		}
		else  // case 2-2
		{
			x[3] = x[2];
			y[3] = y[0];
		}
	}
	else  // case 3
	{
		if(x[2]==x[0])  // case 3-1
		{
			x[3] = x[1];
			y[3] = y[0];
		}
		else  // case 3-2
		{
			x[3] = x[0];
			y[3] = y[1];
		}
	}
	printf("%d %d", x[3], y[3]);
	
	return 0;
}
