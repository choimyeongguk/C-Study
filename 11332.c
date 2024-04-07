#include <stdio.h>
#include <math.h>

int main()
{
	int C, i, j;
	double N, T, L, num;
	char S[7];
	
	scanf("%d", &C);
	for(i=0;i<C;i++)
	{
		scanf("%s %lf %lf %lf", S, &N, &T, &L);
		if(S[3]=='!')  // ÆÑÅä¸®¾ó 
		{
			num = 1;
			for(j=1;j<=N;j++)
			{
				num *= j;
				if(num>L*100000000/T)
				{
					printf("TLE!\n");
					break;
				}
			}
			if(j==N+1) printf("May Pass.\n");
		}
	 	else if(S[2]=='2')  // 2½Â¼ö 
	 	{
	 		if(N<=log2(L*100000000/T)) printf("May Pass.\n");
	 		else printf("TLE!\n");
		}
		else if(S[4]=='2')  // Á¦°ö¼ö 
		{
			if(N*N*T<=100000000*L) printf("May Pass.\n");
			else printf("TLE!\n");
		}
		else if(S[4]=='3')  // ¼¼Á¦°ö¼ö 
		{
			if(N*N*N*T<=100000000*L) printf("May Pass.\n");
			else printf("TLE!\n");
		}
		else
		{
			printf("May Pass.\n");
		}
	}
	
	return 0;
}
