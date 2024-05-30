#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N, M, i, j;
	int* eratos;
	
	scanf("%d %d", &N, &M);
	eratos = (int*)calloc(M+1, sizeof(int));
	
	if(N==1) N++;
	for(i=2;i<=M;i++) eratos[i] = 0;
	
	for(i=2;i<=M;i++) if(eratos[i]==0) for(j=2;i*j<=M;j++) eratos[i*j]++;
	
	for(i=N;i<=M;i++) if(eratos[i]==0) printf("%d\n", i);
	
	return 0;
}
