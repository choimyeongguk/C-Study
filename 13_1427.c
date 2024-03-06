#include <stdio.h>

int main()
{
	int i, j;
	char arr[10];
	int count[10] = {0,};
	scanf("%s", arr);
	
	for(i=0;i<10;i++)
	{
		count[arr[i]-48]++;
	}
	for(i=9;i>=0;i--)
	{
		for(j=0;j<count[i];j++)
		{
			printf("%d", i);
		}
	}
	
	return 0;
}
