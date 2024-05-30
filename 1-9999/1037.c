//#include <stdio.h>
//
//int getGCD(long long int x, long long int y)
//{
//	if(y==0) return x;
//	return getGCD(y, x%y);
//}
//
//int getLCM(long long int x, long long int y)
//{
//	return x*y/getGCD(x, y);
//}
//
//int main()
//{
//	int numDivisor, tmp, i;
//	int min = 1000000, max = 0;
//	int lcm = 1;
//	
//	scanf("%d", &numDivisor);
//	for(i=0;i<numDivisor;i++)
//	{
//		scanf("%d", &tmp);
//		lcm = getLCM(lcm, tmp);
//		max = max>tmp ? max:tmp;
//		min = min<tmp ? min:tmp;
//	}
//	
//	if(lcm==max)
//	{
//		lcm *= min;
//	}
//	printf("%d", lcm);
//	
//	return 0;
//}


#include <stdio.h>

int main()
{
	int T, tmp, i;
	int min=1000000, max=0;
	scanf("%d", &T);
	for(i=0;i<T;i++)
	{
		scanf("%d", &tmp);
		max = max>tmp ? max:tmp;
		min = min<tmp ? min:tmp
	}
	printf("%d", min*max);
	
	return 0;
}

