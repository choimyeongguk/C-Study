#include <stdio.h>
#include <math.h>

int main()
{
	int N, i, j, size, num=0;
	int* arr;
	char* sum;
	
	scanf("%d", &N);
	size = pow(2, N)-1;  // 부분합의 가짓수 
	arr = (int*)malloc(N*sizeof(int));
	
	for(i=0;i<N;i++)
	{
		scanf("%d", &arr[i]);
		num += arr[i];
	}
	sum = (char*)malloc((num+2)*sizeof(char));
	for(i=0;i<num+2;i++) sum[i] = 0;
	
	for(i=1;i<=size;i++)  // 00...1 부터 11...1까지 
	{
		num = 0;
		for(j=0;j<N;j++) num += arr[j] * ((i>>j)&1);
		sum[num] = 1;
	}
	
	i = 0;
	while(++i)
	{
		if(sum[i]==0)
		{
			printf("%d", i);\
			return 0;
		}
	}
	

	return 0;
}
