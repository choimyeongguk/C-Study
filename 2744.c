#include <stdio.h>
#include <string.h>

int main()
{
	int i;
	char word[101];
	
	scanf("%s", word);
	for(i=0;i<strlen(word);i++)
	{
		if(word[i]<='Z') word[i] += 32;
		else word[i] -= 32;
	}
	printf("%s", word);
	
	return 0;
}
