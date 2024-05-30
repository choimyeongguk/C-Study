#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, num=1, i, arr;
	int* stack; int top=0;
	char* cmd; int order=0;
	
	scanf("%d", &n);
	stack = (int*)calloc(n, sizeof(int));
	cmd = (char*)calloc(n, sizeof(int));
	
	for(i=1;i<=n;i++)
	{
		scanf("%d", &arr);
		while(num<=arr) 
		{
			stack[top++] = num++;
			cmd[order++] = '+';
		}
		if(stack[top-1]==arr)
		{
			top--;
			cmd[order++] = '-';
		}
		else
		{
			printf("NO");
			return 0;
		}
	}
	
	for(i=0;i<order;i++) printf("%c\n", cmd[i]);
	
	free(stack);
	free(cmd);
	return 0;
}
