#include <stdio.h>

int main()
{
	int T, H, W, N, i;
	int layer, num; 
	
	scanf("%d", &T);
	for(i=0;i<T;i++)
	{
		scanf("%d %d %d", &H, &W, &N);
		
		layer = N%H==0 ? H:N%H;
		num = N%H==0 ? N/H:N/H+1;
		
		if(num>9) printf("%d%d\n", layer, num);
		else printf("%d0%d\n", layer, num);
	}
	
	return 0;
}
