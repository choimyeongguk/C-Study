#include <stdio.h>

int main()
{
	int T, i, j;
	int a, b, num;
	int numUnit[10] = { 1, 1, 4, 4, 2, 1, 1, 4, 4, 2};
	
	scanf("%d", &T);
	
	for(i=0;i<T;i++)
	{
		scanf("%d %d", &a, &b);
		
		b %= numUnit[a%10];
		b = b ? b:numUnit[a%10];
		
		for(num=1,j=0;j<b;j++)
		{
			num *= a;
			num %= 10;
		}
		
		printf("%d\n", num?num:10);
	}
}
