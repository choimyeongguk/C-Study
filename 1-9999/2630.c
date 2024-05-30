#include <stdio.h>
#include <stdlib.h>

void divideNconquer(int** paper, int N, int row, int col, int* wNum, int* bNum)
{
	int i, j, chk = 0;  // chk==0 -> 전부 같은 색상 
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(paper[row][col]!=paper[row+i][col+j]) 
			{
				chk++;
				break;
			}
		}
	}
	if(chk==0)  // 전부 같은 색상 
	{
		if(paper[row][col]==0) (*wNum)++;
		else (*bNum)++; 
	}
	else
	{
		divideNconquer(paper, N/2, row, col, wNum, bNum);  // 왼쪽 위 
		divideNconquer(paper, N/2, row, col+N/2, wNum, bNum);  // 오른쪽 위
		divideNconquer(paper, N/2, row+N/2, col, wNum, bNum);  // 왼쪽 아래
		divideNconquer(paper, N/2, row+N/2, col+N/2, wNum, bNum);  // 오른쪽 아래 
	}	
}

int main()
{
	int N, i, j, chk=0;
	int wNum = 0, bNum = 0;
	int** paper;
	
	scanf("%d", &N);
	paper = (int**)malloc(N*sizeof(int*));
	for(i=0;i<N;i++) paper[i] = (int*)malloc(N*sizeof(int));n
	for(i=0;i<N;i++) for(j=0;j<N;j++) scanf("%d", &paper[i][j]);
	
	divideNconquer(paper, N, 0, 0, &wNum, &bNum);
	
	printf("%d\n%d", wNum, bNum);
	
	for(i=0;i<N;i++) free(paper[i]);
	free(paper);
	return 0;
}
