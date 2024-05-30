#include <stdio.h>
#define max(a,b) a>b?a:b

typedef struct
{
	int x;
	int y;
} COORD;

double getArea(COORD a, COORD b, COORD c)
{
	double tmp1 = a.x*b.y + b.x*c.y + c.x*a.y;
	double tmp2 = a.y*b.x + b.y*c.x + c.y*a.x;
	tmp1 -= tmp2;
	return (tmp1>0?tmp1:-1*tmp1)/2;
}

int main()
{
	int N, i, j, k;
	double maxArea;
	COORD vertex[35];
	
	scanf("%d", &N);
	
	for(i=0;i<N;i++)
	{
		scanf("%d %d", &vertex[i].x, &vertex[i].y);
	}
	
	for(maxArea=0,i=0;i<N-2;i++)
	{
		for(j=i+1;j<N-1;j++)
		{
			for(k=j+1;k<N;k++)
			{
				maxArea = max(maxArea, getArea(vertex[i], vertex[j], vertex[k]));
			}
		}
	}
	
	printf("%f", maxArea);
	
	return 0;
}
