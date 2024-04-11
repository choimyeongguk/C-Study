#include <stdio.h>
#include <math.h>

void Z(int size, int row, int col, int r, int c, int num)
{
	if(row==r && col==c)
	{
		printf("%d", num);
	}
	else
	{
		size /= 2;
		
		if(r<row+size && c<col+size)  // 1사분면 
		{
			Z(size, row, col, r, c, num);
		}
		else if(r<row+size && c>=col+size)  // 2사분면 
		{
			num += size*size;
			Z(size, row, col+size, r, c, num);
		}
		else if(r>=row+size && c<col+size)  // 3사분면 
		{
			num += size*size*2;
			Z(size, row+size, col, r, c, num);
		}
		else  // 4사분면 
		{
			num += size*size*3;
			Z(size, row+size, col+size, r, c, num);
		}
	}
}

int main()
{
	int N, r, c, num = 0;
	
	scanf("%d %d %d", &N, &r, &c);
	
	Z(pow(2, N), 0, 0, r, c, num);
	
	return 0;
}
