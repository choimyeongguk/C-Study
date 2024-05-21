#include <stdio.h>

int main()
{
	int N, L, i, j;
	int start;
	
	scanf("%d %d", &N, &L);
	
	for(i=L;i<=100;i++)
	{
		if((i*i-i)/2>N)
		{
			i = 101;
			break;
		}
		if((i%2==0 && N%i==i/2)||(i%2==1 && N%i==0)) break;
	}

	if(i>100) printf("-1");
	else
	{
		start = N/i - i/2;
		if(i%2==0) start++;
		
		for(j=0;j<i;j++)
		{
			printf("%d ", start+j);
		}
	}
	
	return 0;
}
