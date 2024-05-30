#include <stdio.h>
#define MIN(a,b) a<b?a:b

int d(int x, int y)
{
	int z = x^y;
	switch(z)
	{
		case 0:
			return 0;
			break;
		case 1: case 2: case 4: case 8:
			return 1;
			break;
		case 3: case 5: case 6: case 9: case 10: case 12:
			return 2;
			break;
		case 7: case 11: case 13: case 14:
			return 3;
			break;
		case 15:
			return 4;
			break;
	}
}

int main()
{
	int T, N, min, i, j, k, l;
	char distance[16][16][16];
	char mbti[100000];
	
	for(i=0;i<16;i++)
	{
		for(j=i;j<16;j++)
		{
			for(k=j;k<16;k++)
			{
				distance[i][j][k] = d(i, j) + d(j, k) + d(k, i);
				distance[i][k][j] = distance[i][j][k];
				distance[j][i][k] = distance[i][j][k];
				distance[j][k][i] = distance[i][j][k];
				distance[k][i][j] = distance[i][j][k];
				distance[k][j][i] = distance[i][j][k];
			}
		}
	}
	
	scanf("%d", &T);
	
	for(i=0;i<T;i++)
	{
		scanf("%d", &N);
		
		for(j=0;j<N;j++) mbti[j] = 0;
		
		for(j=0;j<N;j++)
		{
			getchar();
			mbti[j] += getchar()/'I'<<3;
			mbti[j] += (getchar()/'S')<<2;
			mbti[j] += (getchar()/'T')<<1;
			mbti[j] += (getchar()/'P');
		}
		
		for(min=100, j=0;j<N;j++)
		{
			for(k=j+1;k<N;k++)
			{
				for(l=k+1;l<N;l++)
				{
					min = MIN(min, distance[mbti[j]][mbti[k]][mbti[l]]);
					if(!min) goto PRINT;
				}
			}
		}
		
		PRINT: printf("%d\n", min);
	}

	return 0;
}
