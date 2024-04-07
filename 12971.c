#include <stdio.h>

int main()
{
	int p1, p2, p3, x1, x2, x3, MAX;
	int n1=0, n2=0, n3=0;
	int M1=0, M2=0, M3=0;
	
	scanf("%d %d %d %d %d %d", &p1, &p2, &p3, &x1, &x2, &x3);

	MAX = p1*p2*p3;
	while(M1<MAX && M2<MAX && M3<MAX)
	{
		M1 = x1+p1*n1;
		M2 = x2+p2*n2;
		M3 = x3+p3*n3;
		if(M1==M2 && M2==M3)
		{
			printf("%d", M1);
			return 0;
		}
		if(M1<=M2 && M1<=M3) n1++;
		else if(M2<=M1 && M2<=M3) n2++;
		else n3++;
	}
	printf("-1");
	return 0;
}
