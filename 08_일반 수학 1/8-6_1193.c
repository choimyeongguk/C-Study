#include <stdio.h>

int main()
{
	int X, layer=0, layerNum, son, mother, i;
	
	scanf("%d", &X);
	while(X>0)
	{
		layer++;
		X -= layer;
	}
	layerNum = layer + X;
	
	if(layer%2==0)
	{
		son = layerNum;
		mother = layer - son + 1;
	}
	else
	{
		mother = layerNum;
		son = layer - mother + 1;
	}
	printf("%d/%d", son, mother);
	
	return 0;
}
