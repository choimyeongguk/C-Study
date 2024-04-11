#include <stdio.h>
#include <string.h>

int main()
{
	int i, len;
	char stack[101]; int top;
	char sentence[101];
	
	while(1)
	{
		top = 0;
		gets(sentence);
		len = strlen(sentence);
		if(len==1 && sentence[0]=='.') break;
		
		for(i=0;i<len;i++)
		{
			if(sentence[i]=='(' || sentence[i]=='[')
			{
				stack[top++] = sentence[i];
			}
			
			if(sentence[i]==')')
			{
				if(stack[top-1]=='(') top--;
				else
				{
					top = 1;
					break;
				}
			}
			
			if(sentence[i]==']')
			{
				if(stack[top-1]=='[') top--;
				else
				{
					top = 1;
					break;
				}
			}
		}
		
		printf("%s", top ? "no\n":"yes\n");
	}
	
	return 0;
}
