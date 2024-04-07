#include <stdio.h>

int main()
{
	int N, X, divisorNum, primeNum=0, i, j;
	
	scanf("%d", &N);
	for(i=0;i<N;i++)
	{
		scanf("%d", &X);
		if(X==1) goto notPrime;
		for(j=2;j<X;j++) if(X%j==0) goto notPrime;
		
		primeNum++;
		notPrime: continue;
	}
	printf("%d", primeNum);
	
	return 0;
}
