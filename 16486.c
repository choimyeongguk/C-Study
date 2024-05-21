#include <stdio.h>
#define pi 3.141592

int main()
{
	int d1, d2;
	
	scanf("%d %d", &d1, &d2);
	printf("%.15f", 2*d1+2*pi*d2);
	
	return 0;
}
