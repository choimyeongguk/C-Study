#include <stdio.h>
#define MAX 1002

typedef struct
{
	int order;
	int value;
} DEQUE;

int move(int x) { return (x + MAX) % MAX; }

int main()
{
	int N, tmp, i;
	DEQUE ballon[MAX] = { 0 }; int head, tail;

	scanf("%d", &N);
	head = 0;
	tail = N;
	for (i = 0; i < N; i++)
	{
		scanf("%d", &tmp);
		ballon[i].order = i + 1;
		ballon[i].value = tmp;
	}

	while (head != tail)
	{
		printf("%d ", ballon[head].order);

		tmp = ballon[head].value;
		if (ballon[head].value > 0)
		{
			for (i = 0; i < tmp; i++)
			{
				head = move(++head);
				ballon[tail] = ballon[head];
				tail = move(++tail);
			}
			tail = move(--tail);
		}
		else
		{
			for (i = 0; i > tmp; i--)
			{
				tail = move(--tail);
				ballon[head] = ballon[tail];
				head = move(--head);
			}
			head = move(++head);
		}
	}

	return 0;
}
