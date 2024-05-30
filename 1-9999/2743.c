#include <stdio.h>

int main()
{
	int len=0;
	char word[100] = {'0'};
	scanf("%s", word);
	
	while(word[len]!='\0')	len++;	//문자열의 끝에는 \0이 있음 
	printf("%d\n", len);
	
	return 0;
}
