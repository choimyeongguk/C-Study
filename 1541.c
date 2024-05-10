#include <stdio.h>

int extractNum(int* stack, int* top, char plusOrMinus)
{
	int result = 0, digit = 1;
	while(*top>0)
	{
		result += stack[--(*top)] * digit;
		digit *= 10;
	}
	result = !plusOrMinus ? result:-1*result;
	return result;
}

int main()
{
	int sum = 0, i = 0;
	int stack[6]; int top = 0;
	char plusOrMinus = 0;  // 0 - plus, 1 - minus
	char expression[51];
	
	scanf("%s", expression);
	
	do
	{
		if(48<=expression[i] && expression[i]<=57)  // number
		{
			stack[top++] = expression[i] - '0';
		}
		else  // '-' or '+' or '\0'
		{
			sum += extractNum(stack, &top, plusOrMinus);
			if(expression[i]=='-')
			{
				plusOrMinus = 1;
			}
		}
	} while(expression[i++]!='\0');
	
	printf("%d", sum);
	
	return 0;
}
