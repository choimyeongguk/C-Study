#include <stdio.h>

int main()
{
	int N, len, noGroupNum=0, i, j;
	int alphabet[26];
	char word[101];
	
	scanf("%d", &N);
	for(i=0;i<N;i++)
	{
		len = 0; 
		for(j=0;j<26;j++) alphabet[j] = 0;
		
		scanf("%s", &word);
		while(word[len]!='\0') len++;
		
		alphabet[word[0]-97] = 1;
		for(j=0;j<len-1;j++)
		{
			if(word[j]!=word[j+1])
			{
				if(alphabet[word[j+1]-97]==1)
				{
					noGroupNum++;
					break;
				}
				if(alphabet[word[j+1]-97]==0) alphabet[word[j+1]-97] = 1;
			}
		}
	}
	printf("%d", N-noGroupNum);
	
	return 0;
}
