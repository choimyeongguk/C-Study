#include <stdio.h>

int main()
{
	int arr[5], check, buf, i;
	for(i=0;i<5;i++) scanf("%d", &arr[i]);
	
	printf("%d\n", (arr[0]+arr[1]+arr[2]+arr[3]+arr[4])/5);
	do
	{
		check = 0;
		for(i=0;i<4;i++)
		{
			if(arr[i]>arr[i+1])
			{
				buf = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = buf;
				check++;
			}
		}
	} while(check!=0);
	printf("%d", arr[2]);
	
	return 0;
}
