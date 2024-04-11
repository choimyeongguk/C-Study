#include <stdio.h>

int gcd(int A, int B)  // A>B
{
	if(B==0) return A;
	else gcd(B, A%B);
}

int main()
{
	int sonA, sonB, momA, momB, resultSon, resultMom, num, big;
	
	scanf("%d %d", &sonA, &momA);
	scanf("%d %d", &sonB, &momB);
	
	resultSon = sonA*momB + sonB*momA;
	resultMom = momA*momB;
	
	big = resultSon>resultMom ? resultSon:resultMom;
	num = gcd(big, resultSon+resultMom-big);
	
	resultSon /= num;
	resultMom /= num;
	
	printf("%d %d", resultSon, resultMom);
	
	return 0;
}
