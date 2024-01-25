#include <stdio.h>

int main()
{
	int i, n;
	int student[30] = {0};
	for(i=0;i<28;i++)
	{
		scanf("%d", &n);
		student[n-1] = 1;
	}
	for(i=0;i<30;i++)
	{
		if(student[i]==0) printf("%d\n", i+1);
	}
	/*for(i=0;i<30;i++)
	{
		if(student[i]==0)
		{
			s1 = i;
			break;
		}
	}
	for(i=s1+1;i<30;i++)
	{
		if(student[i]==0)
		{
			s2 = i;
			break;
		}
	}
	s1++; s2++;
	printf("%d\n%d", s1<s2?s1:s2, s1>s2?s1:s2);
	*/
	return 0;
}
