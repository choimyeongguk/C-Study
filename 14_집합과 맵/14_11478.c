#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const char** a, const char** b) { return strcmp(*a, *b); }

int main()
{
	int len, i, j, k, cnt=0;
	char S[1001];
	char** substring;
	
	scanf("%s", S);
	
	len = strlen(S);
	substring = (char**)malloc(len*sizeof(char**));
	for(i=0;i<len;i++) substring[i] = (char*)malloc(len*sizeof(char));
	
	for(i=1;i<=len;i++)  // 부분 문자열의 길이 
	{
		for(j=0;j<len;j++) for(k=0;k<len;k++) substring[j][k] = '\0';  // 부분문자열 배열 초기화 
		
		for(j=0;j<len-i+1;j++)  // 부분 문자열의 시작 위치 
		{
			for(k=0;k<i;k++)
			{
				substring[j][k] = S[j+k];
			}
		}
		
		qsort(substring, len-i+1, sizeof(substring[0]), compare);
		
		cnt++;
		for(j=1;j<len-i+1;j++)
		{
			if(strcmp(substring[j], substring[j-1])!=0)
			{
				cnt++;
			}
		}
	}
	printf("%d", cnt);
	
	for(i=0;i<len;i++) free(substring[i]);
	free(substring);
	return 0;
}
