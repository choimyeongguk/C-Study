#include <stdio.h>

int main()
{
	int i, num=0;
	int arr[10];
	int remainder[42] = {0};
	
	for(i=0;i<10;i++)
	{
		scanf("%d", &arr[i]);
		arr[i] = arr[i]%42;
		remainder[arr[i]] = 1;
	}
	for(i=0;i<42;i++)
	{
		if(remainder[i]==1) num++;
	}
	printf("%d", num);
	
	return 0;
}
