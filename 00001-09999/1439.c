#include <stdio.h>

int main()
{
	int a, b, cnt = 0;
	
	a = getchar();
	while((b=getchar()) != '\n')
	{
		if(a!=b)
		{
			cnt++;
			a = b;
		}
	}	
	if(cnt>1) cnt  = (cnt+1)/2;
	printf("%d", cnt);
	
	return 0;
}
