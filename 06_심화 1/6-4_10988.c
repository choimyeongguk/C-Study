#include <stdio.h>

int main()
{
	int i, value=1;
	int len = 0;
	char word[101];
	
	scanf("%s", word);
	while(word[len]!='\0') len++;
	for(i=0;i<len/2;i++)
	{
		if(word[i]!=word[len-1-i])
		{
			value = 0;
			break;
		}
	}
	printf("%d", value);
	
	return 0;
}
