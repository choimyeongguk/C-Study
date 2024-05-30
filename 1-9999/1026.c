#include <stdio.h>
#include <stdlib.h>

int compare1(const int* a, const int* b)
{
	return *a - *b;
}

int compare2(const int* a, const int* b)
{
	return *b - *a;
}

int main()
{
	int N, sum, i;
	int A[50];
	int B[50];
	
	scanf("%d", &N);
	
	for(i=0;i<N;i++) scanf("%d", &A[i]);
	for(i=0;i<N;i++) scanf("%d", &B[i]);
	
	qsort(A, N, sizeof(int), compare1);
	qsort(B, N, sizeof(int), compare2);
	
	for(sum=0,i=0;i<N;i++)
	{
		sum += A[i]*B[i];
	}
	
	printf("%d", sum);
	
	return 0;
}
