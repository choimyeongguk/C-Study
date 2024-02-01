#include <stdio.h>

int main()
{
	int cube[3], max;
	scanf("%d %d %d", &cube[0], &cube[1], &cube[2]);
	
	if(cube[0]==cube[1]&&cube[0]==cube[2])
	{
		printf("%d", 10000+cube[0]*1000);
	}
	else
	{
		if(cube[0]==cube[1]||cube[0]==cube[2])
		{
			printf("%d", 1000+cube[0]*100);
		}
		else if(cube[1]==cube[2])
		{
			printf("%d", 1000+cube[1]*100);
		}
		else
		{
			max = cube[0]>cube[1]?cube[0]:cube[1];
			max = max>cube[2]?max:cube[2];
			printf("%d", max*100);
		}
	}
	
	return 0;
} 
