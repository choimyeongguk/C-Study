#include <stdio.h>

int main()
{
	int N, top=0, cmd, num, i;
	int stack[1000000]; 
	
	scanf("%d", &N);
	
	for(i=0;i<N;i++)
	{
		scanf("%d", &cmd);
		switch(cmd)
		{
			case 1:
				scanf("%d", &num);
				stack[top++] = num;
				break;
			case 2:
				printf("%d\n", top ? stack[--top]:-1);
				break;
			case 3:
				printf("%d\n", top);
				break;
			case 4:
				printf("%d\n", top ? 0:1);
				break;
			case 5:
				printf("%d\n", top ? stack[top-1]:-1);
				break;
		}
	}
	
	return 0;
}
