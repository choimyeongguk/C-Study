//#include <stdio.h>
//
//typedef struct
//{
//	int document;
//	int interview;
//} APPLICANT;
//
//int compare(const APPLICANT* a, const APPLICANT* b)
//{
//	return a->document - b->document;
//}
//
//int main()
//{
//	int T, N, cnt, interviewMax, i, j;
//	APPLICANT applicant[100000];
//	
//	scanf("%d", &T);
//	for(i=0;i<T;i++)
//	{
//		scanf("%d", &N);
//		
//		for(j=0;j<N;j++)
//		{
//			scanf("%d %d", &applicant[j].document, &applicant[j].interview);
//		}	
//		qsort(applicant, N, sizeof(APPLICANT), compare);
//			
//		cnt = 1, interviewMax = applicant[0].interview;
//		for(j=1;j<N;j++)
//		{
//			if(applicant[j].interview<=interviewMax)
//			{
//				cnt++;
//				interviewMax = applicant[j].interview;
//			}
//		}
//		
//		printf("%d\n", cnt);
//	}
//	
//	return 0;
//}

#include <stdio.h>

int main()
{
	int T, N, document, interview, cnt, min, i, j;
	int applicant[100001];
	
	scanf("%d", &T);
	for(i=0;i<T;i++)
	{
		scanf("%d", &N);
		for(j=0;j<N;j++)
		{
			scanf("%d %d", &document, &interview);
			applicant[document] = interview;
		}
		
		cnt = 1;
		min = applicant[1];
		for(j=2;j<=N;j++)
		{
			if(applicant[j]<=min)
			{
				cnt++;
				min = applicant[j];
			}
		}
		
		printf("%d\n", cnt);
	}
	
	return 0;
}
