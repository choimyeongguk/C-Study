#include <stdio.h>

/*
 * MenOfPassion(A[], n) {
 *     sum <- 0;
 *     for i <- 1 to n
 *         for j <- 1 to n
 *             for k <- 1 to n
 *                 sum <- sum + A[i] �� A[j] �� A[k]; # �ڵ�1
 *     return sum;
 * }
 */
 
int main()
{
	long long int n;
	scanf("%lld", &n);
	printf("%lld\n", n*n*n);  // n�� �������� ������ 
	printf("3");  // n^3�� ��������� O(n^2)�� ǥ�� 
	
	return 0;
}
