#include <stdio.h>

int main()
{
	int N, i;
	int Queue[10000];
	int head = 0;
	int tail = 0;
	char cmd[6];
	
	scanf("%d", &N);
	for(i=0;i<N;i++)
	{
		scanf("%s", cmd);
		
		if(cmd[1]=='u')
			scanf("%d", &Queue[tail++]);
			
		else if(cmd[0]=='p')
			printf("%d\n", head==tail ? -1:Queue[head++]);
			
		else if(cmd[0]=='s')
			printf("%d\n", tail - head);
			
		else if(cmd[0]=='e')
			printf("%d\n", head==tail ? 1:0);
			
		else if(cmd[0]=='f')
			printf("%d\n", head==tail ? -1:Queue[head]);
			
		else
			printf("%d\n", head==tail ? -1:Queue[tail-1]);
	}
	
	return 0;
}
