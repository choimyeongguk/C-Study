#include <stdio.h>
#define MAX 64

void compress(char* picture, int size, int row, int col)
{
	int i, j, chk = 0;  // chk==0 -> 전부 같은 색생
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			if(*(picture+row*MAX+col) != *(picture+(row+i)*MAX+col+j))
			{
				chk++;
				break;
			}
		}
	}
	if(chk==0)  // 전부 같은 색상 
	{
		if(*(picture+row*MAX+col) == '0') printf("0");
		else printf("1");
	}
	else
	{
		printf("(");
		compress(picture, size/2, row, col);
		compress(picture, size/2, row, col+size/2);
		compress(picture, size/2, row+size/2, col);
		compress(picture, size/2, row+size/2, col+size/2);
		printf(")");
	}
}

int main()
{
	int N, i, j, chk = 0;
	char picture[MAX][MAX];
	
	scanf("%d", &N);
	for(i=0;i<N;i++) scanf("%s", picture[i]);

	compress(picture, N, 0, 0);
	return 0;
}
