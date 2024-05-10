#include <stdio.h>

int main()
{
	int T, num, i;
	long long int P[101] = { 0 };
	
	P[1] = 1; P[2] = 1; P[3] = 1;
	P[4] = 2; P[5] = 2;
	
	for(i=6;i<=100;i++)
	{
		P[i] = P[i-1] + P[i-5];
	}
	
	scanf("%d", &T);
	for(i=0;i<T;i++)
	{
		scanf("%lld", &num);
		printf("%lld\n", P[num]);
	}
	
	return 0;
}
