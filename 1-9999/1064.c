#include <stdio.h>
#include <math.h>

int main()
{
	int xa, ya, xb, yb, xc, yc;
	double a, b, c;
	double max, min, tmp;
	
	scanf("%d %d %d %d %d %d", &xa, &ya, &xb, &yb, &xc, &yc);
	
	if((ya-yb)*(xb-xc) == (yb-yc)*(xa-xb))
	{
		printf("-1");
		return 0;
	}
	
	a = sqrt((xb-xc)*(xb-xc) + (yb-yc)*(yb-yc));
	b = sqrt((xc-xa)*(xc-xa) + (yc-ya)*(yc-ya));
	c = sqrt((xa-xb)*(xa-xb) + (ya-yb)*(ya-yb));
	
	tmp = 2*a + 2*b;
	max = tmp;
	min = tmp;
	
	tmp = 2*b + 2*c;
	max = max>tmp ? max:tmp;
	min = min<tmp ? min:tmp;
	
	tmp = 2*c + 2*a;
	max = max>tmp ? max:tmp;
	min = min<tmp ? min:tmp;
	
	printf("%.15f", max-min);
	
	return 0;
}
