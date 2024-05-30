#include <stdio.h>
#include <string.h>

int main()
{
	int i, len;
	char num[6];
	
	while(1)
	{
		scanf("%s", &num);
		if(num[0]=='0') return 0;
		
		len = strlen(num);
		for(i=0;i<len/2;i++)
		{
			if(num[i]!=num[len-1-i])
			{
				printf("no\n");
				goto NOPALINDROME;
			}
		}
		printf("yes\n");
		NOPALINDROME:;
	}
}
