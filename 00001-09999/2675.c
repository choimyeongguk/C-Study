#include <stdio.h>

int main()
{
	int T, R, i, j ,k;
	int len = 0;
	char S[20];
	
	scanf("%d", &T);
	for(i=0;i<T;i++)
	{
		len = 0;
		scanf("%d %s", &R, &S);
		while(S[len]!='\0') len++;
		for(j=0;j<len;j++)
		{
			for(k=0;k<R;k++)
			{
				printf("%c", S[j]);
			}
		}
		printf("\n");
	}
	
	return 0;
}
