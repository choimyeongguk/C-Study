#include <stdio.h>

typedef struct
{
	int order;
	int weight;
} DOC;

int main()
{
	int T, numDoc, target, numPrint, i, j;
	int head, tail;
	DOC document[1000];
	
	scanf("%d", &T);
	for(i=0;i<T;i++)
	{
		scanf("%d %d", &numDoc, &target);
		head = 0;
		tail = numDoc-1;
		for(j=0;j<numDoc;j++)
		{
			document[j].order = j;
			scanf("%d", &document[j].weight);
		}
		
		numPrint = 1;
		while(1)
		{
			for(j=head+1;j<=tail;j++)
			{
				if(document[head].weight < document[j].weight)
				{
					document[++tail] = document[head++];
					goto FINISH;
				}
			}
			if(document[head].order == target)
			{
				printf("%d\n", numPrint);
				break;
			}
			else
			{
				head++;
				numPrint++;
			}
			FINISH: continue;
		}
	}
	
	return 0;
}
