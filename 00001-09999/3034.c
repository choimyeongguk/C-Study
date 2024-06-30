#include <stdio.h>

int main()
{
	int N, W, H, d, l, i;
	
	scanf("%d %d %d", &N, &W, &H);
	d = W*W + H*H;
	for(i=0;i<N;i++)
	{
		scanf("%d", &l);
		if(l*l<=d) printf("DA\n");
		else printf("NE\n");
	}
	
	return 0;
}
