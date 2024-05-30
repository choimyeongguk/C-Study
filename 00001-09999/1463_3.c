#include <stdio.h>

int Solution(int n)
{
    if (n <= 1) return 0;
    int t1 = Solution(n / 2) + n % 2 + 1;
	// n이 짝수인 경우,  n%2==0, 1+Solution(n/2) 성립
	// n이 홀수인 경우, n%2==1, -1 후 1+Solution(n/2) 성립 
    int t2 = Solution(n / 3) + n % 3 + 1;
    return t1 < t2 ? t1 : t2;
}

int main(void)
{   
    int n;
    scanf("%d",&n);
    printf("%d\n",Solution(n));
}
