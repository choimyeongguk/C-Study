#include <stdio.h>

int main()
{
	int A, B, cnt = 1;
	
	scanf("%d %d", &A, &B);
	
	while(B)
	{
		if(B==A)
		{
			printf("%d", cnt);
			return 0;
		}
		
		cnt++;
		if(B%10==1)
		{
			B /= 10;
		}
		else if(!B%2)
		{
			B /= 2;
		}
		else
		{
			break;
		}
	}
	printf("-1");
	return 0;
}
