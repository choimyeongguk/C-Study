#include <stdio.h>

int main()
{
	int len=0, time=0, i;
	char word[16];
	
	scanf("%s", &word);
	while(word[len]!=0) len++;
	for(i=0;i<len;i++) 
	{
		if(word[i]<=67) time += 3;
		else if(word[i]<=70) time += 4;
		else if(word[i]<=73) time += 5;
		else if(word[i]<=76) time += 6;
		else if(word[i]<=79) time += 7;
		else if(word[i]<=83) time += 8;
		else if(word[i]<=86) time += 9;
		else time += 10;
	}
	printf("%d", time);
	
	return 0;
}
