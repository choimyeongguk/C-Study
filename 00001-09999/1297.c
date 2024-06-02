#include <stdio.h>
#include <math.h>

int main()
{
	int D, H, W;
	double k;
	
	scanf("%d %d %d", &D, &H, &W);
	
	k = D/sqrt(H*H+W*W);
	H = H*k;
	W = W*k;
	
	printf("%d %d", H, W);
	
	return 0;
}
