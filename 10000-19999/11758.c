#include <stdio.h>

int main()
{
	int x1, y1, x2, y2, x3, y3, det;
	
	scanf("%d %d", &x1, &y1);
	scanf("%d %d", &x2, &y2);
	scanf("%d %d", &x3, &y3);
	
	x3 -= x2, y3 -= y2;
	x2 -= x1, y2 -= y1;
	det = x2*y3 - x3*y2;
	
	printf("%d", det>0 ? 1:det<0 ? -1:0);
	
	return 0;
}
