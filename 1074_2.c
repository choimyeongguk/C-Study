#include <stdio.h>
#include <math.h>

int Z(int size, int r, int c)
{
	int mid = (int)pow(2, size-1);
	if(size<1) return 0;
	else
	{
		if(r<mid && c<mid)  // 1��и� 
		{
			return Z(size-1, r, c); 
		}
		else if(r<mid && c>=mid)  // 2��и� 
		{
			return mid*mid + Z(size-1, r, c-mid);
		}
		else if(r>=mid && c<mid)  // 3��и� 
		{
			return mid*mid*2 + Z(size-1, r-mid, c);
		}
		else  // 4��и� 
		{
			return mid*mid*3 + Z(size-1, r-mid, c-mid);
		}
	}
}

int main()
{
	int N, r, c, num = 0;
	
	scanf("%d %d %d", &N, &r, &c);
	
	printf("%d", Z(N, r, c));
	
	return 0;
}
