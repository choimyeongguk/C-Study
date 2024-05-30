#include <stdio.h>

void dfs(int depth, int N, int* arr, int* op, int* max, int* min, int value)
{
	if(depth == N-1)
	{
		*max = *max>value ? *max:value;
		*min = *min<value ? *min:value;
	}
	else
	{
		for(int i=0;i<4;i++)
		{
			if(op[i]>0)
			{
				switch(i)
				{
					case 0:
						op[i]--;
						dfs(depth+1, N, arr, op, max, min, value+arr[depth+1]);
						op[i]++;
						break;
					case 1:
						op[i]--;
						dfs(depth+1, N, arr, op, max, min, value-arr[depth+1]);
						op[i]++;
						break;
					case 2:
						op[i]--;
						dfs(depth+1, N, arr, op, max, min, value*arr[depth+1]);
						op[i]++;
						break;
					case 3:
						op[i]--;
						dfs(depth+1, N, arr, op, max, min, value/arr[depth+1]);
						op[i]++;
						break;					
				}
			}
		}
	}
}

int main()
{
	int N, i;
	int max = -1000000000;
	int min = 1000000000;
	int op[4];
	int arr[11];
	
	scanf("%d", &N);
	
	for(i=0;i<N;i++) scanf("%d", &arr[i]);
	for(i=0;i<4;i++) scanf("%d", &op[i]);
	
	dfs(0, N, arr, op, &max, &min, arr[0]);
	
	printf("%d\n%d", max, min);
	
	return 0;
}
