#include <stdio.h>

int main()
{
	int M, x, i, j;
	char S[21] = { 0 };
	char cmd[7];
	
	scanf("%d", &M);
	
	for(i=0;i<M;i++)
	{
		scanf("%s", cmd);
		if(cmd[0]=='a' && cmd[1]=='l')  // all
		{
			for(j=1;j<=20;j++)
			{
				S[j] = 1;
			}
			continue;	
		}
		if(cmd[0]=='e')  // empty
		{
			for(j=1;j<=20;j++)
			{
				S[j] = 0;
			}
			continue;
		}
		scanf("%d", &x);
		switch(cmd[0])
		{
			case 'a':  // add
				if(!S[x]) S[x]++;
				break;
			case 'r':  // remove
				if(S[x]) S[x]--;
				break;
			case 'c':  // check
				printf("%d\n", S[x] ? 1:0);
				break;
			case 't':  // toggle
				S[x] ? S[x]--:S[x]++;
				break;
		}
	}
	
	return 0;
}
