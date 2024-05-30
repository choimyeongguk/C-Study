#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int x;
	int y;
} COORDINATE;

int compare1(const COORDINATE* a, const COORDINATE* b)  // x��ǥ �������� ���� 
{
	if((*a).x==(*b).x) return (*a).y - (*b).y;
	else return (*a).x - (*b).x;  
}

int compare2(const COORDINATE* a, const COORDINATE* b)  // y��ǥ �������� ���� 
{
	if((*a).y==(*b).y) return (*a).x - (*b).x;
	else return (*a).y - (*b).y;
}

int main()
{
	int N, sum=0, i;
	COORDINATE* vertex;
	
	scanf("%d", &N);
	
	vertex = (COORDINATE*)calloc(N, sizeof(COORDINATE));
	for(i=0;i<N;i++) scanf("%d %d", &vertex[i].x, &vertex[i].y);
	
	qsort(vertex, N, sizeof(COORDINATE), compare1);  // x�������� ����, x�� ���� ��� y�������� ���� 
	for(i=0;i<N-1;i+=2)
	{
		sum += vertex[i+1].y - vertex[i].y;
	}
	qsort(vertex, N, sizeof(COORDINATE), compare2);  // y�������� ����, y�� ���� ��� x������� ���� 
	for(i=0;i<N-1;i+=2)
	{
		sum += vertex[i+1].x - vertex[i].x;
	}
	
	printf("%d", sum);
	
	free(vertex);
	return 0;
}
