#include <stdio.h>

int main()
{
	int T, sum, score=0,i, j;
	char result[81];
	
	scanf("%d", &T);
	for(i=0;i<T;i++)
	{
		scanf("%s", result);
		
		sum = 0; score = 0; j = -1;
		while(result[++j]!='\0')
		{
			if(result[j]=='O') sum += ++score;
			else score = 0;
		}
		
		printf("%d\n", sum);
	}
	
	return 0;
}
