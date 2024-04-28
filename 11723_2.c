#include <stdio.h>

int main()
{
	int S = 0, tmp, M, x, i;
	char cmd[7];
	
	scanf("%d", &M);
	
	for(i=0;i<M;i++)
	{
		scanf("%s", cmd);
		if(cmd[0]=='a' && cmd[1]=='l')  // all
		{
			S = 2097151;  // 2^21-1 = 11...11(2)
			continue;	
		}
		if(cmd[0]=='e')  // empty
		{
			S = 0;
			continue;
		}
		
		scanf("%d", &x);
		x--;
		switch(cmd[0])
		{
			case 'a':  // add
				if(!(S>>x&1)) S += 1<<x;
				break;
			case 'r':  // remove
				if(S>>x&1) S -= 1<<x;
				break;
			case 'c':  // check
				printf("%d\n", S>>x&1 ? 1:0);
				break;
			case 't':  // toggle
				S>>x&1 ? (S -= 1<<x) : (S += 1<<x);
				break;
		}
	}
	
	return 0;
}
