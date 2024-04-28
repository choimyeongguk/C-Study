#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int start;
	int end;
} MEETING;

int compare(const MEETING*a, const MEETING* b)
{
	if((*a).end==(*b).end)
	{
		return (*a).start - (*b).start;
	}
	return (*a).end - (*b).end;
}

int main()
{
	int N, cnt, endMin, i;
	MEETING* meeting;
	
	scanf("%d", &N);
	
	meeting = (MEETING*)calloc(N, sizeof(MEETING));
	for(i=0;i<N;i++)
	{
		scanf("%d %d", &meeting[i].start, &meeting[i].end);
	}
	qsort(meeting, N, sizeof(MEETING), compare);
	
	cnt = 1;
	endMin = 0;
	for(i=1;i<N;i++)
	{
		if(meeting[endMin].end<=meeting[i].start)
		{
			cnt++;
			endMin = i;
		}
	}
	printf("%d", cnt);

	free(meeting);
	return 0;
}
