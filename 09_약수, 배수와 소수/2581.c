#include <stdio.h>

int main()
{
	int M, N, primeNum=0, num=1, min=-1, sum=0, i;
	int prime[1230];  // 새롭게 발견되는 소수를 순차적으로 저장할 배열 
	
	scanf("%d", &M);
	scanf("%d", &N);

	while(num<N)
	{
		num++;  // 2부터 시작 
		for(i=0;i<primeNum;i++)
		{
			if(num%prime[i]==0) goto notPrime;
		}
		primeNum++;
		prime[primeNum-1] = num;
		
		notPrime: continue;
	}
	
	for(i=0;i<primeNum;i++)
	{
		if(prime[i]>=M)
		{
			min = i;
			break;
		}
	}
	
	if(min==-1)
	{
		printf("-1");
		return 0;
	}
	
	for(i=min;i<primeNum;i++)
	{
		sum += prime[i];
	}
	printf("%d\n%d", sum, prime[min]);
	
	return 0;
}
