#include <stdio.h>

int numResident(int k, int n)
{
	if(k==0) return n;
	
	int sum = 0;
	for(int i=1;i<=n;i++)
	{
		sum += numResident(k-1, i);
	}
	return sum;
}

int main()
{
	int T, k, n, i;
	
	scanf("%d", &T);
	
	for(i=0;i<T;i++)
	{
		scanf("%d", &k);
		scanf("%d", &n);
		printf("%d\n", numResident(k, n));
	}
	
	return 0;
}
