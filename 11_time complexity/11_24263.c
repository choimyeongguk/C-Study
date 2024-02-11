#include <stdio.h>

/*
 * MenOfPassion(A[], n) {
 *     sum <- 0;
 *     for i <- 1 to n
 *         sum <- sum + A[i]; # 코드1
 *     return sum;
 * }
 */
 
int main()
{
	int n;
	scanf("%d", &n);
	
	printf("%d\n", n);  // n이 증가함에 따라 일정하게 연산 횟수 증가 
	printf("1");  // O(n)
	
	return 0;
}
