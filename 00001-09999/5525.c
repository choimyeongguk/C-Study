#include <stdio.h>
#include <stdlib.h>
#define I -7
#define O -1

int main()
{
	int N, M, cnt, i;
	char* stack; int top = 0;
	
	scanf("%d", &N);
	scanf("%d", &M);
	stack = (char*)calloc(M+2, sizeof(char));
	
	stack[top++] = 0;
	stack[top++] = 0;
	getchar();
	for(i=0;i<M;i++)
	{
		stack[top++] = getchar() - 80;
		
		if(stack[top-1]==I && stack[top-2]==O && stack[top-3]==I)
		{
			top -= 3;
			stack[top++] = 1;
			if(stack[top-2]>0)
			{
				stack[top-2]++;
				top--;
			}
			stack[top++] = I;
		}
	}
	
	for(cnt=0,i=2;i<top;i++)
	{
		if(stack[i]>=N) cnt += stack[i]-N+1;
	}
	printf("%d", cnt);
	
	free(stack);
	return 0;
}
