#include <stdio.h>

/*
 * MenOfPassion(A[], n) {
 *     sum <- 0;
 *     for i <- 1 to n
 *         sum <- sum + A[i]; # �ڵ�1
 *     return sum;
 * }
 */
 
int main()
{
	int n;
	scanf("%d", &n);
	
	printf("%d\n", n);  // n�� �����Կ� ���� �����ϰ� ���� Ƚ�� ���� 
	printf("1");  // O(n)
	
	return 0;
}
