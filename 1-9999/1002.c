#include <stdio.h>
#include <math.h>

int main()
{
	int T, x1, y1, r1, x2, y2, r2, i;
	int l;
	scanf("%d", &T);
	for(i=0;i<T;i++)
	{
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);\
		l = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
		
		if(x1==x2 && y1==y2)
		{
			if(r1==r2) printf("-1\n");
			else printf("0\n");
		}
		else
		{
			if(l>pow(r1+r2, 2) || l<pow(r1-r2, 2)) printf("0\n");
			else if(l==pow(r1+r2, 2) || l==pow(r1-r2, 2)) printf("1\n");
			else printf("2\n");
		}
	}
	
	return 0;
}
