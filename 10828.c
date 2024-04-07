#include <stdio.h>

int main()
{
	int N, num, i;
	int stack[10000];
	int index = 0;
	char cmd[6];
	
	scanf("%d", &N);
	
	for(i=0;i<N;i++)
	{
		scanf("%s", &cmd);
		
		if(cmd[1]=='u')
			scanf("%d", &stack[index++]);
			
		if(cmd[0]=='p' && cmd[1]=='o')
			printf("%d\n", !index?-1:stack[--index]);
			
		if(cmd[0]=='s')
			printf("%d\n", index);
			
		if(cmd[0]=='e')
			printf("%d\n", !index?1:0);
			
		if(cmd[0]=='t')
			printf("%d\n", !index?-1:stack[index-1]);
	}
	
	return 0;
}
