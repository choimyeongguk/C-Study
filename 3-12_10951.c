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

// scanf�Լ��� ���� ��ȯ��. scanf�Լ��� ��ȯ ���� �о���� �Է��� ����.
// EOF(End of File)�� ctrl+Z 
