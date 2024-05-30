#include <stdio.h>

/*
 * MenOfPassion(A[], n) {
 *     sum <- 0;
 *     for i <- 1 to n
 *         for j <- 1 to n
 *             for k <- 1 to n
 *                 sum <- sum + A[i] × A[j] × A[k]; # 코드1
 *     return sum;
 * }
 */
 
int main()
{
	long long int n;
	scanf("%lld", &n);
	printf("%lld\n", n*n*n);  // n의 세제곱번 연산함 
	printf("3");  // n^3에 비례하지만 O(n^2)로 표기 
	
	return 0;
}
