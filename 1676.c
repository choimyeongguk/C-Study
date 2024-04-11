#include <stdio.h>

int main()
{
	int N, num=1, cnt=0;
	
	scanf("%d", &N);
	
	for(; N>=(num*=5); cnt+=N/num);
	
	printf("%d", cnt);
	
	return 0;
}
