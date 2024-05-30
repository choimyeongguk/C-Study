#include <stdio.h>

int main()
{
	int N, k, student[1000], check, buf, i;
	
	scanf("%d %d", &N, &k);
	for(i=0;i<N;i++) scanf("%d", &student[i]);
	
	do
	{
		check = 0;
		for(i=0;i<N-1;i++)
		{
			if(student[i]<student[i+1])
			{
				buf = student[i];
				student[i] = student[i+1];
				student[i+1] = buf;
				check++;
			}
		}
	} while(check!=0);
	printf("%d", student[k-1]);
	
	return 0;
}
