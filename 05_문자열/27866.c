#include <stdio.h>

int main()
{
	int x, i;
	char word[1000];
	scanf("%s", &word);
	scanf("%d", &x);
	printf("%c", word[x-1]);
	
	return 0;
}
