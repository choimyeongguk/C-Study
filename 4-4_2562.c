#include <stdio.h>

int main()
{
	int i, X, max=0, num=0;
	for(i=0;i<9;i++)
	{
		scanf("%d", &X);
		if(X>max)
		{
			max = X;
			num = i+1;
		}
	}
	printf("%d\n%d", max, num);
	
	return 0;
}
