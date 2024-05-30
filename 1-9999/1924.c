#include <stdio.h>

int main()
{
	int x, y, i;
	int num = 0;
	int day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	scanf("%d %d", &x, &y);
	
	for(i=1;i<x;i++) num += day[i];
	num += y;
	num %= 7;
	
	switch(num)
	{
		case 0:
			printf("SUN");
			break;
		case 1:
			printf("MON");
			break;
		case 2:
			printf("TUE");
			break;
		case 3:
			printf("WED");
			break;
		case 4:
			printf("THU");
			break;
		case 5:
			printf("FRI");
			break;
		case 6:
			printf("SAT");
			break;
	}
	
	return 0;
}
