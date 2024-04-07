#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Z(int size, int row, int col, int r, int c, int* num)
{
	if(row==r && col==c)
	{
		printf("%d", *num);
		return 1;
	}
	else
	{
		if(size==1)
		{
			(*num)++;
		}
		else
		{
			size /= 2;
			if(r<size && c<size)
			{
				Z(size, row, col, r, c, )
			}
			
			if(Z(size, row, col, r, c, num)==1) return 1;
			if(Z(size, row, col+size, r, c, num)==1) return 1;
			if(Z(size, row+size, col, r, c, num)==1) return 1;
			if(Z(size, row+size, col+size, r, c, num)==1) return 1;
		}
	}
	return 0;
}

int main()
{
	int N, r, c, num=0;
	
	scanf("%d %d %d", &N, &r, &c);
	Z(pow(2, N), 0, 0, r, c, &num);
	
	return 0;
}
