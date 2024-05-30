#include <stdio.h>

int main()
{
	int N, f, t;
	
	scanf("%d", &N);
	switch(N%5)
	{
		case 0:
			f = N/5;
			t = 0;
			break;
		case 1:
			f = N/5-1;
			t = 2;
			break;
		case 2:
			f = N/5-2;
			t = 4;
			break;
		case 3:
			f = N/5;
			t = 1;
			break;
		case 4:
			f = N/5-1;
			t = 3;
			break;
	}

	if(f<0) printf("-1");
	else printf("%d", f+t);
	
	return 0;
}
