#include <stdio.h>

int main()
{
	int A, B, sum=0, i, j, cnt;
	int seq[1000];
	
	scanf("%d %d", &A, &B);
	
	for(cnt=0,i=1;cnt<B;i++)
	{
		for(j=0;j<i&&cnt<B;j++)
		{
			seq[cnt++] = i;
		}
	}
	
	for(i=A-1;i<B;i++) sum += seq[i];
	printf("%d", sum);
	
	return 0;
}
