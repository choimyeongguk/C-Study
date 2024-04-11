#include <stdio.h>

int main()
{
	int n, i;
	int num = 0;
	scanf("%d", &n);
	
	for(i=1;i<=n;i++) num += i;
	printf("%d", num);
	
	return 0;
}
