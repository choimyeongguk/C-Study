#include <stdio.h>

/*
 * MenOfPassion(A[], n) {
 *     sum <- 0;
 *     for i <- 1 to n - 2
 *         for j <- i + 1 to n - 1
 *             for k <- j + 1 to n
 *                 sum <- sum + A[i] × A[j] × A[k]; # 코드1
 *     return sum;
 * }
 */ 
 
#include <stdio.h>

int main()
{
	long long int n;
	scanf("%lld", &n);
	printf("%lld\n", n*(n-1)*(n-2)/6);  // \sum_{i=1}^{n-2} \sum_{j=i+1}^{n-1} \sum_{k=j+1}^{n}
	printf("3");  // n^3에 비례함 
	
	return 0;
}
