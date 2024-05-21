#include <stdio.h>

int d(int x)
{
	int num = 10;
	int result = x;
	while(x>0)
	{
		result += x%num;
		x /= num;
	}
	return result;
}

int main()
{
	int i;
	char arr[20000] = { 0 };
	for(i=1;i<=10000;i++)
	{
		arr[d(i)]++;
	}
	for(i=1;i<=10000;i++)
	{
		if(!arr[i]) printf("%d\n", i);
	}
	
	return 0;
}
