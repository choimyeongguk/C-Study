#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int compare(const int* a, const int* b)
{
	return *b - *a;
}

int main()
{
	int N, ans=0, len, i, j;
	int weight[26] = { 0, };
	char word[11];
	
	scanf("%d", &N);
	for(i=0;i<N;i++)
	{
		scanf("%s", word);
		len = strlen(word) - 1;
		for(j=len;j>=0;j--)
		{
			weight[word[j]-'A'] += pow(10, len-j);
		}
	}
	qsort(weight, 26, sizeof(int), compare);
	
	for(i=0;weight[i]!=0;i++)
	{
		ans += weight[i]*(9-i);
	}
	printf("%d", ans);
	
	return 0;
}
