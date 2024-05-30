#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N, i;
	char** log;
	
	scanf("%d", &N);
	log = (char**)calloc(N, sizeof(char*));
	for(i=0;i<N;i++) log[i] = (char*)calloc(21, sizeof(char));
	
	scanf("%s", log[0]);
	for(i=0;i<N;i++)
	{
		scanf("%s", log[i]);
		printf("%s", log[i]);
		
	}
	
	for(i=0;i<N;i++) free(log[i]);
	free(log);
	return 0;
}
