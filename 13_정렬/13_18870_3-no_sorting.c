// 시간 초과 

#include <stdio.h>

int main()
{
	int N, compressed, num, min, i;
	int coordinate[1000000];
	
	scanf("%d", &N);
	for(i=0;i<N;i++) scanf("%d", &coordinate[i]);
	
	compressed = 0;
	num = 0;
	
	min = coordinate[0];
	for(i=1;i<N;i++) min = min<coordinate[i]?min:coordinate[i];
	for(i=0;i<N;i++)
	{
		if(coordinate[i]==min) compressed++;
		coordinate[i] = coordinate[i] - min;
	}
	num++;
	
	while(compressed!=N)
	{
		for(i=0;i<N;i++)
		{
			if(coordinate[i]>num-1)
			{
				min = coordinate[i];
				break;
			}
		}
		
		for(i=0;i<N;i++)
		{
			if(coordinate[i]<min && coordinate[i]>num-1) min = coordinate[i];
		}
		for(i=0;i<N;i++)
		{
			if(coordinate[i]==min) compressed++;
			if(coordinate[i]>num-1)
			{
				coordinate[i] = coordinate[i] - min + num;
			}
		}
		num++;
	}
	
	for(i=0;i<N;i++) printf("%d ", coordinate[i]);
	
	return 0;
} 
