#include <stdio.h>
#include <stdlib.h>

int compare(const char* a, const char* b)
{
	return *b - *a;
}

int main()
{
	char num[100001];
	int sum = 0, i;
	
	scanf("%s", num);
	for(i=0;num[i]!='\0';i++)
	{
		sum += num[i] - '0';
	}
	qsort(num, i, sizeof(char), compare);
	
	if(sum%3==0 && num[i-1]=='0')
	{
		printf("%s", num);
	}
	else printf("-1");
	
	return 0;
}
