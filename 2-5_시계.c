#include <stdio.h>

int main()
{
	int hour, minute;
	scanf("%d %d", &hour, &minute);
	
	if(minute>=45)
	{
		printf("%d %d", hour, minute-45);
	}
	else
	{
		if(hour!=0) printf("%d %d", hour-1, 60-(45-minute));	
		else printf("23 %d", 60-(45-minute));	
	}
}
/*
#include <stdio.h>

int main() {
	int h, m;
	scanf("%d %d", &h, &m);

	m -= 45;
	if (m < 0) {
		m += 60;
		h -= 1;

		if (h < 0) h = 23;
	}

	printf("%d %d", h, m);
	return 0;
}
*/
