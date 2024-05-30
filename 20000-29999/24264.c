#include <stdio.h>

/*
 * MenOfPassion(A[], n) {
 *     sum <- 0;
 *     for i <- 1 to n
 *         for j <- 1 to n
 *             sum <- sum + A[i] × A[j]; # 코드1
 *     return sum;
 * }
 */
 
int main()
{
	long long int n;
	scanf("%lld", &n);
	printf("%lld\n", n*n);  // n의 제곱번 연산함
	printf("2");  // O(n^2)
	
	return 0;
}
