#include <stdio.h>

int main()
{
	int buf;
	char A[4], B[4];
	
	scanf("%s %s", &A, &B);
	buf = A[0]; A[0] = A[2]; A[2] = buf;
	buf = B[0]; B[0] = B[2]; B[2] = buf;
	
	if(A[0]==B[0])
	{
		if(A[1]==B[1])
		{
			printf("%s", A[2]>B[2]?A:B);
		}
		else printf("%s", A[1]>B[1]?A:B);
	}
	else printf("%s", A[0]>B[0]?A:B);

//	int A_num, B_num;
//	char A[3], B[3];
//	scanf("%s %s", &A, &B);
//	A_num = (A[2]-48)*100 + (A[1]-48)*10 + A[0]-48;
//	B_num = (B[2]-48)*100 + (B[1]-48)*10 + B[0]-48;
//	printf("%d", A_num>B_num?A_num:B_num);
	
	return 0;
}
