#include <stdio.h>

typedef struct
{
	int d;
	int l;
} MELON;

int main()
{
	int K, W=0, H=0, i;
	int tmp, area;
	MELON field[6];
	
	scanf("%d", &K);
	
	for(i=0;i<6;i++)
	{
		scanf("%d %d", &field[i].d, &field[i].l);
		
		switch(field[i].d)
		{
			case 1: case 2:
				W = W>field[i].l ? W:field[i].l;
				break;
			case 3: case 4:
				H = H>field[i].l ? H:field[i].l;
				break;
		}
	}
	
	int chk = 0;
	for(i=0;i<6;i++)
	{
		if(field[i].d==1 && field[(i+1)%6].d==3) chk++;
		if(field[i].d==3 && field[(i+1)%6].d==2) chk++;
		if(field[i].d==2 && field[(i+1)%6].d==4) chk++;
		if(field[i].d==4 && field[(i+1)%6].d==1) chk++;
		
		if(chk)
		{
			tmp = field[i].l * field[(i+1)%6].l;
			break;
		}
	}
	
	area = H*W - tmp;
	printf("%d", area*K);
	
	return 0;
}
