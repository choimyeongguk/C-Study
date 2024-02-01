#include <stdio.h>

int main()
{
	int N, sum=0, i;
	char nums[100];
	scanf("%d", &N);
	scanf("%s", &nums);
	
	for(i=0;i<N;i++)
	{
		sum += nums[i]-48;
	}
	printf("%d", sum);
	
	return 0;
}
