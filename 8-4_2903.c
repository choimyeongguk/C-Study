#include <stdio.h>
#include <math.h>

int main()
{
	int N, sqNum, dotsOnLine, dotNum;
	
	scanf("%d", &N);  // Ƚ�� �Է� 
	sqNum = pow(4, N);  // ���簢�� ����
	dotsOnLine =  pow(2, N) + 1;  // �� ���� �ִ� ���� ����
	dotNum = pow(dotsOnLine, 2);  // �� �� ���� 
	
	printf("%d", dotNum);
	
	return 0;
}
