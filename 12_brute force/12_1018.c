#include <stdio.h>

int main()
{
	char line[50];
	char board[50][50];
	int N, M, i, j, k, l, cnt1, cnt2, cntMin;
	
	scanf("%d %d", &N, &M);  // 행, 열 입력 
	cntMin = N*M;  // 최악의 경우의 다시 칠해야 하는 개수로 설정 
	for(i=0;i<N;i++)
	{
		scanf("%s", &line);
		for(j=0;j<M;j++) board[i][j] = line[j];  // 입력값을 board 배열에 각각 대입 
	}

	for(i=0;i<N-7;i++)  // board 행 
	{
		for(j=0;j<M-7;j++)  // board 열 
		{
			// 왼쪽 위 돌의 좌표: i행 j열 
			cnt1 = 0;
			cnt2 = 0;
			
			// 왼쪽 위가 Black인 경우
			for(k=0;k<8;k++)  // chess 행 
			{
				for(l=0;l<8;l++)  // chess 열 
				{
					if((k+l+2)%2==0)  // Black이어야 하는 칸 
					{
						if(board[i+k][j+l]=='W') cnt1++;  // Black이어야 하는 칸에 White가 들어감 
					}
					else
					{
						if(board[i+k][j+l]=='B') cnt1++;
					} 
				} 
			}
			
			// 왼쪽 위가 White인 경우
			for(k=0;k<8;k++)  // chess 행 
			{
				for(l=0;l<8;l++)  // chess 열 
				{
					if((k+l+2)%2==0)  // White이어야 하는 칸 
					{
						if(board[i+k][j+l]=='B') cnt2++;  // White이어야 하는 칸에 Black이 들어감 
					}
					else
					{
						if(board[i+k][j+l]=='W') cnt2++;
					} 
				} 
			}
			
			cntMin = cntMin<cnt1?cntMin:cnt1;
			cntMin = cntMin<cnt2?cntMin:cnt2;
		} 
	}
	printf("%d", cntMin);
	
	return 0;
}
