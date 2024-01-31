#include <stdio.h>
#include <math.h>

int main()
{
	int N, B, digit=0, num, i;
	char result[100];
	
	scanf("%d %d", &N, &B);	
	while((double)N/pow(B, digit)>=1) digit++;
	
	for(i=0;i<digit;i++)
	{
		num = N/pow(B, digit-1-i);
		N -= num * pow(B, digit-1-i);
		if(num<10) printf("%c", num+48);
		else printf("%c", num+55);
	}
	
	return 0;
} 
