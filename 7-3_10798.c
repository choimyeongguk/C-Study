#include <stdio.h>

int main()
{
	int len, lenMax, i, j;
	char table[5][16];
	
	for(i=0;i<5;i++) for(j=0;j<16;j++) table[i][j] = '.';
	for(i=0;i<5;i++)
	{
		scanf("%s", table[i]);
	}
	
	while(table[0][len]!='\0') len++;
	lenMax = len;
	for(i=0;i<5;i++)
	{
		len = 0;
		while(table[i][len]!='\0') len++;
		lenMax = lenMax>len?lenMax:len;
	}
	
	for(j=0;j<lenMax;j++)
	{
		for(i=0;i<5;i++)
		{
			if(table[i][j]=='.'||table[i][j]=='\0') continue;
			printf("%c", table[i][j]);
		}
	}
	
	return 0;
}

