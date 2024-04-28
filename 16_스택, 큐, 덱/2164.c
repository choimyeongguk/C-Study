#include <stdio.h>

int func(int* arr, int size)
{
	int i, num;
	
	if(size==1) return arr[0];
	
	if(size%2==0)  // Â¦¼ö 
	{
		for(i=0;i<size/2;i++)
		{
			arr[i] = arr[(i+1)*2-1];
		}
		func(arr, size/2);
	}
	else  // È¦¼ö 
	{
		num = arr[1];
		for(i=0;i<size/2-1;i++)
		{
			arr[i] = arr[(i+1)*2+1];
		}
		arr[size/2-1] = num;
		func(arr, size/2);
	}
}

int main()
{
	int N, i;
	int* card; 
	
	scanf("%d", &N);
	card = (int*)malloc((N/2)*sizeof(int));
	
	if(N==1) printf("1");
	else
	{
		if(N%2==0)  // Â¦¼ö 
		{
			for(i=1;i<=N/2;i++) card[i-1] = i*2;
		}
		else  // È¦¼ö 
		{
			for(i=1;i<N/2;i++) card[i-1] = i*2+2;
			card[N/2-1] = 2;
		}
		
		printf("%d", func(card, N/2));
	}
	
	return 0;
}
