#include <stdio.h>

int main()
{
	int N, M, B, i, j, k;
	int numBlock, maxH, height, time, minTime = 128000000;  // time-최악의 경우: 500*500크기의 땅에서 256개씩 전부 없앰 
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
	
	maxH = numBlock/(N*M);  // 보유한 블록을 최대한 사용하여 만들 수 있는 고른 평지의 최대 높이 
	
	for(i=maxH;i>=0;i--)
	{
		time = 0;
		
		for(j=0;j<N;j++)  // 행 
		{
			for(k=0;k<M;k++)  // 열 
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
