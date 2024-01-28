#include <stdio.h>

int main()
{
	int len=0, num=0, i;
	int used[101] = {0};
	char word[101];
	
	scanf("%s", &word);
	while(word[len]!='\0') len++;
	for(i=0;i<len;i++)
	{
		if(used[i]==0)
		{
			if(word[i]=='c'&&word[i+1]=='=') { num++; used[i+1]=1; }
			else if(word[i]=='c'&&word[i+1]=='-') { num++; used[i+1]=1; }
			else if(word[i]=='d'&&word[i+1]=='z'&&word[i+2]=='=') { num++; used[i+1]=1; used[i+2]=1; }
			else if(word[i]=='d'&&word[i+1]=='-') { num++; used[i+1]=1; }
			else if(word[i]=='l'&&word[i+1]=='j') { num++; used[i+1]=1; }
			else if(word[i]=='n'&&word[i+1]=='j') { num++; used[i+1]=1; }
			else if(word[i]=='s'&&word[i+1]=='=') { num++; used[i+1]=1; }
			else if(word[i]=='z'&&word[i+1]=='=') { num++; used[i+1]=1; }
			else num++;
		}
	}
	printf("%d", num);
	
	return 0;
}
