#include <stdio.h>

int main()
{
	int input1, input2;
	int units, tens, hundres;
	scanf("%d", &input1);
	scanf("%d", &input2);
	
	units = input2%10;
	tens = (input2%100 - units)/10;
	hundres = (input2%1000 - tens)/100;
	
	printf("%d\n", input1*units);
	printf("%d\n", input1*tens);
	printf("%d\n", input1*hundres);
	printf("%d", input1*input2);
	
	return 0;
}
