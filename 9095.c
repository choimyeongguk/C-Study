#include <stdio.h>

void DFS(int num, int sum, int* cnt)
{
	if(sum>num) return;
	if(sum==num) (*cnt)++;
	
	DFS(num, sum+1, cnt);
	DFS(num, sum+2, cnt);
	DFS(num, sum+3, cnt);
}

int main()
{
	int T, num, cnt, i;
	
	scanf("%d", &T);
	for(i=0;i<T;i++)
	{
		cnt = 0;
		scanf("%d", &num);
		DFS(num, 0, &cnt);
		printf("%d\n", cnt);
	}
	
	return 0;
}
