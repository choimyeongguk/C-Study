#include <stdio.h>

typedef struct
{
	int h;
	int w;
	int area;
} PAPER;

void LAY(int* a, int* b)
{
	if(*a > *b)
	{
		int tmp = *a;
		*a = *b;
		*b = tmp;
	}
}

void MAX(int* max, int* x)
{
	if(*max < *x) *max = *x;
}

int main()
{
	int H, W, N, h, w, i, j, tmp;
	PAPER paper[100]; int num = 0;
	int max = 0;
	
	scanf("%d %d", &H, &W);
	LAY(&H, &W);  // 눕혀진(가로가 더 긴) 형태로 변환 
	
	scanf("%d", &N);
	for(i=0;i<N;i++)
	{
		scanf("%d %d", &h, &w);
		LAY(&h, &w);
		if(h<=H && w<=W)
		{
			paper[num].h = h;
			paper[num].w = w;
			paper[num++].area = h*w;
		}
	}
	
	for(i=0;i<num-1;i++)
	{
		for(j=i+1;j<num;j++)
		{
			// 세로로 이어붙이기 
			h = paper[i].h + paper[j].h;
			w = paper[i].w>paper[j].w ? paper[i].w:paper[j].w;
			LAY(&h, &w);
			if(h<=H && w<=W)
			{
				tmp = paper[i].area + paper[j].area;
				MAX(&max, &tmp);
				continue; 
			}
			
			// 가로로 이어붙이기 
			h = paper[i].h>paper[j].h ? paper[i].h:paper[j].h;
			w = paper[i].w + paper[j].w;
			LAY(&h, &w);
			if(h<=H && w<=W)
			{
				tmp = paper[i].area + paper[j].area;
				MAX(&max, &tmp);
				continue; 
			}
			
			// j 돌린 후 세로로 이어붙이기
			h = paper[i].h + paper[j].w;
			w = paper[i].w>paper[j].h ? paper[i].w:paper[j].h;
			LAY(&h, &w);
			if(h<=H && w<=W)
			{
				tmp = paper[i].area + paper[j].area;
				MAX(&max, &tmp);
				continue;
			}
			
			// j 돌린 후 가로로 이어붙이기
			h = paper[i].h>paper[j].w ? paper[i].h:paper[j].w;
			w = paper[i].w + paper[j].h;
			LAY(&h, &w);
			if(h<=H && w<=W)
			{
				tmp = paper[i].area + paper[j].area;
				MAX(&max, &tmp);
				continue;
			} 
		}
	}
	
	printf("%d", max);
	
	return 0;
}
