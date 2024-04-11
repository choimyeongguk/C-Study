#include <stdio.h>

int main()
{
	int input, cnt, i, j;
	char eratos[246913] = { 0 };
	
	eratos[1]++;
	for(i=2;i*i<246912;i++)
	{
		if(eratos[i]==0)
		{
			for(j=2;i*j<=246912;j++)
			{
				eratos[i*j]++;
			}
		}
	}
	
	while(1)
	{
		scanf("%d", &input);
		if(input==0) break;
		
		cnt = 0;
		for(i=input+1;i<=2*input;i++)
		{
			if(eratos[i]==0) cnt++;
		}
		printf("%d\n", cnt);
	}
	
	return 0;
}
