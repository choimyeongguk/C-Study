#include <stdio.h>

int main()
{
	int N, K, i, x=1;
	
	scanf("%d %d", &N, &K);
	
    for(i=N;i>1;i--) x *= i;
    for(i=K;i>1;i--) x /= i;
    for(i=N-K;i>1;i--) x /= i;
    
    printf("%d", x);
	
	return 0;
}
