#include <stdio.h>

int main()
{
	int A, B;
	while(scanf("%d %d", &A, &B) != EOF)
	{
		printf("%d\n", A+B);
	}
	
	return 0;
}

// scanf함수도 값을 반환함. scanf함수의 반환 값은 읽어들인 입력의 개수.
// EOF(End of File)는 ctrl+Z 
