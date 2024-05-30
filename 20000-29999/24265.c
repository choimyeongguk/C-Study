#include <stdio.h>

/*
 * MenOfPassion(A[], n) {
 *     sum <- 0;
 *     for i <- 1 to n - 1
 *         for j <- i + 1 to n
 *             sum <- sum + A[i] × A[j]; # 코드1
 *     return sum;
 * }
 */
 
int main()
{
	long long int n;
	scanf("%lld", &n);
	printf("%lld\n", n*(n-1)/2);  // 1+2+...+(n-1), 예시 참조 
	printf("2");  // O(n^2)
	
	return 0; 
}

/*
 * if n = 4
 * i=1, j=2, 3, 4, 5
 * i=2, j=3, 4, 5
 * i=3, j=4, 5
 * i=4, j=5
 */
