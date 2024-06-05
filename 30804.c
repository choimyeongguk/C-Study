#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N, i;
	int* fruit;
	int p1, p2, t1, t2, num, max = 0;
	
	scanf("%d", &N);
	
	fruit = (int*)calloc(N, sizeof(int));
	for(i=0;i<N;i++) scanf("%d", &fruit[i]);
	
	t1 = p1 = p2 = 0;
	num = 1;  // 과일 종류
	for(;p2<N;p2++)
	{
		if(fruit[p2]!=fruit[t1])
		{
			if(num==1)
			{
				num++;
				t2 = p2;
			}
			else if(fruit[p2]!=fruit[t2])
			{
				max = max>p2-p1 ? max:p2-p1;
				
				p2--;
				while(fruit[p2-1]==fruit[p2]) p2--;
				t1 = p1 = p2;
				num = 1;
				continue;
			}
		}
		
		if(p2==N-1)
		{
			max = max>p2-p1+1 ? max:p2-p1+1;
		}
	}
	printf("%d", max);
	
	free(fruit);
	return 0;
}
