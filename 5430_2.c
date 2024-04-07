#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int T, err, i, j, k;
	int* arr; int head, tail, swap;
	char cmd[100001];
	int num[3], index, numLen;
	char arrInput;
	
	scanf("%d", &T);
	for(i=0;i<T;i++)
	{
		err = 0; index = 1; head = 0; swap = 0;
		
		scanf("%s", cmd);  // 명령어 입력 
		scanf("%d", &tail);  // 배열 크기 입력
		arr = (int*)malloc(tail*sizeof(int));
		
		numLen=0;
		for(j=0;j<tail;j++)
		{
			scanf("%c", &arrInput);
			if(arrInput=='[') continue;
			if(arrInput==',' || arrInput==']')
			{
				arr[j] = 0;
				for(k=0;k<numLen;k++)
				{
					arr[j] += num[k]*pow(10, numLen-k-1);
				}
				numLen = 0;
				k++;
			}
			else
			{
				num[numLen] = arrInput-48;
				numLen++;
			}
		}

		for(j=0;j<tail;j++) printf("%d ", arr[j]);
		printf("\n");
		
		for(j=0;j<strlen(cmd);j++)
		{
			if(cmd[j]=='D') 
			{
				if(head==tail)
				{
					err++;
					break;
				}
				else if(swap==0) head++;
				else tail--;
			}
			else swap = swap==0 ? 1:0;
		}
		
		if(err==0)
		{
			printf("[");
			if(swap==0)
			{
				for(j=head;j<tail-1;j++) printf("%d,", arr[j]);
				if(head!=tail) printf("%d", arr[tail-1]);
			}
			else
			{
				for(j=tail-1;j>head;j--) printf("%d,", arr[j]);
				if(head!=tail) printf("%d", arr[head]);
			}
			printf("]\n");
		} else printf("error\n");
	}
	
	free(arr);
//	free(arrInput);
	return 0;
}
