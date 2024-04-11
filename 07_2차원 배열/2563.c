#include <stdio.h>

int main()
{
	int i, j, k;
	int T, x, y, area=0;
	int paper[100][100] = {0};
	
	scanf("%d", &T);
	for(i=0;i<T;i++)
	{
		scanf("%d %d", &x, &y);  // [99-y][x]
		
		for(j=0;j<10;j++)  // За
		{
			for(k=0;k<10;k++)  // ї­
			{
				if(paper[99-y-j][x+k]==0)
				{
					paper[99-y-j][x+k] = 1;
					area++;
				}
			}
		}
	}
	printf("%d", area);
	
	return 0;
}
