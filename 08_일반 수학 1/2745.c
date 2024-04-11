#include <stdio.h>
#include <math.h>

int main()
{
	int B, len=0, num, sum=0, i;
	char N[100];
	
	scanf("%s %d", N, &B);  // 수, 진법 
	while(N[len]!='\0') len++;  // 자릿수 계산
	 
	for(i=0;i<len;i++)
	{
		if(N[i]<58) num = N[i] - 48;
		else num = N[i] - 55;
		
		sum += num * pow(B, len-i-1);
	}
	printf("%d", sum);
	
	return 0;
}
