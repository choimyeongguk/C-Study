#include <stdio.h>

int main()
{
	int i;
	int len = 0;
	int gapNum = 0;
	char S[1000000];
	
	scanf("%[^\n]s", &S);
	while(S[len]!='\0') len++;
	for(i=0;i<len;i++)
	{
		if(S[i]==' ') gapNum++;
	}
	if(S[0]==' ') gapNum--;
	if(S[len-1]==' ') gapNum--;
	
	printf("%d", gapNum+1);
	
	return 0;
}
