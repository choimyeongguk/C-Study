#include <stdio.h>

void insertion_sort ( int *data)
{
	int i, j, remember;
	for ( i = 1; i < 4; i++ )
	{
		remember = data[(j=i)];
		while ( --j >= 0 && remember < data[j] )
		{
        	data[j+1] = data[j];
    	}
    	data[j+1] = remember;
  	}
}

int main()
{
	int T, i, j;
	int X[4];
	int Y[4];
	
	scanf("%d", &T);
	
	for(i=0;i<T;i++)
	{
		for(j=0;j<4;j++)
		{
			scanf("%d %d", &X[j], &Y[j]);
		}
		
		insertion_sort(X);
		insertion_sort(Y);
		
		if(X[0]==X[1] && X[2]==X[3] && Y[0]==Y[1] && Y[2]==Y[3] && X[2]-X[1]==Y[2]-Y[1])
		{
			printf("1\n");
		}
		else printf("0\n");
	}
}
