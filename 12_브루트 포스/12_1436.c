#include <stdio.h>

int main()
{
	int N;
	int num, sixStack, cnt=0, digit;
	
	scanf("%d", &N);
	
	num = 665;
	while(cnt!=N)
	{
		sixStack = 0;
		num++;
		
		digit = 1;
		while(num%digit!=num)
		{
			digit *= 10;
			if((num%digit)/(digit/10)==6)
			{
				sixStack++;
				if(sixStack>=3)
				{
					cnt++;
					break;
				}
			}
			else
			{
				sixStack = 0;
			}
		}
	}
	printf("%d", num);
	
	return 0;
}
