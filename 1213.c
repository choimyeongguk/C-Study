#include <stdio.h>

int main()
{
	int i = 0, j;
	char name[51]; int start = 0, end = 0;
	char alphabet[26] = { 0 };
	
	scanf("%s", name);
	
	while(name[i]!='\0')
	{
		alphabet[name[i++]-65]++;
		end++;
	}
	end--;
	
	for(i=0;i<51;i++) name[i] = 0;
	for(i=0;i<26;i++)
	{
		if(alphabet[i]%2==1)
		{
			if(name[end/2])
			{
				printf("I'm Sorry Hansoo");
				return 0;
			}
			else
			{
				name[end/2] = i+65;
			}
		}
	}
	for(i=0;i<26;i++)
	{
		if(alphabet[i])
		{
			for(j=0;j<alphabet[i]/2;j++)
			{
				name[start++] = i+65;
				name[end--] = i+65;
			}
		}
	}
	printf("%s", name);
	
	return 0;
}
