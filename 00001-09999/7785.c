#include <stdio.h>
#include <string.h>

int compare(const char* a, const char* b)
{
	return strcmp(a, b)*-1;
}

int main(void)
{
	int n, i;
	char name[1000000][6];
	char check[6];
	
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		scanf("%s %s", name[i], check);
	}
	
	qsort(name, n, sizeof(char)*6, compare);
	
	for(i=0;i<n;i++)
	{
		if(strcmp(name[i], name[i+1])==0)
		{
			i++;
			continue;
		}
		printf("%s\n", name[i]);
	}
	
	return 0;
}
