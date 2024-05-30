#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
	int x;
	int y;
} LOC;

int len(LOC chkpnt1, LOC chkpnt2)
{
	return abs(chkpnt1.x-chkpnt2.x) + abs(chkpnt1.y-chkpnt2.y);
}

int main()
{
	int N, sum, min, tmp, i;
	LOC* chkpnt;
	int* length;
	
	scanf("%d", &N);
	
	chkpnt = (LOC*)calloc(N, sizeof(LOC));
	length = (int*)calloc(N, sizeof(int));
	
	scanf("%d %d", &chkpnt[0].x, &chkpnt[0].y);
	for(sum=0, i=1;i<N;i++)
	{
		scanf("%d %d", &chkpnt[i].x, &chkpnt[i].y);
		length[i-1] = len(chkpnt[i], chkpnt[i-1]);
		sum += length[i-1];
	}
	
	for(min=sum, i=1;i<=N-1;i++)
	{
		tmp = sum - length[i-1] - length[i] + len(chkpnt[i-1], chkpnt[i+1]);
		min = min<tmp ? min:tmp;
	}
	
	printf("%d", min);
	
	free(chkpnt);
	return 0;
}
