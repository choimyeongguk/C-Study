#include <stdio.h>

int main()
{
	char line[50];
	char board[50][50];
	int N, M, i, j, k, l, cnt1, cnt2, cntMin;
	
	scanf("%d %d", &N, &M);  // ��, �� �Է� 
	cntMin = N*M;  // �־��� ����� �ٽ� ĥ�ؾ� �ϴ� ������ ���� 
	for(i=0;i<N;i++)
	{
		scanf("%s", &line);
		for(j=0;j<M;j++) board[i][j] = line[j];  // �Է°��� board �迭�� ���� ���� 
	}

	for(i=0;i<N-7;i++)  // board �� 
	{
		for(j=0;j<M-7;j++)  // board �� 
		{
			// ���� �� ���� ��ǥ: i�� j�� 
			cnt1 = 0;
			cnt2 = 0;
			
			// ���� ���� Black�� ���
			for(k=0;k<8;k++)  // chess �� 
			{
				for(l=0;l<8;l++)  // chess �� 
				{
					if((k+l+2)%2==0)  // Black�̾�� �ϴ� ĭ 
					{
						if(board[i+k][j+l]=='W') cnt1++;  // Black�̾�� �ϴ� ĭ�� White�� �� 
					}
					else
					{
						if(board[i+k][j+l]=='B') cnt1++;
					} 
				} 
			}
			
			// ���� ���� White�� ���
			for(k=0;k<8;k++)  // chess �� 
			{
				for(l=0;l<8;l++)  // chess �� 
				{
					if((k+l+2)%2==0)  // White�̾�� �ϴ� ĭ 
					{
						if(board[i+k][j+l]=='B') cnt2++;  // White�̾�� �ϴ� ĭ�� Black�� �� 
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
