#include <stdio.h>

int main()
{
	int N, v, i;
	int num = 0;
	scanf("%d", &N);
	int arr[N];
	
	for(i=0;i<N;i++) scanf("%d", &arr[i]);
	scanf("%d", &v);
	
	for(i=0;i<N;i++)
	{
		if(arr[i]==v) num++;
	}
	printf("%d", num);
	
	return 0;
}
