#include <stdio.h>

int GCD(int x, int y)
{
	if(y==0) return x;
	GCD(y, x%y);
}

int LCM(int x, int y)
{
	int gcd = GCD(x, y);
	return x*y/gcd;
}

int main()
{
	int T, chk, i;
	int M, N, x, y;
	int lastYear, nx, ny;
	
	scanf("%d", &T);
	
	for(i=0;i<T;i++)
	{
		chk = 0;
		scanf("%d %d %d %d", &M, &N, &x, &y);
		
		lastYear = LCM(M, N);
		nx = x;
		ny = y;
		
		while(nx!=ny)
		{
			nx < ny ? (nx+=M) : (ny+=N);
			
			if(nx>lastYear || ny>lastYear)
			{
				printf("-1\n");
				chk = 1;
				break;
			}
		}
		if(!chk) printf("%d\n", nx);
	}
	
	return 0;
}
