#include <stdio.h>

int main()
{
	int change, num, i;
	int coin[6] = { 500, 100, 50, 10, 5, 1 };
	
	scanf("%d", &change);
	change = 1000 - change;

	for(num=0, i=0;i<6;i++)
	{
		num += change/coin[i];
		change %= coin[i];
	}
	
	printf("%d", num);
	
	return 0;
}
