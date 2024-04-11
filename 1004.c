#include <stdio.h>
#include <stdlib.h>

int main()
{
	int T, cnt, i, j;
	int x1, y1, x2, y2, num;
	int len1, len2;
	int Cx, Cy, Cr;
	
	scanf("%d", &T);
	
	for(i=0;i<T;i++)
	{
		cnt = 0;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		scanf("%d", &num);
		
		for(j=0;j<num;j++)
		{
			scanf("%d %d %d", &Cx, &Cy, &Cr);
			len1 = (Cx-x1)*(Cx-x1) + (Cy-y1)*(Cy-y1);
			len2 = (Cx-x2)*(Cx-x2) + (Cy-y2)*(Cy-y2);
			
			if(len1>Cr*Cr && len2<Cr*Cr) cnt++;
			if(len2>Cr*Cr && len1<Cr*Cr) cnt++;
		}
		
		printf("%d\n", cnt);
	}
}
