#include <stdio.h>

int Solution(int n)
{
    if (n <= 1) return 0;
    int t1 = Solution(n / 2) + n % 2 + 1;
	// n�� ¦���� ���,  n%2==0, 1+Solution(n/2) ����
	// n�� Ȧ���� ���, n%2==1, -1 �� 1+Solution(n/2) ���� 
    int t2 = Solution(n / 3) + n % 3 + 1;
    return t1 < t2 ? t1 : t2;
}

int main(void)
{   
    int n;
    scanf("%d",&n);
    printf("%d\n",Solution(n));
}
