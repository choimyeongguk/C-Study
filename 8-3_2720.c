#include <stdio.h>

int main()
{
	int T, change, num, i;
	
	scanf("%d", &T);
	for(i=0;i<T;i++)
	{
		scanf("%d", &change);
		
		num = change/25;
		printf("%d ", num);
		change -= num*25;
		
		num = change/10;
		printf("%d ", num);
		change -= num*10;
		
		num = change/5;
		printf("%d ", num);
		change -= num*5;
		
		num = change/1;
		printf("%d ", num);
		change -= num*1;
	}
}
