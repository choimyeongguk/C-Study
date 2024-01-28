#include <stdio.h>

int main()
{
	int len=0, max=0, max_num=0, max_alphabet, i;
	int alphabet[26] = {0};
	char word[1000001];
	
	scanf("%s", &word);
	while(word[len]!='\0') len++;
	for(i=0;i<len;i++)
	{
		if(word[i]>90) word[i] -= 32;
		alphabet[word[i]-65]++;
	}
	
	for(i=0;i<26;i++)
	{
		if(alphabet[i]>max)
		{
			max = alphabet[i];
			max_alphabet = i;
		}
	}
	for(i=0;i<26;i++)
	{
		if(alphabet[i]==max) max_num++;
	}
	
	if(max_num>1) printf("?");
	else printf("%c", max_alphabet+65);
	
	return 0;
}
