#include <stdio.h>

int main()
{
	int len=0;
	char word[100] = {'0'};
	scanf("%s", word);
	
	while(word[len]!='\0')	len++;	//���ڿ��� ������ \0�� ���� 
	printf("%d\n", len);
	
	return 0;
}
