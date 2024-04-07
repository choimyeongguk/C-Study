#include <stdio.h>

int main()
{
	int i;
	int crtPiece[6] = {1, 1, 2, 2, 2, 8};
	int fndPiece[6];
	
	for(i=0;i<6;i++)
	{
		scanf("%d", &fndPiece[i]);
		printf("%d ", crtPiece[i] - fndPiece[i]);
	}
	
	return 0;
}
