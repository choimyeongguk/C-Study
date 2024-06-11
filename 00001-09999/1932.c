#include <stdio.h>
#include <stdlib.h>
#define MAX(a,b) a>b?a:b

int main()
{
	int N, max, idx, i, j;
	int* tri;
	
	scanf("%d", &N);
	tri = (int*)calloc(N*(N+1)/2, sizeof(int));
	for(i=0;i<N*(N+1)/2;i++) scanf("%d", &tri[i]);
	
	idx = 1;
	for(i=1;i<N;i++)
	{
		tri[idx] += tri[idx-i];
		idx++;
		for(j=0;j<i-1;j++)
		{
			tri[idx] += MAX(tri[idx-i], tri[idx-i-1]);
			idx++;
		}
		tri[idx] += tri[idx-i-1];
		idx++;
	}
	// 굳이 이러지 말고 삼각형을 0으로 감싸는 방법도 있음!
	// 그러면 일관성 있게 덧셈 가능 
	
	for(max=0,i=0;i<N;i++)
	{
		max = MAX(max, tri[N*(N+1)/2-1-i]);
	}
	printf("%d", max);
	
	return 0;
}
