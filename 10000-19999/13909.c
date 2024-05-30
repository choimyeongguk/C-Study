#include <stdio.h>

int main()
{
	int nWindow, cnt=0;
	
	scanf("%d", &nWindow);
	
	while(++cnt*cnt<=nWindow);
	
	printf("%d", cnt-1);
	
	return 0;
}
