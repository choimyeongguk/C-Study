#include <stdio.h>

int main()
{
	int K, sum, num, i;
	int stack[100000]; int top = 0;
	
	scanf("%d", &K);
	
	for(i=0,sum=0;i<K;i++)
	{
		scanf("%d", &num);
		num==0 ? top--:(stack[top++]=num);
	}
	
	for(i=0;i<top;i++)
	{
		sum += stack[i];
	}
	
	printf("%d", sum);
	
	return 0;
}
