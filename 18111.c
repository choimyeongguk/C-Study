#include <stdio.h>

int main()
{
	int N, M, B, i, j, k;
	int numBlock, maxH, height, time, minTime = 128000000;  // time-�־��� ���: 500*500ũ���� ������ 256���� ���� ���� 
	int map[500][500];
	
	scanf("%d %d %d", &N, &M, &B);
	numBlock = B;
	
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
		{
			scanf("%d", &map[i][j]);
			numBlock += map[i][j];
		}
	}
	
	maxH = numBlock/(N*M);  // ������ ����� �ִ��� ����Ͽ� ���� �� �ִ� �� ������ �ִ� ���� 
	
	for(i=maxH;i>=0;i--)
	{
		time = 0;
		
		for(j=0;j<N;j++)  // �� 
		{
			for(k=0;k<M;k++)  // �� 
			{
				if(map[j][k]>i)
				{
					time += (map[j][k]-i)*2;
				}
				if(map[j][k]<i)
				{
					time += i-map[j][k];
				}
			}
			if(time>minTime) break;
		}
		
		if(time<minTime)
		{
			minTime = time;
			height = i;
		}
	}
	
	printf("%d %d", minTime, height);
	
	return 0;
}
