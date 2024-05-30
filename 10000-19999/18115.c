#include <stdio.h>

int main()
{
	int N, cmd, i;
	int top, bottom = 0;
	int handCard[1000000];
	int floorTop = 0;
	int floorCard[1000000];
	
	scanf("%d", &N);
	top = N-1;
	for(i=0;i<N;i++)
		handCard[i] = N-i-1;

	for(i=0;i<N;i++)
	{
		scanf("%d", &cmd);
		switch(cmd)
		{
			case 1:
				floorCard[floorTop++] = handCard[top--];
				break;
			case 2:
				floorCard[floorTop++] = handCard[top-1];
				handCard[top-1] = handCard[top];
				top--;
				break;
			case 3:
				floorCard[floorTop++] = handCard[bottom++];
				break;
		}
	}
	
	for(i=0;i<N;i++)
		handCard[floorCard[i]] = N-i;
		
	for(i=0;i<N;i++)
		printf("%d ", handCard[i]);
	
	return 0;
}
