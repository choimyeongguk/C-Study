#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N, K, cnt=0, i, j;
	char* table;
	
	scanf("%d %d", &N, &K);
	
	table = (char*)calloc(N, sizeof(char));
	scanf("%s", table);
	
	for(i=0;i<N;i++)
	{
		if(table[i]=='P')
		{
			for(j=i-K;j<=i+K;j++)
			{
				if(j>=0 && j<N && table[j]=='H')
				{
					table[j] = 0;
					cnt++;
					break;
				}
			}
		}
	}
	
	printf("%d", cnt);
	
	free(table);
	return 0;
}
