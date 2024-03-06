#include <stdio.h>

int main()
{
	int N, arr[1000], check=1, buf, i;
	
	scanf("%d", &N);
	for(i=0;i<N;i++) scanf("%d", &arr[i]);
	
	while(check!=0)
	{
		check = 0;
		for(i=0;i<N-1;i++)
		{
			if(arr[i]>arr[i+1])
			{
				buf = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = buf;
				check++;
			}
		}
	}
	
	for(i=0;i<N;i++) printf("%d\n", arr[i]);
	
	return 0;
}
