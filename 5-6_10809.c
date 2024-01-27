#include <stdio.h>

int main()
{
	int i;
	int len = 0;
	int alphabet[26];
	char S[100];
	
	for(i=0;i<26;i++) alphabet[i] = -1;
	scanf("%s", &S);
	while(S[len]!='\0') len++;
	
	for(i=0;i<len;i++)
	{
		if(alphabet[S[i]-97]==-1)
		{
			alphabet[S[i]-97] = i;
		}
	}
	for(i=0;i<26;i++) printf("%d ", alphabet[i]);
	
	return 0;
}
