#include <stdio.h>
#include <string.h>

void printlen(word, num)
{
	printf("%d", strlen(word+num*50));
}

int main()
{
	int N, i;
	char word[100][50];
	
	scanf("%d", &N);
	for(i=0;i<N;i++) scanf("%s", word[i]);
	for(i=0;i<N;i++) printf("%d ", strlen(word[i]));
	printf("\n");
	for(i=0;i<N;i++) printlen(word, i);
	
	return 0;
}
