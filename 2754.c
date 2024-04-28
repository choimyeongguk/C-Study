#include <stdio.h>

int main()
{
	double point = 0;
	char grade = getchar();
	
	if(grade=='F')
	{
		printf("0.0");
	}
	else
	{
		point += 69-grade;
		grade = getchar();
		if(grade!='0') point += grade=='+' ? 0.3:-0.3;
		printf("%.1f", point);
	}
	
	return 0;
}
