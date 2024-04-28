#include <stdio.h>

int digitSum(int x)
{
	int y = 0;
	y += x%10;
	x /= 10;
	y += x%10;
	
	return y;
}

int main()
{
	int N, result, sum, num, cnt=0;
	
	scanf("%d", &N);
	result = N;
	do
	{
		sum = digitSum(result);
		sum %= 10;
		num = result%10;
		result = 10*num + sum;
		cnt++;
	} while(result!=N);
	
	printf("%d", cnt);
	
	return 0;
}
