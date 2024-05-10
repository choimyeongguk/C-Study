#include <stdio.h>

int main()
{
	int T, i, j;
	int a, b, num;
	
	scanf("%d", &T);
	
	for(i=0;i<T;i++)
	{
		scanf("%d %d", &a, &b);
		
		for(num=1,j=0;j<b;j++)
		{
			num *= a;
			num %= 10;
		}
		
		printf("%d\n", num?num:10);
	}
}
