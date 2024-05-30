#include <stdio.h>

int main()
{
	int T, len=0, i, j;
	char word[1000] ={0};
	scanf("%d", &T);
	
	for(i=0;i<T;i++)
	{
		scanf("%s", &word);
		while(word[len]!=0)	len++;
		printf("%c%c\n", word[0], word[len-1]);
		
		for(j=0;j<len;j++) word[j]=0;
		len = 0;
	}
	
	return 0;
}
