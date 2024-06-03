#include <stdio.h>

typedef struct
{
	int x;
	int y;
} POINT;

void swap(POINT* a, POINT* b)
{
	POINT tmp = *a;
	*a = *b;
	*b = tmp;
}

int main()
{
	int tx1, ty1, tx2, ty2, tmp, t1, t2;
	POINT p1, p2, p3;
	
	scanf("%d %d", &p1.x, &p1.y);
	scanf("%d %d", &p2.x, &p2.y);
	scanf("%d %d", &p3.x, &p3.y);
	
	tmp = p2.x-p1.x;
	tx1 = tmp>0 ? tmp:-1*tmp;
	ty1 = tmp>0 ? p2.y-p1.y:p1.y-p2.y;
	tmp = p3.x-p2.x;
	tx2 = tmp>0 ? tmp:-1*tmp;
	ty2 = tmp>0 ? p3.y-p2.y:p2.y-p3.y;
	
	t1 = ty1*tx2;
	t2 = ty2*tx1;
	
	// 1: 반시계, -1: 시계, 0: 일직선 
	printf("t1 = %d, t2 = %d", t1, t2);
	printf("%d", t1==t2 ? 0:t1<t2 ? 1:-1);
	
	return 0;
}
