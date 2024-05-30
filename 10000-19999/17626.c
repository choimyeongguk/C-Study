#include <stdio.h>

int numCase[50001] = { 0 };

int func(int x)
{
	if(x==0) return 0;
	
	int i, tmp, idx, min=x;
	
	for(i=1; i*i<=x; i++)
	{
		idx = x - i*i;
		
		if(numCase[idx]==0)
		{
			numCase[idx] = func(idx);
			tmp = 1 + numCase[idx];
		}
		else tmp = 1 + numCase[idx];
		
		min = min<tmp ? min:tmp;
	}
	
	return min;
}

int main()
{
	int n;
	
	scanf("%d", &n);
	printf("%d", func(n));
	
	return 0;
}
