#include <stdio.h>

int main()
{
	int max, maxLine, maxRow, i, j;
	int table[9][9];
	
	for(i=0;i<9;i++) for(j=0;j<9;j++) scanf("%d", &table[i][j]);
	max = table[0][0];
	maxLine = 0;
	maxRow = 0;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			if(table[i][j]>max)
			{
				max = table[i][j];
				maxLine = i;
				maxRow = j;
			}
		}
	}
	printf("%d\n%d %d", max, maxLine+1, maxRow+1);
	
	return 0;
}
