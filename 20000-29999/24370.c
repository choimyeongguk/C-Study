#include <stdio.h>
#include <math.h>

int main()
{
	int a2, a1, a0, c1, c2, n0, D1, D2, chk=0;
	
	scanf("%d %d %d", &a2, &a1, &a0);
	scanf("%d %d", &c1, &c2);
	scanf("%d", &n0);
	
	D1 = pow(a1, 2)-4*(a2-c1)*a0;
	D2 = pow(a1, 2)+4*(c2-a2)*a0;
	//c1
	if(a2>c1)
	{
		if(D1>0 && n0>=(double)(-1*a1+pow(D1, 0.5))/(2*(a2-c1))) chk++;
		else if(D1<=0) chk++;
		else
		{
			printf("0");
			return 0;
		}
	}
	else if(a2==c1)
	{
		if(a1==0 && a0>=0) chk++;
		else if(a1>0 && n0>=(double)-1*(a0/a1)) chk++;
		else
		{
			printf("0");
			return 0;
		}
	}
	else
	{
		printf("0");
		return 0;
	}
	
	//c2
	if(a2<c2)
	{
		if(D2>0 && n0>=(double)(a1+pow(D2, 0.5))/(2*(c2-a2))) chk++;
		else if(D2<=0) chk++;
		else
		{
			printf("0");
			return 0;
		}
	}
	else if(a2==c2)
	{
		if(a1==0 && a0<=0) chk++;
		else if(a1<0 && n0>=(double)-1*(a0/a1)) chk++;
		else
		{
			printf("0");
			return 0;
		}
	}
	else
	{
		printf("0");
		return 0;
	}
	printf("1");
	
	return 0;
}
