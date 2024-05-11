#include <stdio.h>

int main()
{
	int T, i, j;
	int numStudent, cnt;
	int score[1000];
	double avg;
	
	scanf("%d", &T);
	
	for(i=0;i<T;i++)
	{
		scanf("%d", &numStudent);
		
		for(avg=0, j=0;j<numStudent;j++)
		{
			scanf("%d", &score[j]);
			avg += score[j];
		}
		avg /= numStudent;
		for(cnt=0, j=0;j<numStudent;j++)
		{
			score[j]>avg ? cnt++:cnt;
		}
		
		printf("%.3f%%\n", ((double)cnt/numStudent)*100);
	}
	
	return 0;
}
