#include <stdio.h>

int main()
{
	int N, num, i;
	int passNum = 0;
	int index = 0;
	int stack[1001];
	
	scanf("%d", &N);
	stack[index] = N+1;
	for(i=0;i<N;i++)
	{
		scanf("%d", &num);
		
		if(num == passNum+1)
		{
			passNum++;
		}
		else
		{
			while(stack[index] == passNum+1)
			{
				passNum++;
				index--;
				if(num == passNum+1)
				{
					passNum++;
				}
			}
			if(passNum<num)  // 결국 못 들어갔다! 
			{
				if(stack[index]<num)
				{
					printf("Sad");
					return 0;
				}
				stack[++index] = num; 
			}
		}
	}
	printf("Nice");
	
	return 0;
}

