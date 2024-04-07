#include <stdio.h>

int main()
{
	int T, num, i;
	int one[41];
	
	one[0] = 0; one[1] = 1;
	for(i=2;i<41;i++)
	{
		one[i] = one[i-1] + one[i-2];
	}
	
	scanf("%d", &T);
	for(i=0;i<T;i++)
	{
		scanf("%d", &num);
		if(num==0)
		{
			printf("1 0\n");
		}
		else if(num==1)
		{
			printf("0 1\n");
		}
		else
		{
			printf("%d %d\n", one[num-1], one[num]);
		}		
	}
	
	return 0;
}
