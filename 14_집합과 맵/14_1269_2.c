#include <stdio.h>

int main()
{
	int numA, numB, num, i;
	char chk[100000001] = {0,};
	
	scanf("%d %d", &numA, &numB);
	for(i=0;i<numA;i++)
	{
		scanf("%d", &num);
		chk[(int)num]++;
	}
	for(i=0;i<numB;i++)
	{
		scanf("%d", &num);
		chk[(int)num]++;
	}
	
	num = 0;
	for(i=1;i<=100000000;i++)
	{
		if(chk[i]==1) num++;
	}
	printf("%d", num);
	
	return 0;
}
