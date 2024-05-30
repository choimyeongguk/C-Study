#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int x;
	int y;
} LOC;

int compare(const double* a, const double* b)
{
	return *a - *b;
}

int main()
{
	int T, cnt, tmp1, tmp2, i, j, k;
	double line[6];
	LOC point[4];
	
	scanf("%d", &T);
	
	for(i=0;i<T;i++)
	{
		for(j=0;j<4;j++)
		{
			scanf("%d %d", &point[j].x, &point[j].y);
		}
		
		for(cnt=0, j=0;j<3;j++)
		{
			for(k=j+1;k<4;k++)
			{
				tmp1 = point[j].x-point[k].x;
				tmp2 = point[j].y-point[k].y;
				line[cnt++] = tmp1*tmp1 + tmp2*tmp2;
			}
		}
		qsort(line, 6, sizeof(double), compare);
		if(line[0]==line[1] && line[1]==line[2] && line[2]==line[3] && line[4]==line[5])
		{
			printf("1\n");
		}
		else printf("0\n");
	}
	
	return 0;
}
