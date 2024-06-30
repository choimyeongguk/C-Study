#include <stdio.h>

int main()
{
	int N, cnt, n1, n2, n3, i;
	
	scanf("%d", &N);
	
	if(N<100)
	{
		printf("%d", N);
		return 0;
	}
	
	cnt = 99;
	for(i=100;i<=N;i++)
	{
		n1 = i%10;
		n2 = (i/10)%10;
		n3 = (i/100)%10;
		if(2*n2==n1+n3)
		{
			cnt++;
		}
	}
	if(N==1000) cnt--;
	
	printf("%d", cnt);
	
	return 0;
}
