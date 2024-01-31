#include <stdio.h>

int main()
{
	int N, layer=1;
	
	scanf("%d", &N);
	
	N--;  // 1계층 개수 제외 
	while(N>0)
	{
		layer++;
		N -= 6*(layer-1);
	}
	printf("%d", layer);
	
	return 0;
}
