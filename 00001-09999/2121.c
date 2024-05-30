#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int x;
	int y;
} POINT;

int N, W, H;
POINT* point;

int compare(const POINT* a, const POINT* b)
{
	if((*a).x==(*b).x)
	{
		return (*a).y - (*b).y;
	}
	return (*a).x - (*b).x;
}

int binarySearch(int x, int y, int start, int end)
{
	if(start<=end)
	{
		int mid = (start+end)/2;
		
		if(x<point[mid].x) binarySearch(x, y, start, mid-1);
		else if(x>point[mid].x) binarySearch(x, y, mid+1, end);
		else
		{
			if(y<point[mid].y) binarySearch(x, y, start, mid-1);
			else if(y>point[mid].y) binarySearch(x, y, mid+1, end);
			else return 1;
		}
	}
	else return 0;
}

int isPossible(int i)
{
	int x = point[i].x;
	int y = point[i].y;
	
	if(!binarySearch(x+W, y, i, N-1)) return 0;
	if(!binarySearch(x, y+H, i, N-1)) return 0;
	if(!binarySearch(x+W, y+H, i, N-1)) return 0;
	return 1;
}

int main()
{
	int cnt, i;
	
	scanf("%d", &N);
	scanf("%d %d", &W, &H);
	
	point = (POINT*)calloc(N, sizeof(POINT));
	
	for(i=0;i<N;i++)
	{
		scanf("%d %d", &point[i].x, &point[i].y);
	}
	qsort(point, N, sizeof(POINT), compare);
	
	for(cnt=0, i=0;i<N;i++)
	{
		if(isPossible(i)) cnt++;
	}
	
	printf("%d", cnt);
	
	free(point);
	return 0;
}
