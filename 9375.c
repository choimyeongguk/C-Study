#include <stdio.h>
#include <string.h> 

typedef struct
{
	int num;
	char type[21];
} CLOTHE;

int main()
{
	int i, j, k;
	int T, n;
	int numType, numCase, cnt;
	char tmp[21], type[21];
	CLOTHE clothes[30];
	
	scanf("%d", &T);
	for(i=0;i<T;i++)
	{
		for(numType=0, j=0;j<30;j++)
		{
			clothes[j].num = 0;
			for(k=0;k<21;k++)
			{
				clothes[j].type[k] = 0;
			}
		}
		
		scanf("%d", &n);
		for(j=0;j<n;j++)
		{
			scanf("%s %s", tmp, type);
			for(cnt=0, k=0;k<numType;k++)
			{
				if(strcmp(type, clothes[k].type)==0)
				{
					cnt++;
					clothes[k].num++;
					break;
				}
			}
			if(cnt==0)  // 같은 type 없음 
			{
				for(k=0;k<=strlen(type);k++)
				{
					clothes[numType].type[k] = type[k];
				}
				clothes[numType++].num++;
			}
		}
		
		for(numCase=1, j=0;j<numType;j++)
		{
			numCase *= clothes[j].num+1;
		}
		numCase--;
		printf("%d\n", numCase);
	}
	
	return 0;
}
