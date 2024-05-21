#include <stdio.h>

int main()
{
	int N, L, cnt, tmp, i;
	char pipe[1001] = { 0 };
	
	scanf("%d %d", &N, &L);
	for(i=0;i<N;i++)
	{
		scanf("%d", &tmp);
		pipe[tmp]++;
	}
	
	for(cnt=0, i=1;i<=1000;i++)
	{
		if(pipe[i])
		{
			cnt++;
			i += L-1;
		}
	}
	
	printf("%d", cnt);
	
	return 0;
}
