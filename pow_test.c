#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
	char array1[3][10];
	char array2[3][10];
	
	for(int i=0;i<3;i++)
	{
		scanf("%s", &array1[i]);
	}
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<strlen(array1[i]);j++)
		{
			array2[i][j] = array1[i][j];
		}
	}
	
	for(int i=0;i<3;i++)
	{
		printf("%s\n", array2[i]);
	}
	
	return 0;
}
